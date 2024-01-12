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

const int N = 1e3 + 5;
const int mod = 1e9 + 7;

struct Node {
          int u, r, du;
};

struct Cmp {
          bool operator() (Node a, Node b) {
                    return a.du > b.du;
          }
};

int n, m, q;
int price[N], d[N][105], p[N][105];
vector<pair<int, int>> adj[N];

void solve() {
          cin >> n >> m;
          for (int i = 0; i < n; ++i) cin >> price[i];
          for (int i = 1; i <= m; ++i) {
                    int u, v, w; cin >> u >> v >> w;
                    adj[u].pb({v, w});
                    adj[v].pb({u, w});
          }
          cin >> q;
          for (int tc = 1; tc <= q; ++tc) {
                    int c, s, e ; cin >> c >> s >> e;
                    for (int i = 0; i < n; ++i) {
                              for (int j = 0; j <= c; ++j) {
                                        d[i][j] = inf;
                                        p[i][j] = false;
                              }
                    }
                    d[s][0] = 0;
                    priority_queue<Node, vector<Node>, Cmp> pq;
                    pq.push({s, 0, 0});
                    bool loli = false;
                    while (!pq.empty()) {
                              Node x = pq.top(); pq.pop();
                              if (p[x.u][x.r]) continue; p[x.u][x.r] = true;
                              if (x.r < c) {
                                        if (d[x.u][x.r + 1] > d[x.u][x.r] + price[x.u]) {
                                                  d[x.u][x.r + 1] = d[x.u][x.r] + price[x.u];
                                                  pq.push({x.u, x.r + 1, d[x.u][x.r + 1]});
                                        }
                              }
                              for (auto e : adj[x.u]) {
                                        int v = e.fi, w = e.se;
                                        int need = x.r - w;
                                         if (need >= 0 && d[v][need] > d[x.u][x.r]) {
                                                  d[v][need] = d[x.u][x.r];
                                                  pq.push({v, need, d[v][need]});
                                        }
                              }
                    }
                    int ans = inf;
                    for (int i = 0; i <= c; ++i) ans = min(ans, d[e][i]);
                    if (ans == inf) cout << "impossible\n";
                    else cout << ans << "\n";         
          }
}

int32_t main() {
          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
          // freopen("barnpainting.in", "r", stdin);
          // freopen("barnpainting.out", "w", stdout);
          int tc = 1; // cin >> tc;
          for (int i = 1; i <= tc; ++i) solve();
          cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
          return 0;
}  
