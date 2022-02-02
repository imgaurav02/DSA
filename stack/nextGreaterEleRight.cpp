#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}
vector<int> solve(vector<int>arr)
{
  //write your code here
  int n = arr.size();
  vector<int> ans(n,0);
  stack<int> st;
  ans[n - 1] = -1;
  st.push(arr[n-1]);
  for(int i = n - 2; i >= 0;i--){
      while(!st.empty() and arr[i] >= st.top()){
        st.pop();
      }
      if(st.empty())
        ans[i] = -1;
      else{
        ans[i] = st.top();
      }
      st.push(arr[i]);
  }
  return ans;
  
}

int main(){
    INPUT
    OUTPUT
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    
    vector<int> ans = solve(arr);
    display(ans);

    return 0;
}