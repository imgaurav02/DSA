#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>
int main(){
    INPUT
    OUTPUT
    string s;
    cin >> s;
    /*
        what is the idea we will be generating the subsequences according to the 2^n 01 basis
     */
    // i << n =  2 ^ n

    for(int i = 0;i < (1 << s.size()) - 1;i++){
        string ans = "";
        for(int j = 0;j < s.size();j++){
            if(i & (1 << j)){
                ans += s[j];
            }
        }
        cout << ans << " ";
    }

    return 0;
}