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
        }//��Ϊ��������һ�δ� ѭ���ͻ��Զ��˳� 
		//�������޵���������Ҫ���� ֻ��Ҫ��֤��Ϊ��������
		//4-8-16-15 
        if (tmp+1<=q&&v[tmp+1]==0) {
            que.push(tmp+1);
            f[tmp+1]=f[tmp]+1;
            v[tmp+1]=1;
        }//+1 -1..���ı��� 
        if (tmp*2<=100000&&v[tmp*2]==0) {
            que.push(tmp*2);
            f[tmp*2]=f[tmp]+1;
            v[tmp*2]=1;
        }
        //�������޲��ܳ��������±� ��Ȼ��RE ��Ȼ���Գ������� ���ǲ������޳������� 
        //tmp*2xС������±� 1e5 
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
