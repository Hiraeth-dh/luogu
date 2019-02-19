#include<bits/stdc++.h>
using namespace std;
int n,m,s,x,y,z,edge1[200005],ver1[200005],next1[200005],head1[200005],tot1,ans;
int dis1[200005],vis1[200005],edge2[200005],ver2[200005],next2[200005],head2[200005],tot2;
int dis2[200005],vis2[200005];
priority_queue<pair<int,int> > q1;
priority_queue<pair<int,int> > q2;
void add1(int x,int y,int z){
    ver1[++tot1]=y;
    edge1[tot1]=z;
    next1[tot1]=head1[x];
    head1[x]=tot1;
}
void add2(int x,int y,int z){
    ver2[++tot2]=y;
    edge2[tot2]=z;
    next2[tot2]=head2[x];
    head2[x]=tot2;
}
void dijkstra1(){
    memset(vis1,0,sizeof(vis1));
    memset(dis1,0x3f3f3f3f,sizeof(dis1));
    dis1[s]=0;
    q1.push(make_pair(-dis1[s],s));
    while (!q1.empty()){
        x=q1.top().second;
        q1.pop();
        if (vis1[x]) continue;
        vis1[x]=1;
        for (int i=head1[x];i;i=next1[i]){
            y=ver1[i];
            z=edge1[i];
            if (dis1[y]>dis1[x]+z){
                dis1[y]=dis1[x]+z;
                q1.push(make_pair(-dis1[y],y));
            }
        }
    }
}
void dijkstra2(){
    memset(vis2,0,sizeof(vis2));
    memset(dis2,0x3f3f3f3f,sizeof(dis2));
    dis2[s]=0;
    q2.push(make_pair(-dis2[s],s));
    while (!q2.empty()){
        x=q2.top().second;
        q2.pop();
        if (vis2[x]) continue;
        vis2[x]=1;
        for (int i=head2[x];i;i=next2[i]){
            y=ver2[i];
            z=edge2[i];
            if (dis2[y]>dis2[x]+z){
                dis2[y]=dis2[x]+z;
                q2.push(make_pair(-dis2[y],y));
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add1(x,y,z);
        add2(y,x,z);
    }
    dijkstra1();
    dijkstra2();
    for(int i=1;i<=n;i++) ans=max(ans,dis1[i]+dis2[i]);
    printf("%d\n",ans);
    return 0;
} 
