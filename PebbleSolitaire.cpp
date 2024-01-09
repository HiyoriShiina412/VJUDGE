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

const int maxn=2e5+5;
const int mod=1e9+7;

string s;
int dp[1<<12];

void solve(){
          memset(dp,0,sizeof(dp));
          cin>>s;
          int fmask=0;
          F(i,0,11){
                    if(s[i]=='o')fmask+=(1<<i);
          }
          int ans=INT_MAX;
          queue<int>q;
          q.push(fmask);
          while(!q.empty()){
                    int mask=q.front(); q.pop();
                    if(dp[mask])continue;
                    dp[mask]=1;//not visited
                    int biton=__builtin_popcount(mask);
                    ans=min(ans,biton);
                    F(i,0,11-3+1){
                              if((mask&(1<<(i+1)))==0)continue;
                              if((mask&(1<<i))&&(mask&(1<<(i+2))))continue;
                              if((mask&(1<<i))==0&&(mask&(1<<(i+2)))==0)continue;
                              int tmp=mask-(1<<(i+1));
                              if(mask&(1<<i)){
                                        tmp-=(1<<i);
                                        tmp+=(1<<(i+2));
                              }else{
                                        tmp+=(1<<i);
                                        tmp-=(1<<(i+2));
                              }
                              q.push(tmp);
                    }
          }
          cout<<ans<<"\n";
}

int32_t main() {
          ios_base::sync_with_stdio(0);cin.tie(NULL);
          // freopen(".inp","r",stdin);
          // freopen(".out","w",stdout);
          int tt=1; cin>>tt;
          while(tt--)solve();
          return 0;
}
// 5
// ---oo-------
// -o-o-oo----
// -o----ooo---
// ooooooooooo
// ooooooooo-o

