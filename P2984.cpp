//如果是有向边 需要建立反图 然后求单源最短路
//如果是无向边 那么直接跑跑单源最短路然后两个一加就可以搞掉了
#include<bits/stdc++.h>
using namespace std;
int tot,ver[1000005],edge[1000005],head[1000005],next[1000005],n,m,t,d[1000005],v[1000005],x,y,z,px,py;
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
    scanf("%d%d%d",&n,&m,&t);
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dijkstra();
    while(t--){
    	scanf("%d%d",&px,&py);
		printf("%d\n",d[px]+d[py]); 
	} 
    return 0;
}
