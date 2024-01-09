#include <bits/stdc++.h>
using namespace std;
// 解決策はバッハによって作られました (またはコピーされました :D)
// why tle ?
#define fi first
#define inf 1e18
#define se second
#define pb push_back
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL)

const int maxn = 1e2 + 5;
const int mod = 998244353;

int n, sum, mx;
int a[25];
pair<int, int> dp[1 << 20];

void solve() {
    cin >> n;
    sum = 0;
    mx = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    if (sum % 4 != 0) {
        cout << "no\n";
        return;
    }
    sum /= 4;
    if (mx > sum) {
        cout << "no\n";
        return;
    }
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); ++mask) {
        dp[mask] = {n + 1, 0};
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                auto option = dp[mask ^ (1 << i)];
                if (option.se + a[i + 1] <= sum) {
                    option.se += a[i + 1];
                } else {
                    ++option.fi;
                    option.se = a[i + 1];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
        if (dp[mask].fi > 4) {
            cout << "no\n";
            return;
        }
    }
    // cout  << dp[(1 << n) - 1].fi << " " << dp[(1 << n) - 1].se << "\n";
    if (dp[(1 << n) - 1].fi == 4 && dp[(1 << n) - 1].se == sum) cout << "yes\n";
    else cout << "no\n";
}

int32_t main() {
    IOS;
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
            solve();
    }
    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
}
