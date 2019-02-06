#include<bits/stdc++.h>
using namespace std;
int d[1005],v[1005],edge[1000005],head[1000005],ver[1000005],next[1000005],tot,n,m,x,y,z;
priority_queue<pair<int,int> > q;
//边权的乘积最小 d[1]的初值赋为1 
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	next[tot]=head[x];
	head[x]=tot;
}  
void dijkstra(){
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[1]=1;
	q.push(make_pair(-d[1],1));
	while (!q.empty()){
		x=q.top().second;
		q.pop();
		if (v[x]) continue;
		v[x]=1;
		for (int i=head[x];i;i=next[i]){
			y=ver[i];
			z=edge[i];
			if (d[y]>d[x]*z){
				d[y]=d[x]*z;
				d[y]%=9987;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		z%=9987;
		add(x,y,z);
	}
	dijkstra();
	printf("%d\n",d[n]);
	return 0;
}
