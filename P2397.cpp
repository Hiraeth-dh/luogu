#include<bits/stdc++.h>
using namespace std;
int x,p,cnt,n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (cnt==0) p=x;
		if (p==x) cnt++;
		else cnt--;
	}
	printf("%d\n",p);
	return 0;
} 
//摩尔投票法求区间n/2的众数 
