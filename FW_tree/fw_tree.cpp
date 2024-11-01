#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

class FW_tree{
    vi fw_tree;
    vi og_arr;
    int n;
    int get_sum(int idx){
        int sum = 0;
        while(idx > 0){
            sum += fw_tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    public:
    FW_tree(int n,vi og_arr){
        this -> n = n;
        fw_tree.resize(n+1,0);
        this -> og_arr = og_arr;
    }

    void create(){
        loop(i,1,n+1){
            int val = og_arr[i - 1];
            int og_idx = i;
            while(og_idx <= n){
                fw_tree[og_idx] += val;
                og_idx += (og_idx & -og_idx);
            }
        }
    }

    void print(){
        cout << "OG array : ";
        loop(i,0,n) cout << og_arr[i] << " ";
        cout << endl << "FW Tree : ";
        loop(i,1,n+1) cout << fw_tree[i] << " ";
        cout << endl;
    }


    int get_range_sum(int start,int end){
        if(start < 0 and end >= n) return -1; //checking if start & end are valid
        return (get_sum(end + 1) - get_sum(start));
    }

    void update_val(int idx,int value){
        if(idx < 0 or idx >= n) return;
        int diff = value - og_arr[idx];
        og_arr[idx] = value;
        idx++;
        while(idx <= n){
            fw_tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
    
};

int main(){
    INPUT
    OUTPUT
    int n;
    cin >> n;
    vi arr(n);
    loop(i,0,n) cin >> arr[i];
    FW_tree fw(n,arr);
    fw.create();
    fw.print();
    cout << fw.get_range_sum(2,6) << endl;
    fw.update_val(2,3);
    fw.print();
    cout << fw.get_range_sum(2,6) << endl;
    return 0;
}