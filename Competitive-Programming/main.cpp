#include<iostream>
#include <vector>
#include <cinttypes>

using namespace std;

 
int get_number_of_divisions(int number_of_candies) {
    if (number_of_candies % 2 == 0) {
        return number_of_candies / 2 - 1;
    }
    return number_of_candies / 2;
}

int main() {
    vector<int> output; 
    int number_of_outputs;
    cin >> number_of_outputs;
    for (int i = 0; i < number_of_outputs; ++i) {
       int n;
       cin >> n;
       output.push_back(get_number_of_divisions(n));
    }

    for (int value : output) {
        cout << value << "\n"; 
    }
	return 0;
}