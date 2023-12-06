

//Graphs: A graph is a set of vertices and a collection of edges that each connect a pair of vertices.
//Graphs are used to represent many real-life applications: Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network.

//types of graphs:
//1. Directed Graphs: A directed graph is a graph in which edges have orientations. In other words, the edges are associated with a direction.
//2. Undirected Graphs: An undirected graph is a graph in which edges have no orientations. The edges are bi-directional.
//3. Weighted Graphs: A weighted graph is a graph in which each edge is associated with a weight. Usually, the weight of an edge signifies the distance between two vertices.

//Graph Representation:
//1. Adjacency Matrix: Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.
//for example:
//  a b c d
//a 0 1 0 0
//b 0 0 1 0
//c 0 0 0 1
//d 1 0 0 0

//->above given is adjacency matrix of:
//  a->b->c->d->a

//2. Adjacency List: An array of lists is used. Size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. 


//Breadth First Search (BFS) for a Graph:
//Breadth First Traversal (or Search) for a graph is similar to Breadth First Traversal of a tree. The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all vertices are reachable from the starting vertex.

//Depth First Search (DFS) for a Graph:
//Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array.


