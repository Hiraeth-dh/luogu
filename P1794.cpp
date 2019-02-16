#include<bits/stdc++.h>
using namespace std;
int n,pv,pg,v[505],g[505],t[505],f[505][505];
int main(){
	scanf("%d%d%d",&pv,&pg,&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&t[i],&v[i],&g[i]);
	for (int i=1;i<=n;i++)
		for (int j=pv;j>=0;j--)
			for (int k=pg;k>=0;k--)
	if (j-v[i]>=0&&k-g[i]>=0) f[j][k]=max(f[j][k],f[j-v[i]][k-g[i]]+t[i]);
	printf("%d\n",f[pv][pg]);
	return 0;
} 
