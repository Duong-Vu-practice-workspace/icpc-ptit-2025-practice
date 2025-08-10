//
// Created by duongvct on 8/10/25.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int ans = INT_MAX;

    // Kiểm tra trường hợp phá ngay trong 1 bước
    for (int i = 0; i + 1 < N; i++) {
        long long x = a[i] ^ a[i + 1];
        if (i > 0 && a[i - 1] > x) ans = min(ans, 1);
        if (i + 2 < N && x > a[i + 2]) ans = min(ans, 1);
    }

    // Kiểm tra phá trong 2 bước
    for (int i = 0; i + 2 < N; i++) {
        long long x = a[i] ^ a[i + 1];
        if (x > a[i + 2]) ans = min(ans, 2);
        long long y = a[i + 1] ^ a[i + 2];
        if (a[i] > y) ans = min(ans, 2);
    }

    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}

