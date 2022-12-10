/**
 * @file graph.h
 * @author Uvaish Bakaliya
 * @brief Writing the graph class in this file
 * @version 0.1
 * @date 2022-12-09
 * @copyright Copyright © 2022 UB
 * @note Feel free to use it/edit it.
 */

#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

template <typename vertexT, typename weightT>
class Graph
{
private:
    /**
     * @brief the data we are going to use for the program are
     * only url and description, so we are keeping them together
     */
    struct vertexData
    {
        vertexT url;
        vertexT description;
    };

    typedef unordered_map<vertexData, weightT> edge;
    unordered_map<vertexData, edge> adjList;

    /**
     * @brief the function are private because we are going to run the
     *   function through Other function, and also we don't want to give access
     *   to user.
     */
    void AStartAlgo() const;
    void DFS() const;
    void BFS() const;

public:
    void addVertex(vertexT vertex) const;
    void addEdge(vertexT from, vertexT to, weightT weight) const;
    weightT getWeight(vertexT from, vertexT) const;
    void runDFS() const;
    void runBFS() const;
    void runAStartAlgo() const;
    // Use full for testing
    void dump(ostream &ouput);
};
