#include<bits/stdc++.h>



using namespace std;

void PrimeList(int n){
    
    int res[n+1];
    memset(res,true,sizeof(res));
    res[0] = false;
    res[1] = false;
    for(int i  = 2;i*i<=n;i++){
        if(res[i]){
            for(int j = i*i;j<=n;j+=i)
                res[j] = false;
        }
    }
    for(int i = 0;i<=n;i++)
        if(res[i])
            cout<<i<<" ";
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    PrimeList(n);
    
}