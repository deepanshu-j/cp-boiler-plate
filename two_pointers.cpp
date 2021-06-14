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

void solve(){
    int n,s;
    cin>>n>>s;

    vi a(n);
    for(auto &x:a)
    cin>>x;

    //segment is good if sum of that segment is <=s//
    //Tell the Maximum length of the good segment//

    int l=0,r=0;

    int ans=0;

    int sum=0;
    for(r=0; r<n ;++r){
        sum+=a[r];

        while(sum>s){
            sum-=a[l++];
        }
        ans = max(ans ,r-l+1);
    }
    cout<<ans;
}
int main() {
	fast_io;
    ll t;
    // cin>>t;
    t=1;
    while(t--)
	    solve();
	return 0;
}
