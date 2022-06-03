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

map<int, set<int> > tree;

void remove_parent(int node, int par){
    
    if(tree[node].count(par)>0)
    tree[node].erase(par);
    
    for(auto ch: tree[node]){
        remove_parent(ch, node);
    }
}
void solve(){
    
    int n;
    cin>>n;
    
    
    rep(i,0,n-1){
        int u, v;
        cin>>u>>v;
        
        tree[u].insert(v);
        tree[v].insert(u);
    }
    
    int root=1;
    remove_parent(root, -1);
    
    // for(auto x: tree){
    //     cout<<x.ff<<" : ";
    //     for(auto y: x.ss)cout<<y<<" ";
    //     cout<<"\n";
    // }
    
    vi bfs(n);
    rep(i,0,n)cin>>bfs[i];
    
    int curr = 0; // current index pointer on the queue //
    int next = 1; 
    bool ok=1;
    
    while(curr<n and next<n){
        
        int vertex = bfs[curr];
        int sz = tree[vertex].size();
        
        // now put all the next sz vertices in a check_set //
        set<int> check_set;
        
        rep(i,next, min(n, next+sz)){
            check_set.insert(bfs[i]);
        }
        next = next+sz;
        
        if(check_set!=tree[vertex]){
            ok=0; break; 
        }
        
        ++curr;
    }
    
    cout<<(ok?"Yes\n":"No\n");
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
