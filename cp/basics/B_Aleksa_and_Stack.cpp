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

void solve() {
    int n;
    cin >> n;
    
    vector<ll> nums(n); 
    nums[n - 1] = 1'000'000'000 - 1;

    for (int i = n - 1; i >= 2; i -= 2) {
        nums[i - 1] = nums[i] - 1;
        nums[i - 2] = nums[i] - 2;
    }
    
    if(nums[0] == 0) {
        nums[0] = nums[1] - 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
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
