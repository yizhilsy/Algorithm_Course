#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5+5;const LL PP = 131;
char arrayA[MAXN];char arrayB[MAXN];
// int dp[2][MAXN];    //考虑使用滚动数组优化
int dp[1024][1024];int lcsMap[1024][1024];
int n;int m;
void printall(int nowx,int nowy);stack<char> st;
struct node{
    char ch;int pos1;int pos2;
};
stack<node> st_new;
map<LL,int> vhash;vector<string> strans;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout<<"Enter Test Nums: "<<endl;
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        cin>>m;cin>>n;
        for(int i=1;i<=m;i++){
            cin>>arrayA[i];
        }
        for(int i=1;i<=n;i++){
            cin>>arrayB[i];
        }
        // init
        memset(dp,0,sizeof(dp));
        memset(lcsMap,0,sizeof(lcsMap));
        while(!st.empty()){
            st.pop();st_new.pop();
        }
        vhash.clear();strans.clear();
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(arrayA[i]!=arrayB[j]){
                    //dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        lcsMap[i][j] = 2;   //i-1 j更长
                    }
                    else if(dp[i-1][j] < dp[i][j-1]){
                        dp[i][j] = dp[i][j-1];
                        lcsMap[i][j] = 3;   //i j-1更长
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                        lcsMap[i][j] = 4;   //两者一样长
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                    lcsMap[i][j] = 1;   //表明(i,j)是lcs的一部分
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
        cout<<"LCS(X,Y) can be:"<<endl;
        printall(m,n);
        // for(map<LL,int>::iterator it = vhash.begin();it!=vhash.end();it++){
        //     cout<<it->first<<" ";
        // }
        // cout<<endl;
        cout<<"Using BKDRHASH to filterate duplicates"<<endl;
        for(int i=0;i<strans.size();i++){
            cout<<strans[i]<<endl;
        }
    }
    system("pause");
    return 0;
}
void printall(int nowx,int nowy){
    if(nowx==0||nowy==0){
        stack<node> temp2;
        // while(!temp.empty()){
        //     cout<<temp.top()<<" ";temp.pop();
        // }
        temp2 = st_new;
        string s1;
        while(!temp2.empty()){
            cout<<temp2.top().ch<<"|"<<"( "<<temp2.top().pos1<<","<<temp2.top().pos2<<" ) ";
            s1 +=temp2.top().ch;
            temp2.pop();
        }
        LL hashans =0;
        for(int i=0;i<s1.length();i++){
            hashans = hashans*PP+s1[i];
        }
        cout<<" "<<hashans;
        //cout<<vhash[hashans]<<endl;
        if(vhash[hashans]==0){
            strans.push_back(s1);
            vhash[hashans]=1;
        }
        cout<<endl;
        return;
    }
    if(lcsMap[nowx][nowy]==1){
        node nd;nd.ch=arrayA[nowx];nd.pos1=nowx;nd.pos2=nowy;
        st_new.push(nd);
        printall(nowx-1,nowy-1);
        st_new.pop();
    }
    else if(lcsMap[nowx][nowy]==2){
        printall(nowx-1,nowy);
    }
    else if(lcsMap[nowx][nowy]==3){
        printall(nowx,nowy-1);
    }
    else if(lcsMap[nowx][nowy]==4){
        printall(nowx,nowy-1);
        printall(nowx-1,nowy);
    }
}