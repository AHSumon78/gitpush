#include<bits/stdc++.h>
using namespace std;
int tree[1000];
int i=1;
void inOrder(int root){
    if(tree[root]==INT16_MAX){
        return;
    }
     inOrder(2*root);
     cout<<tree[root]<<" ";
     inOrder(2*root+1);
}
void insert(int val){
    int i=1;
 while(tree[i]!=INT16_MAX){
    if(val<tree[i]){
      i=2*i;
    }
    else{
       i=2*i+1;
      }
 }
 tree[i]=val;
}
int main(){
for(int i=0;i<1000;i++){
    tree[i]=INT16_MAX;
}
 while(cin.peek()!='\n'){
    int x;
    cin>>x;
    insert(x);
 }
 inOrder(1);
}