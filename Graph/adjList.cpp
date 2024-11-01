#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>
// implemented BFS Traversal of graph
void BFS(vector<int> adj[],int start,vector<bool> &vis){
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto i : adj[node]){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
            }
        }
    }
    
}

// implementing the DFS traversal of graph

void DFS(vector<int> adj[],int start,vector<bool> &vis){
    cout << start << " ";
    vis[start] = true;
    for(auto &it : adj[start]){
        if(!vis[it]){
            DFS(adj,it,vis);
        }
    }
}



bool isCycleBFS(vector<int> adj[],int start,vector<bool> &vis){
    queue<pair<int,int>> q;
    q.push({start,-1});
    vis[start] = true;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int node = p.first;
        int parent = p.second;
        for(auto &it : adj[node]){
            if(vis[it] and parent != it)
                return true;
            else if(it != parent){
                q.push({it,node});
                vis[it] = true;
            }
        }
    }   
    return false;
}

int main(){
    INPUT
    OUTPUT
    //taking graph input using adjancency list
    int n,e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    loop(i,0,e){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    loop(i,1,n + 1){
        cout << i << " : ";
        for(int j : adj[i]){
            cout << j << " ";
        }
        cout <<endl;
    }

    //doing Traversal;
    vector<bool> vis(n + 1,false);
    loop(i,1,n+1){
        if(!vis[i]){
            // DFS(adj,i,vis);
            // BFS(adj,i,vis);
            if(isCycleBFS(adj,i,vis)){
                cout << "Yes";
                return 0;

            }
        }
    }
    cout << "No";
    return 0;
}