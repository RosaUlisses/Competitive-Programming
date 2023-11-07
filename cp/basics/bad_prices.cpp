#include <iostream>
#include <vector>

using namespace std;

int get_number_of_bad_prices(vector<int>& prices) {
    int number_of_bad_prices = 0;
    int min = prices[prices.size() - 1];

    for (int i = prices.size() - 2; i >= 0; --i) {
        if (prices[i] > min) number_of_bad_prices++;
        else min = prices[i];
    }

    return number_of_bad_prices;
}

int main() {
    int number_of_sets;
    cin >> number_of_sets;

    vector<int> output;

    for (int i = 0; i < number_of_sets; ++i) {
        int size;
        cin >> size;
        vector<int> prices;
        for (int j = 0; j < size; ++j) {
            int value;
            cin >> value;
            prices.push_back(value);
        }
        output.push_back(get_number_of_bad_prices(prices));
    }

    cout << "\n";

    for (int value : output) {
        cout << value << "\n";
    }

    return 0;
}
