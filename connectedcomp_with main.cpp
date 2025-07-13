#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        vector<bool> visited(V, false);
        int count = 0;
        for (int node = 0; node < V; ++node) {
            if (!visited[node]) {
                dfs(node, adj, visited);
                count++;
            }
        }
        return count;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    Solution sol;
    int components = sol.findNumberOfComponent(V, edges);
    cout << "Connected Components: " << components << endl;

    return 0;
}
