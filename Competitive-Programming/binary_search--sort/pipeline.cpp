#include <iostream>
#include <algorithm>

using namespace std;

int64_t n_pipes(int64_t count, int64_t k) {
    return (k * count ) - ((count * (count + 1)) / 2) + 1;
}


int main() {
    int64_t n, k; 
    cin >> n >> k;

    int64_t l = 0; 
    int64_t r = k;

    
    while(l <= r) {
        int m = l + (r - l) / 2;
        int64_t num_pipes = n_pipes(m, k);
        if (num_pipes < n) {
            l = m + 1;
        }     
        else {
            r = m - 1;
        }
    }

    if (n_pipes(l, k) < n) cout << "-1";
    else cout << l;
    
	return 0;
}
