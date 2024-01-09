#include<bits/stdc++.h>
using namespace std;
// 登ってみる
#define fi first
#define inf 1e18
#define se second
#define int long long
#define pb push_back
#define isz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int N = 5e5 + 5;
const int mod = 1e9 + 7;

int ns, m, n, fm, cost, x, c;
int dp[105][1 << 16];
string s;

void solve() {
          for (int i = 0; i <= n; ++i) {
                    for (int bm = 0; bm < (1 << (ns * 2)); ++bm) {
                              dp[i][bm] = inf;
                    }
          }
          cin.ignore();
          fm = cost = 0;
          for (int i = 1; i <= m; ++i) {
                    getline(cin, s);
                    stringstream ss(s);
                    ss >> c; cost += c;
                    while (ss >> x) {
                              if (fm & (1 << (x - 1))) fm |= (1 << (x - 1 + ns));
                              else fm |= (1 << (x - 1));
                    }
          }
          dp[0][fm] = cost;
          for (int i = 1; i <= n; ++i) {
                    getline(cin, s);
                    stringstream ss(s);  ss >> c;
                    vector<int> v;
                    while (ss >> x) v.pb(x);
                    for (int bm = fm; bm < (1 << (ns * 2)); ++bm) {
                              dp[i][bm] = min(dp[i][bm], dp[i -1][bm]);
                              int cur = bm;
                              for (int y : v) {
                                        if (cur & (1 << (y - 1))) cur |= (1 << (y - 1 + ns));
                                        else cur |= (1 << (y - 1));
                              }
                              dp[i][cur] = min(dp[i][cur], dp[i - 1][bm] + c);
                             //  cout << dp[i][cur] << " ";
                    }
                    // cout << "\n";
          }
          int ans = inf;
          for (int i = 1; i <= n; ++i) ans = min(ans, dp[i][(1 << (2 * ns)) - 1]);
          cout << ans << "\n";
}

int32_t main() {
          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
          // freopen(".inp", "r", stdin);
          // freopen(".out", "w", stdout);
          // int tc = 1; // cin >> tc;
          // for (int i = 1; i <= tc; ++i) solve();
          while (cin >> ns >> m >> n) {
                    if (!ns && !m && !n) break;
                    solve();
          }
          cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
          return 0;
}  
