#include<bits/stdc++.h>
using namespace std;
long long f[10005],n,m,a[30];
int main(){
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    f[0]=1; 
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    if (j-a[i]>=0) f[j]+=f[j-a[i]];
    printf("%lld\n",f[m]);
    return 0;
} 
