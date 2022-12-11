/**
 * @file tests.cpp
 * @author Uvaish Bakaliya
 * @brief This the file where we test our code!
 * @date 2022-12-09
 * @copyright Copyright © UB 2022
 * @note Feel free to use edit how every you please.
 */
#include "graph.h"
#include <ctime>
#include <gtest/gtest.h> // Must have for google test fram work
#include <iostream>
#include <unistd.h>
#include <unordered_set>
using namespace std;

typedef Graph<string, int> graph;
#define TIME_RAND srand((unsigned)time(NULL) * getpid());

string genRandomStr()
{
    const size_t length = 5;
    auto randChar = []() -> char
    {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    string str(length, 0);
    generate_n(str.begin(), length, randChar);
    return str;
}

TEST(Graph, addV_addE_getW)
{
    TIME_RAND;
    set<string> randEle;
    graph G;
    size_t n = 100;
    for (int i = 0; i < n; i++)
    {
        string randStr = genRandomStr();
        if (!randEle.count(randStr))
            randEle.insert(randStr);
        G.addVertex(randStr, randStr);
    }
    stringstream expect, retrieved;
    for (auto i : randEle)
        expect << i << ": " << endl;
    G.dump(retrieved);
    EXPECT_EQ(expect.str(), retrieved.str());
    vector<string> edges;
    vector<int> weights;
    for (auto i : randEle)
        edges.push_back(i);
    for (size_t i = 0; i < edges.size(); i++)
    {
        int randNum = rand() % 10 + 1;
        G.addEdge(edges[i], edges[i + 1], randNum);
        weights.push_back(randNum);
    }
    for (size_t i = 0; i < edges.size(); i++)
    {
        size_t weight = G.getWeight(edges[i], edges[i + 1]);
        EXPECT_EQ(weights[i], weight);
    }
    EXPECT_EQ(randEle.size(), G.size());
}
