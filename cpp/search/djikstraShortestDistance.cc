#include <bits/stdc++.h>

using namespace std;


/* returns shortest path to e starting at s */
int shortestPath(vector<vector<int>>& G, int s, int e) {
    vector<int> distances(G.size(), INT_MAX);
    vector<bool> visited(G.size(), 0);
    distances[s] = 0; // distance to start from start is 0
    queue<int> Q;
    Q.push(s);

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        visited[u] = 1; // mark front of queue as visited
        // get all of adj of u
        for(int x{}; x < G[u].size(); ++x) {
            if(G[u][x] && !visited[x]) {
                Q.push(x);
                if(distances[x] > distances[u] + G[u][x]) {
                    distances[x] = distances[u] + G[u][x];
                }
            }
        }
    
    }

    return distances[e];
}

int main() {
    vector<vector<int>> graph;
    graph.resize(5);
    for(auto& r : graph) r.resize(5);

    graph[0][1] = 2;
    graph[0][4] = 3;
    graph[1][2] = 1;
    graph[2][3] = 4;
    graph[3][1] = 6;

    int sd = shortestPath(graph, 0, 1);
    std::cout << "shortest distance: " << sd << "\n";

    return 0;
}

