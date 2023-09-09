#include <iostream>
#include<cmath>
using namespace std;
int c=0;
string arr[] = {" ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void phonekeypad(char inpu[100], int i, char out[100], int j)
{
    // base caseAAA
    if (inpu[i] == '\0')
    {
        out[j] = '\0';
        cout << out <<" ";
         c++;
        return;
        
    }
   

    // recursive case
    // sabse pehle input aayega   // 2  ab ise integer m change karna hoga
    char ch = inpu[i];     // ' 1'
    int index = ch - '0'; // 1

    for (int l = 0; arr[index][l]!= '\0'; l++)
    {
        out[j] = arr[index][l]; // that is 1 0  //  ab aage ka kaam recursion kar lega
        phonekeypad(inpu, i + 1, out, j + 1);
    }
}
int main()
{
    char inpu[100];

   char out[100];
    cin>>inpu;
    phonekeypad(inpu, 0, out, 0);
     cout<<endl;
   
    cout<<c<<endl;
}