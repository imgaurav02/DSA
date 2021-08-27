#include <iostream>
using namespace std;
bool isValid(string s1,int n){
    for(int i =0;i<n;i++){
        if(!((s1[i]>=97 and s1[i]<=122) or (s1[i]>=65 and s1[i]<=90) or s1[i] == ' ' or s1[i] == ','))
            return 0;
    }
    return 1;
}
string encoding(string s1,int n){
    string str = "";
    for(int i=0;i<n;i++){
        if(s1[i]>=97 and s1[i]<=122){
            char t = s1[i]+5;
            if(t>122)
                str += (t-26);
            else
                str += t;
        }
        else if((s1[i]>=65 and s1[i]<=90)){
            char t = s1[i]+5;
            if(t>90)
                str += (t-26);
            else
                str += t;
        }
        else{
            str += s1[i];
        }
    }
    return str;
}
string decoding(string s1,int n){
    string str = "";
    for(int i=0;i<n;i++){
        if(s1[i]>=97 and s1[i]<=122){
            char t = s1[i]-5;
            if(t<97)
                str += (t+26);
            else
                str += t;
        }
        else if((s1[i]>=65 and s1[i]<=90)){
             char t = s1[i]-5;
            if(t<65)
                str += (t+26);
            else
                str += t;
        }
        else{
            str += s1[i];
        }
    }
    return str;
}
int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    if(isValid(s1,s1.size()) && isValid(s2,s2.size())){
        cout<<encoding(s1,s1.size())<<endl;
        cout<<decoding(s2,s2.size())<<endl;
    }
    else{
        cout<<"INVALID INPUT";
    }
}