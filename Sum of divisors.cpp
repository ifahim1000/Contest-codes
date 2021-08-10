#define int long long
#define MAX  100000001
char stat[100000001];
vector<long long >prime;

/*------bitwise sieve-----*/
void generate () {
    long long  sqrtn = sqrt ( MAX );
    long long  i, j;
    prime.push_back ( 2 );
    for ( i = 3; i <= sqrtn; i += 2 ) {
        if ( !( stat[i/8] & ( 1 << ( i % 8 ) ) ) ) {
            for ( j = i * i; j <= MAX; j += 2 * i ) {
                stat[j/8] |= ( 1 << (j%8) );
            }
        }
    }

    for ( i = 3; i <= MAX; i += 2 ) {
        if ( !( stat[i/8] & ( 1 << ( i % 8 ) ) ) )
        {
            prime.push_back(i);
        }
    }
}
/*----sum of divisors-----*/
vector<pair<ll,ll> >div_count;
long long SOD(long long n) {
    ll root=sqrt(n);
    ll ans=1;
    for(ll i=0; i<(ll)prime.size() && prime[i]<=root; i++)
    {
        if(n%prime[i]==0)
        {
            ll cnt=0;
            while(n%prime[i]==0) {
                cnt++;
                n/=prime[i];
            }
            div_count.push_back({prime[i],cnt});
            root=sqrt(n);
        }
    }
    if(n>1)
    {
        div_count.push_back({n,1LL});
    }
    for(ll i=0;i<div_count.size();i++)
    {
        ll j=modpow(div_count[i].first,div_count[i].second+1LL,100000000000000000LL);
        j--;
        j=j/(div_count[i].first-1LL);
        ans*=j;
    }
  return ans;
}
