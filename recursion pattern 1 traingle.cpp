Take as input N, a number. Print the following pattern. Can you do it recursively ?!

Hint : Bigger Problem? Smaller Problem ? wrt pattern

(for N =4)

*

* *

* * *

* * * *

* * * * *

Input Format
Enter the value of N

Constraints
None

Output Format
Tab separated (*)

Sample Input
5
Sample Output
*
*	*
*	*	*
*	*	*	*
*	*	*	*	*
#include<bits/stdc++.h>

using namespace std;

void display(int n)
{
     if(n==0)
          return;
     display(n-1);
     for(int i=0;i<n;i++)
          cout<<"*\t";
     cout<<"\n";
}

int main()
{
     int n;
     cin>>n;

     display(n);
}