#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

constexpr int inf = 2e9+1;
constexpr int mod = 1e9+7;
constexpr ll maxnum = 3e5+100;


void solve() {
    int n;
    cin >> n;
    vector<vector<char>> mtx(n);
    for (int i = 0; i < n; ++i) {
        string s; 
        cin >> s;
        std::for_each(s.begin(), s.end(), [&](auto& c) {mtx[i].push_back(c);});
    }

    int nops = 0;
    for (int i = 0; i * 2 < n; ++i) {
        for (int j = 0; j * 2 < n; j++) {
            vector<char> chars = {mtx[i][j], mtx[j][n - 1 - i], mtx[n - 1 - j][i], mtx[n - 1 - i][n - 1 - j]};
            char max = *max_element(all(chars));
            std::for_each(chars.begin(), chars.end(), [&](auto& c) { 
                nops += (max - c); 
                c = max;
            });
        } 
    }

    cout << nops << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int nt;
	cin >> nt;

	while(nt--) {
		solve();
	}

	return 0;
}
