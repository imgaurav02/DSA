#include <iostream>
#include <string>
#include<vector>
using namespace std;


int canBeTypedWords(string text, string brokenLetters) {
        vector<string> res;
        string s="";
        int count=0;
        for(int i=0;i<text.size();i++){
             if(text[i]==' '){
                 res.push_back(s);
                 s = "";
             }
            else{
                s +=text[i];
            }
            
        }
        res.push_back(s);
        int check;
        bool flag;
        for(int i=0;i<res.size();i++){
            flag =1;
            for(int j=0;j<brokenLetters.size() && flag;j++){
                check = res[i].find(brokenLetters[j]);
                if(check!=-1){
                    count++;
                    flag =0;
                }
                    
            }
        }
        return count;
    }
int main() {
    string s1 = "hello world";
    string s2 = "ad";
    cout<<canBeTypedWords(s1,s2);
}
