#include<bits/stdc++.h>
using namespace std;
int minn,maxx,n,l,p;
int main(){
    scanf("%d%d",&l,&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&p);
        minn=max(min(l+1-p,p),minn);
        maxx=max(max(l+1-p,p),maxx);
    }
    printf("%d %d",minn,maxx);
    return 0;
}
