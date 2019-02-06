#include<bits/stdc++.h>
using namespace std;
int f[1000005],v[1000005],t,p,q,tmp;
void bfs(){
    memset(f,0,sizeof(f));
    memset(v,0,sizeof(v));
    queue<int> que;
    que.push(p);
    v[p]=1;
    while (!que.empty()){
        tmp=que.front();
        que.pop();
        if (tmp==q) {
            printf("%d\n",f[q]);
            return;
        }//因为检索到第一次答案 循环就会自动退出 
		//所以上限的条件不需要控制 只需要保证不为负数即可
		//4-8-16-15 
        if (tmp+1<=q&&v[tmp+1]==0) {
            que.push(tmp+1);
            f[tmp+1]=f[tmp]+1;
            v[tmp+1]=1;
        }//+1 -1..不改变结果 
        if (tmp*2<=100000&&v[tmp*2]==0) {
            que.push(tmp*2);
            f[tmp*2]=f[tmp]+1;
            v[tmp*2]=1;
        }
        //控制上限不能超过数组下标 不然会RE 虽然可以超过上限 但是不能无限超过上限 
        //tmp*2x小于最大下标 1e5 
        if (tmp-1>0&&v[tmp-1]==0) {
            que.push(tmp-1);
            f[tmp-1]=f[tmp]+1;
            v[tmp-1]=1;
        }
    }
}
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&p,&q);
        bfs();
    }
    return 0;
} 
