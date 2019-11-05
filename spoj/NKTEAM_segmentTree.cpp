    #include <bits/stdc++.h>

    using namespace std;

    vector < pair <int, pair <int,int> > > pi;


    int arr[100005][3],node[400005],n;

    void build(int ind,int i,int j)
    {
        if(i==j)
        {
            node[ind]=INT_MAX;
            return;
        }
        int mid=(i+j)/2;
        build(2*ind,i,mid);
        build(2*ind+1,mid+1,j);
        node[ind]=min(node[2*ind],node[2*ind+1]);
    }

    int query(int ind,int i,int j,int s,int e)
    {
        if(j<s || i>e)
            return INT_MAX;
        if(i>=s && j<=e)
            return node[ind];
        int mid=(i+j)/2;
        return min(query(2*ind,i,mid,s,e),query(2*ind+1,mid+1,j,s,e));
    }

    void update(int ind,int i,int j,int s,int value)
    {
        if(j<s || i>s)
            return;
        if(i==j)
        {
            node[ind]=value;
            return;
        }
        int mid=(i+j)/2;
        update(2*ind,i,mid,s,value);
        update(2*ind+1,mid+1,j,s,value);
        node[ind]=min(node[2*ind],node[2*ind+1]);
    }

    int main()
    {
        int i,j,k,t,a,b,c,cnt=0,l;
        scanf("%d",&n);
        build(1,1,n);
        for(i=0;i<3;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            pi.push_back(make_pair(arr[0][i],make_pair(arr[1][i],arr[2][i])));
        }
        sort(pi.begin(),pi.end());
        cnt=0;
        for(i=0;i<n;i++)
        {
            k=query(1,1,n,1,pi[i].second.first);
            if(pi[i].second.second<k)
                cnt++;
            update(1,1,n,pi[i].second.first,pi[i].second.second);
        }
        printf("%d\n",cnt);
        pi.clear();
    }
