#include<bits/stdc++.h>
using namespace std;

int len(char s[]){
    int i;
    for(i = 0; s[i]!='\0'; i++);
    return i;
}

//validating a string means there is no special character
int isValid(char s[]){
    for (int i = 0; s[i]!='\0'; i++)
    {
      if(!((s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90) || (s[i]>=48 && s[i]<=57)))
        return 0;
    }
    return 1;
}

void reverse(char s[]){
    int n = len(s),i,j;
    char a[n+1];
    for (i = n-1,j=0; i >=0; i--,j++)
    {
        a[j] = s[i];
    }
        cout<<a;
    
}

void reverse2(char s[]){
    int i=0,j=len(s)-1;
    char temp;
    while (i<=j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;j--;
    }
    cout<<s;
}

// checking weather strings are anagram or not strings should be in lower case

int isAnagram(char s1[],char s2[]){
    int arr[26]={0};
    if(len(s1)==len(s2)){
        for (int i = 0; s1[i]!='\0'; i++)
        {
            if(s1[i]>=97 && s1[i]<=122)
                arr[s1[i]-97]++;
            if(s2[i]>=97 && s2[i]<=122)
                arr[s2[i]-97]--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0)
                return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
    

}

// finding duplicated using hash array string shoulb be in lower case
void duplicate(char s[]){
    int arr[26]={0};
    for (int i = 0; s[i]!='\0'; i++)
    {
        if(s[i]>=97 && s[i]<=122)
        arr[s[i]-97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(arr[i]>1){
            cout<<(char)(i+97)<<" repeated "<<arr[i]<<" Times"<<endl;
        }
    }
    
    
}

int main(){
    char s[20];

    // chaning case of string 
    // for (int i = 0; s[i]!='\0'; i++)
    // {
    //     if(s[i]>=97 && s[i]<=122)
    //         s[i]=s[i]-32;
    //     else if(s[i]>=65 && s[i]<=90)
    //         s[i] = s[i]+32;
    // }
    char s1[20],s2[20];
    gets(s1);
    gets(s2);
    if(isAnagram(s1,s2))
        cout<<"Strings Are anagram";
    else
        cout<<"Strings are not anagram";
    // cout<<s;
    return 0;
}