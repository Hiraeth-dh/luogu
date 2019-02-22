#include<bits/stdc++.h>
using namespace std;
int ver[100005],edge[100005],head[100005],next[100005],flag,n,m,tot,cnt,ans,d[100005],v[100005],x,y,z;
priority_queue<pair<int,int> > q;
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	next[tot]=head[x];
	head[x]=tot;
}
void dijkstra(){
	memset(d,0x3f3f3f3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[1]=0;
	q.push(make_pair(-d[1],1));
	while (!q.empty()){
		x=q.top().second;
		q.pop();
		if(v[x]) continue;
		v[x]=1;
		for (int i=head[x];i;i=next[i]){
			y=ver[i];
			z=edge[i];
			if (d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	} 
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	dijkstra();
	for (int i=1;i<=n;i++){
		if (d[i]>ans&&d[i]!=0x3f3f3f3f) ans=d[i],flag=i,cnt=1;
		else if (d[i]==ans) cnt++;
	}//o(n)的方法计算出最大值和最大值的个数 
	printf("%d %d %d\n",flag,ans,cnt);
	return 0;
}
