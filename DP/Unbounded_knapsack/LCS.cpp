#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

/* 
    input : 
    ABCBDAB
    BDCABA
    output :
    ABCB
*/

vector<vi> LCS(string s1,string s2,int m,int n){
    vector<vi> dp(m+1,vi(n+1,0));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }
    return dp;
}

string getLCS(string s1,string s2,int m,int n,vector<vi> &dp){
    int i = m,j = n;
    string res = "";
    while(i > 0 and j > 0){
        if(s1[i - 1] == s2[j - 1]){
            res += s1[i - 1];
            i--;j--;
        }
        else{
            if(dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    // INPUT
    // OUTPUT
    string s1,s2;
    cin >> s1 >> s2;
    vector<vi> dp = LCS(s1,s2,s1.size(),s2.size());
    string res = getLCS(s1,s2,s1.size(),s2.size(),dp);
    cout << res;
    return 0;
}