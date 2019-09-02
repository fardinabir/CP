#include <iostream>

using namespace std;

int arr[100000];

int merge_sort(int left,int right)
{
    int inv_cnt=0;
    if(left<right)
    {
        int mid=(left+right)/2;

        inv_cnt=merge_sort(left,mid);
        inv_cnt+=merg_sort(mid+1,right);

        inv_cnt+=_merge(left,right);
    }
    return inv_cnt;
}

int _merge(int left,int right)
{
    int mid,i=left,j=right,t=0,temp[right-left+1];
    mid=(i+j)/2;

    while(a[])
}

int main()
{
    int i,j,k,l,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<merge_sort(0,n-1)<<endl;
    return 0;
}
