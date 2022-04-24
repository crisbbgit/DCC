#include<iostream>
using namespace std;
int main()
{
    int a,b,u,v,n,i,j,ne=1;
    int visited[10]={0},min,mincost=0,cost[10][10];
	cout<<"Enter the number of nodes:";
	cin>>n;
	cout<<"\nEnter the adjacency matrix:\n";
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		cin>>cost[i][j];
		if(cost[i][j]==0)
			cost[i][j]=999;
	}
	visited[1]=1;
	cout<<"\n\nMinimum Spanning Tree: ";
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0)
		{
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		if(visited[u]==0 || visited[v]==0)
		{
			cout<<"\n Edge"<< ne++ << ":("<<a<<" "<< b<<")" <<" cost:"<<min;
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	cout<<"\n Minimum cost="<<mincost;
	return 0;
}

/*Theory
Spanning Tree
Given an undirected and connected graph G=(V, E), a spanning tree of the graph G is a tree that spans G (that is, it includes every vertex of G) and is a subgraph of G (every edge in the tree belongs to G)
Minimum Cost Spanning Tree
The cost of the spanning tree is the sum of the weights of all the edges in the tree. There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees. There also can be many minimum spanning trees.
Minimum spanning tree has direct application in the design of networks. It is used in algorithms approximating the travelling salesman problem, multi-terminal minimum cut problem and minimum-cost weighted perfect matching.
Prim’s Algorithm
Prim’s Algorithm also use Greedy approach to find the minimum spanning tree. In Prim’s Algorithm we grow the spanning tree from a starting position. Unlike an edge in Kruskal's, we add vertex to the growing spanning tree in Prim's.
In Prim’s Algorithm, we will start with an arbitrary node (it doesn’t matter which one) and mark it. In each iteration we will mark a new vertex that is adjacent to the one that we have already marked. As a greedy algorithm, Prim’s algorithm will select the cheapest edge and mark the vertex. So we will simply choose the edge with weight 1. In the next iteration we have three options, edges with weight 2, 3 and 4. So, we will select the edge with weight 2 and mark the vertex. Now again we
have three options, edges with weight 3, 4 and 5. But we can’t choose edge with weight 3 as it is creating a cycle. So we will select the edge with weight 4 and we end up with the minimum spanning tree of total cost 7 ( = 1 + 2 +4).

Algorithm
Step 1: Keep a track of all the vertices that have been visited and added to the spanning tree.

Step 2: Initially the spanning tree is empty.

Step 3: Choose a random vertex, and add it to the spanning tree. This becomes the root node.

Step 4: Add a new vertex, say x, such that x is not in the already built spanning tree. x is connected to the built spanning tree using minimum weight edge. (Thus, x can be adjacent to any of the nodes that have already been added in the spanning tree). Adding x to the spanning tree should not form cycles.

Step 5: Repeat the Step 4, till all the vertices of the graph are added to the spanning tree.

Step 6: Print the total cost of the spanning tree.
Time complexity
Prim’s Algorithm Time Complexity-

Worst case time complexity of Prim’s Algorithm is-
O(ElogV) using binary heap
O(E + VlogV) using Fibonacci heap

Time Complexity Analysis

If adjacency list is used to represent the graph, then using breadth first search, all the vertices can be traversed in O(V + E) time.
We traverse all the vertices of graph using breadth first search and use a min heap for storing the vertices not yet included in the MST.
To get the minimum weight edge, we use min heap as a priority queue.
Min heap operations like extracting minimum element and decreasing key value takes O(logV) time.

So, overall time complexity
= O(E + V) x O(logV)
= O((E + V)logV)
= O(ElogV)

This time complexity can be improved and reduced to O(E + VlogV) using Fibonacci heap.

*/

