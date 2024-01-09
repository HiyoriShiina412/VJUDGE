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

int n, m;
int dp[N][21], h[N];
vector<int> adj[N];

void dfs(int u, int p) {
          dp[u][0] = p;
          for (auto v : adj[u]) {
                    if (v == p) continue;
                    h[v] = h[u] + 1;
                    dfs(v, u);
          }
}

int lca(int u, int v) {
          if (h[u] < h[v]) swap(u, v);
          int k = h[u] - h[v];
          for (int j = 0; j <= 17; ++j) {
                    if (k & (1 << j)) u = dp[u][j];
          }
          if (u == v) return u;
          k = __lg(h[u]);
          for (int j = k; j >= 0; --j) {
                    if (dp[u][j] != dp[v][j]) {
                              u = dp[u][j];
                              v = dp[v][j];
                    }
          }
          return dp[u][0];
}

void solve() {
          cin >> n;
          for (int i = 1; i < n; ++i) {
                    int u, v; cin >> u >> v;
                    adj[u].pb(v);
                    adj[v].pb(u);
          }
          dfs(1, 1);
          for (int j = 1; j <= 20; ++j) {
                    for (int i = 1; i <= n; ++i) {
                              dp[i][j] = dp[dp[i][j - 1]][j - 1];
                    }
          }
}

int32_t main() {
          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
          // freopen(".inp", "r", stdin);
          // freopen(".out", "w", stdout);
          int tc = 1; // cin >> tc;
          for (int i = 1; i <= tc; ++i) solve();
          cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
          return 0;
}  