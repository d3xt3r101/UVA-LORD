#include <bits/stdc++.h>

using namespace std;

map < char, vector< char > > Adlist;

map < char, bool > visit;

void bfs(char s)
{
    queue < char > q;
    q.push(s);

    visit[s]=true;
    while(!q.empty())
    {
        char p=q.front();
        q.pop();
        for(int i=0; i<Adlist[p].size(); i++)
        {
            if(visit[Adlist[p][i]]==false)
            {
                q.push(Adlist[p][i]);
                visit[Adlist[p][i]]=true;
            }
        }
    }

}

int counter(char ch)
{
    int cnt=0;
    for(char i='A'; i<=ch; i++)
    {
        if(visit[i]==false)
        {
            bfs(i);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios :: sync_with_stdio(false);
    int testc;
    cin>> testc;
    string s;
    getline(cin,s);
    getline(cin,s);

    while(testc--)
    {
        string t;
        getline(cin,t);
        for(char ch='A'; ch<=t[0]; ch++)
        {
            visit[ch]=false;
            Adlist[ch].clear();
        }

        while(getline(cin,s) )
        {
            if(!s.size()) break;
            Adlist[s[0]].push_back(s[1]);
            Adlist[s[1]].push_back(s[0]);
        }
        cout<< counter(t[0]) ;
        (testc>0) ? cout<<endl<<endl : cout<<endl ;


    }
}


