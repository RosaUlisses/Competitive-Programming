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
    if(v > v2) return v - v2;
    
    else if(v == v2) return 0;
    
    return ((v2 / v) + 1) * v - v2;
}

void solve() {
    int n, k; 
    cin >> n >> k;
    ivec nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; 
    }

    int min = inf;
    int ix = 0;
    for (int i = 0; i < n; ++i) {
        if(nums[i] % k == 0) {
            print("0");
            return;
        }
        int diff = f_diff(k, nums[i]);
        if(diff < min) {
            min = diff; 
            ix = i;
        }
    }
    
    int res = f_diff(k, nums[ix]);
    print(res);
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
