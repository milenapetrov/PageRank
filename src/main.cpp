#include <iostream>
#include <set>
#include <map>
#include <iomanip>
#include <vector>
#include "AdjacencyList.h"
using namespace std;

int main()
{
    int no_of_lines, power_iterations;
    AdjacencyList Graph;
    std::string from, to;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;
    //creates graph
    for(int i = 0;i < no_of_lines; i++)
    {
        std::cin >> from;
        std::cin >> to;
        Graph.insertPage(from, to);
    }
    //computes rank and updates graph --> prints
    Graph.PageRank(power_iterations);
}
