
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int randomnum(int n){
    return rand()%n;
}
void insert(int data,int n,vector<int>adj[]){
    int r=randomnum(n);
    cout<<r<<endl;
    for(int i=0;i<=r;i++)
    adj[i].push_back(data);
    
}
void del(int n,int key,vector<int> adj[]){
    for(int i=0;i<n;i++)
         adj[i].erase(remove(adj[i].begin(), adj[i].end(), key), adj[i].end());
           
}
void display(int n,vector<int> adj[])
{
    for(int i=0;i<n;i++)
    {
        cout<<"Level "<<i <<":";
        for(auto it: adj[i])
        cout<<it<<" ";
        cout<<endl;
    }
}
int main()
{
    int n,data;
    cout<<"Enter the max level:";
    cin>>n;
    vector<int> adj[n];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[0].push_back(4);
    adj[0].push_back(5);
    adj[1].push_back(2);
    adj[1].push_back(3);
    
    cout<<"Enter the value to insert:";
    cin>>data;
    insert(data,n,adj);
    
    display(n,adj);
    
    int key;
    cout<<"Enter the key to delete:";
    cin>>key;
    del(n,key,adj);
    
    display(n,adj);

    return 0;
}
