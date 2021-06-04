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
/*---- Number of divisors-----*/
long long NOD(long long n) {
    int root=sqrt(n);
    long long ret=1;
    for(int i=0; i<prime.size() && prime[i]<=root; i++) {
        if(n%prime[i]==0) {
            int cnt=1;
            while(n%prime[i]==0) {
                cnt++;
                n/=prime[i];
            }
            ret*=cnt;
            root=sqrt(n);
        }
    }
    if(n>1)
        ret*=2;
    return ret;
}
