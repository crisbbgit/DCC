#include<iostream>
using namespace std;
int main()
{
    int n,flag[100]= {0},v[100],w[100],m[100][100],W,i,j,k;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the values: ";
    for(i=1; i<=n; i++)
        cin>>v[i];
    cout<<"Enter the weights: ";
    for(i=1; i<=n; i++){
        cin>>w[i];
    }
    cout<<"Enter the capacity of knapsack: ";
    cin>>W;
    for(j=0; j<=W; j++){
        m[0][j]=0;
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=W; j++)
        {
            if(w[i]<=j)
            {
                if( m[i-1][j] > (m[i-1][j-w[i]]+v[i]) )
                    m[i][j]=m[i-1][j];
                else
                    m[i][j]=m[i-1][j-w[i]]+v[i];
            }
            else
                m[i][j]=m[i-1][j];
        }
    }
    i=n;
    k=W;
    while(i>0 && k>0)
    {
        if(m[i][k]!=m[i-1][k])
        {
            flag[i]=1;
            k=k-w[i];
            i=i-1;
        }
        else
            i--;
    }
    cout<<"\nThe resultant vector is ";
    cout<<"( ";
    for(i=1; i<=n; i++){
        cout<<flag[i]<<" ";
    }
    cout<<")";
    cout<<"\n\nThe total profit is "<<m[n][W];
    cout<<"\n";
    return 0;
}
/*Theory

The 0/1 knapsack problem means that the items are either completely or no items are filled in a knapsack. The basic idea of Knapsack dynamic programming is to use a table to store the solutions of solved subproblems. If you face a subproblem again, you just need to take the solution in the table without having to solve it again. Therefore, the algorithms designed by dynamic programming are very effective.
To solve a problem by dynamic programming, you need to do the following tasks:
Find solutions of the smallest subproblems.
Find out the formula (or rule) to build a solution of subproblem through solutions of even smallest subproblems.
Create a table that stores the solutions of subproblems. Then calculate the solution of subproblem according to the found formula and save to the table.
From the solved subproblems, you find the solution of the original problem.
When analyzing 0/1 Knapsack problem using Dynamic programming, you can find some noticeable points. The value of the knapsack algorithm depends on two factors:
How many packages are being considered
The remaining weight which the knapsack can store.
Therefore, you have two variable quantities.
With dynamic programming, you have useful information:
the objective function will depend on two variable quantities
the table of options will be a 2-dimensional table.
If calling B[i][j] is the maximum possible value by selecting in packages {1, 2, …, i} with weight limit j.
The maximum value when selected in n packages with the weight limit M is B[n][M]. In other words: When there are i packages to choose, B[i][j] is the optimal weight when the maximum weight of the knapsack is j.
The optimal weight is always less than or equal to the maximum weight: B[i][j] ≤ j.
For example: B[4][10] = 8. It means that in the optimal case, the total weight of the selected packages is 8, when there are 4 first packages to choose from (1st to 4th package) and the maximum weight of the knapsack is 10. It is not necessary that all 4 items are selected.


Algorithm

Dynamic Programming (Weights [1 … N], Values [1 … N],
Table [0 ... N, 0 … Capacity])
// Input:
Array Weights contains the weights of all items
Array Values contains the values of all items
Array Table is initialized with 0s; it is used to store the results from the dynamic
programming algorithm.
//Output:
The last value of array Table (Table [N, Capacity]) contains the optimal solution of the problem for the given Capacity.
for i = 0 to N do
    for j = 0 to Capacity
        if j < Weights[i] then
           Table[i, j] <- Table[i-1, j]
        else
          Table[i, j] <- maximum { Table[i-1, j]
                    AND
            Values[i] + Table[i-1, j – Weights[i]]
return Table[N, Capacity]

In the implementation of the algorithm instead of using two separate arrays for the weights and the values of the items, we used one array Items of type item, where item is a structure with two fields: weight and value.

To find which items are included in the optimal solution, we use the following algorithm:

n <- N   c <- Capacity
Start at position Table[n, c]
While the remaining capacity is greater than 0 do
      If Table[n, c] = Table[n-1, c] then
                 Item n has not been included in the optimal solution
      Else
                 Item n has been included in the optimal solution
                 Process Item n
                 Move one row up to n-1
                 Move to column c – weight(n)


Complexity

Thus, the complexity of the Dynamic Programming algorithm is O (N*Capacity). In terms of memory, Dynamic Programming requires a two-dimensional array with rows equal to the number of items and columns equal to the capacity of the knapsack. This algorithm is probably one of the easiest to implement because it does not require the use of any additional structures.

*/
