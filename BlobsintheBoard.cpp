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

const int N = 2e5 + 5;
const int mod = 998244353;

int r, c, n, tc, fmask;
int moveX[] = {1, -1, 0, 0, -1, -1, 1, 1,    2, -2, 0, 0, -2, -2, 2, 2}; 
int moveY[] = {0, 0, -1, 1, 1, -1, 1, -1,   0, 0, -2, 2, 2, -2, 2, -2};
int dp[1 << 16];

int posbit(int x, int y) {
          if (x < 1 || y < 1 || x > r || y > c) return inf;
          return (x - 1) * c + y - 1;
}

int loli(int mask) {
          if (__builtin_popcount(mask) == 1) return 1;
          if (dp[mask] != -1) return dp[mask];
          int ans = 0;       
          for (int i = 1; i <= r; ++i) {
                    for (int j = 1; j <= c; ++j) {
                              int u = posbit(i, j);
                              if ((mask & (1 << u)) == 0) continue;
                              int v, w, cur;
                              for (int k = 0; k < 8; ++k) {
                                        v = posbit(i + moveX[k], j + moveY[k]);
                                        w = posbit(i + moveX[k + 8], j + moveY[k + 8]);
                                        if (v < 0 || w < 0 || v >= r * c || w >= r * c) continue;
                                        if (mask & (1 << v) && (mask & (1 << w)) == 0) {
                                                  cur = mask;
                                                  cur -= (1 << u); cur -= (1 << v); cur += (1 << w);
                                                  ans += loli(cur);
                                        }
                              }
                    }
          }
          if (ans == 0) return dp[mask] = 0;
          return dp[mask] = ans;
}

void solve() {
          cin >> r >> c >> n;
          memset(dp, -1, sizeof(dp));
          fmask = 0;
          for (int i = 1; i <= n; ++i) {
                    int x, y; cin >> x >> y;
                    int p = posbit(x, y);
                    fmask += (1 << p);
          }
          cout << "Case " << ++tc << ": " << loli(fmask) << "\n";
}

int32_t main() {
          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
          // freopen(".inp", "r", stdin);
          // freopen(".out", "w", stdout);
          int tc = 1; cin >> tc;
          for (int i = 1; i <= tc; ++i) solve();
          cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
          return 0;
}  
