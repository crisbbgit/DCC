#include<iostream>
using namespace std;
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
  int a[30],n,i;
  cout<<"Enter no of elements: ";
  cin>>n;
  cout<<"Enter array elements: ";
  for(i=0;i<n;i++){
  	  cin>>a[i];
  }
  mergesort(a,0,n-1);
  cout<<"\nSorted array is: ";
  for(i=0;i<n;i++){
  	  cout<<a[i]<<" ";
  }
  return 0;
}
 
void mergesort(int a[],int i,int j)
{
  int mid;
  if(i<j)
   {
    mid=(i+j)/2;
    mergesort(a,i,mid); 
    mergesort(a,mid+1,j); 
    merge(a,i,mid,mid+1,j); 
   }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
  int temp[50];
  int i,j,k;
  i=i1;
  j=i2;
  k=0;
  while(i<=j1 && j<=j2) 
   {
    if(a[i]<a[j])
    temp[k++]=a[i++];
    else
    temp[k++]=a[j++];
   }
  while(i<=j1) 
  temp[k++]=a[i++];
  while(j<=j2) 
  temp[k++]=a[j++];

  for(i=i1,j=0;i<=j2;i++,j++)
  a[i]=temp[j];
}
/*Theory: Merge sort is a divide-and-conquer algorithm based on the idea of
 breaking down a list into several sub-lists until each sublist consists of 
 a single element and merging those sublists in a manner that results into a sorted list.

Key Points:
"	Divide the unsorted list into N sublists, each containing 1 element.
"	Take adjacent pairs of two singleton lists and merge them to form a 
    list of 2 elements. N will now convert into N/2 lists of size 2.
"	Repeat the process till a single sorted list of obtained.

While comparing two sublists for merging, the first element of both lists is taken 
into consideration. While sorting in ascending order, the element that is of a lesser 
value becomes a new element of the sorted list. This procedure is repeated until both the 
smaller sublists are empty and the new combined sublist comprises all the elements of both the sublists.
Merge sort is the algorithm of choice for a variety of situations: when stability is required, 
when sorting linked lists, and when random access is much more expensive than sequential access
(for example, external sorting on tape).

Properties:
"	Stable
"	O(n) extra space for arrays 
"	O(log(n)) extra space for linked lists
"	O(n*log(n)) time
"	Not adaptive
"	Does not require random access to data

ALGORITHM:
mergesort(int a[],int i,int j)
if i<j 
Step 1 : Defines the current array in 2 parts:  
   mid=(i+j)/2
Step 2 : Sort the 1st part of array:   
   Call mergesort(a,i,mid)
Step 3 : Sort the 2nd part of array:
   Call mergesort(a,mid+1,j)
Step 4 : Merge the both parts by comparing elements of both parts:
   merge(a,i,mid,mid+1,j)
 
Time Complexity:

1.	Best Case Time Complexity: O(n*log n)
2.	Worst Case Time Complexity: O(n*log n)
3.	Average Time Complexity: O(n*log n)
*/
