#include <iostream>
#include <vector>

using namespace std;

vector<int> factorize(int64_t n) {
    vector<int> factors;
    for (int d = 2; d * d <= n; ++d) {
        while(n % d == 0) {
            factors.push_back(d); 
            n /= d;
        } 
    }

    if (n > 1) {
        factors.push_back(n);
    }
    
    return factors;
}

void solve() {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if (i == 1) continue;
        if (i % 2 == 0 && i != 2) {
            cout << i / 2 << " " << i / 2 << "\n";
            return;
        }

        vector<int> factors = factorize(i);
        if (factors.size() >= 2) {
            cout << factors[0] << " " << i - factors[0] << "\n";
            return;
        }
    }
    
    cout << "-1\n";
}

int main() {
    int nt;
    cin >> nt;
    
    while(nt--) {
        solve();
    }

	return 0;
}
