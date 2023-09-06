//  problem B 动态规划
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> v;
int n;
struct node{
    int r;int c;
};
vector<node> matrix;
LL dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout<<"Enter Test Nums:"<<endl;
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        v.clear();matrix.clear();   //init
        memset(dp,0,sizeof(dp));
        for(int i=0,x;i<=n;i++){
            cin>>x;v.push_back(x);
        }
        node stpos;stpos.c=-114514;stpos.r=-114514;matrix.push_back(stpos);
        for(int i=0;i<n;i++){   //矩阵从1开始
            node temp;temp.r=v[i];temp.c=v[i+1];
            matrix.push_back(temp);
        }
        cout<<"Case "<<z<<":"<<endl;
        for(int i=0;i<=n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=1;j+i<=n;j++){
                if(j==(j+i)){
                    dp[j][j+i]==0;
                }
                else{
                    dp[j][j+i] = dp[j+1][j+i] + v[j-1]*v[j+i]*v[j];
                    for(int k=0;k<=(i-1);k++){  //共有i+1个
                        dp[j][j+i]=min(dp[j][j+i],(dp[j][j+k]+dp[j+k+1][j+i]+v[j-1]*v[j+i]*v[j+k]));
                    }
                }
            }
        }
        cout<<dp[1][n]<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
    return 0;
}