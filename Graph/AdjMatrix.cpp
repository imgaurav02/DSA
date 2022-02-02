#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>


//representing graph using ajacency matrix

int main(){
    INPUT
    OUTPUT
    int n,e;
    cin >> n >> e;
    vector<vector<int> > adj(n+1,vector<int>(n+1,0));
    loop(i,0,e){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    loop(i,0,n+1){
        loop(j,0,n+1){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}