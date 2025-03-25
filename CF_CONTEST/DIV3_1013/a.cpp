#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define pb push_back
#define inint(x) int x; cin>>x
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rep(i,j) foreach(i,0,j,1)
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl

typedef vector<int> vi;

void solve() {
    inint(a);
    vi d(a);
    rep(i,a) cin >> d[i];

    string t = "01032025";
    unordered_map<char,int> f;
    for(char c : t) f[c]++;

    unordered_map<char,int> cnt;
    rep(i,a) {
        char c = '0' + d[i];
        cnt[c]++;

        bool k = true;
        for(char h : t) {
            if(cnt[h] < f[h]) {
                k = false;
                break;
            }
        }

        if(k) {
            out(i+1);
            return;
        }
    }
    out(0);
}

int32_t main() {
    fastio();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}