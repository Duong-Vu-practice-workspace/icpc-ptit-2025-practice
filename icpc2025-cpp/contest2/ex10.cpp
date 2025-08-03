//
// Created by duongvct on 8/3/25.
//
#include <bits/stdc++.h>
using namespace std;
bool isCP(long long n)
{
    long long x=sqrt(n);
    return(x*x==n);
}
void solve()
{
    long long a;
    cin>>a;
    long long sum=2*a*a;
    long long mx=sqrt(sum);
    for(long long i=1;i<=100000;i++)
    {
        long long tmp=sum-(i*i);
        long long c=sqrt(tmp);
        if(isCP(tmp)&&c!=i&&i!=a&&c!=a&&c>=1&&c<=10000)
        {
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)

    {

        solve();
        cout<<endl;


    }
    return 0;
}
