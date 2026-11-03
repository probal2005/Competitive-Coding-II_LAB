import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution {
    public boolean validPath(int n, int[][] edges,
                             int source, int destination) {
        if (n <= 0 || source < 0 || destination < 0 ||
            source >= n || destination >= n) {
            return false;
        }

        // Build the undirected adjacency list.
        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            if (edge == null || edge.length != 2 ||
                edge[0] < 0 || edge[0] >= n ||
                edge[1] < 0 || edge[1] >= n) {
                return false;
            }

            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        boolean[] visited = new boolean[n];
        Stack<Integer> stack = new Stack<>();

        stack.push(source);
        visited[source] = true;

        // Iterative Depth-First Search.
        while (!stack.isEmpty()) {
            int node = stack.pop();

            if (node == destination) {
                return true;
            }

            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }

        return false;
    }
}

class Main {
    public static void main(String[] args) {
        int n = 6;

        int[][] edges = {
            {0, 1},
            {0, 2},
            {3, 5},
            {5, 4},
            {4, 3}
        };

        int source = 0;
        int destination = 5;

        Solution solution = new Solution();

        boolean result = solution.validPath(
            n, edges, source, destination
        );

        System.out.println("Number of Vertices: " + n);
        System.out.println("Source: " + source);
        System.out.println("Destination: " + destination);
        System.out.println("Valid Path Exists: " + result);
    }
}
