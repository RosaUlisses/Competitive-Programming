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
    int n, d, h;
    cin >> n >> d >> h;
    
    ivec hbs(n);
    fin(val, hbs) cin >> val;

    int l = -1;
    double area = 0.0;
    for (int i = sz(hbs) - 1; i >= 0; --i) {
        if(l == -1) {
            area += (h * d / 2);
            l = hbs[i];
            continue;
        }
        
        int th = hbs[i] + h; 
        if(th > l) {
            int nh = (th - (th - l));
            int sb = d - 2 * nh; 
            area += ((sb + d) * h / 2);
            l = hbs[i];
            continue;
        }

        area += (h * d / 2);
        l = hbs[i];
    }

    print(area);
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
