///
///
///     UVA 1597 , a must do, do clean if needed, give time !!!
///
///

#include <bits/stdc++.h>

using namespace std;

map <string,vector < pair <int,int> > > mp;
vector <string> vstr[105];


bool cmp(pair <int,int> a,pair <int,int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main()
{
    int t,doc_id=0,line=0,i,n,m,j,xx;
    string st,stt,stx;
    scanf("%d",&t);
    while(t--)
    {
        line=0;
        while(getline(cin,st))
        {
            if(st=="**********")
                break;

            vstr[doc_id].push_back(st);
            stringstream ss(st);
            while(ss>>stx)
            {
                xx=stx.size()-1;
                if(!(stx[xx]>='a' && stx[xx]<='z') && !(stx[xx]>='A' && stx[xx]<='Z'))
                    stx.erase(stx.end()-1);
                transform(stx.begin(),stx.end(),stx.begin(),::tolower);
                mp[stx].push_back({doc_id,line});
            }
            line++;
        }
        doc_id++;
    }
    scanf("%d",&t);
    getchar();
    int doc_flag[105]={0};
    string stcmd[3];
    vector < pair <int,int> > find_call;
    set <int> find_set;
    set <int> :: iterator sit;
    while(t--)
    {
        i=0,stcmd[0]="",stcmd[1]="",stcmd[2]="";
        getline(cin,st);
        stringstream ss(st);
        while(ss>>stcmd[i])
            i++;
        if(stcmd[1]=="" && stcmd[2]=="")
        {
            transform(stcmd[0].begin(),stcmd[0].end(),stcmd[0].begin(),::tolower);
            find_call=mp[stcmd[0]];
            cout<<vstr[find_call[0].first][find_call[0].second]<<endl;
            for(i=1;i<find_call.size();i++)
            {
                cout<<"---------"<<endl;
                cout<<vstr[find_call[i].first][find_call[i].second]<<endl;
            }
        }
        else if(stcmd[2]=="" && stcmd[0]=="NOT")
        {
            find_call=mp[stcmd[1]];
            for(i=0;i<doc_id;i++)
            {
                find_set.insert(i);
            }
            cout<<find_set.size()<<endl;
            for(i=0;i<find_call.size();i++)
            {
                cout<<" not ache : "<<find_call[i].first<<" "<<find_call[i].second<<endl;
                find_set.erase(find_set.find(find_call[i].first));
            }
            cout<<find_set.size()<<endl;
            bool fgg=true;
            find_set.insert(12);
            for(auto siit=find_set.begin();siit!=find_set.end();++siit)
            {
                if(!fgg)
                {
                    cout<<"---------"<<endl;
                }
                for(i=0;i<vstr[*sit].size();i++)
                {
                    cout<<vstr[*sit][i]<<endl;
                }

            }
            find_call.clear();
            find_set.clear();
        }
        else if(stcmd[0]!="" && stcmd[1]!="" && stcmd[2]!="")
        {
            if(stcmd[1]=="AND")
            {
                find_call=mp[stcmd[0]];
                for(i=0;i<find_call.size();i++)
                {
                    doc_flag[find_call[i].first]=1;
                }

                find_call=mp[stcmd[2]];
                for(i=0;i<find_call.size();i++)
                {
                    doc_flag[find_call[i].first]= doc_flag[find_call[i].first]==1 ? 2 : doc_flag[find_call[i].first];
                }

                find_call=mp[stcmd[0]];
                find_call.reserve(find_call.size()+mp[stcmd[2]].size());
                find_call.insert(find_call.end(),mp[stcmd[2]].begin(),mp[stcmd[2]].end());
                sort(find_call.begin(),find_call.end(),cmp);
                for(i=0;i<find_call.size();i++)
                {
                    if(doc_flag[find_call[i].first]==2 && (find_call[i-1]!=find_call[i]))
                    {
                        if(i!=0 && find_call[i].first!=find_call[i-1].first)
                            cout<<"---------"<<endl;
                        cout<<vstr[find_call[i].first][find_call[i].second]<<endl;
                    }

                }
                find_call.clear();
                memset(doc_flag,0,sizeof(doc_flag));
            }
            else if(stcmd[1]=="OR")
            {
                find_call=mp[stcmd[0]];
                find_call.reserve(find_call.size()+mp[stcmd[2]].size());
                find_call.insert(find_call.end(),mp[stcmd[2]].begin(),mp[stcmd[2]].end());
                sort(find_call.begin(),find_call.end(),cmp);

                for(i=0;i<find_call.size();i++)
                {
                    if(find_call[i-1]!=find_call[i])
                    {
                        if(i!=0 && find_call[i].first!=find_call[i-1].first)
                            cout<<"---------"<<endl;
                        cout<<vstr[find_call[i].first][find_call[i].second]<<endl;
                    }

                }
                find_call.clear();
            }
        }
    }
    return 0;
}
/*

4
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
Of course, Lisa did not necessarily
intend to read his books. She might
want the computer only to write her
midterm. But Dan knew she came from
a middle-class family and could hardly
afford the tuition, let alone her reading
fees. Books might be the only way she
could graduate
**********
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
I am very very very happy!
What about you?
**********
6
computer
books AND computer
books OR protected
NOT security
very
slick

*/

