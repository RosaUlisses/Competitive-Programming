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
    int n;
    cin >> n;
    ivec v(n);
    fin(val, v) cin >> val;
    
    if(n == 1) {
        print(v[0] - 1);
        return;
    }
    
    int ans = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        int fst = v[i];
        int count = 0;
        bool h0 = true;
        while(v[i + 1] == v[i] - 1 || v[i + 1] == v[i]) {
            if(v[i + 1])
            i++;
            count++;
        }           
        
        if(count > 0 && h0) {
            ans += fst;
        }
        else ans += (fst - 1);
    }

    print(ans);
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
