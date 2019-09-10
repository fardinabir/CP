/// spoj INVCNT

#include <bits/stdc++.h>

using namespace std;

long long int arr[300000];

long long int _merge(int left,int right);

long long int merge_sort(int left,int right)
{
    long long int inv_cnt=0;
    if(left<right)
    {
        int mid=(left+right)/2;

        inv_cnt=merge_sort(left,mid);
        inv_cnt+=merge_sort(mid+1,right);

        inv_cnt+=_merge(left,right);
    }
    return inv_cnt;
}

long long int _merge(int left,int right)
{
    int mid=(left+right)/2,i=left,j=mid+1,t=0,temp[right-left+1];
    long long int inv_cnt=0;

    while(i<=mid && j<=right)
    {
        if(arr[i]>arr[j])
        {
            inv_cnt+=(mid-i+1);
            temp[t++]=arr[j++];
        }
        if(arr[i]<arr[j])
        {
            temp[t++]=arr[i++];
        }
    }
    while(i<=mid)
    {
        temp[t++]=arr[i++];
    }
    while(j<=right)
    {
        temp[t++]=arr[j++];
    }
    for(i=left;i<=right;i++)
        arr[i]=temp[i-left];

    return inv_cnt;
}

int main()
{
    long long int i,j,k,l,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<merge_sort(0,n-1)<<endl;
    }

    return 0;
}
/*
2

3
3
1
2

5
2
3
8
6
1

*/
