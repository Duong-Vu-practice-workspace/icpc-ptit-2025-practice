//
// Created by duongvct on 8/17/25.
//
#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    int minRes = INT_MAX;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int diff = abs(a[i] - b[j]);
            if (diff < minRes) {
                minRes = diff;
                res = i - j;
            }
        }
    }
    cout << res;
    return 0;
}