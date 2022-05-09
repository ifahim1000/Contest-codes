#define inf 1e9
ll dis[500][500];

void f_w()
{
    for(ll k=0;k<n;k++)
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(dis[i][k]<inf && dis[k][j]<inf)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
}

f_w();
