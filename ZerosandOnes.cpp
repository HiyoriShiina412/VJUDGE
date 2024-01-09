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

const int maxn=(1<<15)+5;
const int mod=1e9+7;

int n,k,tc;
int dp[70][70][105];
int modk[70];

int subtract(int x,int y){
          return ((x-y)%k+k)%k;
}

void solve(){
          memset(dp,0,sizeof(dp));
          memset(modk,0,sizeof(modk));
          cin>>n>>k;
          if(n%2||k==0){
                    cout<<"Case "<<++tc<<": "<<0<<"\n";
                    return;
          }
          modk[0]=1;
          F(i,1,n-1){
                    modk[i]=(modk[i-1]*2)%k;
          }
          dp[1][1][modk[n-1]]=1;
          F(i,2,n){
                    F(j, 1, i){
                              F(m,0,k-1){
                                        dp[i][j][m]+=dp[i-1][j][m];//bit is off
                                        dp[i][j][m]+=dp[i-1][j-1][subtract(m,modk[(n-i)])];//bit is on
                              }
                    }
          }
          cout<<"Case "<<++tc<<": "<<dp[n][n/2][0]<<"\n";
}

int32_t main() {
          ios_base::sync_with_stdio(0);cin.tie(NULL);
          // freopen(".inp","r",stdin);
          // freopen(".out","w",stdout);
          int tt=1; cin>>tt;
          while(tt--)solve();
          return 0;
}
