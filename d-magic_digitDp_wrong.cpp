#include <bits/stdc++.h>
using namespace std;

#define fast_io {   ios_base::sync_with_stdio(false);\
                    cin.tie(0);\
                    cout.tie(0);   }
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define pb push_back
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
ll dp[2005][2005][2];
ll m,d;
ll const MOD=1e9+7;
ll power[2005];
ll binPow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=(1LL*res*a)%m;
        a=(1LL*a*a)%m;

        n>>=1;
    }
    return res;
}
// solve(position, sum , smaller)

bool doesThisStringFollows(string a){


    ll sum=0;
    rep(i,0,a.length()){
        if(i&1){
            if(a[i]-'0'==d)
            continue;
            else
            return false;
        }
        else{
            if(a[i]-'0'==d)
            return false;
            else
            continue;

        }
        sum=(sum%m+(power[a.length()-i-1]*(a[i]-'0'))%m)%m;
    }


    // cout<<sum<<"**\n";
    // cout<<"\n"<<sum<<"\n";


    if(a.length()<5){

        ll aint=0;
        rep(i,0,a.length()){
            ll character=(a[i]-'0');
            // cout<<pow[a.length()-i-1]<<" "<<character<<"\n";
            aint+=(pow(10,a.length()-i-1)*character);
        }
        // cout<<"aint : "<<aint<<"\n";
        if(aint< m){
            return false;
        }
        else
        return aint%m==0;

        return sum%m==0;
    }

    // if(a=="0" && m!=0)
    // return false;

    return sum%m==0 ;


    // if(sum%m==0)
    // return true;
    // else
    // return false;


}
ll solve(string& s, ll n, ll sum, bool smaller ){

    //base case//
    if(n==s.length()){
        if(sum%m==0)return 1;
        return 0;
    }

    if(dp[n][sum][smaller]!=-1)
        return dp[n][sum][smaller];

    // //
    ll ub= smaller ? 9 : s[n]-'0' ;
    // cout<<"\nub : "<<ub<<" , ";
    ll ans =0;

    if(n%2==0){
        rep(i,0,ub+1){

            if(i!=d){
                if(smaller){
                    ans = (ans%MOD +solve(s, n+1, (sum+( i*power[s.length()-n-1] ))%m, smaller)%MOD)%MOD;
                }
                else{
                    ans = (ans%MOD + solve(s, n+1, (sum+( i*power[s.length()-n-1] ))%m, (i==ub)?0:1 )%MOD)%MOD;
                }
            }

        }
    }
    else{

        if(smaller){
            ans =(ans%MOD +solve(s, n+1,  (sum+( d*power[s.length()-n-1] ))%m, smaller)%MOD)%MOD;
        }
        else{
                if(d<=ub){
                        ans =(ans%MOD +solve(s, n+1,  (sum+( d*power[s.length()-n-1] ))%m, (d==ub)?0:1 )%MOD)%MOD;
                }
        }
    }



    return dp[n][sum][smaller]=ans ;

}
int main() {
	fast_io;
    // ll t;
    // cin>>t;
    // t=1;
    // rep(tt,1,t+1){

    //     // cout<<"Case #"<<tt<<": ";
    //     solve();
    // }


    cin>>m>>d;

    string a,b;
    cin>>a>>b;
    memset(dp, -1, sizeof dp );

    rep(p,0,2005){
        power[p]=binPow(10,p);
    }

    ll ans1=solve(a,0,0,0);
    memset(dp, -1, sizeof dp );


    ll ans2=solve(b,0,0,0);


    cout<<ans2-ans1+doesThisStringFollows(a)<<"\n";
    // cout<<power[1]<<"&&"<<power[2]<<"**";

    // cout<<ans1<<"\n"<<ans2<<"\n"<<doesThisStringFollows(a);

	return 0;
}
 
