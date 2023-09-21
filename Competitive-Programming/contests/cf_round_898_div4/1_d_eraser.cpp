#include <bits/stdc++.h>
#define cout(x) cout << x
#define endl ('\n')

using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    string s; 
    cin >> s;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            count++; 
            i += (k - 1);
            continue;
        }
    }

    cout(count) << "\n";
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
