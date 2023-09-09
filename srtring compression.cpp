// not running both of my solution 

/*
STRINGS-STRING COMPRESSION
Take as input S, a string.
Write a function that does basic string compression.
Print the value returned. E.g. for input �aaabbccds� print out a3b2c2ds.


Input Format:
A single String S.

Constraints:
A string of length between 1 to 1000
Output Format:
The compressed String.

Sample Input:
aaabbccds
Sample Output:
a3b2c2ds
Explanation:
In the given sample test case 'a' is repeated 3 times consecutively,
'b' is repeated twice, 'c' is repeated twice.
But, 'd' and 's' occurred only once that's why we do not write their occurrence.
*/
#include<iostream>
using namespace std;
int main()
{
    char a[1000];
    cin.getline(a,1000);
    int count=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
        }
        else if(a[i]!=a[i+1])
        {
            cout<<a[i]; // not equal toh print kr diya 
            if(count>0)
            {
                cout<<count+1; // tbhi krenge jb 0 se bd hog value :> toh hm us point ke count ko age badha denge and phir dubara se 0 kr denge 
            }
            count=0;
        }
    }
	return 0;
}

// another solution bnaya 
#include<bits/stdc++.h>

using namespace std;

int  main()
{
     string str;
     cin>>str;

     int count =1;
     char last_digit=str[0];
     cout<<last_digit;
     for(int i=1;i<str.length();i++)
     {
          if(str[i]==last_digit)
               count++; // equal toh count ++ kya mene 
          else if(count>1)
          {
               cout<<count; // not equal toh count prnt kiya 
               count=1;   // then dubarase value 1 krdi 
               last_digit=str[i]; // usk last value k sttre krke print krdi 
               cout<<last_digit;
          }
          else if(count==1)
          {
               last_digit=str[i];
               cout<<last_digit;
          }
     }
     if(count>1)
          cout<<count;
}