#include<bits/stdc++.h>
#include<stack>
using namespace std;
void preOrder(char a[]){
        int i=1;
        stack<int> st;
        st.push(0);
        while(a[i]!='\0'){
           cout<<a[i];
           if(a[2*i+1]!='\0'){
             st.push(2*i+1);
           } 
           if(a[i*2]!='\0'){
            i=2*i;
           }
           else{
            i=st.top();
            st.pop();
           }
        }
}
void inOrder(char a[]){
    stack<int> st;
    st.push(0);
    int i=1;

    xxx:
    while(a[i]!='\0'){
        st.push(i);
        i=2*i;
    }
    i=st.top();
    st.pop();
    while(a[i]!='\0'){
        cout<<a[i];
        if(a[2*i+1]!='\0'){
        i=2*i+1;
        goto xxx;
        }
    i=st.top();
    st.pop();
    }


}
void postOrder(char a[]){
int i=1;
stack<int> st;
st.push(0);
xxx:
while(a[i]!='\0'){
st.push(i);
if(a[2*i+1]!='\0'){
    st.push(-(2*i+1));
}
i=2*i;
}
i=st.top();
st.pop();
while(i>0){
    cout<<a[i];
    i=st.top();
    st.pop();
}
if(i<0){
    i=-i;
    goto xxx;
}
}
int main(){
    char a[100];
    for(int i=0;i<100;i++){
        a[i]='\0';
    }
    a[1]='A';
    a[2]='B';
    a[3]='C';
    a[4]='W'; 
    a[6]='P';
    a[7]='S'; 
    a[8]='N';
    a[9]='Q';
    a[13]='Z';
    a[18]='L'; 
    a[19]='M';
    a[26]='X';
    preOrder(a);
    cout<<"\n";
    inOrder(a);
    cout<<"\n";
    postOrder(a);

}