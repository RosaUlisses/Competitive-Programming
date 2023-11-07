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
#define min(x) *min_element(all(x))
#define max(x) *max_element(all(x))
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
    int n, d;
    cin >> n >> d;

    vector<pair<int,int>> monsters(n);

    for (int i = 0; i < n; ++i) {
        cin >> monsters[i].f;
        if (monsters[i].f % d == 0) {
            monsters[i].f = d;
        }
        else  monsters[i].f = monsters[i].f % d;       
        monsters[i].s = i;
    }

    // stable sort does not change the order of elements of the same value
    stable_sort(all(monsters), [](auto& i, auto& j) {
        return i.f > j.f;
    });

    fin(m, monsters) {
        print_s(m.s + 1);
    }

    print("");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
