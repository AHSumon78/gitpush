#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
typedef struct node *nodeptr;
nodeptr getNode(){
    nodeptr p=(nodeptr)malloc(sizeof(struct node));
    p->next=NULL;
    return p;
}
int main(){
    nodeptr linkA,linkB;
    cout<<"Enter 1st LinkList:\n";
    int data;
    cin>>data;
    linkA=getNode();
    linkA->data=data;
    nodeptr ptr=linkA;
    while(cin.peek()!='\n')
    {
        cin>>data ;
      ptr->next=getNode();
      ptr=ptr->next;
      ptr->data=data;
    }
    nodeptr endA=ptr;
    ptr=linkA;
    cout<<"You have entered the 1st List:\n";
    while(ptr!=endA->next)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

    cout<<"\n\nEnter 2nd LinkList:\n";
    data =0;
    
    cin>>data;
    linkB=getNode();
    linkB->data=data;
    ptr=linkB;
   
    while(cin.peek()!='\n')
    {
        cin>>data ;
      ptr->next=getNode();
      ptr=ptr->next;
      ptr->data=data;
    }
    nodeptr endB=ptr;
    ptr=linkB;
    cout<<"You have entered the 2nd List:\n";
    while(ptr!=endB->next)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

    cout<<"\n\nMarging ListA and ListB:\n";
    endA->next=linkB;
        ptr=linkA;
    while(ptr!=endB->next)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }


}