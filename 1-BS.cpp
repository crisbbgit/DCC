#include<iostream>
using namespace std;
int main()
{
  int c,first,last,middle,n,search,array[100];

  cout<<"Enter number of elements\n";
  cin>>n;

  cout<<"Enter "<<n<<" integers\n";

  for(c=0;c<n;c++){
  	    cin>>array[c];
  }

  cout<<"Enter value to find\n";
  cin>>search;

  first = 0;
  last = n-1;
  middle = (first+last)/2;

  while (first <= last) {
    if(array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      cout<<search<<" found at location "<<middle+1<<endl;
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    cout<<"Not found! "<<search<<" isn't present in the list.\n";

  return 0;
}

/*Theory: This search algorithm works on the principle of divide and conquer.
For this algorithm to work properly, the data collection should be in the sorted form.
 
Binary search looks for a particular item by comparing the middle most item of the collection.
If a match occurs, then the index of item is returned. If the middle item is greater than the item,
then the item is searched in the sub-array to the left of the middle item. Otherwise, the item is 
searched for in the sub-array to the right of the middle item. This process continues on the 
sub-array as well until the size of the subarray reduces to zero. Binary search is a fast search 
algorithm with run-time complexity of O(log n).
 
Advantages:
"	A fairly simple algorithm based on the divide and conquer approach.
"	Much faster in comparison to the linear search. Linear search requires 
    N/2 and N comparisons for average and worst-case scenarios. 
	Binary search merely requires a total of log2 (N) and log2 (N) comparisons, 
	respectively for average and worst-case scenarios. To put it simply, linear search 
	on an average requires 500,000 comparisons to be made for a set of million elements. 
	Binary search, on the other hand, requires merely 20 comparisons.
"	Often available as an already implemented library routine
 
Disadvantages:
"	Complicated than the linear search.
"	Great loss in efficiency if the list doesn't support random-access.
"	Works only for lists that are sorted and kept sorted.
 
Binary Search Applications:
In libraries of Java, .Net, C++ STL.
While debugging, the binary search is used to pinpoint the place where the error happens.

Algorithm:

Step 1 : Find the middle element of array. using ,
middle = first+last / 2 ;
Step 2 : If middle = element, return 'element found' and index.
Step 3 : if middle > element, call the function with last = middle - 1 .
Step 4 : if middle < element, call the function with first = middle + 1 .
Step 5 : Exit.
 
Time Complexity:

1.	Best case complexity: O(1) 
2.	Average case complexity: O(log n) 
3.	Worst case complexity: O(log n)
*/

