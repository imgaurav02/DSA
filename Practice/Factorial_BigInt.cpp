#include <bits/stdc++.h>
using namespace std;

void multiply(int x,vector<int> &arr){
    int carry = 0;
    for(int i  = 0;i<arr.size();i++){
        int mul = arr[i] * x + carry;
        arr[i] = mul % 10;
        carry = mul / 10;
    }
    while(carry){
        arr.push_back(carry % 10);
        carry /=10;
    }
}

vector<int> fact(int n){

    vector<int> res;
    res.push_back(1);
    if(n == 0 or n == 1)
        return res;
    for(int i = 2;i<=n;i++){
        multiply(i,res);
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    int n;
    cin>>n;
    vector<int> res;
    res = fact(n);
    for(int i  = 0;i<res.size();i++)
        cout<<res[i];
}
