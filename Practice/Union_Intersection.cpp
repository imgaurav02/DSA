#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

void intersection(int a[],int b[],int na,int nb){
    int max = 0;
    loop(i,0,na){

        if(max<a[i])
            max=a[i];
    }
    loop(i,0,nb){

        if(max<b[i])
            max=b[i];
    }
    int h[max+1]={0};
    loop(i,0,na)
        h[a[i]]++;
    loop(i,0,nb)
        h[b[i]]++;
    
    vector<int> uni;

    loop(i,0,max+1){
        if(h[i]>0)
            uni.push_back(i);
    }
    
    loop(i,0,uni.size())
        cout<<uni[i]<<" ";
}

void Union(int a[],int b[],int na,int nb){
    int max = 0;
    loop(i,0,na){

        if(max<a[i])
            max=a[i];
    }
    loop(i,0,nb){

        if(max<b[i])
            max=b[i];
    }
    int h[max+1]={0};
    loop(i,0,na)
        h[a[i]]++;
    loop(i,0,nb)
        h[b[i]] = h[b[i]]-2;
    
    vector<int> uni;

    loop(i,0,max+1){
        if(h[i]==-1)
            uni.push_back(i);
    }
    
    loop(i,0,uni.size())
        cout<<uni[i]<<" ";
}

int main(){
    int a[7]={1,2,3,8,9,50,100};
    int b[5]={1,4,3,8,12};
    
    Union(a,b,7,5);
    cout<<endl;
    intersection(a,b,7,5);
        
}