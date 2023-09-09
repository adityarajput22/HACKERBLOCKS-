/*Replace all occurrences of pi with 3.14

Input Format
Integer N, no of lines with one string per line

Constraints
0 < N < 1000
0 <= len(str) < 1000

Output Format
Output result one per line

Sample Input
3
xpix
xabpixx3.15x
xpipippixx
Sample Output
x3.14x
xab3.14xx3.15x
x3.143.14p3.14xx
Explanation
All occurrences of pi have been replaced with "3.14".
*/

#include<bits/stdc++.h>

using namespace std;

void display(string str,int i)
{
     if(i>=str.length())
          return;
     if(str[i]=='p'&&str[i+1]=='i')  // p and i dekhte hi 3.14
     {
          cout<<"3.14";
          display(str,i+2); // and print hote hi i+2 yani age ke sare element print ho jay 
     }
     else
     {
          cout<<str[i]; // if pi is not wwrittten  then print that value 
          display(str,i+1);  // dispaly i+1 se chalega and print hota rhega  
     }

}

int main()
{
     int t; // testcase liya kha tk chlana hai  3
     cin>>t; // positive value is true 

     while(t--) // yeh jo 3 line ke test case hai yeh hi aur sirf whi 3 chale 
     {           // 0 hote hi nah chale 
          string s;
          cin>>s; // string ko input mai liya 

          display(s,0); // display function call kiya 
          cout<<"\n";
     }
}
