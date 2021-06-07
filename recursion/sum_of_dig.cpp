#include<bits/stdc++.h>
using namespace std;
int SOD(int n){
    static int s=0;
    if(n==0)
        return 0;
    s = n%10 + SOD(n/10);
    return s;
}
int main(int argc, char const *argv[])
{
    cout<<SOD(245);
    return 0;
}
