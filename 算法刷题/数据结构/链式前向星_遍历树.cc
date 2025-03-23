#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX=2e5;
struct node{ ///下面是链式前向星存图
    LL to;
    LL next;
}edge[MAX+5];
LL n,ans;
LL head[MAX+5];

// 数组链表来存储临接表
void addedge(LL u,LL v)
{
    edge[ans].to=v;
    edge[ans].next=head[u];
    head[u]=ans++;
}
void init()
{
    memset(head,-1,sizeof(head));
    ans=0;
}
LL cnt;
LL num[MAX+5];
bool vis[MAX+5];
void dfs(int u) ///递归实现深度优先搜索
{
    printf("%d ",u);
    vis[u]=true;
    for(int i=head[u];~i;i=edge[i].next){
        int to=edge[i].to;
        if(!vis[to]){
            dfs(to);
        }
    }
}

void bfs(int u) ///队列实现广度优先搜索
{
    queue<int>q;
    vis[u]=true;
    q.push(u);
    while(!q.empty()){
        int k=q.front();
        q.pop();
        printf("%d ",k);
        for(int i=head[k];~i;i=edge[i].next){
             int to=edge[i].to;
             if(!vis[to]){
                q.push(to);
                vis[to]=true; ///因为不是递归实现，所以每次放入队列后都需要立即标记。
             }
        }
    }
}

int main()
{
    init();
    cin>>n;
    for(LL i=0;i<n-1;i++){
        LL u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    cout<<"dfs:"<<endl;
    dfs(1);
    memset(vis,false,sizeof(vis));
    cout<<endl<<"bfs:"<<endl;
    bfs(1);
    printf("\n");
    cout<<endl;
    return 0;
}