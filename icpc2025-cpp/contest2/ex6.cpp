#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
//.order_of_key() : so lg item <k ,.find_by_order() : tim theo so thu tu

int cmp(pair<int,int>x,pair<int,int>y){
    if(x.second==y.second){
        return (x.second-x.first)<(y.second-y.first);
    }
    return (x.second<y.second);
}
//                  8
//                  26
//                  1     5
//   29             18    34
// 0 42             40    8
//18 71 21 67 38 13 99 37 47 76
//
//0 1 2 3 4 5 6 7
//0
//1   0     g
//2       0     g
//3       0   g
//4     0 g
//5-2=3
//7-4=3
//6-4=2
//4-3=1
//99 76 71
//40 29 42
//59 47 29=126>
//
//1 5 8 8 18 40 29 26 34 42
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cin>>a[i].first;

    pair<int,int>a[n];
    ll sum[n]={};
    for(int i=0;i<n;i++){
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    sort(a,a+n,cmp);

    //	for(int i=0;i<n;i++){
    //		cout<<a[i].first<<" "<<a[i].second<<endl;
    //	}
    sum[0]=a[0].first;
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i].first;
    }
    //	for(int i=0;i<n;i++){
    //		cout<<sum[i]<<" ";
    //	}cout<<endl;
    ll res=0,dem=0,ans=0;
    for(int i=n-1;i>=0;i--){
        res+= a[i].second-a[i].first;
        dem++;
        if(res>=sum[i-1]){
            ans=sum[i-1];
            break;
        }
    }
    cout<<dem<<" "<<ans;

    return 0;
}


