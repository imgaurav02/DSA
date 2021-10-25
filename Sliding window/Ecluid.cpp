#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

ll ecluid(ll a,ll b){
    if(a < b)
        return ecluid(b,a);
    if(b == 0)
        return a;
    return ecluid(b,a%b);
}

int main(){
    INPUT
    OUTPUT
    ll a,b;
    cin>>a>>b;
    cout<<ecluid(a,b);
    return 0;
}