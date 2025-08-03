//
// Created by duongvct on 8/3/25.
//
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    int max_free, prefix_free, suffix_free;
    int cover; // -1: mixed, 0: all free, 1: all occupied
    Node *left, *right;
    Node(int l, int r): l(l), r(r), max_free(r-l+1), prefix_free(r-l+1), suffix_free(r-l+1), cover(0), left(nullptr), right(nullptr) {}
};

void push(Node* node) {
    if (node->cover == -1 || node->l == node->r) return;
    int mid = (node->l + node->r) / 2;
    if (!node->left) node->left = new Node(node->l, mid);
    if (!node->right) node->right = new Node(mid+1, node->r);
    for (auto child : {node->left, node->right}) {
        child->cover = node->cover;
        if (node->cover == 0) {
            child->max_free = child->prefix_free = child->suffix_free = child->r - child->l + 1;
        } else {
            child->max_free = child->prefix_free = child->suffix_free = 0;
        }
    }
    node->cover = -1;
}

void pull(Node* node) {
    node->prefix_free = node->left->prefix_free;
    if (node->left->prefix_free == node->left->r - node->left->l + 1)
        node->prefix_free += node->right->prefix_free;
    node->suffix_free = node->right->suffix_free;
    if (node->right->suffix_free == node->right->r - node->right->l + 1)
        node->suffix_free += node->left->suffix_free;
    node->max_free = max({node->left->max_free, node->right->max_free, node->left->suffix_free + node->right->prefix_free});
    if (node->left->cover == node->right->cover && node->left->cover != -1)
        node->cover = node->left->cover;
    else
        node->cover = -1;
}

void update(Node* node, int l, int r, int val) {
    if (node->r < l || node->l > r) return;
    if (l <= node->l && node->r <= r) {
        node->cover = val;
        if (val == 0) {
            node->max_free = node->prefix_free = node->suffix_free = node->r - node->l + 1;
        } else {
            node->max_free = node->prefix_free = node->suffix_free = 0;
        }
        return;
    }
    push(node);
    update(node->left, l, r, val);
    update(node->right, l, r, val);
    pull(node);
}

// Tìm vị trí trái nhất có đoạn trống dài >= k, trả về vị trí bắt đầu, hoặc -1 nếu không có
int query(Node* node, int k) {
    if (node->max_free < k) return -1;
    if (node->l == node->r) return node->l;
    push(node);
    if (node->left->max_free >= k) return query(node->left, k);
    if (node->left->suffix_free + node->right->prefix_free >= k)
        return node->left->r - node->left->suffix_free + 1;
    return query(node->right, k);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    Node* root = new Node(1, N);
    int denied = 0;
    for (int i = 0; i < M; ++i) {
        string s; cin >> s;
        if (s == "A") {
            int k; cin >> k;
            int pos = query(root, k);
            if (pos == -1) denied++;
            else update(root, pos, pos + k - 1, 1);
        } else {
            int a, b; cin >> a >> b;
            update(root, a, b, 0);
        }
    }
    cout << denied << '\n';
    return 0;
}