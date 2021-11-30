#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pi pair<int,int>
#define tri pair<int,pi>
#define pb push_back
using namespace std;
int  main()
{
   
    int v,e;
    scanf("%d%d",&v,&e);
    
    vector<vector<pi>> graph(v+1);
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }
    
    int source=1;

    int dist[v+1];
    memset(dist,INF,sizeof(dist));
    dist[source]=0;
    int prev[v+1];
    memset(prev,-1,sizeof(dist));
    
    priority_queue<pi,vector<pi>,greater<pi>> p_q;
    p_q.push({dist[source],source});
    
    while(!p_q.empty())
    {
        int u=p_q.top().second;
        p_q.pop();
        
        for(auto x:graph[u])
        {
            int dgs=dist[u]+x.second;
            if(dgs<dist[x.first])
            {
                dist[x.first]=dgs;
                prev[x.first]=u;
                p_q.push({dist[x.first],x.first});
                
            }
        }
    }
    
    if(prev[v]==-1||dist[v]>=INF)
    printf("-1 ");
    else
    {
       int i=v;
       vector<int> stk;
       stk.pb(v);
       while(i!=source)
       {
        stk.pb(prev[i]);
        i=prev[i];
       }
       
        if(all_of(stk.begin(),stk.end(),[](int m){return m!=-1;}))
        {
            for(auto itr=stk.rbegin();itr!=stk.rend();itr++)
            {
                printf("%d ",*itr);
            }
        }
        else
        {
            printf("-1 ");
        }
        
    }
    
    
}