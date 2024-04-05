#include<iostream>
using namespace std;
const int N = 1e6+1;
int p[N];
int main()
{
    int n,q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i ++ ){
        scanf("%d", &p[i]);
    }

    while(q--){
        int x;
        scanf("%d",&x);
        int l=0,r=n-1;

        while(l<r){
            int mid=(l+r)>>1;
            if(p[mid]>=x) r=mid;
            else l=mid+1;
        }
        //q[l]是第一个>=x的数
        //先判断x是否存在，存在l即为左边界
        //在找右边界
        if(p[l]!=x){
            cout<<"-1 -1"<<endl;
        }
        else{
            cout << l<<" ";

            int l=0,r=n-1;
            while(l<r){

                int mid=(l+r+1)>>1;
                if(p[mid]<=x) l=mid;
                else r=mid-1;
            }

            cout << l<<endl;

        }
    }
    return 0;
}

