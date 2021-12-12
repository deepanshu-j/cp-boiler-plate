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

const int MOD = 1e9 + 7;

int add(int i, int j) {
	if ((i += j) >= MOD)
		i -= MOD;
	return i;
}
int sub(int i, int j) {
	if ((i -= j) < 0)
		i += MOD;
	return i;
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
