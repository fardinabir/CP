#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000005

char box[2005][2005];
ll temp_row[205],n,m;

ll hist_rec()
{
    ll top,area=0,mx=0;
    stack <int> st;
    for(int i=0;i<m;)
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
        scanf("%lld %lld",&n,&m);
//        if(!n)
//            return 0;
        p=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++){
                cin>>box[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                temp_row[j] = box[i][j]=='0'? temp_row[j]+1 : 0;
            }

            p=max(p,hist_rec());
        }
        printf("Case %lld: ",++idd);
        printf("%lld\n",p);
        memset(temp_row,0,sizeof(temp_row));
    }
    return 0;
}
/*


2

5 7

0110110

0000010

1000001

0100001

1100010

3 3

001

100

101

*/
