#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,l,x[4][4];
    int *a,**b;
    b=&x;
    **b=3;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            *((*b+i)+j)=3*i+j;
            cout<<*((*b+i)+j)<<" ";
        }
        cout<<endl;
    }

    cout<<**b;

}
