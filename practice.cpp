
// #include<bits/stdc++.h>

// /**
#include<iostream>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
// */


using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
using ll = long long;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    
    vector<pii> a;
    rep(i,1,n+1){
        
        // int cnt = 0;
        int k = 1; 
        while(i*k<=n){
            ++k;
        }
        
        a.pb({k-1, i});
    }

    sort(all(a), [](pair<int,int> &left, pair<int,int> &right){

        if(left.ff != right.ff)
            return left.ff > right.ff;
        
        // else
        // if(left.ss==right.ss) 
            return left.ss > right.ss;
    });

    for(auto x: a){
        cout<<x.ss<<" , "<<x.ff<<"\n";
    }

    vi res(n, 1);

    int g = a[1].ss;
    int p = 2;

    auto paint = [&res](int freq, int val){
        // paint last freq els of res with val //
        int last = n-1;
        while(freq--){
            res[last--] = val; 
        }
    };

    while(p<n){
        if(__gcd(g, a[p].ss)==g){
             
            g = a[p].ss;

            paint(a[p].ff , a[p].ss); 
        }
        
        ++p;
    }

    for(auto x: res)
    cout<<x<<" ";
}

signed main() {
    
    //OPTIMIZE

    freopen("in.txt" , "r" , stdin) ;
    freopen("out.txt" , "w" , stdout) ;
	
    fast_io;
	int t=1;
	// cin>>t;
	while(t--)
	{
	    solve();
	}

// #ifdef LOCAL_DEFINE
        // cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"; // or cerr
// #endif
	return 0;
}
