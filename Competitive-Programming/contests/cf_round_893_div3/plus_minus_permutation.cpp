#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    
    ll min = 1, max = n;

    if (x == y) {
        cout << "0\n";
        return;
    }

    ll sum = 0;

    ll num_x_s = n / x - (n / lcm(x,y));  
    ll num_y_s = n / y - (n / lcm(x,y));
    
    
    sum += num_x_s * (n + (n - num_x_s + 1)) / 2;
    sum -= num_y_s * (1 + num_y_s) / 2;
    
    cout << sum << "\n";
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
