/* 

    Given a word and a text, return the count of the occurrences of 
    anagrams of the word in the text(For eg: anagrams of word for are for, ofr, rof etc.))

    Input : forxxorfxdofr
        for
    Output : 3
    Explanation : Anagrams of the word for - for, orf, 
    ofr appear in the text and hence the count is 3.

    Input : aabaabaa
            aaba
    Output : 4
    Explanation : Anagrams of the word aaba - aaba, 
    abaa each appear twice in the text and hence the
    count is 4.
*/


#include<bits/stdc++.h>
using namespace std;

int countOccurenceAnagram(string s,string pattern){
    map<char,int> m;
    int k = pattern.size();
    int count;
    // for(int i =0; i<k;i++){
    //     if(m.find(pattern[i]) == m.end())
    //         m[pattern[i]] = 1;
    //     else{
    //         m[pattern[i]]++;

    // }
    // OR uuper

    for(int i =0; i<k;i++)
        m[pattern[i]]++;
    count =  m.size();
    int i = 0,j = 0,res = 0;
    while(j<s.size()){
        if(m.find(s[j]) != m.end()){
            m[s[j]]--;
            if(m[s[j]] == 0)
                count--;
        }
        if(j - i +1 <k)
            j++;
        else if(j - i+1 ==k){
            if(!count)
                res++;
            if(m.find(s[i]) != m.end()){
                m[s[i]]++;
                if(m[s[i]] == 1)
                    count++;
            }
            i++;j++;
        }
    }
    return res;
}

int main(){
    string s,pattern;
    cin>>s;
    cin>>pattern;
    cout<<countOccurenceAnagram(s,pattern);
}