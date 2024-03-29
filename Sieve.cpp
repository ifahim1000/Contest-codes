#define mx 100006
vector<int>prime;
 
bool vis[mx];
 
void sieve() {
    ll x=sqrt((int)mx);
    for(int i=3; i<=x; i+=2) {
        if(vis[i]==0) {
            for(int j=i*i; j<mx; j+=2*i)
                vis[j]=1;
        }
    }
    prime.push_back(2);
    for(int i=3; i<mx; i+=2)
        if(vis[i]==0)
            prime.push_back(i);
}
