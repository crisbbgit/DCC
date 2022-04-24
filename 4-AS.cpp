#include <iostream>
#include <algorithm>
using namespace std;
struct Activity
{
    int start, finish;
};

bool Sort_activity(Activity s1, Activity s2)
{
    return (s1.finish< s2.finish);
}

void print_Max_Activities(Activity arr[], int n)
{
    Activity arr1[n];
    for(int i=0; i<=n-1; i++)
	{
		arr1[i].start=arr[i].start;
		arr1[i].finish=arr[i].finish;
    }
	sort(arr, arr+n, Sort_activity);

	cout<< "Following activities are selected:\n";

    int p,i = 0;
    for(p=0;p<n;p++)
    {
        if(arr1[p].start == arr[i].start && arr1[p].finish == arr[i].finish)
            break;
    }
	cout<<"A"<<p+1<<"-("<<arr[i].start<< ", " <<arr[i].finish << ")\n";

    for (int j = 1; j < n; j++)
    {
      	if (arr[j].start>= arr[i].finish)
      	{
      	    for(p=0;p<n;p++)
      	    {
      	        if(arr1[p].start == arr[j].start && arr1[p].finish == arr[j].finish)
                    break;
      	    }
			cout<<"A"<<p+1<<"-(" <<arr[j].start<< ", "<<arr[j].finish << ") \n";
			i = j;
      	}
    }
}
int main()
{
    int N;
    cout<<"Enter no. of activities: ";
    cin>>N;
    Activity arr[N];
	for(int i=0; i<=N-1; i++)
	{
		cout<<"Enter the start and end time of "<<i+1<<" activity \n";
		cin>>arr[i].start>>arr[i].finish;
    }
	print_Max_Activities(arr, N);
    return 0;
}

/*Theory: Greedy Algorithm:
Greedy is an algorithmic paradigm that builds up a solution piece by piece, always 
choosing the next piece that offers the most obvious and immediate benefit. Greedy 
algorithms are used for optimization problems. An optimization problem can be solved 
using Greedy if the problem has the following property: At every step, we can make a 
choice that looks best at the moment, and we get the optimal solution of the complete problem. 
If a Greedy Algorithm can solve a problem, then it generally becomes the best method 
to solve that problem as the Greedy algorithms are in general more efficient than other 
techniques like Dynamic Programming.

At every step, there is a choice that is optimal for the problem up to that step, and 
after the last step, the algorithm produces the optimal solution of the complete problem.

Characteristics of the Greedy Algorithm:
The important characteristics of a Greedy algorithm are:
"	There is an ordered list of resources, with costs or value attributions. These quantify constraints on a system.
"	We will take the maximum quantity of resources in the time a constraint applies.
"	For example, in an activity scheduling problem, the resource costs are in hours, and the 
    activities need to be performed in serial order.
    
Activity Selection:
The Activity Selection Problem is an optimization problem which deals with the selection of 
non-conflicting activities that needs to be executed by a single person or machine in a given 
time frame. This problem is also known as the interval scheduling maximization problem (ISMP).
Each activity is marked by a start and finish time. Greedy technique is used for finding the 
solution since this is an optimization problem.

Given a set of activities with their starting and finishing times. Select the maximum number 
of activities that a single person has to performed with an assumption that only a single activity 
is executed by a single person at a time.


ALGORITHM:
We are provided with n activities; each activity has its own start and finish time. 
In order to find the maximum number of non-conflicting activities, the following steps need to be taken:
Step 1: Sort the activities in ascending order based on their finish times.
Step 2: Select the first activity from this sorted list.
Step 3: Select a new activity from the list if its start time is greater than or equal to the 
        finish time of the previously selected activity.
Step 4: Repeat the last step until all activities in the sorted list are checked.

Complexity:
Case 1: O(N), in case, the given array is sorted according to their finish times, where N is total steps.
Case 2: O(NlogN), in case, the given array is not sorted according to their finish times, where N is total steps.
*/

