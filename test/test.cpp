//
// Created by Milena Petrovic on 11/7/22.

#include "../src/AdjacencyList.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <cmath>

using namespace std;


TEST_CASE("Insert", "[test]"){
    AdjacencyList list;
    list.insertPage("google.com", "yahoo.com");
    REQUIRE(list.contains("google.com"));
    REQUIRE(list.contains("yahoo.com"));
    REQUIRE_FALSE(list.contains("urmom.com"));
}

TEST_CASE("Insert 10,000", "[test2]"){
    AdjacencyList list;
    for(int i = 1; i <= 10000; i++){
        list.insertPage("0", "1");
    }
    REQUIRE(list.contains("0"));
    REQUIRE(list.contains("1"));
    REQUIRE_FALSE(list.contains("2"));
}

TEST_CASE("pageRank-1 iteration", "[1]"){
    AdjacencyList list;
    list.insertPage("0", "5");
    list.insertPage("1", "0");
    list.insertPage("2", "0");
    list.insertPage("3", "0");
    list.insertPage("4", "0");
    list.insertPage("5", "0");
    list.PageRank(1);

    vector<double> actual = list.getRanks();
    for(int i = 0; i < actual.size(); i++){
        actual[i]= round(actual[i]*100.0)/100.0;
    }
    vector<double> expected {0.17, 0.17, 0.17, 0.17, 0.17, 0.17};
    REQUIRE(actual == expected);
}

TEST_CASE("pageRank-2 iteration", "[2]"){
    AdjacencyList list;
    list.insertPage("0", "5");
    list.insertPage("1", "0");
    list.insertPage("2", "0");
    list.insertPage("3", "0");
    list.insertPage("4", "0");
    list.insertPage("5", "0");
    list.PageRank(2);

    vector<double> actual = list.getRanks();
    for(int i = 0; i < actual.size(); i++){
        actual[i]= round(actual[i]*100.0)/100.0;
    }
    vector<double> expected {0.83, 0.00, 0.00, 0.00, 0.00, 0.17};
    REQUIRE(actual == expected);
}

TEST_CASE("pageRank-3 iteration", "[3]"){
    AdjacencyList list;
    list.insertPage("0", "5");
    list.insertPage("1", "0");
    list.insertPage("2", "0");
    list.insertPage("3", "0");
    list.insertPage("4", "0");
    list.insertPage("5", "0");
    list.PageRank(3);

    vector<double> actual = list.getRanks();
    for(int i = 0; i < actual.size(); i++){
        actual[i]= round(actual[i]*100.0)/100.0;
    }
    vector<double> expected {0.17, 0.00, 0.00, 0.00, 0.00, 0.83};
    REQUIRE(actual == expected);
}

TEST_CASE("pageRank-10,000 iteration", "[10,000]"){
    AdjacencyList list;
    list.insertPage("0", "5");
    list.insertPage("1", "0");
    list.insertPage("2", "0");
    list.insertPage("3", "0");
    list.insertPage("4", "0");
    list.insertPage("5", "0");
    list.PageRank(10000);

    vector<double> actual = list.getRanks();
    for(int i = 0; i < actual.size(); i++){
        actual[i]= round(actual[i]*100.0)/100.0;
    }
    vector<double> expected {0.83, 0.00, 0.00, 0.00, 0.00, 0.17};
    REQUIRE(actual == expected);
}




