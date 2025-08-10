//
// Created by duongvct on 8/10/25.
//
#include <bits/stdc++.h>
using namespace std;

int main () {
    long long x, y;
    cin >> x >> y;
    long long d = abs(x - y);
    if (d <= 1) {
        cout << "Bob";
    } else {
        cout << "Alice";
    }
}