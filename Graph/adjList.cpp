#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>
// implemented BFS Traversal of gragh
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

    //doing BFS;
    vector<bool> vis(n + 1,false);
    loop(i,1,n+1){
        if(!vis[i]){
            BFS(adj,i,vis);
        }
    }
    return 0;
}