/// spoj yodaness

#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int _merge(int left,int right);

int merge_sort(int left,int right)
{
    int inv_cnt=0;
    if(left<right)
    {
        int mid=(left+right)/2;

        inv_cnt=merge_sort(left,mid);
        inv_cnt+=merge_sort(mid+1,right);

        inv_cnt+=_merge(left,right);
    }
    return inv_cnt;
}

int _merge(int left,int right)
{
    int mid=(left+right)/2,i=left,j=mid+1,t=0,temp[right-left+1],inv_cnt=0;

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
    int i,j,k,l,n,t;
    string st[30005],st1[30005];
    cin>>t;
    map <string,int> mp;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>st[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>st1[i];
            mp[st1[i]]=i;
        }
        for(i=0;i<n;i++)
        {
            arr[i]=mp[st[i]];
        }
        cout<<merge_sort(0,n-1)<<endl;
        mp.clear();
    }

    return 0;
}
