//
// Created by duongvct on 7/27/25.
//
#include <bits/stdc++.h>
using namespace std;
int main () {
    set<long long> se;
    int n;
    cin >> n;
    long long ans = 0;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        long long x = a[i];
        if (se.upper_bound(x) == se.end()) {
            ans++;
        }
        se.insert(x);
    }
    cout << ans;
}
