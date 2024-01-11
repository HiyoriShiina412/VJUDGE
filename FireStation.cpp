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

const int N = 5e2 + 5;
const int mod = 1e9 + 7;

struct Node {
          int u, du;
};

struct Cmp {
          bool operator() (Node a, Node b) {
                    return a.du > b.du;
          }
};

int f, n, fire, ans, pos;
string s;
bool skip[N];
vector<pair<int, int>> adj[N];
vector<int> station;

int solvesub() {
          vector<int> fd(n + 5, inf);
          for (int i = 0; i < isz(station); ++i) {
                    int r = station[i];
                    vector<int> d(n + 5, inf);
                    vector<bool> p(n + 5, false);
                    d[r] = 0;
                    priority_queue<Node, vector<Node>, Cmp> pq;
                    pq.push({r, 0});
                    while (!pq.empty()) {
                              Node x = pq.top();
                              pq.pop();
                              if (p[x.u]) continue;
                              p[x.u] = true;
                              for (auto e : adj[x.u]) {
                                        int v = e.fi, w = e.se;
                                        if (d[v] > d[x.u] + w) {
                                                  d[v] = d[x.u] + w;
                                                  pq.push({v, d[v]});
                                        }
                              }
                    }
                    for (int i = 1; i <= n; ++i) fd[i] = min(fd[i], d[i]);
          }
          int loli = -inf;
          for (int i = 1; i <= n; ++i) loli = max(loli, fd[i]);
          return loli;
}

void solve() {
          cin >> f >> n;
          station.clear();
          for (int i = 1; i <= n; ++i) {
                    adj[i].clear();
                    skip[i] = false;
          }
          for (int i  = 1; i <= f; ++i) {
                    cin >> fire; station.pb(fire);
                    skip[fire] = true;
          }
          cin.ignore();
          while (getline(cin, s) && !s.empty()) {
                    stringstream ss(s);
                    int u, v, w;
                    ss >> u >> v >> w;
                    adj[u].pb({v, w});
                    adj[v].pb({u, w});
          }
          ans = inf;
          for (int i = n; i >= 1; --i) {
                              if (!skip[i]) station.pb(i);
                              int res = solvesub();
                              // cout << res << "\n";
                              if (res <= ans) {
                                        ans = res;
                                        pos = i;
                              }
                              if (!skip[i]) station.pop_back();
          }
          cout << pos << "\n";
}

int32_t main() {
          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
          // freopen("barnpainting.in", "r", stdin);
          // freopen("barnpainting.out", "w", stdout);
          int tc = 1; cin >> tc;
          for (int i = 1; i <= tc; ++i) {
                    solve();
                    if(tc - i) cout << "\n";
          }
          cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
          return 0;
}  
