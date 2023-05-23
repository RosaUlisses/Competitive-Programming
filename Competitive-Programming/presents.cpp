#include <iostream>
#include <vector>

using namespace std;

int main() {
    int number_of_friends;
    cin >> number_of_friends;
    vector<int> output(number_of_friends);
    
    for (int i = 0; i < number_of_friends; ++i) {
        int friend_number;
        cin >> friend_number;
        output[friend_number - 1] = i + 1;
    }

    for (int value : output) {
        cout << value << " ";
    }

	return 0;
}
