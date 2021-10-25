/* Given a sorted array and find the given element
    Let us consider an array arr = {1, 5, 7, 8, 13, 19, 20, 23, 29}.
     Find the location of the item 23 in the array.
 */

 #include<bits/stdc++.h>
 using namespace std;
 #define INPUT freopen("input.txt","r",stdin);
 #define OUTPUT freopen("output.txt","w",stdout);
 #define loop(i,a,b) for(int i = a;i<b;i++)
 #define looprev(i,a,b) for(int i = a;i>=b;i--)
 #define mid(l,r) (l+(r-l)/2)
 #define ll long long int
 #define vi vector<int>
 int main(){
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vector<int> arr(n);
    loop(i,0,n)
        cin>>arr[i];
    int key;
    cin>>key;
    int l = 0,h = n-1;
    while(l<=h){
        int m = mid(l,h);
        if(arr[m] == key){
            cout<<"Found at index : " << m<<endl;
            return 0;
        }
        else if(arr[m] > key)
            h = m - 1;
        else
            l = m + 1;
    }
    cout<<"Not Found";
    return 0;
 }