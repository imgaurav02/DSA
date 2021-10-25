#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

bool isSmaller(string s1,string s2){
    if(s1.size() < s2.size())
        return true;
    else if(s1.size() > s2.size())
        return false;
    loop(i,0,s1.size())
    {
        if(s1[i] > s2[i])
            return false;
        else if(s1[i] < s2[i])
            return true;
    }
    return false;
}

string getdiff(string s1,string s2){
    if(isSmaller(s1,s2))
        swap(s1,s2);
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int carry = 0;
    string res;
    loop(i,0,s2.size()){
        int temp = (s1[i] - 48) - (s2[i] - 48) - carry;
        if(temp < 0){
            temp +=10;
            carry = 1;
        }
        else    
            carry = 0;
        res.push_back(temp + 48);
    }
    loop(i,s2.size(),s1.size()){
        int temp = (s1[i] - 48) - carry;
        if(temp < 0){
            temp +=10;
            carry = 1;
        }
        else    
            carry = 0;
        res.push_back(temp + 48);
    }
    reverse(res.begin(),res.end());
    return res;
}

string getSum(string s1,string s2)
{
    if(s1.size() < s2.size())
        swap(s1,s2);
    string s;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int carry = 0;
    loop(i,0,s2.size()){
        int temp = (s1[i] - 48) + (s2[i] - 48) + carry;
        if(temp > 9){
            temp -=10;
            carry = 1;
        }
        else 
            carry = 0;
        s.push_back(temp + 48);
    }
    loop(i,s2.size(),s1.size()){
        int temp = (s1[i] - 48) + carry;
        if(temp > 9){
            temp -=10;
            carry = 1;
        }
        else 
            carry = 0;
        s.push_back(temp + 48);
    }
    if(carry != 0)
        s.push_back(carry + 48);
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    INPUT
    OUTPUT
    string s1,s2;
    cin>>s1>>s2;
    // cout<<getdiff(s1,s2)<<endl;
    cout<<getSum(s1,s2);
    return 0;
}