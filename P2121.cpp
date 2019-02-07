#include<bits/stdc++.h>
using namespace std;
int px,py,ans,n,m,k,flag,f[100005];
struct p{
    int x,y,z;
}a[100005];
bool cmp(p a,p b){
    return a.z>b.z;
}
int find(int x){
    if (x==f[x]) return x;
    return f[x]=find(f[x]);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=m;i++) 
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+m+1,cmp);
    for (int i=1;i<=m;i++){
         px=find(a[i].x);
         py=find(a[i].y);
         if (px==py) continue;
         f[px]=py;
         ans+=a[i].z;
         flag++;
         if (flag==k) break;
    }
    printf("%d\n",ans);
    return 0;
}
