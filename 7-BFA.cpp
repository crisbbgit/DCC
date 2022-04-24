#include<iostream>
#define MAX 10
using namespace std;

typedef struct edge
{
  int src;
  int dest;
  int wt;
}edge;

void bellman_ford(int nv,edge e[],int src_graph,int ne)
{
  int u,v,weight,i,j=0;
  int dis[MAX];


  for(i=0;i<nv;i++)
  {
    dis[i]=999;
  }


  dis[src_graph]=0;


  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].src;
      v=e[j].dest;
      weight=e[j].wt;


      if(dis[u]!=999 && dis[u]+weight < dis[v])
      {
        dis[v]=dis[u]+weight;
      }
    }

  }


  for(j=0;j<ne;j++)
  {
    u=e[j].src;
    v=e[j].dest;
    weight=e[j].wt;

    if(dis[u]+weight < dis[v])
    {
      cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
      return;
    }
  }

  cout<<"\nVertex"<<"  Distance from source";
  for(i=1;i<=nv;i++)
  {
    cout<<"\n"<<i<<"\t"<<dis[i];
  }

}


int main()
{
  int nv,ne,src_graph;
  edge e[MAX];

  cout<<"Enter the number of vertices: ";
  cin>>nv;


  printf("Enter the source vertex of the graph: ");
  cin>>src_graph;

  cout<<"\nEnter no. of edges: ";
  cin>>ne;

  for(int i=0;i<ne;i++)
  {
    cout<<"\nFor edge "<<i+1<<"=>";
    cout<<"\nEnter source vertex :";
    cin>>e[i].src;
    cout<<"Enter destination vertex :";
    cin>>e[i].dest;
    cout<<"Enter weight :";
    cin>>e[i].wt;
  }

  bellman_ford(nv,e,src_graph,ne);

  return 0;
}

/*THEORY
Bellman ford algorithm is a single-source shortest path algorithm. This algorithm is used to find the shortest distance from the single vertex to all the other vertices of a weighted graph.
There are various other algorithms used to find the shortest path like Dijkstra algorithm, etc.
If the weighted graph contains the negative weight values, then the Dijkstra algorithm does not confirm whether it produces the correct answer or not.
In contrast to Dijkstra algorithm, bellman ford algorithm guarantees the correct answer even if the weighted graph contains the negative weight values.
Dynamic Programming is used in the Bellman-Ford algorithm. It begins with a starting vertex and calculates the distances between other vertices that a single edge can reach.
It then searches for a path with two edges, and so on. The Bellman-Ford algorithm uses the bottom-up approach.

Algorithm
The Bellman-Ford algorithm works by grossly underestimating the length of the path from the starting vertex to all other vertices. The algorithm then iteratively relaxes those estimates by discovering new ways that are shorter than the previously overestimated paths.

You can ensure that the result is optimized by repeating this process for all vertices.

Step 1: Make a list of all the graph's edges. This is simple if an adjacency list represents the graph.

Step 2: "V - 1" is used to calculate the number of iterations. Because the shortest distance to an edge can be adjusted V - 1 time at most, the number of iterations will increase the same number of vertices.

Step 3: Begin with an arbitrary vertex and a minimum distance of zero. Because you are exaggerating the actual distances, all other nodes should be assigned infinity.

For each edge u-v, relax the path lengths for the vertices:

If distance[v] is greater than distance[u] + edge weight uv, then

distance[v] = distance[u] + edge weight uv

Step 4:If the new distance is less than the previous one, update the distance for each Edge in each iteration. The distance to each node is the total distance from the starting node to this specific node.

Step 5: To ensure that all possible paths are considered, you must consider alliterations. You will end up with the shortest distance if you do this.


Time Complexity for Bellman Ford Algorithm:
Worst Case Time Complexity: O(V^3)
Average Case Time Complexity: O(E V)
Best Case Time Complexity: O(E)
where:

V is number of vertices
E is number of edges
*/
