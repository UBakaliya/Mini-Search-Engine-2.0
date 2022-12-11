/**
 * @file graph.h
 * @author Uvaish Bakaliya
 * @brief Writing the graph class in this file
 * @version 0.1
 * @date 2022-12-09
 * @copyright Copyright © 2022 UB
 * @note Feel free to use edit how every you please.
 */

#pragma once

#include "linkedList.h"
#include <iostream>
#include <map>
#include <set>
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
    struct graphData
    {
        unordered_map<vertexT, weightT> edge;
        LinkedList<vertexT> urls;
    };
    size_t edgeCounter;
    // keys are going to be the description --> url and edge
    map<vertexT, graphData> adjList;

    /**
     * @brief the function are private because we are going to run the
     *   function through Other function, and also we don't want to give access
     *   to user.
     */
    void AStartAlgo() const;
    void DFS() const;
    void BFS() const;

public:
    Graph() { this->edgeCounter = 0; }

    ~Graph() { this->adjList.clear(); }

    size_t size() { return this->adjList.size(); }

    void addVertex(vertexT descriptWord, vertexT url)
    {
        adjList[descriptWord].urls.insert(url);
    }

    void addEdge(vertexT from, vertexT to, weightT weight)
    {
        this->adjList[from].edge[to] = weight;
        this->edgeCounter++;
    }

    weightT getWeight(vertexT from, vertexT to)
    {
        weightT weight = this->adjList[from].edge[to];
        return weight;
    }

    void runDFS() const;
    void runBFS() const;
    void runAStartAlgo() const;
    // use full for testing
    void dump(std::ostream &ouput)
    {
        for (const auto &i : adjList)
        {
            ouput << i.first << ": ";
            for (const auto &j : i.second.edge)
                ouput << '(' << j.first << ',' << j.second << ')' << ' ';
            ouput << endl;
        }
    }
};
