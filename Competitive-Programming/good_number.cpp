#include <iostream>
#include <set>
#include <string>

using namespace std;

bool is_good_number(string number, int k) {
    set<int> digits;
    for (int i = 0; i <= k; ++i) { digits.insert(i); }

    for (auto digit : number) {
        int value = digit - '0';
        if (digits.find(value) != digits.end()) {
            digits.erase(value);
        }
    }

    return digits.empty();
}

int main() {
    int number_of_tests, k;
    cin >> number_of_tests >> k;

    int count = 0;
    for (int i = 0; i < number_of_tests; ++i) {
       string number;
       cin >> number;
        if (is_good_number(number, k)) count++;
    }
    
    cout << count << "\n";
    
	return 0;
}
