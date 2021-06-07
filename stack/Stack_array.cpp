#include<bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
private:
    int size;
    int top;
    T *s;
public:
    void push(T x);
    void display();
    T pop();
    T peek(int index);
    int isEmpty();
    int isFull();
    T stackTop();
    Stack(int size){
        this->size = size;
        top =-1;
        s = new T[this->size];
    }
};
template <class T>
T Stack<T>::stackTop(){
    if(isEmpty())
        return -1;
    return s[top];
}

template <class T>
T Stack<T>::peek(int index){
    if(top-index+1<0){
        cout<<"wrong Index";
        return -1;
    }
    return s[top-index+1];
}

template <class T>
int Stack<T>::isEmpty(){
    return top==-1;
}

template <class T>
int Stack<T>::isFull(){
    return top == size-1;
}

template <class T>
void Stack<T>::push(T x){
    if(isFull())
        cout<<"Stack Overflow";
    else{
        top++;
        s[top] =x;
    }
}


template <class T>
T Stack<T>::pop(){
    int x;
    if(isEmpty()){
        cout<<"Stack Underflow";
        return -1;
    }
    else{
        x = s[top];
        top--;
        return x;
    }
}


template <class T>
void Stack<T>::display(){
    for(int i=top;i>=0;i--)
        cout<<s[i]<<" ";
}





int main(){
    Stack<char> st(10);
    int check=1;
    while(check)
    {
        int choice;
        cout<<"\nEnter 1 for push\n";
        cout<<"Enter 2 for pop the element\n";
        cout<<"Enter 3 for display\n";
        cout<<"Enter 4 for peek on particular index of stack\n";
        cout<<"Enter 5 for display the top element of stack \n";
        cout<<"Enter 6 for exit\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            char x;
            cout<<"Enter the value you want push";
            cin>>x;
            st.push(x);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 4:
            int index;
            cout<<"\nEnter the index: ";
            cin>>index;
            cout<<st.peek(index);
            break;
        case 5:
            cout<<st.stackTop();
            break;
        case 6:
            check =0;
            break;
        default:
            break;
        }
    }
    
    return 0;
}