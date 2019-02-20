#include<bits/stdc++.h>
using namespace std;
int a,ans,minn=1e6,n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a);
		minn=min(a,minn);
		ans=max(ans,a-minn);
	}
	printf("%d\n",ans);
	return 0;
} 
