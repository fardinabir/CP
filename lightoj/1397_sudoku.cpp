///\\\\\\
///
/// "For every complex problem there is an answer that is clear, simple, and wrong." -H.L Mencken
///
///\\\\\\\

#include <bits/stdc++.h>

using namespace std;

vector <string> st_arr[105];

int main()
{
    int t,doc_id=0,i,line=0,n,m,j;
    string st,stx,stt;
    map <string,vector< pair<int,int> > > mp;
    scanf("%d",&t);
    while(t--)
    {
        line=0;
        while(getline(cin,st))
        {
            st_arr[doc_id].push_back(st);
            if(st=="**********")
                break;
            stringstream ss(st);
            while(ss>>stx)
            {
                transform(stx.begin(),stx.end(),stx.begin(),::tolower);
                mp[stx].push_back({doc_id,line});
            }
            line++;
        }
        doc_id++;
    }
    cin>>t; // for query
    while(t--)
    {
        getline(cin,st);
        stringsteam ss(st);
        while(ss>>stx)
        {

        }
    }
    return 0;
}
/*

4
one   repeat  repeat  repeat
A manufacturer, importer, or seller of
digital media devices may not (1) sell,
or offer for sale, in interstate commerce,
or (2) cause to be transported in, or in a
manner affecting, interstate commerce,
a digital media device unless the device
includes and utilizes standard security
technologies that adhere to the security
system standards.
**********
one two   repeat  repeat  repeat   repeat
Of course, Lisa did not necessarily
intend to read his books. She might
want the computer only to write her
midterm. But Dan knew she came from
a middle-class family and could hardly
afford the tuition, let alone her reading
fees. Books might be the only way she
could graduate
**********
one two three   repeat   repeat  repeat  repeat   repeat
Research in analysis (i.e., the evaluation
of the strengths and weaknesses of
computer system) is essential to the
development of effective security, both
for works protected by copyright law
and for information in general. Such
research can progress only through the
open publication and exchange of
complete scientific results
**********
one two three   four   repeat  repeat   repeat  repeat  repeat   repeat
I am very very very happy!
What about you?
**********
10
a
of
off
offer
of AND offer
of AND off
off AND offer
NOT off
for
for AND information
*/
