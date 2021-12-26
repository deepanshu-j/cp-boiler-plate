#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
using ll = long long;
typedef pair<int,int> pii;
typedef vector<int> vi;
void solve(){
    int n;
    cin>>n;
    
    vector<pii> a(n);
    
    rep(i,0,n){
        int x, y;
        cin>>x;
        cin>>y;
        a[i].ff = x;
        a[i].ss = y;
    }
    
    // sort(all(a));
    
    // Sort the vector of pairs acc. to the second element in desc order // 
    // if tie on second el, sort acc to first el in desc oredr //  

// // 8
// // 9 0
// // 2 5
// // 8 0
// // 6 5
// // 3 0
// // 1 5
// // 13 3
// // 1 3

// gives 
/**
// // 6 5
// // 2 5
// // 1 5
// // 13 3
// // 1 3
// // 9 0
// // 8 0
// // 3 0
*/
    // when it compares between two pair which to keep on left and which on right //
    sort(all(a), [](pair<int,int> &left, pair<int,int> &right){

        if(left.ss != right.ss)
            return left.ss > right.ss;
        
        // else
        // if(left.ss==right.ss) 
            return left.ff > right.ff;
    });
    
    for(auto [x,y]: a)
        cout<<x<<" "<<y<<"\n";

    
}

signed main() {
	fast_io;
	ll t=1;
// 	cin>>t;
	
	while(t--)
	{
	    solve();
	}
	return 0;
}
