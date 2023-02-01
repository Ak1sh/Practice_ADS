//TC: O(ElogV)
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
void sol(vector<pair<int,int>> adj[] ,int s,int n)
{
    vector<int>dist(n+1,1e9);
    priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    dist[s]=0;
    
    while(!pq.empty()){
        int prevdistance=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int adjnode=it.first;
            int adjwt=it.second;
            
            if(prevdistance+adjwt<dist[adjnode]){
                dist[adjnode]=prevdistance+adjwt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(dist[i]==1e9) continue;
         cout<<dist[i]<<" ";
    }
   
}
int main()
{
    int n,m,s;
    cout<<"Enter the number of nodes:";
    cin>>n;

    cout<<"Enter the number of edges:";
    cin>>m;
    
    cout<<"Enter the source:";
    cin>>s;
    
    cout<<"Enter the graph nodes and weight:";
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
        
    }
    sol(adj,s,n);
    return 0;
}
