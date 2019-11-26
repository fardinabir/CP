#include <bits/stdc++.h>
#define ll  long long int

using namespace std;

set <float> st;

int main()
{
    ll i,j,k,d,n;
    while(1)
    {
        cin>>n;
        if(!n)
            return 0;
        int arr[205][2];
        float x,y,m;
        for(i=0;i<n;i++)
        {
            cin>>arr[i][0]>>arr[i][1];
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                x=(arr[i][0]-arr[j][0]);
                y=(arr[i][1]-arr[j][1]);
                if(x)
                    m=y/x;
                else
                    m=INT_MAX;

                st.insert(m);
            }
        }
        cout<<st.size()<<endl;
        st.clear();
    }

}
