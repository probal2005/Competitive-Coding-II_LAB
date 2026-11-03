#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {
        if (n <= 0 || source < 0 || destination < 0 ||
            source >= n || destination >= n) {
            return false;
        }

        // Build the undirected adjacency list.
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            if (edge.size() != 2 ||
                edge[0] < 0 || edge[0] >= n ||
                edge[1] < 0 || edge[1] >= n) {
                return false;
            }

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        stack<int> st;

        st.push(source);
        visited[source] = true;

        // Iterative Depth-First Search.
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (node == destination) {
                return true;
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    st.push(neighbor);
                }
            }
        }

        return false;
    }
};

int main() {
    int n = 6;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 5},
        {5, 4},
        {4, 3}
    };

    int source = 0;
    int destination = 5;

    Solution solution;

    bool result = solution.validPath(
        n, edges, source, destination
    );

    cout << "Number of Vertices: " << n << '\n';
    cout << "Source: " << source << '\n';
    cout << "Destination: " << destination << '\n';
    cout << "Valid Path Exists: "
         << (result ? "true" : "false") << '\n';

    return 0;
}
