 Bool vis[1000001];
Int phi[1000001];
Void totient(int n)
{
 N=1000001;
For(int i=0;i<=n;i++)
{
    Phi[ i ]=i ;
}
For(i=2;i<=1000001;i++)
{
   If( ! mark[ i  ])
   {
      For(j= i;j<=1000001;j+=i)
      {
          Mark[ j ]=1;
          Phi[ j ]=( phi[ j ] / i ) – ( i -1 );
       }
   }
 }
}
Complexity:  O(n*log(log(n))) 
ϕ(n)=n *(1−1/p1)*(1−1/p2) *..*(1−1/pk)
where p1,p2,pk  are the prime factors of “n”.
