#include <iostream>

using namespace std;

int kth_not_divisible(int n, int k) {
    int result = k + (k / (n - 1));
    if (result % n == 0) return result - 1;
    return result;
}

int main() {
    int number_of_inputs;
    cin >> number_of_inputs;

    for (int i = 0; i < number_of_inputs; ++i) {
        int n, k;
        cin >> n >> k;
        cout << kth_not_divisible(n, k) << "\n";
    }
    
	return 0;
}
