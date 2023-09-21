//  D 哈夫曼编码问题
//  Arthur:Shiyu Lu
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5;
struct node{
    char chdata;int weight;
    int leftchild;int rightchild;int father;
    int treenodesize;
};
node tree[MAXN];
void init(){
    for(int i=0;i<MAXN;i++){
        tree[i].father=-2;//father==-1代表此结点是二叉树的根节点
        tree[i].leftchild=-1;
        tree[i].rightchild=-1;
        tree[i].treenodesize=1;
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
void dfs(int nownode);string huffmancode;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int z=1;z<=T;z++){
        init();
        while(!huffmanheap.empty()){
            huffmanheap.pop();
        }
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
        int ct=num+1;
        for(int i=1;i<=num;i++){
            cout<<tree[i].weight<<" ";
        }
        cout<<endl;
        cout<<"=================="<<endl;
        int finalroot;
        while(!huffmanheap.empty()){
            if(huffmanheap.size()==1){//此时表明最终的哈夫曼树已经出来了
                cout<<huffmanheap.top().rootpos<<","<<huffmanheap.top().weight<<endl;
                finalroot=huffmanheap.top().rootpos;
                break;
            }
            heapnode n1=huffmanheap.top();
            huffmanheap.pop();
            heapnode n2=huffmanheap.top();
            huffmanheap.pop();
            //贪心合并两颗树
            if(n1.weight>n2.weight){
                tree[ct].leftchild=n1.rootpos;
                tree[n1.rootpos].father=ct;
                tree[ct].rightchild=n2.rootpos;
                tree[n2.rootpos].father=ct;
                int sumweight=n1.weight+n2.weight;
                tree[ct].weight=sumweight;
                tree[ct].treenodesize=tree[n1.rootpos].treenodesize+tree[n2.rootpos].treenodesize;
                //将新的树所对应的结点插入堆中
                heapnode newn3;newn3.weight=sumweight;
                newn3.rootpos=ct;
                huffmanheap.push(newn3);
                ct++;
            }
            else if(n1.weight<n2.weight){
                tree[ct].leftchild=n2.rootpos;
                tree[n2.rootpos].father=ct;
                tree[ct].rightchild=n1.rootpos;
                tree[n1.rootpos].father=ct;
                int sumweight=n1.weight+n2.weight;
                tree[ct].weight=sumweight;
                tree[ct].treenodesize=tree[n1.rootpos].treenodesize+tree[n2.rootpos].treenodesize;
                //将新的树所对应的结点插入堆中
                heapnode newn3;newn3.weight=sumweight;
                newn3.rootpos=ct;
                huffmanheap.push(newn3);
                ct++;
            }
            else{//此时相等
                int size1=tree[n1.rootpos].treenodesize;
                int size2=tree[n2.rootpos].treenodesize;
                if(size1<=size2){
                    tree[ct].leftchild=n1.rootpos;
                    tree[n1.rootpos].father=ct;
                    tree[ct].rightchild=n2.rootpos;
                    tree[n2.rootpos].father=ct;
                    int sumweight=n1.weight+n2.weight;
                    tree[ct].weight=sumweight;
                    tree[ct].treenodesize=tree[n1.rootpos].treenodesize+tree[n2.rootpos].treenodesize;
                    //将新的树所对应的结点插入堆中
                    heapnode newn3;newn3.weight=sumweight;
                    newn3.rootpos=ct;
                    huffmanheap.push(newn3);
                    ct++;
                }
                else{
                    tree[ct].leftchild=n2.rootpos;
                    tree[n2.rootpos].father=ct;
                    tree[ct].rightchild=n1.rootpos;
                    tree[n1.rootpos].father=ct;
                    int sumweight=n1.weight+n2.weight;
                    tree[ct].weight=sumweight;
                    tree[ct].treenodesize=tree[n1.rootpos].treenodesize+tree[n2.rootpos].treenodesize;
                    //将新的树所对应的结点插入堆中
                    heapnode newn3;newn3.weight=sumweight;
                    newn3.rootpos=ct;
                    huffmanheap.push(newn3);
                    ct++;
                }
            }
        }
        for(int i=1;i<=ct-1;i++){
            cout<<i<<": "<<tree[i].weight<<","<<tree[i].leftchild<<" "<<tree[i].rightchild<<"|";
        }
        cout<<endl;
        dfs(finalroot); 
    }
    return 0;
}
void dfs(int nownode){
    if(tree[nownode].leftchild==-1&&tree[nownode].rightchild==-1){
        cout<<tree[nownode].weight<<" "<<huffmancode<<endl;
        return;
    }
    if(tree[nownode].leftchild!=-1){
        huffmancode.push_back('0');
        dfs(tree[nownode].leftchild);
        huffmancode.pop_back();
    }
    if(tree[nownode].rightchild!=-1){
        huffmancode.push_back('1');
        dfs(tree[nownode].rightchild);
        huffmancode.pop_back();
    }
    return;
}