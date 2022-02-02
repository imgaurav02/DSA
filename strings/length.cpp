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


//finding duplicates using bits manipulation
void duplicateUsingBits(char s[]){
    /* 
        here we are going to use the logic of bits manipulation
        1-> masking which is and operation  to check weather bit is on or not
        2-> merging which use OR operation  to on the bit using left shift
    */
    
    int hash=0,x=0;
    for(int i=0;s[i] != '\0';i++){
        x = 1;
        x = x<<(s[i]-97);
        if((x&hash)>0){
            cout<<s[i]<<" is diplicate "<<endl;
        }
        else{

            hash = x | hash;
        }
    }
}
// this simple suction according to compare to upper both to find permutations and for knowledge
// i using default argument which assign with given value if u pass otherwise it will be default
void simple_perm(string S,string answer=""){
		    // static vector<string> res;
		    if(S.size()==0){
                cout<<answer<<" ";
		        // res.push_back(answer);
		        // return res;
		    }
		    for(int i=0;i<S.size();i++){
		        char ch = S[i];
		        string LSS = S.substr(0,i);
		        string RSS = S.substr(i+1);
		        string remaining_string = LSS + RSS;
		        simple_perm(remaining_string,answer+ch);
		    }
		    // sort(res.begin(),res.end());
		    // return res;
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
    // gets(s1);
    // gets(s2);
    simple_perm("ABC");
    scanf("%[^\n]s",s1);
    duplicateUsingBits(s1);
    // if(isAnagram(s1,s2))
    //     cout<<"Strings Are anagram";
    // else
    //     cout<<"Strings are not anagram";
    // cout<<s;
    return 0;
}