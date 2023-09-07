#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5+5;
char arrayA[MAXN];char arrayB[MAXN];
// int dp[2][MAXN];    //考虑使用滚动数组优化
int dp[1024][1024];int lcsMap[1024][1024];
int n;int m;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        cin>>m;cin>>n;
        for(int i=1;i<=m;i++){
            cin>>arrayA[i];
        }
        for(int i=1;i<=n;i++){
            cin>>arrayB[i];
        }
        memset(dp,0,sizeof(dp));memset(lcsMap,0,sizeof(lcsMap));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(arrayA[i]!=arrayB[j]){
                    //dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        lcsMap[i][j] = 2;   //i-1 j更长
                    }
                    else if(dp[i-1][j] <= dp[i][j-1]){
                        dp[i][j] = dp[i][j-1];
                        lcsMap[i][j] = 3;   //i j-1更长
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                    lcsMap[i][j] = 1;   //表明i j是lcs的一部分
                }
            }
        }
        cout<<"lcs length: "<<dp[m][n]<<endl;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<"\t";
            }
            cout<<endl;
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<lcsMap[i][j]<<" ";
            }
            cout<<endl;
        }
        stack<char> st;
        int x=m;int y=n;
        while(x!=0&&y!=0){
            int way = lcsMap[x][y];
            if(way==1){
                st.push(arrayA[x]);
                x--;y--;
            }
            else if(way==2){
                x--;
            }
            else{
                y--;
            }
        }
        cout<<"LCS(X,Y): ";
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}