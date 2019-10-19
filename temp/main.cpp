///
///
///     UVA 1597 , a must do, Uncompleted for AND and or
///
///

#include <bits/stdc++.h>
#define newl "\n"

using namespace std;

vector <string> vstr[1000];
map <string, vector < pair<int,int> > > mp;
map <string, set < int > > mpd;


bool cmp(pair <int,int> a,pair <int,int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main()
{
    int t,doc_id=0,line=0,i,n,m,j,x;
    string st,stt,stx;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        line=0;
        while(getline(cin,st))
        {
            if(st=="**********")
                break;
            vstr[doc_id].push_back(st);
            stx="";
            for(i=0;i<st.size();i++)
            {
                if(!(st[i]>='a' && st[i]<='z') && !(st[i]>='A' && st[i]<='Z'))
                {
                    transform(stx.begin(),stx.end(),stx.begin(),::tolower);
                    //cout<<endl<<"Mapping :"<<stx<<" > "<<doc_id<<" : "<<line<<endl;
                    mp[stx].push_back({doc_id,line});
                    mpd[stx].insert(doc_id);
                    stx="";
                }
                else
                    stx+=st[i];
            }
            transform(stx.begin(),stx.end(),stx.begin(),::tolower);
            //cout<<endl<<"Mapping :"<<stx<<" > "<<doc_id<<" : "<<line<<endl;
            mp[stx].push_back({doc_id,line});
            mpd[stx].insert(doc_id);

            line++;
        }
        doc_id++;
    }

    scanf("%d",&t);
    getchar();
    string cmd[3];
    set <int> find_set;
    vector <pair <int,int> > vcs;
    int fg=0;
    while(t--)
    {
        getline(cin,st);
        cmd[0]=cmd[1]=cmd[2]="";
        stringstream ss(st);
        x=0;
        while(ss>>cmd[x])
            x++;
        if(x==1)
        {
            if(mp[cmd[0]].empty())
            {
                printf("Sorry, I found nothing.\n==========\n");
                continue;
            }
            for(i=0;i<mp[cmd[0]].size();i++)
            {
                if(i==0 || mp[cmd[0]][i]!=mp[cmd[0]][i-1])
                {
                    if(i && mp[cmd[0]][i].first!=mp[cmd[0]][i-1].first )
                        printf("----------\n");  // for different doc

                    cout<<vstr[mp[cmd[0]][i].first][mp[cmd[0]][i].second]<<"\n";
                }

            }
        }
        else if(x==2)
        {
            fg=0;
            for(i=0;i<mp[cmd[1]].size();i++)
            {
                //cout<<mp[cmd[1]][i].first<<endl;
                find_set.insert(mp[cmd[1]][i].first);
            }
            if(find_set.size()==doc_id)
            {
                find_set.clear();
                printf("Sorry, I found nothing.\n==========\n");
                continue;
            }
            for(i=0;i<doc_id;i++)
            {
                if(find_set.find(i)==find_set.end())
                {
                    if(fg)
                        printf("----------\n");  // for different doc

                    for(j=0;j<vstr[i].size();j++)
                    {
                        cout<<vstr[i][j]<<newl;
                    }
                    fg=1;
                }
            }
            find_set.clear();
        }
        else if(x==3)
        {
            if(cmd[1]=="OR")
            {
                vcs=mp[cmd[0]];
                vcs.reserve(vcs.size()+mp[cmd[2]].size()+1);
                vcs.insert(vcs.end(),mp[cmd[2]].begin(),mp[cmd[2]].end());

                if(vcs.empty())
                {
                    printf("Sorry, I found nothing.\n==========\n");
                    continue;
                }
                sort(vcs.begin(),vcs.end(),cmp);

                fg=0;

                for(i=0;i<vcs.size();i++)
                {
                    if(i && fg&& vcs[i-1].first!=vcs[i].first)
                        printf("----------\n");
                    if(!i || (vcs[i-1]!=vcs[i]))
                    {
                        cout<<vstr[vcs[i].first][vcs[i].second]<<endl;
                        fg=1;
                    }
                }
            }
            else if(cmd[1]=="AND")
            {
                vcs=mp[cmd[0]];
                vcs.reserve(vcs.size()+mp[cmd[2]].size()+1);
                vcs.insert(vcs.end(),mp[cmd[2]].begin(),mp[cmd[2]].end());
                sort(vcs.begin(),vcs.end(),cmp);

                fg=0;
                for(i=0;i<vcs.size();i++)
                {
                    if(mpd[cmd[0]].find(vcs[i].first)!=mpd[cmd[0]].end() && mpd[cmd[2]].find(vcs[i].first)!=mpd[cmd[2]].end() )
                    {
                        if(!fg)
                        {
                            cout<<vstr[vcs[i].first][vcs[i].second]<<endl;
                            fg=1;
                        }
                        else if(fg && vcs[i-1]!=vcs[i])
                        {
                            if(vcs[i].first!=vcs[i-1].first)
                                printf("----------\n");
                            cout<<vstr[vcs[i].first][vcs[i].second]<<endl;
                        }
                    }
                }
                if(!fg)
                {
                    printf("Sorry, I found nothing.\n==========\n");
                    continue;
                }
            }
        }
        printf("==========\n");
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
66
computer
books AND computer
books OR protected
NOT security
very
slick
one
two
three
four
repeat
NOT one
NOT two
NOT three
NOT four
NOT repeat
one AND one
one AND two
one AND three
one AND four
one AND repeat
two AND one
two AND two
two AND three
two AND four
two AND repeat
three AND one
three AND two
three AND three
three AND four
three AND repeat
four AND one
four AND two
four AND three
four AND four
four AND repeat
repeat AND one
repeat AND two
repeat AND three
repeat AND four
repeat AND repeat
one OR one
one OR two
one OR three
one OR four
one OR repeat
two OR one
two OR two
two OR three
two OR four
two OR repeat
three OR one
three OR two
three OR three
three OR four
three OR repeat
four OR one
four OR two
four OR three
four OR four
four OR repeat
repeat OR one
repeat OR two
repeat OR three
repeat OR four
repeat OR repeat
*/

