@ solution from meh

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

const int maxn=(1 << 15)+5;
const int mod=1e9+7;

int n,x,y,tc;
int a[maxn];
int dp[105][maxn];
int sum[maxn];

int dac(int x,int mask){
          if(dp[x][mask]!=0)return dp[x][mask];
          int s=sum[mask],y;
          if(s%x)return dp[x][mask]=-1;
          else y=s/x;
          if(__builtin_popcount(mask)==1)return dp[x][mask]=1;
          int s1,s2;
          F(i,1,max(x,y)-1){
                    s1=x*i,s2=y*i;
                    for(int sub=mask;sub>0;sub=(sub-1)&mask){
                              if(sub==mask)continue;
                              if(i<y&&sum[sub]==s1){
                                        int g1=dac(x,sub),g2=dac(x,mask-sub);
                                        if(g1==1&&g2==1)return dp[x][mask]=1;
                              }
                              if(i<x&&sum[sub]==s2){
                                        int g1=dac(i,sub),g2=dac(x-i,mask-sub);
                                        if(g1==1&&g2==1)return dp[x][mask]=1;
                              }
                    }
          }
          return dp[x][mask]=-1;
}

void solve(){
          memset(dp,0,sizeof(dp));
          memset(sum,0,sizeof(sum));
          cin>>x>>y;
          F(i,1,n) cin>>a[i];
          F(mask,1,(1<<n)-1){
                    F(j,0,n-1) if(mask&(1 << j)) sum[mask]+=a[j+1];
          }
          cout<<"Case "<<++tc<<": ";
          if(x*y==sum[(1<<n)-1]&&dac(x,(1<<n)-1)==1)cout<<"Yes\n";
          else cout<<"No\n";
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
