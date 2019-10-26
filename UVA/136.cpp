#include<bits/stdc++.h>

using namespace std;

set <long long int> st;

int n=30;

void solve(long long int s)
{
    if(st.end()!=st.find(s) || s>INT_MAX)
        return;
    st.insert(s);
    solve(s*2);
    solve(s*3);
    solve(s*5);
}

int main() {
	int t2 = 1, t3 = 1, t5 = 1, tmp, i,n2,n3,n5;
    solve(1);
	set <long long int> :: iterator it;
	it=st.begin();
	advance(it,1499);
	printf("The 1500'th ugly number is %d.\n", *it);
    return 0;
}
/*

859963392

*/
