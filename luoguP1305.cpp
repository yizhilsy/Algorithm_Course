#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5;
struct node{
    char data;
    int leftchild;int rightchild;int father;
};
node tree[MAXN];
void init(){
    for(int i=0;i<MAXN;i++){
        tree[i].father=-1;
        tree[i].leftchild=-1;
        tree[i].rightchild=-1;
    }
}
void LeftInsert(int par,int herepos){
    tree[herepos].father=par;
    tree[par].leftchild=herepos;
}
void RightInsert(int par,int herepos){
    tree[herepos].father=par;
    tree[par].rightchild=herepos;
}
void dfs(int nodepos);
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int n;cin>>n;int ct=1;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        int fa;bool flag=false;
        for(int j=1;j<=ct-1;j++){
            if(tree[j].data==s[0]){
                fa=j;flag=true;break;
            }
        }
        if(flag==false){
            fa=ct;
            tree[ct].data=s[0];
            ct++;
        }
        if(s[1]!='*'){
            tree[ct].data=s[1];
            tree[ct].father=fa;
            tree[fa].leftchild=ct;
            ct++;
        }
        if(s[2]!='*'){
            tree[ct].data=s[2];
            tree[ct].father=fa;
            tree[fa].rightchild=ct;
            ct++;
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<tree[i].data<<","<<tree[i].leftchild<<","<<tree[i].rightchild<<endl;
    // }
    dfs(1);
    cout<<endl;
    return 0;
}
void dfs(int nodepos){
    if(nodepos==-1){
        return;
    }
    cout<<tree[nodepos].data;
    dfs(tree[nodepos].leftchild);
    dfs(tree[nodepos].rightchild);
    return;
}