#include <bits/stdc++.h>
#define cout(x) cout << x

using namespace std;

constexpr int inf = 2e9+1;

void solve() {
    int n;
    cin >> n;
    
    int min = inf;
    int min_ix = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] < min) {
            min_ix = i; 
            min = nums[i];
        }
    }
    
    nums[min_ix]++;
    
    int product = 1;
    for (int i = 0; i < n; ++i) {
       product *= nums[i]; 
    }
    
    cout(product) << "\n";
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
