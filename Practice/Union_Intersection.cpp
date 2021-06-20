#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main(){
    int a[5]={1,2,3,8,9};
    int b[5]={1,4,3,8,12};
    int max = 0;
    loop(i,0,5){

        if(max<a[i])
            max=a[i];
    }
    loop(i,0,5){

        if(max<b[i])
            max=b[i];
    }
    int h[max+1]={0};
    loop(i,0,5)
        h[a[i]]++;
    loop(i,0,5)
        h[b[i]]++;
    
    vector<int> uni;

    loop(i,0,max+1){
        if(h[i]>0)
            uni.push_back(i);
    }
    
    loop(i,0,uni.size())
        cout<<uni[i]<<" ";

        
}