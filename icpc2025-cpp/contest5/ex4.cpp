//
// Created by duongvct on 8/24/25.
//
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}
//5
//54 540 567 5670 9
//5670567540
//5675670540
int main () {
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    long long b[6];
    b[0] = stoll(a[n - 1] + a[n - 2] + a[n - 3]);
    b[1] = stoll(a[n - 1] + a[n - 3] + a[n - 2]);
    b[2] = stoll(a[n - 2] + a[n - 1] + a[n - 3]);
    b[3] = stoll(a[n - 2] + a[n - 3] + a[n - 1]);
    b[4] = stoll(a[n - 3] + a[n - 1] + a[n - 2]);
    b[5] = stoll(a[n - 3] + a[n - 2] + a[n - 1]);
    cout << *max_element(b, b + 6);
    return 0;
}