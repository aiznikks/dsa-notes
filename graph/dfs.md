# DSA Notes

## DFS in Graph (Depth-First Search)

### Important Terminology:

<details>
<summary>Click to expand!</summary>

> **DFS (Depth-First Search)**: A graph traversal algorithm that explores as far as possible along each branch before backtracking.
>
> **Stack**: In DFS, a stack (or the function call stack during recursion) is used to store the nodes being visited.
> 
> **Adjacency List**: A way to represent a graph where each node has a list of its neighboring nodes.
> 
> **Visited Array (`vis`)**: An array used to track whether a node has been visited or not during traversal.
> 
> **Backtracking**: The process of returning to previously visited nodes when no further unvisited nodes are available in the current branch.

</details>

---

### Steps to Implement DFS:

1. **Create a `vis` array**:
   - Initialize a visited array (`vis`) of size `n` with all values set to `0` (unvisited).

2. **Create an adjacency list**:
   - Use an adjacency list, which is an array of vectors: `vector<int> adj[n+1]`. This will store the graph structure.

3. **Call DFS recursively on the starting node**:
   - Start the DFS from the given node and mark it as visited.

4. **Recursively explore each neighbor**:
   - For each neighbor of the current node:
     - If the neighbor is not visited, recursively call DFS on that neighbor.

5. **Backtrack**:
   - When all neighbors are visited or there are no unvisited neighbors, the function backtracks to the previous node.

---

### DFS Implementation Code:

```cpp
void dfs(int node, vector<int> adj[], int vis[], vector<int> &dfsTraversal) {
    // Step 3: Mark the node as visited
    vis[node] = 1;
    dfsTraversal.push_back(node);  // Add the node to DFS result

    // Step 4: Recursively explore each neighbor
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, dfsTraversal);
        }
    }
}

vector<int> dfsofGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};  // Step 1: Initialize visited array
    vector<int> dfsTraversal;  // To store the DFS result

    // Step 2: Call DFS for each component (handle disconnected graphs)
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, dfsTraversal);
        }
    }
    return dfsTraversal;  // Return the DFS traversal
}
```

Time and Space Complexity
<details> <summary>Click to expand!</summary>
Time Complexity (TC):
Initialization:
Initializing the vis array takes O(V) time.
Initializing the queue takes O(1) time.
Processing Each Node:
Each node is processed exactly once, contributing O(V) to the time complexity.
Processing Each Edge:
Each edge is examined once per endpoint. In an adjacency list, this results in O(E) time, where E is the number of edges. For undirected graphs, each edge is counted twice, but the total remains O(E).
Combining these:
Time Complexity = O(V) + O(E)
Space Complexity (SC):
Visited Array (vis):
The vis array has a size of V, so it requires O(V) space.
Queue:
The queue can store at most all vertices in the worst case, requiring O(V) space.
Adjacency List (adj):
The adjacency list requires space proportional to the number of vertices and edges, O(V + E).
BFS Result Vector (bfs):
The bfs vector stores the BFS traversal, which can have at most V elements, so it requires O(V) space.
Combining these:
Space Complexity = O(V + E)
</details> ```
Explanation:
HTML <details> and <summary> Tags: These create a collapsible section. When users click on the summary, the content within the <details> tag expands or collapses.
Usage: This method works in Markdown files that render HTML, such as GitHub or certain Markdown viewers.

