//
// Created by duongvct on 7/5/25.
//
#include <iostream>
using namespace std;
int a[500000], tree[2000000];
void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) {
        return -1e9;
    }
    if (l <= u && v <= r) {
        return tree[id];
    }
    int mid = (l + r) >> 1;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    return max(get1, get2);
}
int main (){
    int n, m, q;
    cin >> n >> m;
    while (m--) {
        int u,v, k;
        cin >> u >> v >> k;
        a[u] += k;
        a[v + 1] -= k;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + a[i];
    }
    a[n + 1] = 0;
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << get(1, 1, n, x, y) << endl;
    }
}