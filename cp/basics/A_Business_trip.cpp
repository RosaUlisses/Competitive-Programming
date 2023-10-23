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
    int k;
    ivec nums(12);
    cin >> k;
    for (int i = 0; i < 12; ++i) {
        cin >> nums[i]; 
    }

    if (k == 0) {
        print("0");
        return;
    }

    sort(nums.begin(), nums.end());

    int count = 0, acc = 0;
    for (int i = 11; i >= 0 ; --i) {
        count++;
        acc += nums[i];
        if (acc >= k) {
            print(count);
            return;
        }
    }

    print("-1");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();

    return 0;
}
