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

int parent[1000];
int _rank[1000];
void initialize(int lim){
    //if there are n nodes , then this fn will make sure every node's parent is he himself//
    // and _rank of every node is 0 initially//
    rep(i,1,lim+1){
        parent[i]=i;
        _rank[i]=0;
    } 
}

int findParent(int node){
    if(node==parent[node])
        return node;
        
    return findParent(parent[node]);
    // return parent[node]= findParent(parent[node]); // With Path Compression//
}

void unionOperation(int u, int v){
    u = findParent(u);
    v = findParent(v);
    if(_rank[u]<_rank[v]){
        parent[u]=v; 
    }
    else 
    if(_rank[v]<_rank[u]){
        parent[u]=v;
    }
    else{
        parent[v]=u;
        ++_rank[v];
    }
    
}

bool doesBelongToSameSet(int u, int v){
    return (findParent(u)==findParent(v));
}

void solve(){
    
    // Here n represents n different sets{disjoint sets} represented by numbers 1->n // initially all sets having only member as themselves //
    // eg - (1) (2) (3) (4) (5) 
    // We will perform union on these sets // union set 1 and set 2// or union the set which 1 belongs to with the set which 2 belongs to
    // eg - union(1,2)
    // our eg set becomes (1 2) (3) (4) (5)
    // union(2,4)
    // our eg set becomes (1 2 4) (3) (5)
    // union(3,5)
    // our eg set becomes (1 2 4) (3 5)
    // now find me does 1 and 3 belong to the same set// nodes
    // find()
    
    
    //other terminology - n nodes// one and the same thing//
    
    int n=5;// no. of elements 
    // cin>>n;
    initialize(n);// initialize a dsu with 1->n elements // initially all nodes/sets will have parent as themselves
    
    int u,v;
    // cin>>u>>v;
    
    
    unionOperation(1,2);
    unionOperation(2,4);
    unionOperation(3,5);
    // (1 2 4) (3 5)
    
    
    u=1; v=4;
    // to find does u and v belong to same sets //
    if(doesBelongToSameSet(u, v))
    cout<<"YES, Belong to the same set\n";
    else 
    cout<<"NO, do not belong to the same sets\n";
    
    
    u=3; v=5;
    // to find does u and v belong to same sets //
    doesBelongToSameSet(u, v) ? cout<<"YES, Belong to the same set\n" : cout<<"NO, do not belong to the same sets\n";
    
     u=4; v=5;
    // to find does u and v belong to same sets //
    if(doesBelongToSameSet(u, v))
    cout<<"YES, Belong to the same set\n";
    else 
    cout<<"NO, do not belong to the same sets\n";
    
    
    // union 3,4 
    unionOperation(3,4);
    
}
int main() {
	fast_io;
	int t=1;
// 	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}

//OUTPUT
// YES, Belong to the same set
// YES, Belong to the same set
// NO, do not belong to the same sets
