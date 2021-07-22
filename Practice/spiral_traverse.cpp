#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n],i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    for( i=0;i<m;i++){
        for( j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int min_r = 0;
    int min_c = 0;
    int max_r = m-1;
    int max_c = n-1;
    int total_elements = m*n;
    int count = 0;
    while(count<total_elements){

        // left
        for(i = min_r,j=min_c;i <=max_r && count<total_elements;i++){
            cout<<a[i][j]<<" ";
            count++;
        }
        min_c++;
        // bottom
        for(i = max_r,j=min_c;j <=max_c && count<total_elements ;j++){
            cout<<a[i][j]<<" ";
            count++;
        }
        max_r--;
        // right
        for(i = max_r,j=max_c;i >= min_r && count<total_elements ;i--){
            cout<<a[i][j]<<" ";
            count++;
        }
        max_c--;
        // top
        for(i = min_r,j=max_c;j >=min_c && count<total_elements ;j--){
            cout<<a[i][j]<<" ";
            count++;
        }
        min_r++;
    }
    return 0;
}