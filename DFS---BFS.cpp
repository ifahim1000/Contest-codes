#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int>a[1000];
int level[1000];
bool visited[1000];
//----------<DFS>---------
void dfs(int s)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<a[s].size();i++)
    {
        if(visited[a[s][i]]==false)
        {
            dfs(a[s][i]);
        }
    }
}
//--------<bfs>---------
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    int p;
    level[s]=0;
    visited[s]=true;
    while(!q.empty())
    {
        p=q.front();
        cout<<p<<" "<<level[p]<<endl;

        q.pop();
        for(int i=0;i<a[p].size();i++)
        {
            if(visited[a[p][i]]==false)
            {
                q.push(a[p][i]);
              // cout<<a[p][i]<<" ";
                level[a[p][i]]=level[p]+1;
                visited[a[p][i]]=true;
            }
        }
    }

}

int main()
{
    int node,edge,j,k,i;
    cin>>node;
    cin>>edge;

    for(j=0;j<edge;j++)
    {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(i=0;i<=node;i++)
    {
        visited[i]=false;
    }

    for(i=0;i<node;i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
        }
    }
    cout<<endl<<"dfs finished"<<endl;
    for(i=1;i<node;i++)
    {
        if(visited[i]==false)
        {

            bfs(i);
        }
    }

}
