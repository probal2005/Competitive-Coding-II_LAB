class Solution:
    def validPath(self, n, edges, source, destination):
        if (n <= 0 or source < 0 or destination < 0
                or source >= n or destination >= n):
            return False

        # Build the undirected adjacency list.
        adj = [[] for _ in range(n)]

        for edge in edges:
            if (len(edge) != 2 or
                    edge[0] < 0 or edge[0] >= n or
                    edge[1] < 0 or edge[1] >= n):
                return False

            u, v = edge
            adj[u].append(v)
            adj[v].append(u)

        visited = [False] * n
        stack = [source]
        visited[source] = True

        # Iterative Depth-First Search.
        while stack:
            node = stack.pop()

            if node == destination:
                return True

            for neighbor in adj[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    stack.append(neighbor)

        return False


if __name__ == "__main__":
    n = 6

    edges = [
        [0, 1],
        [0, 2],
        [3, 5],
        [5, 4],
        [4, 3]
    ]

    source = 0
    destination = 5

    solution = Solution()
    result = solution.validPath(n, edges, source, destination)

    print(f"Number of Vertices: {n}")
    print(f"Source: {source}")
    print(f"Destination: {destination}")
    print(f"Valid Path Exists: {str(result).lower()}")
