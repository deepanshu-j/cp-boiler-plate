/*      AUTHOR: Deepanshu Johar 
        codeforces: Dj46
*/
#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define repb(i,a,b) for(ll i=b-1 ; i>=(a) ; --i )
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define debugvec(x) cout<<#x<<": [ ";\
        for(ll iii=0;iii<x.size();++iii)\
        if(iii<x.size()-1)cout<<x[iii]<<" ,";else cout<<x[iii];\
        cout<<" ]\n";
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define inf 0x3f3f3f3f
const ll MOD= 998244353;

void solve(){
    string s="i love stupidity";
    // cin>>s;
    
    vector<string> splits;
    std::istringstream ss(s);
    std::string token;
    
    char delimiter = ' '; // ','
    while(getline(ss, token, delimiter)) {
        // std::cout << token << '\n';
        splits.emplace_back(token);
    }
    
    for(auto x: splits)cout<<x<<'\n';
    
}
signed main() {
	fast_io;
	ll t=1;
// 	cin>>t;
	rep(i,1,t+1)
	{
	   // cout<<"Case #"<<i<<": ";
	    solve();
	}
	return 0;
}
