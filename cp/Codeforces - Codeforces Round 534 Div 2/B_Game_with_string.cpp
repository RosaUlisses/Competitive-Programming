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

bool n_end(str& str) {
    for (int i = 0; i < sz(str); ++i) {
        if(i + 1 < sz(str) && str[i] == str[i + 1]) {
            return true;
        } 
    }
    
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    str str;
    cin >> str;
    bool pl = true;
    int s = -1;
    int e = -1;
    while(n_end(str)) {
        for (int i = 0; i < sz(str); ++i) {
            if(i + 1 < sz(str) && str[i] == str[i + 1] && s == -1) {
                s = i; 
                e = i;
                for (int j = i + 1; j < sz(str) && str[i] == str[j]; ++j) {
                    e = j; 
                }
            }
        }  
        
        str.erase(s, e - s + 1);
        pl = !pl;
        s = -1;
    }
    
    if (!pl) {
        print("Yes");
    }
    else print("No");
    
    return 0;
}
