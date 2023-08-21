#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *list;
    moreEdge *nextEdge;
};
typedef struct node *nodeptr;
struct moreEdge{
    node *edge;
    moreEdge *nextEdge;
};
typedef struct moreEdge *edgeptr;
nodeptr getNode(){
    nodeptr p=(nodeptr)malloc(sizeof(struct node));
    p->list=NULL;
    p->nextEdge=NULL;
    return p;
}

edgeptr getEdge(){
    edgeptr p=(edgeptr)malloc(sizeof(struct moreEdge));
}
void addNode(nodeptr a,nodeptr b){
   a->list=b;
}
void addEdge(nodeptr a,nodeptr b){
    if(a->nextEdge==NULL){
        edgeptr p=getEdge();
        p->edge=b;
        a->nextEdge=p;
    }
    else{
        edgeptr p=a->nextEdge;
        while(p->nextEdge!=NULL){
            p=p->nextEdge;
        }
        edgeptr x=getEdge();
        x->edge=b;
        p->nextEdge=x;
    }
}
void displayAdjecency(nodeptr a){
    nodeptr ptr=a;
    while(ptr!=NULL){
        cout<<ptr->data<<": ";
        if(ptr->nextEdge!=NULL){
            edgeptr eptr=ptr->nextEdge;
            while(eptr!=NULL){
                cout<<eptr->edge->data<<" ";
                eptr=eptr->nextEdge;
            }
        }
        cout<<"\n";
        ptr=ptr->list;
       
    }
}
int main(){
    int n;
    cout<<"Enter Number of Node N: ";
    cin>>n;
         nodeptr arr[5];
         cout<<"Enter node data\n";
         for(int i=0;i<n;i++){
            arr[i]=getNode();
            cout<<"\n node data for "<<i+1<<" :";
            cin>>arr[i]->data;
            addNode(arr[i-1],arr[i]);
         }

         cout<<"Enter Adjecency List:\n";
         for(int i=0;i<n;i++){
             cout<<"For "<<arr[i]->data<<": ";
             edgeptr eptr=arr[i]->nextEdge;
             while(cin.peek()!='\n'){
                 int data;
                 cin>>data;
                 edgeptr c=getEdge();
                 eptr->nextEdge=c;
                 c->edge=arr[data-'A'];
                 eptr=eptr->nextEdge;
             }
         }

}