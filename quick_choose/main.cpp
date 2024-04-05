#include<iostream>
using namespace std;
const int N=1e6+10;
int q[N];

void quick_sort(int q[],int l,int r){
    if(l>=r)
        return;
    int x=q[(l+r)>>1],i=l-1,j=r+1;
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j){
            swap(q[i],q[j]);
        }

    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);


}
int quick_choose(int l,int r,int m){
    if(l==r)
        return q[l];
    int x=q[(l+r)>>1],i=l-1,j=r+1;
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j){
            swap(q[i],q[j]);
        }

    }

    int sl=j-l+1;//前半部分的长度
    if(m<=sl)//当所取的部分在前一部分
        return quick_choose(l,j,m);
    else
        return quick_choose(j+1,r,m-sl);


}
int main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    /*
    quick_sort(q,0,n-1);
    printf("%d",q[m-1]);
     */
    cout<<quick_choose(0,n-1,m);
    return 0;



}