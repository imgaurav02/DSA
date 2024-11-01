#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

//print name 5 times
void printName(int cnt){
    if(cnt <= 5)
    {
        cout << "Gaurav" << endl;
        printName(cnt + 1);
    }
}


//print 1 to N
void oneToN(int n){
    if(!n)
        return;
    oneToN(n - 1);
    cout << n << endl;
}

//print N to 1
void NToOne(int n){
    if(!n)
        return;
    cout << n << endl;
    NToOne(n - 1);
}

//sum of n numbers

int sumN(int n){
    if(n == 1) return 1;
    return n + sumN(n - 1);
}

int fact(int n){
    if(n == 1) return 1;
    return n * fact(n - 1);
}


//reverse an array

void RevserArray(vector<int> &arr,int l,int r){
    if(l >= r) return;
    swap(arr[l],arr[r]);
    RevserArray(arr,l + 1,r - 1);
}

//string is palindrome or not?

bool isPalindrome(string s,int l,int r){
    if(l >= r) return true;
    return s[l] == s[r] ? isPalindrome(s,l + 1, r - 1) : false;
}

//permuations

void permutations(int n){
    static vi vis(n,false);
    static string ans;
    if(ans.size() == n){
        cout << ans << endl;
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i - 1]){
            vis[i - 1] = true;
            ans.push_back(i + '0');
            permutations(n);
            vis[i - 1] = false;
            ans.pop_back();
        }
    }
}

int main(){
    INPUT
    OUTPUT
    int n;
    cin >> n;
    permutations(n);
    return 0;
}