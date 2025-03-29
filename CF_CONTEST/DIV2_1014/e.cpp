#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;

ll modexp(ll base, ll exp) {
    ll res = 1 % MOD;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

bool isOddCell(ll x, ll y, ll n, ll m) {
    if (x == 1 && y > 1 && y < m) return true;
    if (x == n && y > 1 && y < m) return true;
    if (y == 1 && x > 1 && x < n) return true;
    if (y == m && x > 1 && x < n) return true;
    return false;
}

void solve() {
    ll n, m;
    int k;
    cin >> n >> m >> k;

    ll totalCells = n * m, freeTotal = totalCells - k;
    ll totalOdd = 2 * (m - 2) + 2 * (n - 2);

    vector<int> cavolinexy(k);
    ll precoloredOddCount = 0;
    int precoloredOddSum = 0;

    for (int i = 0; i < k; i++) {
        ll x, y;
        int c;
        cin >> x >> y >> c;
        cavolinexy[i] = c;
        if (isOddCell(x, y, n, m)) {
            precoloredOddCount++;
            precoloredOddSum = (precoloredOddSum + c) & 1;
        }
    }

    ll freeOdd = totalOdd - precoloredOddCount;
    ll freeEven = freeTotal - freeOdd;
    ll waysEven = modexp(2, freeEven);
    ll waysOdd = (freeOdd > 0) ? modexp(2, freeOdd - 1) : ((precoloredOddSum == 0) ? 1LL : 0LL);
    ll ans = (waysEven % MOD) * (waysOdd % MOD) % MOD;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
