

#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

int longest_k_unique_substr(string s,int n,int k){
    int i = 0, j = 0;
    map<string,int> m;
    int maxi = INT_MIN;
    while(j<n){
        m[s.substr(j,1)]++;
        if(m.size() == k){
            maxi = max(maxi,j-i+1);
        }
        else if(m.size() > k){
            while(m.size() > k){
                m[s.substr(i,1)]--;
                if(m[s.substr(i,1)] == 0)
                    m.erase(s.substr(i,1));
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
    cout<<longest_k_unique_substr(s,s.size(),k);
    return 0;
}