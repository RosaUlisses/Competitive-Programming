#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) (x.begin(), x.end())

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

int f_diff(int v, int v2) {
    if(v2 % v == 0) return 0;
    
    if(v > v2) return v - v2;

    return ((v2 / v) + 1) * v - v2;
}


void solve() {
    int n, k;
    cin >> n >> k;
    ivec nums(n);

    int n_even = 0;
    int n_odds = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if(nums[i] % 2 == 0) {
            n_even++;
        }
        else {
            n_odds++;
        }
    }

    int min_diff = inf;
    for (auto& val: nums) {
        int diff = f_diff(k, val);
        if (min_diff > diff) {
            min_diff = diff;
        }
    }

    if(k == 2) {
        if(n_odds >= 1) {
            print(min(min_diff, 1));
            return;
        }
    }

    if(k == 4) {
        if(n_even >= 2) {
            print(0);
            return;
        }
        
        if(n_even == 1 && n_odds >= 1) {
            print(min(1, min_diff));
            return;
        }
        
        if (n_odds >= 2) {
            print(min(2, min_diff));
            return;
        }
    }

    print(min_diff);
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
