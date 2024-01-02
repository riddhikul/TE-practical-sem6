#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V; //for number of vertices
    vector<vector<int>> adj; //adjacency list
    public:
    Graph(int vertices){ 
        V=vertices;
        adj.resize(vertices+1);
    }

    void addEdge(int u,int v){

    }

    void recbfs(vector<int>&visit , queue<int> &q,vector<int>&ans){
        
    }
};