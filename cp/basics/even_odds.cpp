#include <iostream>
#include <cinttypes>

using namespace std;

int main() {
    std::uint64_t number, index;
    cin >> number >> index;

    std::uint64_t max_odd_index = number % 2 == 0 ? number / 2 : number / 2 + 1;

    if (index <= max_odd_index) {
        cout << (index - 1) * 2 + 1; 
    }
    
    else {
        index -= max_odd_index;    
        cout << index * 2;
    }
    
	return 0;
}
