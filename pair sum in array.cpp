/*
QUESTION

You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements. 
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.
Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2


 Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
*/

//SOLUTION

#include<algorithm>


int countnumber(int arr[], int size, int n)
{  
    int i=0,count=0;
   for(i; i<size; i++)
   {
       if(arr[i]==n)
               {count++;}
       }
    return count;
   }



int pairSum(int *arr, int n, int num)
{   
    sort(arr, arr+n);
	int i=0, j=n-1, count=0, m;
    while (i<j)
    {  
        if(arr[j]+arr[i]==num)
        {   
             if(arr[i]==arr[j])
           { m=(n*(n-1))/2;
            count+=m;
            break;
           }
          int c1=countnumber(arr, n, arr[i]);
         int c2=countnumber(arr,n, arr[j]);
            count+=(c1*c2);
       j=j-c2;
       i=i+c1;
            
            
            
            
            
            // 1)
            // testcase: 1 1 1 1, num=2
            // check if arr[i]==arr[j]
            // total pairs=mC2=m*(m-1)/2 ; add in count 
            
            // 2)
            // testcase: 1 1 1 2 2 2 , num=3
            // count=9; for each 1, there r 3 2's
            
            // 1)count the no. of 1's
            // 2)count the no. of 2's
            // 3)count+=count of 1's * count of 2'
        }
        
        else if(arr[j]+arr[i]<num)
        {i++;}
        
        else
        {j--;}
    }
    
    return count;
}
