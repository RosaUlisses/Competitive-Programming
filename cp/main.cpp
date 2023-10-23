#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

void solve() {
    int n;
    cin >> n;
    ivec nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; 
    }

    sort(all(nums));
    
    ivec sorted(n);
    int ix = n - 1;
    for (int i = 0; i < n / 2; ++i) {
        sorted[ix] = nums[i]; 
        ix--;
        sorted[ix] = nums[nums.size() - 1 - i];
        ix--;
    }

    if (nums.size() % 2 != 0) {
        sorted[0] = nums[n / 2];
    }

    for (int i = 0; i < n; ++i) {
        cout << sorted[i] << " "; 
    }

    cout << "\n";
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