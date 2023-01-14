#include <bits/stdc++.h>

using namespace std;

int m,n;
const int N=2e3;
char a[N][N];
bool flag[N][N];

void dfs(int ui,int uj){
    flag[ui][uj]=true;
    int ti[8]={0,0,-1,1,1,-1,-1,1};
    int tj[8]={-1,1,0,0,1,-1,1,-1};
    for(int i=0;i<8;i++){
        int vi=ui+ti[i],vj=uj+tj[i];
        if(vi>=0 and vi<m and vj>=0 and vj<n){
            if(!flag[vi][vj]) dfs(vi,vj);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++){
            a[i][j]=s[j];
            if(a[i][j]=='0') flag[i][j]=true;
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!flag[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}