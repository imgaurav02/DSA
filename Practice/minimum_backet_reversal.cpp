#include<bits/stdc++.h>
using namespace std;

int min_reversal(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='}' && !st.empty()){
            if(st.top()=='{')
                st.pop();
            else
                st.push(s[i]);
        }
        else
            st.push(s[i]);
    }

    int len = st.size();
    int res=0;
    while(!st.empty() && st.top() == '{'){
        res++;
        st.pop();
    }
    return (len/2 + res%2);
}

int main(){
    string s;
    // scanf("%[^\n]s",&s);
    cin>>s;
    cout<<min_reversal(s);
}