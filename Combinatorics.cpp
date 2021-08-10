namespace Combi {
    int mod = 1e9+7;
    const int N = 2e6 + 100;
    int fact[N], inv[N];
    int bigmod(int b, int p, int m) {
       if(p == 0) return 1%m;
       int t = bigmod(b,p/2,m);
       t = (1ll*t*t)%m;
       if(p&1) return 1ll*t*b%m;
       return t;
    }
    int nCr(int n, int r) {
       if(n < 0 or r < 0 or r > n) return 0;
       int ret = 1ll*fact[n]*inv[r]%mod;
       ret = 1ll*ret*inv[n-r]%mod;
       return ret;}
    // X1 + X2 + ... + Xvar = Sum
    int no_of_eqns(int sum, int var) {
       return nCr(sum+var-1,var-1); // Xi >= 0
       // return C(sum-1,var-1); // Xi > 0
    }
    void init() {
       fact[0] = 1;
       for(int i = 1; i < N; i++) {
           fact[i] = 1ll*fact[i-1]*i%mod;
       }
       inv[N-1] = bigmod(fact[N-1], mod-2, mod);
       for(int i = N-2; i >= 0; i--) {
           inv[i] = 1ll*inv[i+1]*(i+1)%mod;
       }
    }
}
