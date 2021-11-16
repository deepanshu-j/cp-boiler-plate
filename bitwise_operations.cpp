#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

// n is 0 indexed //
int printKthBit(unsigned int n, unsigned int k)
{
    return ((n & (1 << k)) >> k);
}

void solve(){
    
}
int main() {
	fast_io;
	int t=1;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
