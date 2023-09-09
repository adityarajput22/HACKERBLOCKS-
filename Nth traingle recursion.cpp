#include<bits/stdc++.h>

using namespace std;

int tNum(int n)
{
     if(n==0)
          return 0; // n-1 tk chale n se shuru hokr 
     return n + tNum(n-1); // means ki pichle wale ka kiya like -->>input = 3 ; so, 3+2+1=> 6 or like input = 4 ; so, 4+3+2-->> 9
}

int main()
{
     int n;
     cin>>n;

     cout<<tNum(n);
}



  
  
          // mam ne kkarwaya hai copy mai 


          