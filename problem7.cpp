#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> boxweight;
int n;
int c1,c2;bool IsLoad[128];bool bestLoadway[128];
LL bestweight;LL nowweight;
void dfs(int nowweight);
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int z=1;z<=T;z++){
        //init;
        memset(IsLoad,0,sizeof(IsLoad));
        boxweight.clear();
        cin>>n;
        for(int i=0,x;i<n;i++){
            cin>>x;boxweight.push_back(x);
        }
        cin>>c1>>c2;

    }
    system("pause");
    return 0;
}
void dfs(int i){
    if(i>n){    //搜索边界
        if(nowweight>bestweight){   
            bestweight=nowweight;
        }
    }
    //将此集装箱装入货轮1
    if(nowweight+boxweight[i-1]<c1){    //判断是否可以装
        IsLoad[i]=true;
    }
    


    //将此集装箱不装入货轮1
    IsLoad[i]=false;

}