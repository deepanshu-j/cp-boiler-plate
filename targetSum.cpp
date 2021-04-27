#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define pb push_back
typedef long long ll;

//subset sum using plain recursion 
// bool dp(vector<int> v,int n,int sum){

//     //base case//
//     if(sum<0)
//     return false;
//     if(sum==0)
//     return true;
//     if(n==0)
//     return sum==v[0];

//     //reccurence//
//     return dp(v,n-1,sum)||(sum-v[n]<0?false:dp(v,n-1,sum-v[n]));

// }

// bool targetSum(vector<int> v,int sum)
// {
//     //returns true if subset with that sum exist 
//     //else false
//     sum=accumulate(v.begin(),v.end(),0);
//     return dp(v,v.size()-1,sum);

// }

bool targetSum(vector<int> &nums,int sum){
    int n=nums.size();
    
    int dp[n+1][sum+1];
    //we have dp[0...n][0...sum]; not //dp[0...n-1][0...sum]//because n=0 is our base case 

    memset(dp,false,sizeof dp);
    
    //initialization//
    //sum==0 with no element // this isnt possible when targetSum>0 and all elements are >0 therefore false  
    dp[0][0]=false;
    
    //n=0 represents phi set// 


    //sum==0  n>0 true
    for(int i=1;i<=n;++i)
        dp[i][0]=true;
    
    //sum>0 n=0=>phi set
    for(int i=1;i<=sum;++i)
        dp[0][i]=false;
    
    ///tabulation//
    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=sum;++j)
        {
            if(j-nums[i-1]<0)
                dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
        }
    
    return dp[n][sum];
}
void solve(){
    
    int n;
    cin>>n;
    
    vector<int> v(n);
    
    for(auto &x: v)
    {
        cin>>x;
    }
    
    int sum=16;//
    if(targetSum(v,sum))
    cout<<"YES\n";
    else
    cout<<"NO\n";
    
}
int main() {
	fast_io;
	ll t;
// 	cin>>t;
	
	t=1;
	while(t--)
	{
	    solve();
	}
	return 0;
}
//input
// 4
// 1 5 11 15

//sum=16

//output
//YES