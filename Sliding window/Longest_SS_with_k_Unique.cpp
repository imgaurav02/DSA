/*
    Find the longest substring with k unique characters in a given string
    Given a string you need to print longest possible substring that has exactly K unique characters. 
    If there are more than one substring of longest possible length, then print any one of them.

    "aabbcc", k = 1
    Max substring can be any one from {"aa" , "bb" , "cc"}.

    "aabbcc", k = 2
    Max substring can be any one from {"aabb" , "bbcc"}.

    "aabbcc", k = 3
    There are substrings with exactly 3 unique characters
    {"aabbcc" , "abbcc" , "aabbc" , "abbc" }
    Max is "aabbcc" with length 6.

    "aaabbb", k = 3
    There are only two unique characters, thus show error message. 
 */


#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

int solve(string s,int n,int k){
    map<char,int> m;
    int maxi = INT_MIN;
    int i = 0,j = 0;
    while(j < n){
        m[s[j]]++;
        if(m.size() == k){
            maxi = max(maxi,j-i+1);
        }
        else if(m.size() > k){
            while(m.size() > k){
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return maxi;
}

int main(){
    INPUT
    OUTPUT
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<solve(s,s.size(),k);
    return 0;
}