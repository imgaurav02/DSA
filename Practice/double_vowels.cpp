#include<bits/stdc++.h>
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
string double_vowels(string s){
    string res = "";
    int n = s.size();
    loop(i,0,n){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            res = res +s[i] + s[i];
        else
            res = res + s[i];
    }
    return res;
}

int main(){
    INPUT
    OUTPUT
    string s;
    cin>>s;
    cout<<double_vowels(s);
}