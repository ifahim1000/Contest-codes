long long po(long long a,long long b)
{
    long long ans=1;
 while(b--) ans*=a;
 return ans;
}
long long prime(long long a)
{     for(long long i=1; i*i<=a; i++)
          {   if(a%i==0) return 1;  }
       return 0;
}
void phi(long long  n)
{
   long long i,mul=1,holder,fre=0;
   if(prime(n)==0) mul=n-1;
   else
 {
     for(i=2; i*i<=n; i++)
     {
          if(n%i==0)
         {
             while(n%i==0)
             {
                 n=n/i;
                 holder=i;
                fre++;
             }
             mul*=(po(holder,fre-1)*(holder-1));
             fre=0;
         }
    }
     if(n!=1) {
         mul*=(n-1);
    }
 }
 cout << mul << endl;
}
