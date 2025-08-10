//
// Created by duongvct on 8/10/25.
//
#include<bits/stdc++.h>
using namespace std;
// bool cmp(pair<int, int> a, pair<int, int> b) {
//     return abs(a.first - b.first) + abs(a.second - b.second);
// }

int main () {
    int n;
    cin >> n;
    vector<pair<long long, long long>> a;
    vector<long long > sum;
    vector<long long> diff;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        a.push_back({x, y});
        sum.push_back(x + y);
        diff.push_back(x  -y);
    }
    // long long maxR = *max(sum);
    // cout << maxR << endl;
    return 0;
}