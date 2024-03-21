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

bool is_good(str& str) {
    for (int i = 0; i < sz(str); ++i) {
        if(i == sz(str) - 1) {
            continue;
        } 
        if(str[i] == str[i + 1]) {
           return false;
        } 
    }
    
    return true;
}

void solve() {
    int sz_s, sz_t;
    cin >> sz_s >> sz_t;
    
    str ss, t;
    
    cin >> ss >> t;

    bool s_good = true;
    bool one_cont = false;
    bool zero_cont = false;
    
    for (int i = 0; i < sz(ss); ++i) {
        if(i == sz(ss) - 1) {
            continue;
        }
        
        if(ss[i] == ss[i + 1]) {
            s_good = false;
            if (ss[i] == '0') {
                zero_cont = true; 
            }
            else {
                one_cont = true;
            }
        }
    }
    
    if(s_good) {
        print("Yes");
        return;
    }
    
    if(!is_good(t)) {
        print("No");
        return;
    }
    
    if(one_cont && zero_cont) {
        print("No");
        return;
    }
    
    if(one_cont) {
        if (t[0] == '0' && t[sz(t) - 1] == '0') {
            print("Yes");
            return;
        }
    }
    
    if(zero_cont) {
        if(t[0] == '1' && t[sz(t) - 1] == '1') {
            print("Yes");
            return;
        }
    }

    print("No");
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
