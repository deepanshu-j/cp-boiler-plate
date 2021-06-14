//spoj aggresive cows//
// binary search imp problem//

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

const ll INF= 1e9;
ll n,c;
const ll big=1e5+5;
ll a[big];

bool check(ll d){
    ll last=-INF;
    ll cnt=0;

    rep(i,0,n){

        if(a[i]-last >=d){
            last=a[i];
            ++cnt;
        }
    }

    if(cnt>=c)
    return true;
    else
    return false;
}
void binarySearch(){
    ll l=0,h=INF;
    ll ans;
    while(l<=h){
        ll mid=l+(h-l)/2;

        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    cout<<ans<<"\n";
}
void solve(){

    cin>>n>>c;

    rep(i,0,n)
        cin>>a[i];

    sort(a,a+n);

    binarySearch();

}
int main() {
	fast_io;
    ll t;
    cin>>t;
    // t=1;
    while(t--)
	    solve();
	return 0;
}
