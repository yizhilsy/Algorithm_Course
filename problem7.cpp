#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> boxweight;
int n;int c1,c2;
bool IsLoad[128];LL nowweight;
bool bestLoadway[128];LL bestweight;
LL remainweight=0;
void dfs(int i);
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int z=1;z<=T;z++){
        //init;
        memset(IsLoad,0,sizeof(IsLoad));memset(bestLoadway,0,sizeof(bestLoadway));
        remainweight=0;nowweight=0;bestweight=0;
        boxweight.clear();
        cin>>n;
        LL sumweight=0;
        for(int i=0,x;i<n;i++){
            cin>>x;boxweight.push_back(x);
            remainweight+=x;
            sumweight+=x;
        }
        cin>>c1>>c2;
        dfs(1);
        cout<<"ship 1's best carry weight: "<<bestweight<<endl;
        cout<<"way: ";
        for(int i=1;i<=n;i++){
            cout<<i<<": "<<bestLoadway[i]<<"; ";
        }
        cout<<endl;
        if(sumweight-bestweight>c2){
            cout<<"no way to load!"<<endl; 
        }
        else{
            cout<<"we can load!"<<endl;
        }
    }
    return 0;
}
//此种方法保证每次搜到叶子结点都是更优解
void dfs(int i){
    if(i>n){    //搜索边界
        if(nowweight>bestweight){   
            bestweight=nowweight;
        }
        return;
    }
    //剩余的重量变少
    remainweight-=boxweight[i-1];
    //将此集装箱装入货轮1
    if(nowweight+boxweight[i-1]<c1){    //判断是否可以装
        IsLoad[i]=true;
        nowweight+=boxweight[i-1];
        dfs(i+1);
        nowweight-=boxweight[i-1];
    }
    //将此集装箱不装入货轮1
    if(nowweight+remainweight>bestweight){  //有可能会产生更优解
        IsLoad[i]=false;
        dfs(i+1);
    }
    //回溯，返回剩余的重量
    remainweight+=boxweight[i-1];
    bestLoadway[i]=IsLoad[i];
    return;
}
