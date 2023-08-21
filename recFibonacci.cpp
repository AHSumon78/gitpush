#include<bits/stdc++.h>
using namespace std;
const int DP=1000;
long long int dp[DP];
long long fibo(int N){
    if(dp[N]==-1){
       if(N<=1){
        dp[N]=N;
       
     }
    
    else{
            dp[N]=fibo(N-2)+fibo(N-1);   
    }
     cout<<dp[N]<<" ";
    }
   
     return dp[N];  
}
long long fact(long long n){
    if(n==0||n==1){
        cout<<1;
        return 1;
    }
    cout<<n<<"*";
    return n*fact(n-1);
}
void towerH(int n,char beg,char aux,char end){
    if(n==1){
        cout<<beg<<"->"<<end<<",";
        return;
    }
    towerH(n-1,beg,end,aux);
     cout<<beg<<"->"<<end<<",";
    towerH(n-1,aux,beg,end);
    return;
}
int main(){
    for(int i=0;i<DP;i++){
        dp[i]=-1;
    }
    int n=20;
    fibo(n);
      cout<<"\n\n";
    long long int x=fact(20);
     cout<< "="<<x;
    while(1){
  int n;
  cin>>n;
    towerH(n,'A','B','C');
       cout<<"\n\n";
    }
  
}