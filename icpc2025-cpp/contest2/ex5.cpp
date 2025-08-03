//
// Created by duongvct on 8/3/25.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int power(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int solve_component(const vector<int>& vals, const vector<int>& cnt, int K) {
    int n = vals.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        int ways = (power(2, cnt[i]) - 1 + MOD) % MOD;
        if(i == 0) {
            dp[i+1] = (dp[i] + ways) % MOD;
        } else {
            if(vals[i] - vals[i-1] == K) {

                dp[i+1] = (dp[i] + dp[i-1] * ways % MOD) % MOD;
            } else {
                dp[i+1] = (dp[i] * (ways + 1)) % MOD;
            }
        }
    }
    return (dp[n] - 1 + MOD) % MOD;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        vector<int> A(N);
        map<int, int> cnt_map;
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
            cnt_map[A[i]]++;
        }
        set<int> visited;
        int ans = 1;
        for(auto it = cnt_map.begin(); it != cnt_map.end(); ++it) {
            int x = it->first;
            if(visited.count(x)) continue;
            vector<int> vals;
            vector<int> cnts;
            int cur = x;

            while(cnt_map.count(cur - K)) cur -= K;

            while(cnt_map.count(cur)) {
                vals.push_back(cur);
                cnts.push_back(cnt_map[cur]);
                visited.insert(cur);
                cur += K;
            }
            int res = solve_component(vals, cnts, K);
            ans = ans * (res + 1) % MOD;
        }
        cout << (ans - 1 + MOD) % MOD << '\n';
    }
    return 0;
}