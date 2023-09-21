//  D 哈夫曼编码问题
//  Arthur:Shiyu Lu
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5;
struct node{
    char chdata;int weight;
    int leftchild;int rightchild;int father;
};
node tree[MAXN];
void init(){
    for(int i=0;i<MAXN;i++){
        tree[i].father=-2;//father==-1代表此结点是二叉树的根节点
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
struct heapnode{
    int rootpos;int weight;
};
class MyCompare{
public:
    bool operator()(heapnode n1,heapnode n2) const{
        return n1.weight>n2.weight;
    }
};
priority_queue<heapnode,vector<heapnode>,MyCompare> huffmanheap;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int z=1;z<=T;z++){
        init();
        int num;cin>>num;
        vector<int> array;
        for(int i=0,x;i<num;i++){
            cin>>x;array.push_back(x);
        }
        cout<<"Case "<<z<<endl;
        for(int i=1;i<=num;i++){
            tree[i].father=-1;
            tree[i].weight=array[i-1];
            heapnode hn;hn.rootpos=i;hn.weight=tree[i].weight;
            huffmanheap.push(hn);
        }
        while(!huffmanheap.empty()){
            cout<<huffmanheap.top().rootpos<<","<<huffmanheap.top().weight<<endl;
            huffmanheap.pop();
        }
    }
    return 0;
}