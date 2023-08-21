#include<bits/stdc++.h>
using namespace std;
class hashx{
    string a[10000];
    int table;
     public:
    hashx(){
        table=0;
        for(int i=0;i<29;i++){
            a[i]="\0";
        }
    }
   
    void setTable(int val){
      table=val;
    }
    void insertx(string s){
      int i=folding(s);
      if(!a[i].compare("\0"))
      a[i]+=s;
      else{
      i++;
      while(a[i].compare("\0")){
       i++;
      }
      a[i]+=s;
      }
    }
    void display(){
        for(int i=0;i<table;i++){
            if(a[i].compare("\0")!=0)
            cout<<a[i];
            else 
            cout<<"-";
            if(i<table-1){
                cout<<",";
            }
        }
    }
    void search(string val){
        int i=folding(val);
        if(a[i].compare(val)==0){
            cout<<"success index :"<<i<<"\n";
        }
        else if(a[i].compare("\0")==0){
            cout<<val<<" is not found!\n";
        }
        else{
            i++;
            while(a[i].compare(val)!=0){
                if(a[i].compare("\0")==0){
                    cout<<val<<" is not found!\n";
                    return;
                }
                i++;
            }
            cout<<"collision! "<<a[i]<<"\n";

        }
    }
    private:
     int  folding(string s){
        int l=s.length()+1;
        l=l/2;
        int sum=0;
        int i=0;
        while(l--){
            sum+=stoi(s.substr(i,2));
            i+=2;
        }
       return (sum%table);
    }
      
};
int main(){
       hashx st;
       cout<<"Enter table value: ";
       int x;
       cin>>x;
       st.setTable(x);
       cout<<"Enter number to the hash table for end press enter:\n";
     string s="\0";
    while(cin.peek()!='\n' || s.compare("\0")==0){
      
        cin>>s;
        st.insertx(s);
    }
    st.display();
    cout<<"\nEnter which value do you want to search:\n";
    string val;
    cin>>val;
    st.search(val);

     
}