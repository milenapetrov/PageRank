//
// Created by Milena Petrovic on 11/16/22.
//

#include "AdjacencyList.h"
#include <iostream>
#include <set>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

void AdjacencyList::insertPage(string from, string to){
    //creates adjacency list
    inGraph[to].insert(from);  //list of in pages
    outGraph[from]++;             //outDegree increments
    if(inGraph.find(from) == inGraph.end())
        inGraph[from] = {};

    double rank = 1.0/(double)inGraph.size();
    vertices[to] = rank;
    vertices[from] = rank;
    //makes sure that previously added nodes get updated rank with increase in size
    for(const auto& i: vertices)
        vertices[i.first] = rank;
}

double AdjacencyList::computeRank(const string& vertex) {
    //rank = inRank1/outDeg(inRank1) + inRank2/outDeg(inRank2)
    double ret = 0.0;
    //i is a constant reference because its value is not being changed
    for (const auto& i: inGraph[vertex])  ///O(inDegree(V))
        ret += vertices[i]/outGraph[i];
    return ret;
}

// prints the PageRank of all pages after p powerIterations in ascending alphabetical order of webpages and rounding rank to two decimal places
void AdjacencyList::PageRank(int p){
    map<string, double> final;
    for(int i = 1; i < p;i++){
        for(const auto& v: vertices)
            final[v.first] = computeRank(v.first);
        //updates each value in list after full iteration of rank computation
        vertices = final;
    }
    //prints
    for(const auto& i: vertices)
        cout << i.first << " " << fixed << setprecision(2) << i.second << endl;
}

bool AdjacencyList::contains(const string& vertex) {
    if(inGraph.count(vertex))
        return true;
    return false;
}

vector<double> AdjacencyList::getRanks() {
    vector<double> ret;
    for(const auto& i : vertices)
        ret.push_back(i.second);
    return ret;
}