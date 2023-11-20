#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl;

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

int trial(int n) {
    int count = 0;

    for (int i = 2; i * i < n; ++i) {
        while(n % i == 0) {
            count++;
            n /= i;
        }
    }
    
    if(n > 1) count++;
    
    return count;
}

void solve() {
    int n;
    cin >> n;
    ivec nums(n);
    map<int,int> divs;
    for (auto& i: nums) {
        cin >> i; 
        divs[i] = trial(i); 
    }

    for (auto& val: divs) {
        if(val.second % n != 0) {
            print("NO");
            return;
        }
    }

    print("YES");
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
