#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
const ll MOD = 1e9 + 7; //10^9+7//


// ll dp[pos][smaller][rem][even][leadingzero]
ll dp[2001][2][2001][2][2];
ll m,d;
string a,b;
string s,ss;
ll powerr[2005];
ll binPow2(ll a,ll n)
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
ll binPow(ll a,ll n)
{
    return powerr[n];
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

//leadingzero means its the leading position
ll f(ll pos,bool smaller, ll rem,bool even, bool leadingzero){
    //base case//

    if(pos==-1){
        if(rem%m==0)
        return 1;
        else
        return 0;

    }


    //check in memo//
    if(dp[pos][smaller][rem][even][leadingzero]!=-1){
        return dp[pos][smaller][rem][even][leadingzero];
    }


    //recc//
    ll ans=0;
    // bool even =((s.length()-pos) % 2==0);
    if(smaller){
        if(even){
            // cout<<"vcgavs";
            //anything // d
            ans += f(pos-1, true, (rem+(d%m * binPow(10,pos) )%m ) %m , ((d==0&& leadingzero) ? false : !even ),  (d==0 && leadingzero)? true: false)%MOD;

        }else{

            //anything // anything except d
            // cout<<"thus";
            rep(i,0,10){
                if(i!= d){

                    // cout<<"i: "<<i<<" f()"<<f(pos-1 , true, (rem+(i%m * binPow(10,pos) )%m ) %m,  (i==0&& leadingzero) ? false : !even , (i==0 && leadingzero)? true: false);
                    ans += f(pos-1 , true, (rem+(i%m * binPow(10,pos) )%m ) %m,  (i==0&& leadingzero) ? false : !even , (i==0 && leadingzero)? true: false)%MOD;
                }
            }
        }
    }
    else{
        if(even){//only d at this position//
            if(d<(ss[pos]-'0'))
            ans += f(pos-1, true,  (rem+(d%m * binPow(10,pos) )%m ) %m ,(d==0&& leadingzero) ? false : !even, (d==0 && leadingzero)? true: false)%MOD;
            else
            if(d==(ss[pos]-'0'))
            ans += f(pos-1, false,  (rem+(d%m * binPow(10,pos) )%m ) %m,(d==0&& leadingzero) ? false : !even, (d==0 && leadingzero)? true: false)%MOD;

        }
        else{
            //anything except d at this pos
            rep(i,0, (ss[pos]-'0')+1 ){
                if(i!=d){
                    // cout<<"i: "<<i<<"\n";
                    ans+=f(pos-1, (((ss[pos]-'0')==i)? false : true) ,  (rem+(i%m * binPow(10,pos) )%m ) %m, (i==0&& leadingzero) ? false :!even ,(i==0 && leadingzero)? true: false )%MOD;
                }
            }
        }
    }
    // cout<<"pos: "<<pos<< " ans: "<<ans<<"\n";
    return dp[pos][smaller][rem][even][leadingzero]=ans%MOD;
}

void solve(){
    cin>>m>>d>>a>>b;
    memset(dp, -1 ,sizeof dp);

    powerr[0]=1;
    powerr[1]=10;
    // cout<<binPow2(10,1)<<"\n";

    // cout<<binPow2(10,2)<<"\n";
    rep(j,2,b.size()+5){
        powerr[j]=binPow2(10,j);
    }
    // s=b;

    // ll ans_b=f(s.size()-1, 0, 0 ,0,1);

    s=a;
    reverse(a.begin(),a.end());
    ss=a;
    // reverse(a.begin(),a.end());
    ll ans_a=f(s.size()-1, 0, 0 ,0,1)%MOD;
    memset(dp, -1 ,sizeof dp);
    s=b;
    reverse(b.begin(),b.end());
    ss=b;

    ll ans_b=f(s.size()-1, 0, 0 ,0,1)%MOD;

    ll ans=(ans_b-ans_a)%MOD;
    // cout<<"ans "<<ans<<"\n" ;
    // cout<<"ans_a "<<ans_a<<"\n";

    // cout<<"ans_b "<<ans_b<<"\n";


    //original ans//
    cout<<ans%MOD;

}
int main() {
	fast_io;
	ll t;
	t=1;
// 	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
