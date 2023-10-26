#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define lix(x) (x.size() - 1)

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
    int n, k;
    cin >> n >> k;
    
    map<str,int> strs;
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        str s;      
        cin >> s;
        sort(all(s));
        if(has(strs, s)) {
            strs[s]++;
        }
        else {
            strs.insert({s, 1});
        }
    }

    for (auto& p : strs) {
        if (p.second % 3 == 0) {
            ans += p.second / 3;
        }
        
        strs.erase(p.first);
    }
    
    
    


    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();  

    return 0;
}
