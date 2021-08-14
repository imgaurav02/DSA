#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top;
        int size;
        char *s;
};

void display(Stack *st){
    for(int i=st->top;i>-1;i--)
        cout<<st->s[i]<<" ";
    cout<<endl;
}
void push(Stack *st,char ch){
    if(st->top == st->size-1){
        cout<<"Over";
    }
    else{
        st->top++;
        st->s[st->top] = ch;
    }
}
char pop(Stack *st){
    char x;
    x = st->s[st->top];
    st->top--;
    return x;
}

int isBalanced(string s){
    Stack st;
    st.top =-1;
    st.size = s.length();
    st.s = new char[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')
            push(&st,s[i]);
        else if(s[i]==')')
        {
            if(st.top == -1)
                return 0;
            pop(&st);
        }
    }
    if(st.top==-1)
        return 1;
    return 0;
}

int isBalanced2(string s){
    Stack st;
    st.top =-1;
    st.size = s.length();
    st.s = new char[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='('  or s[i]=='{' or s[i]=='[')
            push(&st,s[i]);
        else if(s[i]==')'or s[i]=='}' or s[i]==']')
        {
            if(st.top == -1 or s[i]-st.s[st.top]>2 or s[i]-st.s[st.top]<1)
            {
                return 0;
            }
            pop(&st);
        }
    }
    if(st.top==-1)
        return 1;
    return 0;
}

int priority(char ch){
    if(ch=='-' or ch == '+')
        return 1;
    if(ch=='*' or ch=='/')
        return 2;
}

int isOprator(char ch){
    if(ch =='+' or ch =='-' or ch =='*' or ch=='/')
        return 1;
    return 0;
}

char * IntoPo(char *s){
    Stack st;
    st.size = strlen(s);
    st.top= -1;
    st.s = new char[strlen(s)];
    char *r;
    r = new char[strlen(s)+1];
    int i=0,j=0;
    while(s[i] != '\0'){
        if(isOprator(s[i])){
           if(st.top==-1 or priority(s[i])>priority(st.s[st.top])){
                push(&st,s[i]);
                i++;
           }
            else{
                r[j] = pop(&st);
                // cout<<r[j];
                j++;
            }
        }
    
        else{
            r[j] = s[i];
            i++;j++;
        }
        // display(&st);
        
    }
    while(st.top!=-1)
        r[j++]=pop(&st);
    r[j] = '\0';
    return r;
}


// evaluating postfix expression
int EvalPostfix(char *postfix){
    Stack st;
    st.size = strlen(postfix);
    st.top= -1;
    st.s = new char[strlen(postfix)];
    int i=0,x1,x2;
    while (postfix[i] !='\0')
    {
        if(isOprator(postfix[i])){
            x2 = pop(&st);
            x1 = pop(&st);
            switch (postfix[i])
            {
            case '+':
                push(&st,(x1+x2));
                break;
            case '-':
                push(&st,(x1-x2));
                break;
            case '*':
                push(&st,(x1*x2));
                break;
            case '/':
                push(&st,(x1/x2));
                break;
            
            default:
                break;
            }
        }
        else{
            push(&st,postfix[i]-'0');
        }
        i++;
    }
    return pop(&st);  
}