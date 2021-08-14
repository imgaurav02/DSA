#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<bool> bin;
    int n;
    cin>>n;
    bool x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        bin.push_back(x);
    }
    int dec=0;
    int j;
    for(int i=n-1,j=0;i>=0;i--){
        dec += bin[i]*pow(2,j++);
    }
    vector<int> base6;
    while(dec){
        base6.push_back(dec%6);
        dec /=6;
    }
    for(int i=base6.size()-1;i>=0;i--)
        cout<<base6[i];
    return 0;
}