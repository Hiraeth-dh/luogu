#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
map<string,int> q;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		cin>>a;
		q[a]=1;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		cin>>a;
		if (q[a]==1){
			printf("OK\n");
			q[a]=2;
		}
		else if (q[a]==2) printf("REPEAT\n");
		else printf("WRONG\n");
	}
	return 0;
}
