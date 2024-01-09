#include <bits/stdc++.h>
using namespace std;
// 解決策はバッハによって作られました (またはコピーされました :D)
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

struct info {
     int x, y, z, s;
};

int n, tc;
info a[maxn];
int dp[1 << 9];

void solve() {
     while (cin >> n) {
          if (!n) break;
          for (int i = 1; i <= n; ++i) {
               cin >> a[i].x >> a[i].y >> a[i].z >> a[i].s;
               --a[i].x; --a[i].y; --a[i].z;
          }
          for (int i = 0; i < (1 << 9); ++i) {
               dp[i] = -1;
          }
          dp[0] = 0;
          for (int i = 1; i <= n; ++i) {
               for (int j = 0; j < (1 << 9); ++j) {
                    if (dp[j] < 0) continue; 
                    if (j & (1 << a[i].x)) continue;
                    if (j & (1 << a[i].y)) continue;
                    if (j & (1 << a[i].z)) continue;
                    int nj = j | (1 << a[i].x) | (1 << a[i].y) | (1 << a[i].z);
                    dp[nj] = max(dp[nj], dp[j] + a[i].s);
               }
          }
          cout << "Case " << ++tc << ": " << dp[(1 << 9) - 1] << "\n";
     }
}

int32_t main() {
    IOS;
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
            solve();
    }
}
