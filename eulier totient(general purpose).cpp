bool mark[1000001];
long long phi[1000001];

void totient(long long x)
{
    for(long long i=1;i<=1000001;i++)
    {
        phi[i]=i;
    }
    for(long long i=2;i<=1000001;i++)
    {
        if(!mark[i])
        {
            for(long long j=i;j<=1000001;j+=i)
            {
                mark[j]=1;
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}
