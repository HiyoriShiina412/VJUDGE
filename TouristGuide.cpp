#include<bits/stdc++.h>
using namespace std;
//悲しい少年
#define fi first
#define inf 1e18
#define se second
#define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define F(i,a,b) for(int i=a;i<=b;++i)
#define F1(i,a,b) for(int i=a;i>=b;--i)
#define ret(x) {cout<<x<< "\n";return;}
#define FF(i,a,b,pl) for(int i=a;i<=b;i+=pl)

const int maxn=1e2+5;
const int mod=1e9+7;

int n,m,tc,tdfs;
string city[maxn];
vector<string>ans;
map<string,vector<string>>adj;
map<string,int>num,low,joint;

void dfs(string u,string p){
          num[u]=low[u]=++tdfs;
          int child=0;
          for(auto v:adj[u]){
                    if(v==p)continue;
                    if(!num[v]){
                              dfs(v,u);
                              low[u]=min(low[u],low[v]);
                              ++child;
                              if(u==p){
                                        if(child>1)joint[u]=1;
                              }else if(low[v]>=num[u])joint[u]=1;
                    }else low[u]=min(low[u],num[v]);
          }
}

void solve(){
          adj.clear();
          ans.clear();
          num.clear();
          low.clear();
          joint.clear();
          F(i,1,n)cin>>city[i];
          cin>>m;
          F(i,1,m){
                    string u,v;
                    cin>>u>>v;
                    adj[u].pb(v);
                    adj[v].pb(u);
          }
          F(i,1,n){
                    if(!num[city[i]]){
                              tdfs=0;
                              dfs(city[i],city[i]);
                    }
          }
          F(i,1,n){
                    if(joint[city[i]]){
                              ans.pb(city[i]);
                    }
          }
          sort(all(ans));
          ++tc;
          if(tc!=1)cout<<"\n";
          cout<<"City map #"<<tc<<": "<<sz(ans)<<" camera(s) found\n";
          F(i,0,sz(ans)-1){
                    cout<<ans[i]<<"\n";
                    //if(i!=sz(ans)-1)cout<<"\n";
          }
}         

int32_t main() {
          ios_base::sync_with_stdio(0);cin.tie(NULL);
          // freopen(".inp","r",stdin);
          // freopen(".out","w",stdout);
          while(cin>>n){
                    if(!n)break;
                    solve();
          }
          return 0;
}
