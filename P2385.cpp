#include<bits/stdc++.h>
using namespace std;
int dx[15],dy[15],a[35][35],v[35][35],f[35][35];
int m,n,px,py,qx,qy,zx,zy,xx,yy,tmpx,tmpy;
queue<pair<int,int> > q;
void bfs(){
	q.push(make_pair(qx,qy));
	v[qx][qy]=1;
	while(!q.empty()){
		xx=q.front().first;
		yy=q.front().second;
		q.pop(); 
		for (int i=1;i<=8;i++){
			tmpx=xx+dx[i];
			tmpy=yy+dy[i];
			if (a[tmpx][tmpy]==4) {
				printf("%d\n",f[xx][yy]+1);
				return;
			}
			if (tmpx>0&&tmpx<=n&&tmpy>0&&tmpy<=m&&v[tmpx][tmpy]==0&&a[tmpx][tmpy]==1){
				v[tmpx][tmpy]=1;
				f[tmpx][tmpy]=f[xx][yy]+1;
				q.push(make_pair(tmpx,tmpy));
			}
		}
	} 
} 
int main(){
	scanf("%d%d%d%d",&n,&m,&px,&py);
	dx[1]=px;dy[1]=py;
	dx[2]=px;dy[2]=-py;
	dx[3]=py;dy[3]=px;
	dx[4]=py;dy[4]=-px;
	dx[5]=-px;dy[5]=py;
	dx[6]=-px;dy[6]=-py;
	dx[7]=-py;dy[7]=px;
	dx[8]=-py;dy[8]=-px;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			scanf("%d",&a[i][j]);
			if (a[i][j]==3) qx=i,qy=j;
			//if (a[i][j]==4) zx=i,zy=j;
		}
	bfs();
	return 0;
} 
