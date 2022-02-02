#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

bool isValid(vector<string> board,int row,int col,int n){
    int dupcol = col,duprow = row;
    while(col >= 0 and row >= 0){
        if(board[row][col] == 'q')
            return false;
        col--;
        row--;
    }
    col = dupcol;
    row = duprow;
    while(col >= 0){
        if(board[row][col] == 'q')
            return false;
        col--;
    }
    col = dupcol;
    row = duprow;
    while(col >= 0 and row < n){
        if(board[row][col] == 'q')
            return false;
        col--;
        row++;
    }
    return true;
}

void NQueen(vector<string> &board,int col,int n){
    if(col == n){
        loop(i,0,n)
            cout<<board[i]<<endl;
        cout<<endl<<endl;
        return;
    }
    loop(i,0,n){
        if(isValid(board,i,col,n)){
            board[i][col] = 'q';
            NQueen(board,col+1,n);
            board[i][col] = '.';
        }
    }
}

int main(){
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vector<string> board(n);
    string s(n,'.');
    loop(i,0,n)
        board[i] = s;
    NQueen(board,0,n);

    return 0;
}