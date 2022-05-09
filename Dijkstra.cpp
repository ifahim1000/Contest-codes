#define ll   long long
#define pll  pair<long long,long long>
#define inf  1e18

ll n,m;
vector<ll>dis,par,path;
vector<vector<pll> > adj(100005);

void dijkstra( ll s)
{
    dis.assign(adj.size(), inf);
    par.assign(adj.size(), -1);

    dis[s]=0;
    priority_queue<pll,vector<pll> , greater<pll> >q;
    q.push({0,s});

    while(!q.empty())
    {
        ll distance=q.top().first;
        ll node=q.top().second;
        q.pop();

        if(distance!=dis[node])
        {
            continue;
        }
        for(ll k=0;k<adj[node].size();k++)
        {
            ll nxt_node=adj[node][k].first;
            ll len=adj[node][k].second;
          
            if(dis[nxt_node]> dis[node]+len)
            {
                dis[nxt_node]=dis[node]+len;
                par[nxt_node]=node;
                q.push({dis[nxt_node],nxt_node});
            }
        }
    }
}

void print_path(ll src)
{
     for(ll i=n;i!=src;i=par[i])
        {
            path.push_back(i);
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        for(ll i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;

}


 dijkstra(src);
 print_path(src);


