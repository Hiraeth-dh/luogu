#include<bits/stdc++.h>
using namespace std;
char a[2005][2005];
int v[2005][2005],d[2005][2005],px,py,tmpx,tmpy,n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int,int> > q;
void bfs(){
    q.push(make_pair(px,py));
    v[px][py]=1;
    while (!q.empty()){
        px=q.front().first;
        py=q.front().second;
        q.pop();//∫‹÷ÿ“™£°£°£° 
        for (int i=0;i<=3;i++){
            tmpx=dx[i]+px;
            tmpy=dy[i]+py;
            if (a[tmpx][tmpy]=='d') {
                printf("%d\n",d[px][py]+1);
                return;
            }
            else if (a[tmpx][tmpy]=='.'&&tmpx>0&&tmpx<=n&&tmpy>0&&tmpy<=m&&v[tmpx][tmpy]==0){
                v[tmpx][tmpy]=1;
                d[tmpx][tmpy]=d[px][py]+1;
                q.push(make_pair(tmpx,tmpy));
            }
        }
    }
    printf("No Way!\n");
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if (a[i][j]=='m') {px=i;py=j;}
            }
    bfs();
    return 0;
} 
