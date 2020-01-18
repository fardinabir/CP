/// I am nobody, dust I was and dust I will be...

/// SPOJ DQUERY,ac

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int arr[1000005],freq[1000005],block,cnt;

struct st
{
    int first,second,index;
};

bool cmp(st a,st b)
{
    if(a.first/block!=b.first/block)
        return a.first<b.first;
    return a.second<b.second;
}

void remv(int index)
{
    freq[arr[index]]--;
    if(freq[arr[index]]==0)
        cnt--;
}

void add(int index)
{
    freq[arr[index]]++;
    if(freq[arr[index]]==1)
        cnt++;
}

int main() {
    int i,j,q,k,f=0,l,m,n,t=1,c=INT_MAX,x=0,y=0,z;
    scanf("%d",&n);
    block=sqrt(n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&q);
    st pi[q];
    int ans[q];
    i=0;
    while(i<q)
    {
        scanf("%d %d",&x,&y);
        x--;
        y--;
        pi[i].first=x;
        pi[i].second=y;
        pi[i].index=i;
        i++;
    }
    sort(pi,pi+q,cmp);
    int prev_strt=0,prev_end=0,new_strt,new_end,sum=0;
    for(i=0;i<q;i++)
    {
        new_strt=pi[i].first;
        new_end=pi[i].second;

        // for moving new_strt pointer
        // when start point is on the right side of prev_start, then to remove elements
        while(new_strt>prev_strt)
        {
            remv(prev_strt);
            prev_strt++;
        }
        // when start point is on the left side of prev_start, then to add new elements
        while(new_strt<prev_strt)
        {
            add(prev_strt-1);
            prev_strt--;
        }

        // for moving new_end pointer
        // when new_end point is on the left side of prev_end, then to remove elements
        while(prev_end>new_end+1)
        {
            remv(prev_end-1);
            prev_end--;
        }
        // when new_end point is on the right side of prev_end, then to add new elements
        while(new_end>=prev_end)
        {
            add(prev_end);
            prev_end++;
        }
        ans[pi[i].index]=cnt;
        // cout<<prev_strt<<" - "<<prev_end-1<<" : "<<cnt<<endl;
    }
    for(i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}

/*

what's here? man? look up...!


5
1 1 2 1 3
3
1 5
2 4
3 5
*/
