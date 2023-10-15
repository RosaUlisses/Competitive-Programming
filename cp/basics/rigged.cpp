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
     
    void solve() {
        int n; 
        cin >> n;
        vector<ii> athlts(n);
        for (int i = 0; i < n; ++i) {
            cin >> athlts[i].first;
            cin >> athlts[i].second;
        }
     
        
        int max = 1;
        for (int i = 1; i < n; ++i) {
            if (athlts[i].second >= athlts[0].second) {
                if (athlts[i].first < max) continue;
                if (athlts[0].first > athlts[i].first) {
                    max = athlts[i].first + 1;
                }
     
                if (athlts[i].first >= athlts[0].first) {
                    cout << "-1" << "\n";
                    return;
                }
            }
        }
        
        cout << max << "\n";
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
