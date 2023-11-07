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
    }

    vector<pair<str,int>> v;
    for (auto& p : strs) {
        if(v.size() < 3) {
            v.push_back(p);
            continue;
        } 
        
        auto mp = *min_element(all(v), [](auto& p1, auto& p2) { return p1.second < p2.second; });

        vector<pair<str,int>> aux;
        for_each(all(v), [&](auto& p1) { 
            p1.second -= mp.second; 
            if(p1.second > 0) {
                aux.push_back(p1);
            }
        });
        
        ans += mp.second;
        v = aux; 
    }
    
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();  

    return 0;
}
