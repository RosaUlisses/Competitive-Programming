#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define lix(x) (x.size() - 1)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int v; 
        cin >> v;
        if (!has(m, v)) m.insert({v, 1});
        else m[v]++;
    }
    
    int ans = 0;
    int np = 0;
    for (auto& p: m) {
        ans += p.second / 4;
        if(p.second % 4 == 0) {
            continue;
        }
        if(p.second % 4 == 3) {
            np++;
        }
        
        else if(p.second % 2 == 0) {
            np++;
        }
    }
    
    ans += (np / 2);
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;
}
