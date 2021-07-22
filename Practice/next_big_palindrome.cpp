#include<bits/stdc++.h>
using namespace std;

vector<int> nextPalindrome(vector<int> v,int n){
    int mid = n/2;
    int i = mid -1;
    int j = !n&1?mid:mid+1;
    bool isLeftSmall=0;
    while(i>=0 && v[i]==v[j]){

        i--; j++;
    }
    if(i<0 || v[i]<v[j])
        isLeftSmall = 1;
    while(i>=0){
        v[j++] = v[i--];
    }
    if(isLeftSmall){
        int carry = 1;
        i = mid-1;
        if(n&1){
            v[mid] +=carry;
            carry = v[mid]/10;
            v[mid] %=10;
            j = mid+1;
        }
        else
         j = mid;
        while (i>=0)
        {
            v[i] += carry;
            carry = v[mid]/10;
            v[mid] %=10;
            v[j++] = v[i--];
        }
    }
    
    return v;
}

bool all9s(vector<int> v,int n){
    for(int i=0;i<n;i++)
    {
        if(v[i] != 9)
            return 0;
    }
    return 1;
}

int main(){
    vector<int> num;
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        num.push_back(x);
    }
    if(all9s(num,num.size()))
    {
        cout<<"1 ";
        for(int i=1;i<num.size();i++)
            cout<<"0 ";
        cout<<"1";
    }
    else{
        vector<int> res = nextPalindrome(num,num.size());
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
    }
    
}