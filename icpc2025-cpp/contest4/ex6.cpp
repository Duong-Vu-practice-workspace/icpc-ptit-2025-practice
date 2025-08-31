//
// Created by duongvct on 8/17/25.
//
#include <bits/stdc++.h>
using namespace std;
int main () {
    int x;
    cin >> x;
    int y = (x % 100) * 10 + x / 100;
    int z = (x % 10) * 100 + x / 10;
    cout << x + y + z;
    return 0;
}