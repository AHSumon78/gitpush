#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cout<<"Enter row :";
    cin>>x;
    int A[x][x];
    int B[x*(x+1)/2];
    for(int i=0;i<x;i++){
       for(int j=0;j<x;j++){
             cin>>A[i][j];
       }
    }
    int k=0;
       for(int i=0;i<x;i++){
       for(int j=0;j<x;j++){
             if(A[i][j]!=0){
                B[k]=A[i][j];
                  k++;
             }
       }
    }
    int i,j;
    cin>>i>>j;
    int l=(i-1)*i/2;
    if(i<j){
        cout<<"0 ";
    }
    else{
        cout<<B[l+j]<<"\n";
    }
    int r;
    cout<<"which row to print :";
    cin>>r;
    r-=1;
    int c=r+1;
    r=r*(r+1)/2;
    for(int i=r;i<r+x;i++){
             if(c>0)
            cout<<B[i]<<" ";
             else
             cout<<"0 ";
             c--;

    }


    
}