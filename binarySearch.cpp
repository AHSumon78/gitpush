#include<bits/stdc++.h>
using namespace std;
void binarySearch(int a[],int n,int item){
    int start=0;
    int end=n;
    int mid=(start+end)/2;
    while(start<=end && a[mid]!=item){
     if(a[mid]<item){
        start=mid;
     }
     else{
        end=mid-1;
     }
      mid=(start+end)/2;
    }
    if(a[mid]==item){
        cout<<item <<" found at index "<<mid<<endl;
    }
    else{
        cout<<"Not found!\n";
    }
}
int main(){
    int a[10]={3,2,75,8,9,23,4};
    sort(a,a+7);
 
    binarySearch(a,7,75);

}