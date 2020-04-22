#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000005

char box[2001][2001];
ll temp_row[30000],n,m;

ll hist_rec()
{
    ll top,area=0,mx=0;
    stack <int> st;
    for(int i=0;i<n;)
    {
        if(st.empty() || temp_row[i]>temp_row[st.top()])
            st.push(i++);
        else
        {
            while(!st.empty() && temp_row[st.top()]>=temp_row[i])
            {
                top=st.top();
                st.pop();
                area= st.empty()? i*temp_row[top] : (i-st.top()-1)*temp_row[top];
                mx=max(mx,area);
            }
        }
    }
    while(!st.empty())
    {
        top=st.top();
        st.pop();
        area= st.empty()? n*temp_row[top] : (n-st.top()-1)*temp_row[top];
        mx=max(mx,area);
    }
    return mx;
}

int main()
{
    ll tc,idd=0,b,s,nn,temp,r,i,j,p,k,q,c,sod,lob,hor;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
//        if(!n)
//            return 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&temp_row[i]);
        }

        printf("Case %lld: %lld\n",++idd,hist_rec());
    }
    return 0;
}
