#include<bits/stdc++.h>
using namespace std;
class Term{
    public:
    int cof;
    int exp;
};
class polynomial{
    public:
    int n;
    Term *t;
};
void addition(polynomial p1,polynomial p2){
    polynomial p3;
    p3.n=p1.n+p2.n;
    p3.t = new Term[p3.n];
    int i,j,k,check=0;
    i=j=k=0;
    while (i<p1.n && j<p2.n)
    {
        if(p1.t[i].exp>p2.t[j].exp){
            p3.t[k++] = p1.t[i++];
            check++;
        }
        else if(p1.t[i].exp<p2.t[j].exp){
            p3.t[k++] = p2.t[j++];
            check++;
        }
        else {
            p3.t[k].cof = p1.t[i].cof + p2.t[j].cof;
            p3.t[k++].exp = p1.t[i++].exp + p2.t[j++].exp;
            check++;
        }
    }
    for (i = 0; i < check; i++)
    {
        cout<<p3.t[i].cof<<"x^"<<p3.t[i].exp<<"+";
    }
    
}
int main()
{
    polynomial p1,p2;
    cout<<"how many terms in 1st polynomial: ";
    cin>>p1.n;
    p1.t = new Term[p1.n];
    for (int i = 0; i < p1.n; i++)
    {
        cout<<"Enter the coefficient and exponent of "<<i+1<<" Term: ";
        cin>>p1.t[i].cof;
        cin>>p1.t[i].exp;
    }
    cout<<"\nhow many terms in 2nd polynomial: ";
    cin>>p2.n;
    p2.t = new Term[p2.n];
    for (int i = 0; i < p2.n; i++)
    {
        cout<<"Enter the coefficient and exponent of "<<i+1<<" Term: ";
        cin>>p2.t[i].cof;
        cin>>p2.t[i].exp;
    }
   addition(p1,p2);
    
    return 0;
}