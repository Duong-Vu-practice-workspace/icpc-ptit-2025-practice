//
// Created by duongvct on 8/3/25.
//
#include<bits/stdc++.h>
using namespace std;
long long a[87];
void init() {
    a[0] = 2;
    a[1] = 1;
    for (int i = 2; i <= 86; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
}
int main () {
    init();
    int n;
    cin >> n;
    cout << a[n];
}