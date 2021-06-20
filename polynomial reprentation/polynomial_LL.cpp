#include<bits/stdc++.h>
using namespace std;

class Polynomial
{
public:
    int coeff;
    int pow;
    Polynomial *next;
};

Polynomial *first=NULL;
Polynomial *firstLast=NULL;
Polynomial *second=NULL;
Polynomial *secondLast=NULL;

void createFirst(int c,int p){
    Polynomial *temp = new Polynomial;
    temp->coeff = c;
    temp->pow = p;
    temp->next = NULL;
    if(first==NULL){
        first = firstLast = temp;
    }
    else{
        firstLast->next = temp;
        firstLast = temp;
    }

}
void createSecond(int c,int p){
    Polynomial *temp = new Polynomial;
    temp->coeff = c;
    temp->pow = p;
    temp->next = NULL;
    if(second==NULL){
        second = secondLast = temp;
    }
    else{
        secondLast->next = temp;
        secondLast = temp;
    }

}
// void createThird(int c,int p){
//     Polynomial *temp = new Polynomial;
//     temp->coeff = c;
//     temp->pow = p;
//     temp->next = NULL;
//     if(third==NULL){
//         third = thirdLast = temp;
//     }
//     else{
//         thirdLast->next = temp;
//         thirdLast = temp;
//     }

// }

void copypoly(Polynomial* r,
              Polynomial** copy)
{
    // Copy the values of r in the
    // polynomial copy
    while (r != NULL) {
  
        Polynomial* z= new Polynomial;
  
        // Store coeffcient and power
        z->coeff = r->coeff;
        z->pow = r->pow;
        z->next = NULL;
  
        Polynomial* dis = *copy;
        if (dis == NULL) {
            *copy = z;
        }
        else {
            while (dis->next != NULL) {
                dis = dis->next;
            }
            dis->next = z;
        }
        r = r->next;
    }
}

void store_quotient(int mul_c, int diff,Polynomial *quo)
{
    // Till quo is non-empty
    while (quo->next != NULL) {
        quo = quo->next;
    }
  
    // Update powers and coefficient
    quo->pow = diff;
    quo->coeff = mul_c;
    quo->next = new Polynomial;
    quo = quo->next;
    quo->next = NULL;

}
void formNewPoly(int diff, float mul_c,
                Polynomial* poly)
{
    // Till poly is not empty
    while (poly->next != NULL) {
        poly->pow += diff;
        poly->coeff *= mul_c;
        poly = poly->next;
    }
}

void polySub(Polynomial* poly1,Polynomial* poly2,Polynomial* poly)
{
  
    // Compute until poly1 and poly2 is empty
    while (poly1->next && poly2->next) {
  
        // If power of 1st polynomial
        // > 2nd, then store 1st as
        // it is and move its pointer
        if (poly1->pow > poly2->pow) {
  
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
            poly->next = new Polynomial ;
            poly = poly->next;
            poly->next = NULL;
        }
  
        // If power of 2nd polynomial >
        // 1st then store 2nd as it is
        // and move its pointer
        else if (poly1->pow < poly2->pow) {
  
            poly->pow = poly2->pow;
            poly->coeff = -1 * poly2->coeff;
            poly2 = poly2->next;
            poly->next = new Polynomial ;
            poly = poly->next;
            poly->next = NULL;
        }
  
        // If power of both polynomial
        // is same then subtract their
        // coefficients
        else {
  
            if ((poly1->coeff
                 - poly2->coeff)
                != 0) {
  
                poly->pow = poly1->pow;
                poly->coeff = (poly1->coeff- poly2->coeff);
  
                poly->next = new Polynomial ;
                poly = poly->next;
                poly->next = NULL;
            }
  
            // Update the pointers
            // poly1 and poly2
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
  
    // Add the remaining value of polynomials
    while (poly1->next || poly2->next) {
  
        // If poly1 exists
        if (poly1->next) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
  
        // If poly2 exists
        if (poly2->next) {
            poly->pow = poly2->pow;
            poly->coeff = -1 * poly2->coeff;
            poly2 = poly2->next;
        }
  
        // Add the new node to poly
        poly->next = new Polynomial ;
        poly = poly->next;
        poly->next = NULL;
    }
}

void display(Polynomial *p){
    while (p)
    {
        cout<<p->coeff<<"x^"<<p->pow<<" ";
        p = p->next;
    }

}
void divide(Polynomial *f,Polynomial *s){
    Polynomial *rem = NULL,*quotient=NULL;
    quotient = new Polynomial;
    quotient->next = NULL;
    Polynomial *q=NULL;
    Polynomial *r=NULL;
    copypoly(f, &q);
    copypoly(s, &r);

    while (q != NULL
           && (q->pow >= s->pow)) {
  
        // difference of power
        int diff = q->pow - s->pow;
  
        int mul_c = (q->coeff/ s->coeff);
  
        store_quotient(mul_c, diff,
                       quotient);
  
        Polynomial* q2 = NULL;
  
        copypoly(r, &q2);
  
        formNewPoly(diff, mul_c, q2);
  
        Polynomial *store = NULL;
        store = new Polynomial;
  
        // Perform polynomial subtraction
        polySub(q, q2, store);
  
        // Now change value of q to the
        // subtracted value i.e., store
        q = store;
        delete q2;
    }

    // Print the quotient
    cout << "Quotient: ";
    display(quotient);
  
    // Print the remainder
    cout << "Remainder: ";
    rem = q;
    display(rem);

}


int main(){
    int c,p;
    int terms;
    cout<<"How Many terms in Dividend polynomial: ";
    cin>>terms;
        while(terms--){
            cout<<"Enter the term: ";
            cin>>c>>p;
            createFirst(c,p);
        }
    cout<<"How Many terms in divisor polynomial: ";
    cin>>terms;
        while(terms--){
            cout<<"Enter the term: ";
            cin>>c>>p;
            createSecond(c,p);
        }

    divide(first,second);
    return 0;
}