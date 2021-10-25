#include<bits/stdc++.h>
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
using namespace std;


bool isPalindrome(string s,int low,int high){
    while(low<=high){
        if(s[low] != s[high])
            return 0;
        low++;
        high --;
    }
    return 1;
}
string LongestPalindrome(string s,int n){
   int max = INT_MIN;
   int start;
   for(int i  = 0;i<n;i++){
       for(int j = i;j<n;j++){
           if(isPalindrome(s,i,j)){
               if(j-i+1>max){
                   max = j - i +1;
                   start = i;
               }
           }
       }
   }
    return s.substr(start,max);
   
}

int main(){
    INPUT
    OUTPUT
    string s;
    cin>>s;
    int n = s.size();
    cout<<LongestPalindrome(s,n);
    return 0;
}