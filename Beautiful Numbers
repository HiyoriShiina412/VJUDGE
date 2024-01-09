#include <bits/stdc++.h>
using namespace std;
// 解決策はバッハによって作られました (またはコピーされました :D)
// why tle
#define fi first
#define inf 1e18
#define se second
#define pb push_back
// #define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pr(x) { cout << x << "\n"; return; }
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL)

const int maxn = 1e2 + 1;
const int mod = 1e9 + 7;

int n, m;
int dp[105][15][1 << 10];

void solve() {
    cin >> n >> m;
    if (n > m) pr(0);
    if (n == m) pr(1);
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                dp[i][j][mask] = 0;
            }
        }
    }
    for (int j = 1; j < n; ++j) {
        dp[1][j][1 << j] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int j = 0; j < n; ++j) {
                if (j) dp[i + 1][j - 1][mask | (1 << (j - 1))] = (dp[i + 1][j - 1][mask | (1 << (j - 1))] + dp[i][j][mask]) % mod;
                if (j + 1 < n) dp[i + 1][j + 1][mask | (1 << (j + 1))] = (dp[i + 1][j + 1][mask | (1 << (j + 1))] + dp[i][j][mask]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = n; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            // cout << dp[i][j][(1 << n) - 1] << " \n"[j == n - 1];
            ans = (ans + dp[i][j][(1 << n) - 1]) % mod;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    IOS;
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
}
