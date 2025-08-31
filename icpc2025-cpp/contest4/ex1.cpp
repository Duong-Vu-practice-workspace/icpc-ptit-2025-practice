#include <bits/stdc++.h>
using namespace std;


int main() {

    int n = 4;
    int m = 5;
    int dem = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k <= 5; k++) {
                for (int l = 1; l <= 5; l++) {
                    if ((i < j && j < k && l <= k) || (i < j && j < l && k <= j) || (i < k && k < l && j <= i) || (j < k && k < l && i > j)) {
                        dem++;
                    }

                }
            }
        }
    }
    cout << dem;
    return 0;
}