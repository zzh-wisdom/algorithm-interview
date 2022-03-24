# dfs_欧拉序

<https://www.acwing.com/blog/content/3414/>

## dfs 序列判断祖先关系

```cpp
#include <iostream>
#include <cstdio>

using namespace std;
const int N=1e5+5;

int n,m;
int head[N],to[N],nxt[N],cnt;
int ein[N],eout[N],tot,root;

void add(int x,int y) { //链式前向星
    to[++cnt]=y;
    nxt[cnt]=head[x];
    head[x]=cnt;
}

void dfs(int x) {
    ein[x]=++tot;   //tot用了计数，这里记录下x的入栈时间
    for(int i=head[x];i;i=nxt[i]) {
        int y=to[i];
        if(!ein[y]) //如果y没访问过，就dfs(y)
          dfs(y);
    }
    eout[x]=++tot;  //记录x的出栈时间
}

bool up(int x,int y) {  //即上面的那串代码
    return (ein[x]<=ein[y] and eout[x]>=eout[y]);
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        if(y!=-1) {     //判断根结点
            add(x,y);
            add(y,x);
        }
        else root=x;
    }
    dfs(root);  //生成欧拉序
    cin>>m;
    while(m--) {
        int x,y;
        cin>>x>>y;
        if(up(x,y))     //x是y的祖先
          cout<<1<<endl;
        else if(up(y,x))    //y是x的祖先
          cout<<2<<endl;
        else
          cout<<0<<endl;
    }
    return 0;
}
```

