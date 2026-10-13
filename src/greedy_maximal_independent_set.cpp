#include "greedy_maximal_independent_set.hpp"

#include <unordered_set>

using namespace std;
using namespace boost;

using Graph = adjacency_list<vecS, vecS, undirectedS>;

#define FORALL_VERTICES(u, graph) \
    for (auto u : make_iterator_range(vertices(graph)))
#define FORALL_OUTEDGES(u, e, graph) \
    for (auto e : make_iterator_range(out_edges(u, graph)))

struct CompareNodesByOutDegree {
    CompareNodesByOutDegree(
            const Graph& graph)
        : graph(graph)
    {

    }

    bool operator()(
        size_t u,
        size_t v)
    {
        return out_degree(u, graph) < out_degree(v, graph);
    }

    const Graph& graph;
};

vector<size_t>
greedy_maximal_independent_set(
        const Graph& graph)
{
#ifdef   USE_HASH_SET
    std::unordered_set<size_t> independent_set;
#elifdef USE_FAST_SET
    vector<size_t>        independent_set_elements;
    vector<bool>          independent_set_direct_addressing_table(num_vertices(graph), false);
#else
    #error "Define USE_HASH_SET or USE_HASH_SET"
#endif

    vector<size_t> sorted_vertices;
    sorted_vertices.reserve(num_vertices(graph));

    // Add all vertices U in graph G to a list, and then sort that list by node degree - O(n log n)
    FORALL_VERTICES(u, graph)
        sorted_vertices.push_back(u);

    sort(
        sorted_vertices.begin(),
        sorted_vertices.end(),
        CompareNodesByOutDegree(graph)
    );

    for (size_t u : sorted_vertices)
    {
        bool neighbor_in_independent_set = false;
        FORALL_OUTEDGES(u, e, graph)
        {
            size_t v = target(e, graph);
#ifdef   USE_HASH_SET
            if (independent_set.contains(v))
#elifdef USE_FAST_SET
            if (independent_set_direct_addressing_table[v])
#endif
            {
                neighbor_in_independent_set = true;
                break;
            }
        }

        if (!neighbor_in_independent_set)
        {
#ifdef   USE_HASH_SET
            independent_set.emplace(u);
#elifdef USE_FAST_SET
            independent_set_direct_addressing_table[u] = true;
            independent_set_elements.push_back(u);
#endif
        }
    }

#ifdef   USE_HASH_SET
    return vector<size_t>(independent_set.begin(), independent_set.end());
#elifdef USE_FAST_SET
    return independent_set_elements;
#endif
}

bool
validate_independent_set(
        const Graph& graph,
        vector<size_t> independent_set_vertices)
{
    vector<bool> independent_set_direct_addressing_table(num_vertices(graph), false);
    for (size_t u : independent_set_vertices)
        independent_set_direct_addressing_table[u] = true;
    
    for (size_t u : independent_set_vertices)
    {
        FORALL_OUTEDGES(u, e, graph)
        {
            size_t v = target(e, graph);
            if (independent_set_direct_addressing_table[v])
                return false;
        }
    }

    return true;
}
