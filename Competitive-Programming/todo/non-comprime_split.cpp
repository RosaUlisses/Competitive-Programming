#include <iostream>

using namespace std;

bool is_prime(int n) {
    if (n == 1) return true;
    if (n == 2) return false;
    
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int main() {
    int nt;
    cin >> nt;

    for (int i = 0; i < nt; ++i) {
        int l, r; 
        cin >> l >> r;
        pair<int,int> {-1 ,-1};

        for (int j = 1; j < l - 1; ++j) {
            for (int k = 0; k < r; ++k) {
                
            } 
        }
    }
	return 0;
}
