#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x,y,m,xt,yt,ans=0;
    fin >> x>>y>>m;
    xt = m/x;
    yt = m/y;
    for(int i=0;i<=xt;++i){
        for(int j=0;j<=yt;j++){
            int temp = x*i+y*j;
            if(temp<=m) ans=max(temp,ans);
        }
    }
    fout << ans << "\n";
    
    return 0;
}