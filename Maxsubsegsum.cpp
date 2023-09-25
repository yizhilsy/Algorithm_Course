//最大子矩阵问题 luoguP2331
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e3;
LL matrix[MAXN][MAXN];
//n行m列的矩阵
int n;int m;
LL Maxmatrixsum();
LL Maxsubsum(int length,LL* array);
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }
    LL ans=Maxmatrixsum();
    cout<<ans<<endl;
    return 0;
}
LL Maxsubsum(int length,LL* array){//求解最大子段和
    LL maxans=-1e7;LL prebest=0;
    for(int i=1;i<=length;i++){
        if(i==1){
            prebest=array[i];
            maxans=max(maxans,prebest);
        }
        else{
            prebest=max(array[i],array[i]+prebest);
            maxans=max(maxans,prebest);
        }
    }
    return maxans;
}
LL Maxmatrixsum(){
    LL maxsum=-1e5;
    LL temp[m+1];
    for(int i=1;i<=n;i++){
        memset(temp,0,sizeof(temp));
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                temp[k]+=matrix[j][k];
                LL subans=Maxsubsum(m,temp);
                maxsum=max(maxsum,subans);
            }
        }
    }
    return maxsum;
}
