//
// Created by Milena Petrovic on 11/16/22.
//

//#ifndef PAGERANK_ADJACENCYLIST_H
//#define PAGERANK_ADJACENCYLIST_H
#include <iostream>
#include <set>
#include <map>
#include <vector>
#pragma once
using namespace std;

class AdjacencyList {
private:
    map<string, set<string> > inGraph; //adjacency list of nodes pointing to key node
    map<string, int> outGraph;        //graph of each node's out degree
    map<string, double> vertices;     //graph of each node's rank
public:
    void PageRank(int p);
    double computeRank(const string& vertex);
    void insertPage(string from, string to);
    bool contains(const string& vertex);
    vector<double> getRanks();
};


//#endif //PAGERANK_ADJACENCYLIST_H
