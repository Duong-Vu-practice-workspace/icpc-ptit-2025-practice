//
// Created by duongvct on 8/10/25.
//
#include<bits/stdc++.h>
using namespace std;
// bool cmp(pair<int, int> a, pair<int, int> b) {
//     return abs(a.first - b.first) + abs(a.second - b.second);
// }
bool cmp(pair<int, int> a, pair<int, int> b) {
    return abs(a.first + a.second) < abs(b.first + b.second);
}
int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main () {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, cmp);
    // for (int i = 0; i < n; i++) {
    //     cout << a[i].first << " " << a[i].second << endl;
    // }
    int maxDist = INT_MIN;
    for (int i = 1; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int d = dist(a[i], a[j]);
            cout << a[i].first << " " << a[i].second << endl;
            cout << a[j].first << " " << a[j].second << endl;
            cout << "d: " << d << endl;
            if (d >= maxDist) {
                maxDist = d;
            }
        }
    }
    cout << maxDist;
    return 0;
}