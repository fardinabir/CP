/// uva 836 , onno vabe korte hobe !

#include <bits/stdc++.h>

using namespace std;



int main()
{
    int arr[100][100];
    int i,j,k,l,s=0,cnt,id,n,t,x,cum[1000]={0};
    cin>>t;
    string st;

    while(t--)
    {
        i=0;
        cin>>st;
        for(j=0;j<st.size();j++)
        {
            arr[i][j]= st[i]=='0'? 0 : 1;
        }
        i++;
        k=st.size();
        while(i<k)
        {
            cin>>st;
            for(j=0;j<st.size();j++)
            {
                arr[i][j]= st[i]=='0'? 0 : 1;
            }
            i++;
        }
        int mx=-1;
        n=k;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                s=0,x=0;
                for(k=0;k<n;k++)
                {
                    cum[k]+=arr[k][j];
                    s+=cum[k];
                    if(s<=0)
                        x=k,s=0;
                    if((j-i+1)*(k-x+1)==s)
                        mx=max(mx,s);
                    else
                        x=k,s=0;
                }
            }
            for(k=0;k<n;k++)
            {
                cum[k]=0;
            }
        }
        printf("%d\n",mx);
    }
}

/*


1

10111000
00010100
00111000
00111010
00111111
01011110
01011110
00011110

*/
