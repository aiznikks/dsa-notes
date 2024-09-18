# DSA Notes

## BFS in Graph (Level-wise Traversal)

### Steps to Implement BFS:

1. **Create a `vis` array**:
   - Initialize a visited array (`vis`) of size `n` with all values set to `0` (unvisited).
   
2. **Create an adjacency list**:
   - Use an adjacency list, which is an array of vectors: `vector<int> adj[n+1]`. This will store the graph structure.

3. **Push the starting node into a queue and mark it visited**:
   - Insert the starting node into the queue and mark it as visited in the `vis` array.

4. **Process the queue**:
   - While the queue is not empty:
     - Remove the front node from the queue and print it.
     - For the current node, ask "Who are your neighbors?"
     - Push each unvisited neighbor into the queue and mark them as visited in the `vis` array.

5. **Check before pushing**:
   - Before pushing a node into the queue, check if it is already visited. If visited, do not push it into the queue again.

---

### BFS Implementation Code:

```cpp
vector<int> bfsofGraph(int V, vector<int> adj[]) {
    // Step 1: Create visited array
    int vis[V] = {0};
    vis[0] = 1;  // Mark starting node as visited

    // Step 2: Initialize queue and result vector
    queue<int> q;
    q.push(0);  // Step 3: Push the starting node into the queue
    vector<int> bfs;

    // Step 4: Process the queue until it's empty
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);  // Add node to BFS result

        // Step 5: Traverse through the neighbors of the current node
        for (auto it : adj[node]) {
            // Step 6: If the neighbor is not visited, mark it and push it into the queue
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;  // Return the BFS traversal
}

```


### Time Complexity (TC):

1. **Initialization**:
   - Initializing the `vis` array takes **O(V)** time.
   - Initializing the queue takes **O(1)** time.

2. **Processing Each Node**:
   - Each node is processed exactly once, which takes **O(V)** time.

3. **Processing Each Edge**:
   - In an undirected graph, each edge is examined twice (once for each end), resulting in **2E** edge operations. This simplifies to **O(E)**.

Combining these:

**Time Complexity = O(V) + O(E)**

Where:
- `V` is the number of vertices (nodes).
- `E` is the number of edges.

### Space Complexity (SC):

1. **Visited Array (`vis`)**:
   - The `vis` array has a size of `V`, so it requires **O(V)** space.

2. **Queue**:
   - The queue can store at most all vertices in the worst case, requiring **O(V)** space.

3. **Adjacency List (`adj`)**:
   - The adjacency list requires space proportional to the number of vertices and edges, **O(V + E)**.

4. **BFS Result Vector (`bfs`)**:
   - The `bfs` vector stores the BFS traversal, which can have at most `V` elements, so it requires **O(V)** space.

Combining these:

**Space Complexity = O(V + E)**

Where:
- `V` is the number of vertices (nodes).
- `E` is the number of edges.

---

### Summary:

- **Time Complexity**: **O(V + E)**, where `V` is the number of vertices and `E` is the number of edges.
- **Space Complexity**: **O(V + E)**, considering the `vis` array, adjacency list, queue, and BFS result vector.


### Important Terminology:
> **BFS (Breadth-First Search)**: A graph traversal algorithm that explores nodes level by level.
> 
> **Queue**: A First-In-First-Out (FIFO) data structure used in BFS to store nodes.
> 
> **Adjacency List**: A way to represent a graph where each node has a list of neighbors.
> 
> **Visited Array (`vis`)**: An array used to keep track of whether a node has been visited or not during traversal.
> 
> **Neighbors**: Nodes directly connected to a given node by an edge in a graph.

> **Degrees**: Number of neighbour nodes
