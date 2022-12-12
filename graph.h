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
#include <queue>
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
        unordered_map<vertexT, weightT> edges;
        LinkedList<vertexT> urls;
    };
    size_t edgesCounter;
    // keys are going to be the description --> url and edges
    map<vertexT, graphData> adjList;

    /**
     * @brief the function are private because we are going to run the
     *   function through Other function, and also we don't want to give access
     *   to user.
     */
    void privateDFS(
        vertexT v, vector<vertexT> &dfsData, map<vertexT, bool> &visited)
    {
        visited[v] = true;
        dfsData.push_back(v);
        for (const auto &i : this->adjList[v].edges)
        {
            if (!visited[i.first])
                privateDFS(i.first, dfsData, visited);
        }
    }

    vector<vertexT> privateBFS(vertexT v)
    {
        queue<vertexT> q;
        vector<vertexT> dfsData;
        q.push(v);
        map<vertexT, bool> visited;
        visited[v] = true;
        while (!q.empty())
        {
            vertexT frontV = q.front();
            q.pop();
            dfsData.push_back(frontV);
            for (const auto &i : this->adjList[v].edges)
            {
                if (!visited[i.first])
                {
                    q.push(i.first);
                    visited[i.first] = true;
                }
            }
        }
        return dfsData;
    }

public:
    Graph() { this->edgesCounter = 0; }

    ~Graph() { this->adjList.clear(); }

    size_t size() { return this->adjList.size(); }

    void addVertex(vertexT descriptWord, vertexT url) { this->adjList[descriptWord].urls.insert(url); }

    void addEdge(vertexT from, vertexT to, weightT weight)
    {
        this->adjList[from].edges[to] = weight;
        this->edgesCounter++;
    }

    weightT getWeight(vertexT from, vertexT to)
    {
        weightT weight = this->adjList[from].edges[to];
        return weight;
    }

    vector<vertexT> DFS(vertexT v)
    {
        vector<vertexT> dfsData;
        map<vertexT, bool> visited;
        privateDFS(v, dfsData, visited);
        return dfsData;
    }

    vector<vertexT> BFS(vertexT v) { return privateBFS(v); }

    // use full for testing
    void dump(ostream &ouput)
    {
        for (const auto &i : adjList)
        {
            ouput << i.first << ": ";
            for (const auto &j : i.second.edges)
                ouput << '(' << j.first << ',' << j.second << ')' << ' ';
            ouput << endl;
        }
    }
};
