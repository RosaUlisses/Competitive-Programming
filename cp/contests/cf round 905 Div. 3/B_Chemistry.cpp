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

int gk(str& s) {
    map<char, int> m;
    int sum = 0;
    int k = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(!has(m, s[i])) {
            m.insert({s[i], 1});
        }
        else m[s[i]]++;
        sum++;
    }

    for (auto p: m) {
        if (p.second % 2 == 0) continue;
        sum--;
        k++;
    }

    return k - 1;
}


void solve() {
    int n, k;
    cin >> n >> k;
    str a;
    cin >> a;
    
    if(a.size() == 1) {
        print("YES");
        return;
    }

    int res = gk(a);
    if(res <= k) {
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
