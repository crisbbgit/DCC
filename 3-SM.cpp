#include<iostream>
using namespace std;
int main()
{
  int a[2][2],b[2][2],c[2][2], i, j;
  int p1,p2,p3,p4,p5,p6,p7;
 
  cout<<"Enter the 4 elements of First matrix: ";
  for(i = 0;i < 2; i++)
      for(j = 0;j < 2; j++)
           cin>>a[i][j];
 
  cout<<"Enter the 4 elements of Second matrix: ";
  for(i = 0; i < 2; i++)
      for(j = 0;j < 2; j++)
           cin>>b[i][j];
 
  cout<<"\nThe First matrix is:";
  for(i = 0; i < 2; i++){
      cout<<"\n";
      for(j = 0; j < 2; j++)
           cout<<a[i][j]<<" ";
  }
 
  cout<<"\nThe Second matrix is:";
  for(i = 0;i < 2; i++){
      cout<<"\n";
      for(j = 0;j < 2; j++)
           cout<<b[i][j]<<" ";
  }
 
  p1= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  p2= (a[1][0] + a[1][1]) * b[0][0];
  p3= a[0][0] * (b[0][1] - b[1][1]);
  p4= a[1][1] * (b[1][0] - b[0][0]);
  p5= (a[0][0] + a[0][1]) * b[1][1];
  p6= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
  p7= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
 
  c[0][0] = p1 + p4- p5 + p7;
  c[0][1] = p3 + p5;
  c[1][0] = p2 + p4;
  c[1][1] = p1 + p3 - p2 + p6;
 
   cout<<"\nAfter multiplication using Strassen's algorithm: ";
   for(i = 0; i < 2 ; i++){
      cout<<"\n";
      for(j = 0;j < 2; j++)
           cout<<c[i][j]<<" ";
   }
   return 0;
}

/*Theory: Strassen Matrix Multiplication which gives an overview that how we can 
find the multiplication of two 2*2 dimension matrix by the brute-force algorithm. 
But by using divide and conquer technique the overall complexity for multiplication 
two matrices is reduced. This happens by decreasing the total number if multiplication 
performed at the expenses of a slight increase in the number of addition.

The usual multiplication of two 2 × 2 matrices takes 8 multiplications and 4 additions.
Strassen showed how two 2 × 2 matrices can be multiplied using only 7 multiplications 
and additions as well as subtractions.

Strassen's algorithm uses 7 multiplications which reduces the time complexity of the 
matrix multiplication algorithm a little bit. The addition and Subtraction operation 
takes less time compared to the multiplication process. 

Procedure of Strassen matrix multiplication.
There are some procedures:

1.	Divide matrices A and B in 4 sub-matrices of size N/2*N/2.
2.	Calculate the 7 matrix multiplications recursively.
3.	Compute the submatrices of C.
4.	Combine these submatrices into our new matrix C. 
 
Strassen's Matrix multiplication can be performed only on square matrices where n is a
power of 2. Order of both of the matrices are N x N.

Using Strassen's Algorithm we compute the following -

P1 = (A11 + A22) * (B11 + B22)
P2 = (A21 + A22) * B11
P3 = A11 * (B12 - B22)
P4 = A22 * (B21 - B11)
P5 = (A11 + A12) * B22
P6 = (A21 - A11) * (B11 + B12)
P7 = (A12 - A22) * (B21 + B22)

C11 = P1 + P4 - P5 + P7
C12 = P3 + P5
C21 = P2 + P4
C22 = P1 - P2 + P3 + P6

1.	We divide the input matrices into submatrices of size N/2 x N/2. This step can be performed in O(1) times.
2.	We calculate 10 addition/subtraction operations which takes O(N^2) time.
3.	We make 7 recursive calls to calculate P1 to P7. The output of this step would be 
    7 matrix of order N X 2. This step takes 7T(N/2) time.
4.	Finally, by adding and subtracting submatrices of P[i], we get our resultant matrix C. 
    The time complexity of this step would be O(N^2).
    
Therefore the total time complexity of this algorithm would be:
T(N) = 7T(N/2) + O(N2) = O(Nlog27) ? O(N2.8074)
"	Worst case time complexity: O(N^2.8074).
"	Best case time complexity: O(1).
*/
