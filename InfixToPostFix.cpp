//Using inbuilt stack library to create stack
#include <iostream>
#include<math.h>
using namespace std;
class stack{
        char str[100];
        int TOP=-1;
        public:
        char top(){
            return str[TOP];
        }
        void push(char a){
            TOP+=1;
            str[TOP]=a;
        }
        void pop(){
            if (TOP!=-1){
                TOP-=1;
            }
        }
        bool empty(){
            if(TOP==-1)
            return true;
            else 
            return false;
        }
};
int priority (char alpha){
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
 
    if(alpha == '^')
        return 3;

 
    return 0;
}
string convert(string infix)
{
    int i = 0;
    string postfix = "";
    // using inbuilt stack< > from C++ stack library
    stack s;

    while(infix[i]!='\0')
    {
        // if operand add to the postfix expression
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z'||infix[i]>='0' && infix[i]<='9')          
        {
            postfix += infix[i];
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i]==')')
        {
            while(s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.empty() && priority(infix[i]) <= priority(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }


    cout << "Postfix is : " << postfix; //it will print postfix conversion  
    return postfix;
}
 double operation(int a,int b,char op){
    switch (op)
    {
    case '-':
         return a-b;
        break;
    case '+':
         return a+b;
        break;
    case '*':
         return a*b;
        break;
     case '/':
         return a*(1.0)/b;
             break;
     case '^':
         return pow(a,b);
        break;
    
    default:
       cout<<"invalid OP!\n";
        return -1;
        break;
    }
 }
double postFixEvaluation(string s){
      stack st;
      int i=0;
      //s[i]>='a' && s[i]<='z'|| s[i]>='A'&& s[i]<='Z'||s[i]>='0' && s[i]<='9'
      while(s[i]!='\0'){
         if(s[i]>='a' && s[i]<='z'|| s[i]>='A'&& s[i]<='Z'){
            cout<<"Set value for "<<s[i]<<": ";
            int x;
            cin>>x;
            st.push(x);
            i++;
        }
        else if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
            i++;
        }
        else{
             int b=st.top();
             st.pop();
             int a=st.top();
             st.pop();
             st.push(operation(a,b,s[i]));
             i++;
            }
      }
      return st.top();
}
int main()
{
    string infix ;
    cin>>infix;
    string postfix;
    postfix = convert(infix);
    cout<<"\n";
    cout<< postFixEvaluation(postfix);
    ////KL+MN*-OP^W*U/V/T*+Q+
    ////KL+MN∗−OPW∗U/V/T∗+Q+///KL+MN*-OP^W*U/V/T*+Q+
    return 0;
}