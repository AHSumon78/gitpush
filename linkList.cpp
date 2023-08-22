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
class LinkList{
        int element;
        nodeptr head=NULL;
        nodeptr tail=NULL;
        public:
        void insertNode(int data){
            nodeptr newNode=getNode();
            newNode->data=data;
            if(head==NULL){
               head=newNode;
               tail=newNode;
            }
            else{
               tail->next=newNode;
               tail=tail->next;
            }
        }
        nodeptr getHead(){
            return head;
        }
       void insertAfter(int val,int item){
        nodeptr newNode=getNode();
        newNode->data=item;
        nodeptr ptr=head;
               while(ptr->data!=val){
                ptr=ptr->next;
               }
               if(ptr==NULL){
                cout<<"sorry the value is not exist!\n";
                return;
               }
               nodeptr after=ptr->next;
               ptr->next=newNode;
               newNode->next=after;
       }
       void insertFirst(int data){
        nodeptr newNode=getNode();
        newNode->data=data;
        newNode->next=head;
        head=newNode;
       }
       void deleteVal(int val){
        nodeptr prev=NULL;
        nodeptr ptr=head;
               while(ptr->data!=val){
                prev=ptr;
                ptr=ptr->next;
               
               }
               if(ptr==NULL){
                cout<<"sorry the value is not exist!\n";
                return;
               }
               else{
               prev->next=ptr->next;
               free(ptr);
               }
       }
       void sortList(){
        nodeptr i=head,j=head;
        nodeptr k=NULL;
        while(i!=NULL){
            j=head;
            while(j->next!=k){
                if( j->data>j->next->data){
                 int x=j->next->data;
                 j->next->data=j->data;
                 j->data=x;
                }
                 j=j->next;
            }
            k=j->next;
            i=i->next;
        }
       }
       
};
void printList(nodeptr head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    
}
int main(){
    LinkList ll;
      int data;
    cout<<"Enter a list:\n";
     while(cin.peek()!='\n'){
        cin>>data;
        ll.insertNode(data);
     }
     printList(ll.getHead());
     ll.insertFirst(99);
    printList(ll.getHead());
    ll.insertAfter(3,88);
     printList(ll.getHead());
     ll.deleteVal(42);
      printList(ll.getHead());
      ll.sortList();
        printList(ll.getHead());

     

}