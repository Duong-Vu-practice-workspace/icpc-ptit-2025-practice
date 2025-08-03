//
// Created by duongvct on 8/3/25.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
//.order_of_key() : so lg item <k ,.find_by_order() : tim theo so thu tu

int parent[200001]={};
int dem[200001]={};
void init(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        dem[i]=1;
    }

}

int find(int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=find(parent[u]);
}

void unions(int x,int y){
    int a= find(x);
    int b= find(y);
    if(a==b){
        return;
    }
    if(dem[a]<dem[b]){
        swap(a,b);
    }
    parent[b]=a;
    dem[a]+=dem[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    init(n);
    while(m--){
        int x,y;
        cin>>x>>y;
        unions(x,y);
    }
    int ans=0;
    for(int i=1;i<=n;i++){

        if(parent[i]==i){
            ans=max(ans,dem[i]);
        }
    }
    cout<<ans;
    return 0;
}