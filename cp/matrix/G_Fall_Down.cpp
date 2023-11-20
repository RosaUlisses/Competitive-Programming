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
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
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
    int ni, nj;
    cin >> ni >> nj;
    vector<vector<char>> mat(ni, vector<char>(nj, '.'));

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            cin >> mat[i][j]; 
        } 
    }

    for (int i = 0; i < ni; ++i) {
        int f = -1;
        for (int j = nj - 1; j >= 0; --j) {
            if (mat[j][i] == '.' && f == -1) f = j;
            if (mat[j][i] == 'o') f = -1;
            if(mat[j][i] == '*') {
                mat[j][i] = '.';
                mat[f][i] = '*';
            } 
        } 
    }
    
    fin(r, mat) {
        fin(val, r) {
            cout << val;
        }
        cout << endl; 
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
