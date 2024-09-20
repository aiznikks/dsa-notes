# DSA Notes

## Dijkstra's Algorithm Using Priority Queue

### Important Terminology:

<details>
<summary>Click to expand!</summary>

> **Dijkstra's Algorithm**: An algorithm to find the shortest path between nodes in a graph, typically starting from a source node to all other nodes.
>
> **Priority Queue (Min-Heap)**: A data structure that efficiently retrieves the next node with the smallest tentative distance.
>
> **Adjacency List**: A way to represent a graph where each node has a list of its neighboring nodes and the respective edge weights.
>
> **Distance Array (`dist`)**: An array where each index represents the minimum distance from the source node to that node.
>
> **Relaxation**: The process of updating the shortest known distance to a node if a shorter path is found.

</details>

---

### Steps to Implement Dijkstra's Algorithm:

1. **Initialize the `dist` array**:
   - Set the distance to the source node as 0 and all other nodes as infinity (`INF`).

2. **Use a priority queue (min-heap)**:
   - The priority queue stores pairs of `(distance, node)`, where `distance` is the current shortest distance to `node`.

3. **Extract the node with the smallest distance**:
   - Pop the node with the smallest distance from the priority queue.

4. **Relax all adjacent nodes**:
   - For each adjacent node, calculate the new distance. If the new distance is smaller than the current recorded distance, update the distance and push the node back into the priority queue with the new distance.

5. **Repeat until the queue is empty**:
   - Continue extracting nodes and relaxing their neighbors until the priority queue is empty.

---

### Dijkstra's Algorithm Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S) {
    // Step 1: Initialize the dist array
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;

    // Step 2: Use a priority queue to store {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});  // Distance to source is 0

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Step 4: Relax all adjacent nodes
        for (auto it : adj[node]) {
            int nextNode = it.first;
            int nextDist = it.second;

            if (dist[nextNode] > d + nextDist) {
                dist[nextNode] = d + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    return dist;  // Return the distance array
}
```
Time and Space Complexity:
<details> <summary>Click to expand!</summary>
Time Complexity:
Priority Queue Operations: Each insertion and deletion from the priority queue takes 
O
(
log
⁡
V
)
O(logV) time.
Processing Each Edge: Each edge is processed once, and the relaxation takes 
O
(
log
⁡
V
)
O(logV) due to the priority queue.
Thus, the overall time complexity is: 
O
(
(
V
+
E
)
log
⁡
V
)
O((V+E)logV)
Space Complexity:
Distance Array (dist): This takes 
O
(
V
)
O(V) space.
Priority Queue: The priority queue can store up to 
O
(
V
)
O(V) elements.
Adjacency List (adj): The adjacency list takes 
O
(
V
+
E
)
O(V+E) space.
Therefore, the space complexity is: 
O
(
V
+
E
)
O(V+E)
</details> ```
Explanation of Key Concepts:
Priority Queue (Min-Heap): Used to always pick the node with the smallest tentative distance.
Relaxation: The process of updating the shortest known path to a node.
Adjacency List: Represents the graph, where each node has a list of connected nodes and the weight of the edge connecting them.