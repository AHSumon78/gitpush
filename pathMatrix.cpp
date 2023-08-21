#include<bits/stdc++.h>
using namespace std;
class matrix{
       private:
       int node=0;
       int a[10][100][100];
       public:
    void setNode(int n){
        node=n;
    }
    void inputMatrix(){
        cout<<"Enter adjecent matrix:\n";
        for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){
               cin>>a[0][i][j];
            }
        }
    }
    void calPathMatrixB(){
       for( int k=1;k<node;k++){
        for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){
                int sum=0;
                for(int c=0;c<node;c++){
                  sum+=a[0][i][c]*a[k-1][c][j];
                }
                a[k][i][j]=sum;
                sum=0;
            }
        }
       }
       int B[100][1000];
       bool connected=true;
           for (int i=0;i<node;i++){
            for(int j=0;j<node;j++){
               for(int k=0;k<node;k++){ 
                B[i][j]+=a[k][i][j];
            }
            if(B[i][j]==0){
                connected=false;
            }
               printf("%5.1d",B[i][j]);
           }
           cout<<"\n";
       }
       if(connected==true)
       cout<<"\nstrongly";
       else
       cout<<"\nweekly";
       cout<<" connected!";

    }
    void calculatePathMatrix(){
          for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){
               if(a[0][i][j]==0){
                a[0][i][j]=INT16_MAX;
               }
            }
        }
        for(int k=1;k<node;k++){
            for(int i=0;i<node;i++){
                for(int j=0;j<node;j++){
                    a[k][i][j]=min(a[k-1][i][j],a[k-1][i][k]+a[k-1][k][j]);
                }
            }
        }

         for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){
               if(a[node-1][i][j]==INT16_MAX){
                 a[node-1][i][j]=0;
                }
                printf("%5d",a[node-1][i][j]);
            }
            cout<<"\n";
        }
    }
};
int main(){
          cout<<"Enter Node:";
          int m;
          cin>>m;
          matrix mt;
          mt.setNode(m);
          mt.inputMatrix();
          cout<<"\n\n";
          mt.calPathMatrixB();
          cout<<"\n\n";
          mt.calculatePathMatrix();
         
          return 0;
}