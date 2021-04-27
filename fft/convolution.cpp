#include <bits/stdc++.h>
#define endl "\n"
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define pb push_back
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
using ll=long long;
namespace cpalgo{
    void fft(vector<cd> & a, bool invert) {
        ll n = a.size();
        if (n == 1)
            return;
    
        vector<cd> a0(n / 2), a1(n / 2);
        for (ll i = 0; 2 * i < n; i++) {
            a0[i] = a[2*i];
            a1[i] = a[2*i+1];
        }
        fft(a0, invert);
        fft(a1, invert);
    
        double ang = 2 * PI / n * (invert ? -1 : 1);
        cd w(1), wn(cos(ang), sin(ang));
        for (ll i = 0; 2 * i < n; i++) {
            a[i] = a0[i] + w * a1[i];
            a[i + n/2] = a0[i] - w * a1[i];
            if (invert) {
                a[i] /= 2;
                a[i + n/2] /= 2;
            }
            w *= wn;
        }
    }
    vector<ll> convolution(vector<ll> const& a, vector<ll> const& b) {//O(nlogn)//
        vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        ll n = 1;
        while (n < a.size() + b.size()) 
            n <<= 1;
        fa.resize(n);
        fb.resize(n);
    
        fft(fa, false);
        fft(fb, false);
        for (ll i = 0; i < n; i++)
            fa[i] *= fb[i];
        fft(fa, true);
    
        vector<ll> result(n);
        for (ll i = 0; i < n; i++)
            result[i] = round(fa[i].real());
        return result;
    }
}

vi conv(vi a,vi b) // O(n^2) //
{
    ll n=a.size();
    ll m=b.size();
    vi c(n+m-1,0);
    for(ll i=0;i<n;++i)
        for(ll j=0;j<m;++j)
        {
            c[i+j]+=(a[i]*b[j]);
        }
    return c;
}
void solve(){
    
    ll n;
    cin>>n;
    
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);
    
    for(auto &x:a)
    cin>>x;
    for(auto &x:b)
    cin>>x;
    
    // for(auto x:a)
    // cout<<x<<" ";
    // cout<<"\n";
    // for(auto x:b)
    // cout<<x<<" ";
    // cout<<"\n";
    
    auto c=cpalgo::convolution(a,b);
  
    c.resize(a.size()+b.size()-1);
    for(auto x:c)
    cout<<x<<" ";
    cout<<"\n";
  
    // for(ll i=0;i<a.size()+b.size()-1;++i)
    // cout<<c[i]<<" ";
    // cout<<"\n";
   
}
int main() {
	fast_io;
	ll t;
	cin>>t;
	while(t--)
	{
	  solve();
	}   
}

// Input:
// 2
// 2
// 1 2 3
// 3 2 1
// 2
// 1 0 1
// 2 1 0

// Output:
// 3 8 14 8 3
// 2 1 2 1 0

// Explaination
// 1st test case n=2, the polynomials are x^2 + 2x + 3 and 3x^2 + 2x + 1.

// On multiplying we get 3x^4 + 8x^3 + 14x^2 + 8x + 3 and hence the answer is 3 8 14 8 3.

// 2nd test case n=2, the polynomials are x^2 + 1 and 2x^2 + x. 

// On multiplying we get 2x^4 + x^3 + 2x^2 + x and hence the answer is 2 1 2 1 0. 