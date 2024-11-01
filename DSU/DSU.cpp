#include<bits/stdc++.h>

using namespace std;

int find(int a,vector<int> &parent){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a],parent);
}

void Union(int a,int b,vector<int> &size,vector<int> &parent){
    int parent_a = find(a,parent);
    int parent_b = find(b,parent);

    if(parent_a == parent_b) return;

    if(size[parent_b] > size[parent_a]){
        swap(parent_a,parent_b);
    }
    parent[parent_b] = parent[parent_a];
    size[parent_a] += size[parent_b];
}

int main(){
    int n;
    cin >> n;
    cout << "hello" << endl;
    vector<int> arr(n + 1),size(n+1,1);
    for(int i = 0;i <= n;i++)
    {
        arr[i] = i;
    }
    Union(1,2,size,arr);
    Union(2,3,size,arr);
    cout << find(2,arr) << " " << find(3,arr) << " " << size[1] << " " << size[2];
}