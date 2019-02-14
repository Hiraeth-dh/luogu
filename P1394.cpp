#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,f[305],a[305],px,py;
//并查集维护连通性 并将祖先节点更新为高度最高的点 f[1]即为结果 
int find(int x){
	if (x==f[x]) return x;
	return f[x]=find(f[x]);
} 
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i,scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		px=find(x);
		py=find(y);
		if (px==py) continue;
		if (a[px]>a[py]) f[py]=px;
		if (a[py]>a[px]) f[px]=py; 
	}
	for (int i=1;i<=n;i++)
		if (find(i)!=find(1)) {
			printf("Non\n");
			return 0;
		} 
	printf("Oui, j'ai trouve la solution.\n%d\n",find(1));//寻找祖先 不是f[1] 
	return 0;
} 
