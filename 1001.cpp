//  A
#include <bits/stdc++.h>
#include<ctime>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<cstdio>
#include<time.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3+5;
int Map[MAXN][MAXN];int ct=1;
void dfs(int x1,int y1,int x2,int y2,int spex,int spey);
//color unit
void SetColor(int fore = 7, int back = 0)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (back << 4) + fore);
}

int colorstype[39][3]={{245,245,245},{252,230,202},{255,0,0},{227,73,13},{156,102,31},{255,127,80},{255,99,71},{255,192,203},{176,23,31},{255,0,255},
{0,255,0},{0,255,255},{127,255,0},{64,224,205},{8,46,84},{34,139,34},{107,142,35},{0,0,255},{3,168,158},{25,25,112},{0,199,140},{255,255,0},{255,153,18},
{255,215,0},{255,125,64},{255,227,132},{255,128,0},{237,145,33},{85,102,0},{128,42,42},{199,97,20},{244,164,95},{160,82,45},{199,97,20},{160,32,240},
{218,112,214},{138,43,226}};

int main()
{
    //使用此种方法输出带颜色文本是不可关闭同步流
    // ios::sync_with_stdio(false);
    // cin.tie(0); 
    // cout.tie(0);
    
    //load color units
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode))return GetLastError();

    cout<<"Test Nums:"<<endl;
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        SetColor();
        memset(Map,0,sizeof(Map));ct=1;          //INIT
        int k;int x;int y;
        cin>>k>>x>>y;
        int n=(1<<k);
        cout<<"Case "<<z<<":"<<"n="<<n<<endl;
        Map[x][y]=-1;
        dfs(1,1,n,n,x,y);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==x&&j==y){
                    SetColor();
                    cout<<"#"<<"    ";
                }
                else{
                    //cout<<Map[i][j]<<"\t";

                    // wprintf(L"\x1b[38;2;%d;%d;%dm%d\t", colorstype[Map[i][j]][0], 
                    // colorstype[Map[i][j]][1], colorstype[Map[i][j]][2],Map[i][j]);
                    int back=Map[i][j]%16;
                    if(back==0){
                        SetColor(7,back);
                        if(Map[i][j]>=10){
                            cout<<char('A'+Map[i][j]-10)<<"    ";
                        }
                        else{
                            cout<<Map[i][j]<<"    ";
                        }
                    }
                    else{
                        SetColor(0,back);
                        if(Map[i][j]>=10){
                            cout<<char('A'+Map[i][j]-10)<<"    ";
                        }
                        else{
                            cout<<Map[i][j]<<"    ";
                        }
                    }
                }
            }
            cout<<endl;
        }
    }
    SetColor();
    system("pause");
    return 0;
}
void dfs(int x1,int y1,int x2,int y2,int spex,int spey){
    if(x1==x2&&y1==y2){
        return;
    }
    int mid=((x2-x1)+1)/2;                          //just a num not a pos
    if((spex-x1+1)<=mid&&(spey-y1+1)>mid){   //1
        Map[x1+mid-1][y1+mid-1]=ct;
        Map[x1+mid][y1+mid-1]=ct;
        Map[x1+mid][y1+mid]=ct;
        ct++;
        for(int i=1;i<=4;i++){
            if(i==1){
                dfs(x1,y1+mid,x1+mid-1,y2,spex,spey);
            }
            else if(i==2){
                dfs(x1,y1,x1+mid-1,y1+mid-1,x1+mid-1,y1+mid-1);
            }
            else if(i==3){
                dfs(x1+mid,y1,x2,y1+mid-1,x1+mid,y1+mid-1);
            }
            else{
                dfs(x1+mid,y1+mid,x2,y2,x1+mid,y1+mid);
            }
        }
    }
    else if((spex-x1+1)<=mid&&(spey-y1+1)<=mid){  //2
        Map[x1+mid-1][y1+mid]=ct;
        Map[x1+mid][y1+mid-1]=ct;
        Map[x1+mid][y1+mid]=ct;
        ct++;
        for(int i=1;i<=4;i++){
            if(i==1){
                dfs(x1,y1+mid,x1+mid-1,y2,x1+mid-1,y1+mid);
            }
            else if(i==2){
                dfs(x1,y1,x1+mid-1,y1+mid-1,spex,spey);
            }
            else if(i==3){
                dfs(x1+mid,y1,x2,y1+mid-1,x1+mid,y1+mid-1);
            }
            else{
                dfs(x1+mid,y1+mid,x2,y2,x1+mid,y1+mid);
            }
        }
    }
    else if((spex-x1+1)>mid&&(spey-y1+1)<=mid){    //3
        Map[x1+mid-1][y1+mid]=ct;
        Map[x1+mid-1][y1+mid-1]=ct;
        Map[x1+mid][y1+mid]=ct;
        ct++;
        for(int i=1;i<=4;i++){
            if(i==1){
                dfs(x1,y1+mid,x1+mid-1,y2,x1+mid-1,y1+mid);
            }
            else if(i==2){
                dfs(x1,y1,x1+mid-1,y1+mid-1,x1+mid-1,y1+mid-1);
            }
            else if(i==3){
                dfs(x1+mid,y1,x2,y1+mid-1,spex,spey);
            }
            else{
                dfs(x1+mid,y1+mid,x2,y2,x1+mid,y1+mid);
            }
        }
    }
    else if((spex-x1+1)>mid&&(spey-y1+1)>mid){    //4
        Map[x1+mid-1][y1+mid]=ct;
        Map[x1+mid-1][y1+mid-1]=ct;
        Map[x1+mid][y1+mid-1]=ct;
        ct++;
        for(int i=1;i<=4;i++){
            if(i==1){
                dfs(x1,y1+mid,x1+mid-1,y2,x1+mid-1,y1+mid);
            }
            else if(i==2){
                dfs(x1,y1,x1+mid-1,y1+mid-1,x1+mid-1,y1+mid-1);
            }
            else if(i==3){
                dfs(x1+mid,y1,x2,y1+mid-1,x1+mid,y1+mid-1);
            }
            else{
                dfs(x1+mid,y1+mid,x2,y2,spex,spey);
            }
        }
    }
    
}