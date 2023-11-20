#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define set_inputs cin.tie(0)->sync_with_stdio(0); #ifndef online_judge freopen("input.txt", "r", stdin); #endif

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
    int h, na, nl;
    cin >> h >> na >> nl;

    if((h - nl * 10) <= 0) {
        print("YES");
        return;
    }

    for (int i = 0; i < na; ++i) {
        h = (h / 2) + 10;
        if((h - nl * 10) <= 0) {
            print("YES");
            return;
        }       
    }
    
    if((h - nl * 10) <= 0) {
        print("YES");
    }
    
    else print("NO");
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
