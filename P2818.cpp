#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a[1005];
int main(){
	cin>>n>>a;
	for (int i=0;i<strlen(a);i++){
		ans=ans*10+(a[i]-'0');
		ans%=n;
	} 
	if (ans==0) printf("%d\n",n);
	else printf("%d\n",ans);
	return 0;
} 
