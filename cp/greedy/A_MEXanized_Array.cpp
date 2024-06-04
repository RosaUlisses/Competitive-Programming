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
    int n, k, x;
    cin >> n >> k >> x;

    if (n < k || k > (x + 1)) {
        print(-1);
        return;
    }
    


    int sum = 0;
    int count = 0;

    for (int i = 0; i < k; ++i) {
        sum += i; 
        count++;
    }

    for (int i = 0; i < n - count; ++i) {
        if (k == x) {
            sum += (x - 1);
        } 
        else sum += x;
    }

    print(sum);
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
