#include <iostream>
#include <cstdlib>
#include <chrono>
#include <format>

#include "greedy_maximal_independent_set.hpp"

using namespace std;
using namespace boost;
using Graph = adjacency_list<vecS, vecS, undirectedS>;

int main()
{
    Graph graph;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    {
        auto start_time = high_resolution_clock::now();

        for (size_t u = 0; u < 10000; u++)
            add_vertex(graph);
    
        for (auto u : make_iterator_range(vertices(graph)))
        {
            for (auto v : make_iterator_range(vertices(graph)))
            {
                if (u == v)
                    continue;

                if (rand() % 10 == 1)
                    add_edge(u, v, graph);
            }
        }

        auto end_time = high_resolution_clock::now();

        duration<double, std::milli> ms_double = start_time - end_time;
        cout << format("Generating Graph: {}ms", ms_double.count()) << endl;
    }

    {
        auto start_time = high_resolution_clock::now();

        vector<size_t> independent_set_vertices = greedy_maximal_independent_set(graph);

        auto end_time = high_resolution_clock::now();

        for (const size_t u : independent_set_vertices)
            cout << format("{} ", u);
        cout << endl;

        duration<double, std::milli> ms_double = start_time - end_time;
        cout << format("Solving MIS: {}ms", ms_double.count()) << endl;

        //validate_independent_set(graph, independent_set_vertices);
    }

    return EXIT_SUCCESS;
}
