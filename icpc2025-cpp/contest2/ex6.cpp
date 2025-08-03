#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
class Bottle {
    int index;
    int currentCap;
    int volume;
    public Bottle(int index, int currentCap, int volume) {
        this->index = index;
        this->currentCap = currentCap;
        this->volume = volume;
    }
    public Bottle() {

    }
    
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int sumV = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sumV += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    return 0;
}


