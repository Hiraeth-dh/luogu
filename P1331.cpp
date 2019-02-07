#include<bits/stdc++.h>
using namespace std;
int n,m,ans,tmp;
char a[1005][1005];
bool pd(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
				//tmp=1;因为是对每个点进行遍历 所以对自身也要判断 修改部分代码的时候没有考虑全面
				tmp=0;
				if (a[i][j]=='#') tmp++;
				if (a[i+1][j]=='#') tmp++;
				if (a[i][j+1]=='#') tmp++;
				if (a[i+1][j+1]=='#') tmp++;
				if (tmp==3) return false;
			} 
	return true;
}  
//失败类型一定出现死角 但是死角怎么检索？？
//对每一个点的周围四个点进行计数 然后进行判断 只以'#'进行判断肯定会有遗漏的
//对每个点进行遍历 才能不重不漏 因为可以是对缺角进行计数 
/*
6 6
.....#
##...#
##...#
..#..#
.....#
######
*/
void dfs(int x,int y){
	if (a[x][y]=='#'){
		a[x][y]='.';
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x+1,y+1);
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
	if (!pd()) {
		printf("Bad placement.\n");
		return 0;
	}		
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
	if (a[i][j]=='#') {
		dfs(i,j);	
		ans++;
	}	
	printf("There are %d ships.\n",ans);
	return 0;
}
