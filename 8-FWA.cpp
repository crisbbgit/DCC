#include<iostream>
using namespace std;
int min(int,int);
void floyds(int p[10][10],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    if(i==j)
     p[i][j]=0;
    else
     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}
int main()
{
 int p[10][10],w,n,e,u,v,i,j;;
 cout<<"Enter the number of vertices: ";
 cin>>n;
 cout<<"\nEnter the number of edges: ";
 cin>>e;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   p[i][j]=999;
 }
 for(i=1;i<=e;i++)
 {
  cout<<"\nEnter the start and end vertices of edge "<<i<<" with its weight: \n";
  cin>>u>>v>>w;
  p[u][v]=w;
 }
 cout<<"\nMatrix of input data:\n";
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   cout<<p[i][j]<<" \t";
  cout<<"\n";
 }
 floyds(p,n);
 cout<<"\nTransitive closure:\n";
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   cout<<p[i][j]<<" \t";
  cout<<"\n";
 }
 cout<<"\nThe shortest paths are: \n";
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   if(i!=j)
    cout<<"\n<"<<i<<","<<j<<">="<<p[i][j];
  }
  return 0;
}

/* theory
Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph. This algorithm works for both the directed and undirected weighted graphs.
But, it does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).
Floyd-Warhshall algorithm is also called as Floyd's algorithm, Roy-Floyd algorithm, Roy-Warshall algorithm, or WFI algorithm.
This algorithm follows the dynamic programming approach to find the shortest paths.
The graph may have negative weight edges, but no negative weight cycles.
If there is such a negative cycle, you can just traverse this cycle over and over, in each iteration making the cost of the path smaller. So you can make certain paths arbitrarily small,
or in other words that shortest path is undefined. That automatically means that an undirected graph cannot have any negative weight edges,
as such an edge forms already a negative cycle as you can move back and forth along that edge as long as you like.
This algorithm can also be used to detect the presence of negative cycles. The graph has a negative cycle if at the end of the algorithm, the distance from a vertex  to itself is negative.


Floyd-Warshall Algorithm

n = no of vertices
A = matrix of dimension n*n
for k = 1 to n
    for i = 1 to n
        for j = 1 to n
            Ak[i, j] = min (Ak-1[i, j], Ak-1[i, k] + Ak-1[k, j])
return A


Time Complexity
There are three loops. Each loop has constant complexities. So, the time complexity of the Floyd-Warshall algorithm is O(n^3).
*/


