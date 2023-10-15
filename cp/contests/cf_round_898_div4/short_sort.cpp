#include <bits/stdc++.h>
#define cout(x) cout << x

using namespace std;

void solve() {
    string s; 
    cin >> s;
    if ((s[2] == 'a' || s[0] == 'c') && !(s[2] == 'a' && s[0] == 'c')) cout("no\n");
    else cout("yes\n");
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
