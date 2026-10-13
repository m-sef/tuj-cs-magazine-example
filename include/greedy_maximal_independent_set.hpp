#ifndef GREEDY_MAXIMAL_INDEPENDENT_SET_H
#define GREEDY_MAXIMAL_INDEPENDENT_SET_H

#include <vector>

#include <boost/graph/adjacency_list.hpp>

std::vector<size_t>
greedy_maximal_independent_set(
        const boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>& graph);

bool
validate_independent_set(
        const boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>& graph,
        const std::vector<size_t>& independent_set_vertices);

#endif
