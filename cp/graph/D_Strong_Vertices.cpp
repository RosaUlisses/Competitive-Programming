#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define loop(x, y) for(int x = 0; x < y; x++)
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

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

void solve() {
    int n;
    cin >> n;
    
    ivec a(n), b(n);

    fin(val, a) cin >> val;
    fin(val, b) cin >> val;
     
    int mx = -inf;
    for (int i = 0; i < n; ++i) {
        if(mx < a[i] - b[i]) {
            mx = a[i] - b[i];
        }
    }
    
    ivec strongs;
    for (int i = 0; i < n; ++i) {
        if (a[i] - b[i] == mx) {
            strongs.push_back(i + 1);
        } 
    }

    sort(all(strongs));

    print(sz(strongs));
    
    fin(s, strongs) {
        print_s(s);
    }

    print("");
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
