#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7; //10^9+7//

int binPow(int a,int n)
{
    int res=1;
    while(n)
    {
        if(n&1)
            res=(1LL*res*a)%MOD;
        a=(1LL*a*a)%MOD;
        
        n>>=1;
    }
    return res;
}

///this calculated ncr%MOD///
int ncr(int n,int r,vector<ll> &fact,vector<ll> &inv)
{
    /// ///
    if(r>n)
    return 0;
    
    int multiply=( 1LL * fact[n] * inv[r] )%MOD;
    multiply=(1LL * multiply * inv[n-r] )%MOD;
    
    return multiply;
    //this function returns an integer because value of MOD can be contained in an integer
    //but to avoid error we are using 1LL //which does the multiplication like as if ll//
}
void solve(){
    
    
    int n;
    cin>>n;
    
    
    ///calc fact and inv vector///
    
    vector<ll> fact(n+1,1LL);
    vector<ll> inv(n+1,1LL);
    
    for(int i=1;i<=n;++i)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        inv[i]=binPow(fact[i],MOD-2);
    }
    
    
    //now you can use ncr directly here//
}
int main() {
	fast_io;
	
	solve();
	
	return 0;
}
