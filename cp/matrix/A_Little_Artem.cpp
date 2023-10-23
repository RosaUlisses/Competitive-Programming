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
    int r, c;
    cin >> r >> c;
    vector<vector<char>> mtx(r);
    for (int i = 0; i < mtx.size(); ++i) {
        mtx[i] = vector<char>(c, 'W'); 
    }
    
    int count = 0;
    if (r * c % 2 != 0) {
        for (int i = 0; i < r; i += 2) {
            for (int j = 0; j < c; ++j) {
                if (count == (r * c) / 2 + 1) {
                    break;
                }
                mtx[i][j] = 'B';
                count++;
            } 
        } 
    }
    
    else {
        for (int i = 0; i < r; i += 2) {
            for (int j = 0; j < c; ++j) {
                if (count == (r * c) / 2 + 1) {
                    break;
                }
                mtx[i][j] = 'B';
                count++;
            }
        }

        for (int i = 0; i < r - 1; ++i) {
            mtx[i][0] = 'B'; 
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << mtx[i][j]; 
        } 
        cout << "\n";
    } 
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
