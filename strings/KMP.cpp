#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

vi calculateLPS(string &pattern){
    int m = pattern.size();
    vi lps(m,0);
    lps[0] = 0;
    int prev_ele = 0;
    loop(i,1,m){
        if(pattern[i] == pattern[prev_ele]){
            lps[i] = prev_ele + 1;
            prev_ele++;
        }
        else if(prev_ele == 0){
            lps[i] = 0;
        }
        else{
            prev_ele = lps[prev_ele - 1];
            i--;
        }
    }
    return lps;
}

int isMatching(string &s,string &pattern){
    int n = s.size();
    int m = pattern.size();
    if(m > n) return -1;
    if(m == 0 or n == 0) return -1;
    vi lps = calculateLPS(pattern);
    int i = 0,j = 0;
    while(i < n){
        if(s[i] == pattern[j]){
            i++;j++;
        }
        else if(j == 0){
            i++;
        }
        else{
            j = lps[j - 1];
        }

        if(j == m) return i - m; //returning the index of matching substring which starts from i - m
    }
    return -1; //if no matching substring found
}

int main(){
    INPUT
    OUTPUT
    string s,pattern;
    cin >> s >> pattern;
    int ind = isMatching(s,pattern);
    if(ind == -1) cout << "No matching substring found\n";
    else{
        cout << "Matching substring found at index : " << ind << endl;
    } 

    
    return 0;
}