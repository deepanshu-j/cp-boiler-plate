#include<bits/stdc++.h>
using namespace std; 

int fn(string s)
{
	int n=s.size();
	
	int oc[n+1];
	int ec[n+1];////all the gaps between the numbers
	
	
	//memset(oc,1,sizeof oc);
	memset(ec,0,sizeof ec);
	
	if(n==1)
	return 1;
	
	int pt=0,dis=-1;

	///pt is the center of the currently maintained palindrome
	/// pt+dis gives us the boundary till where we know 

	for(int i=0;i<n;++i)
	{
		//oc[i]=1;///intializing it here itself////could j=have used memset
		
		///POD //this is what makes it O(n)==> 3 cases
		if( pt+dis < i )///i is not in the maintained palindromic  string///exp algo will run
		oc[i]=1;		
		else

		// [pt-(i-pt)] is the mirror image of i wrt pt
		//remember pt + oc[pt]-1 gives us the boundary 

		if( pt+dis < i+oc[pt-(i-pt)] )// pt-(i-pt) => i as these are mirror images 
		{	
			oc[i]=pt+dis-i+1;////difficult ////probable point of mistake ...dont forget to +1 
		}///+1 because {dis=oc[pt]-1} so to compensate this -1
		else
		if( pt+dis >= i )///i is in the range of currently maintained palindromic string but we dont know beyond 
		{	
			oc[i]=oc[pt-(i-pt)];
		}

		///expansion algorithm
		while(i-oc[i]>=0 && i+oc[i]<n && s[i - oc[i] ]==s[ i+oc[i] ] )
		{	++oc[i];
		}
		

		//update the currently maintained palsindromic string
		if(pt+dis < i+ oc[i]-1) 
		{
			pt=i;
			dis=oc[i]-1;
		}
	}

	int sum1=0,sum2=0;
	for(int i=0;i<n;++i)
	sum1+=oc[i];
	// cout<<oc[i]<<"*";
	// cout<<"\n";
	// return -1;

	///for even centered

	pt=0,dis=-1;
	for(int i=0;i<n;++i)
	{	
		if(pt+dis < i)
		ec[i]=0;
		else
		if(pt+dis < i+ec[pt-(i-pt)] )
		{
			ec[i]=pt+dis-i+1;
		}
		else
		{
			ec[i]=ec[pt-(i-pt)];
		}

		///exp algo
		while(i-ec[i]-1>=0 && i+ec[i] <n && s[i-ec[i]-1]==s[i+ec[i]])
		++ec[i];

		if(pt+dis < i+ec[i]-1)
		{
			pt=i;
			dis=ec[pt]-1;
		}
	}

	//
	cout<<"odd_center\n";
	for(int i=0;i<n;++i)
	cout<<oc[i]<<" " ;
	cout<<"\n";
	///
	cout<<"even_center\n";
	for(int i=0;i<n;++i)
	cout<<ec[i]<<" " ;
	cout<<"\n";

	for(int i=0;i<n;++i)
	sum2+=ec[i];
	return sum1+sum2;

}
int main() 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
	cout<<fn(s)<<"\n";
    
} 
