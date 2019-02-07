#include<bits/stdc++.h>
using namespace std;
int n,m,ans,tmp;
char a[1005][1005];
bool pd(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
				//tmp=1;��Ϊ�Ƕ�ÿ������б��� ���Զ�����ҲҪ�ж� �޸Ĳ��ִ����ʱ��û�п���ȫ��
				tmp=0;
				if (a[i][j]=='#') tmp++;
				if (a[i+1][j]=='#') tmp++;
				if (a[i][j+1]=='#') tmp++;
				if (a[i+1][j+1]=='#') tmp++;
				if (tmp==3) return false;
			} 
	return true;
}  
//ʧ������һ���������� ����������ô��������
//��ÿһ�������Χ�ĸ�����м��� Ȼ������ж� ֻ��'#'�����жϿ϶�������©��
//��ÿ������б��� ���ܲ��ز�© ��Ϊ�����Ƕ�ȱ�ǽ��м��� 
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
