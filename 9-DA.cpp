#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main()
{
    Graph g;
    int n;
    cout<<"Enter number of edges: ";
    cin>>n;
    cout<<endl;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter starting and end vertex for edge "<<i+1<<" : ";
        cin>>a>>b;
        g.addEdge(a, b);
    }
    int m;
    cout<<endl<<"Enter the starting vertex: ";
    cin>>m;
    cout<<endl;
    cout << "Following is Depth First Traversal"
            " (starting from vertex "<<m<<") \n";
    g.DFS(m);
    return 0;
}

/*THEORY

The DFS algorithm is a recursive algorithm that uses the idea of backtracking.
It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.

Here, the word backtrack means that when you are moving forward and there are no more nodes along the current path,
you move backwards on the same path to find nodes to traverse. All the nodes will be visited on the current path till all the unvisited nodes have been traversed after which the next path will be selected.

This recursive nature of DFS can be implemented using stacks. The basic idea is as follows:
Pick a starting node and push all its adjacent nodes into a stack.
Pop a node from stack to select the next node to visit and push all its adjacent nodes into a stack.
Repeat this process until the stack is empty. However, ensure that the nodes that are visited are marked.
This will prevent you from visiting the same node more than once. If you do not mark the nodes that are visited and you visit the same node more than once, you may end up in an infinite loop.

ALGORITHM
1. Create a recursive function that takes the index of the node and a visited array.
2. Mark the current node as visited and print the node.
3. Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.
4. Run a loop from 0 to the number of vertices and check if the node is unvisited in the previous DFS, call the recursive function with the current node.

Time complexity:
O(V + E), where V is the number of vertices and E is the number of edges in the graph.
*/

