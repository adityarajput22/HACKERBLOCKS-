#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int x;
    int num;
    for(int i = 1;i<=n;i++)
    {
        cin>>x;
        cin>>num;
        int out = min(x%num,num-x%num);
        cout<<out<<endl;
    }
    return 0;
}