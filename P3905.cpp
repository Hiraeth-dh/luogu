#include<bits/stdc++.h>
using namespace std;//思路转变 floyd搞一搞 
int n,m,d,x,y,z,px,py,f[105][105],v[105][105];
int main(){
	memset(f,0x3f,sizeof(f));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=0;
		f[y][x]=0;
		v[x][y]=z;
		v[y][x]=z;
	}
	scanf("%d",&d);
	for (int i=1;i<=d;i++){
		scanf("%d%d",&x,&y);
		f[x][y]=v[x][y];
		f[y][x]=v[y][x];
	}
	scanf("%d%d",&px,&py);
	for (int k=1;k<=n;k++) 
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	printf("%d\n",f[px][py]);
	return 0;
} 
