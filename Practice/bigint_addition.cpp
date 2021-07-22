#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

vector<int> sum(vector<int> a,vector<int> b){
    int sum,carry =0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int> c;
    int j=0,k=0;
    while(j<a.size() && k<b.size()){
        sum = a[j++] + b[k++] + carry;
        carry = sum/10;
        c.push_back(sum%10);
    }
    for(;j<a.size();j++)
    {
        sum = a[j] + carry;
        carry = sum/10;
        c.push_back(sum%10);
    }
    for(;k<b.size();k++)
    {
        sum = a[k] + carry;
        carry = sum/10;
        c.push_back(sum%10);
    }
    if(carry != 0)
        c.push_back(carry);
    
    reverse(c.begin(),c.end());

    return c;

} 

int main(){
    string s1,s2;
    vector<int> a;
    vector<int> b;
    cin>>s1>>s2;
    loop(i,0,s1.length())
        a.push_back(s1[i]-'0');
    loop(i,0,a.size())
        cout<<a[i]<<" ";
    loop(i,0,s2.length())
        b.push_back(s2[i]-'0');
    cout<<endl;
    loop(i,0,b.size())
        cout<<b[i]<<" ";
    vector<int> s;
    s = sum(a,b);
    cout<<endl;
    loop(i,0,s.size())
        cout<<s[i]<<" ";
}