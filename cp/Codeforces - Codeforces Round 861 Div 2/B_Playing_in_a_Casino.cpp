#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define fin(x, y) for(auto& x : y)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
#define f first
#define s second


using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int inf = 3e5 + 100;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 2e9 + 1;


void solve() {
    int n, m;
    cin >> n >> m;
    
    imat c(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j]; 
        } 
    }
    
    ll pot = 0;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            pot += abs(c[j][i] - c[j + 1][i]); 
        }
    }

    print(pot); 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
