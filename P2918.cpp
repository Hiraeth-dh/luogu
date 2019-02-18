#include<bits/stdc++.h>
using namespace std;
int n,p[105],c[105],h,ans=0x3f3f3f3f,f[500090];
int main(){
    scanf("%d%d",&n,&h);
    memset(f,0x3f3f3f3f,sizeof(f));
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&p[i],&c[i]);
        f[p[i]]=c[i];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=h+5000;j++)
    if (j-p[i]>=0) f[j]=min(f[j],f[j-p[i]]+c[i]);
   	for (int j=h;j<=h+5000;j++) ans=min(ans,f[j]);
   	printf("%d\n",ans);
    return 0;
} 
