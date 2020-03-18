#include<bits/stdc++.h>
#define mx 100005
#define test_case printf("Case %d:\n",id++)

using namespace std;

int arr[mx+1],node[4*mx+1],first_pos[mx+1],freq[mx+1];

unordered_map <int,int> unmap;

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind]=freq[i];
        return;
    }
    int mid=(i+j)>>1;
    build(ind<<1,i,mid);
    build(ind<<1|1,mid+1,j);
    node[ind]=max(node[ind<<1],node[ind<<1|1]);
}

int query(int ind,int i,int j,int s,int e)
{
    if(i>e || j<s) return -1;
    if(i>=s && j<=e) return node[ind];
    int mid=(i+j)>>1;
    return max(query(ind<<1,i,mid,s,e),query(ind<<1|1,mid+1,j,s,e));
}

int main()
{
    int i,j,a,b,k=0,l,c=0,t,n,x,y,q,id=1,z,MX=-1;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    cin>>t;
    while(t--)
    {
        scanf("%d %d %d",&n,&c,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            unmap[arr[i]]++;
        }
        for(i=1;i<=n;i++)
        {
            freq[i]=unmap[arr[i]];
            if(!first_pos[arr[i]])
                first_pos[arr[i]]=i;
        }
        build(1,1,n);
        test_case;
        int c1,c2,c3;
        while(q--)
        {
            scanf("%d %d",&a,&b);
            if(first_pos[arr[a]]==first_pos[arr[b]])
                printf("%d\n",b-a+1);
            else
            {
                c1=(freq[arr[a]]+first_pos[arr[a]]-a),a=freq[arr[a]]+first_pos[arr[a]];
                c2=(b-first_pos[arr[b]]+1),b=first_pos[arr[b]]-1;
                c3=0;
                if(a<=b)
                    c3=query(1,1,n,a,b);
                printf("%d\n",max(c1,max(c3,c2)));
            }
        }
        unmap.clear();
        memset(first_pos,0,sizeof first_pos);
    }
    return 0;
}

/*
1
7 3 5
1 2 2 3 2 2 3
3 5
3 6
1 4
1 2
3 4
*/
