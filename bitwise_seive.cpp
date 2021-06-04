//up to 3*10^8
#define MAX  100000001
char stat[100000001];
vector<long long >prime;
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
