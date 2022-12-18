#include<bits/stdc++.h>
#define    mxx      505
using namespace std;
int ch[mxx*mxx][26],ss=1, num[mxx*mxx],f[mxx*mxx];
vector<int>vec;
void insert(string s)
{
    int u=0;
    for(int i = 0; i < s.size(); i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c])ch[u][c]=ss++;
        u=ch[u][c];
    }
    vec.push_back(u);
}

void build_fail()
{
    queue<int>q;
    for(int i = 0; i < 26; i++)
    {
        if(ch[0][i])q.push(ch[0][i]);
    }
    int r,u,v;
    while(!q.empty())
    {
        r=q.front();
        q.pop();
        for(int c = 0; c < 26; c++)
        {
            u=ch[r][c];
            if(!u)continue;
            q.push(u);     v=f[r];
            while(v && ch[v][c]==0)v=f[v];
            f[u]=ch[v][c];
        }
    }
}


void search(string s)
{
    int j=0;
    for(int i = 0; i < s.size(); i++)
    {
        int c=s[i]-'a';
        while(j && ch[j][c]==0)j=f[j];
        j=ch[j][c];
        int temp=j;
        while(temp)
        {
            num[temp]++;
            temp=f[temp];
        }
    }
}

int main()
{
     string s="aba";    insert(s);
     s="ba";    insert(s);
     s="ac";    insert(s);
     s="a";    insert(s);
     s="abc";    insert(s);
     build_fail();
     s="ababacbabc";
     search(s);
     for(int i=0;i<vec.size();i++)
     {
         cout<<num[vec[i]]<<endl;
     }

    return 0;
}
