//
// Created by duongvct on 8/3/25.
//
#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int a[n];
    int max = -1e9;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
        }
        sum += a[i];
    }
    int secondSum = sum - max;
    if (max < secondSum) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}