#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> p(n + 1);
    long long a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (i == 0) {
            p[0] = a;
        }
        p[i + 1] = b;
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            for (int k = i; k < j; ++k) {
                long long cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    if (n > 0) {
        cout << dp[0][n - 1];
    } else {
        cout << 0;
    }
    return 0;
}