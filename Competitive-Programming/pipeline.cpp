#include <iostream>
#include <vector>

using namespace std;

int64_t get_pipe_count(int64_t splitter_max, int64_t splitter) {
    int64_t count = splitter_max;

    for (int64_t i = splitter_max - 1; i >= splitter; i--) {
        count += (i - 1);
    }
    
    return count;
}

int64_t get_number_of_splitters(int64_t min_splitter, int64_t max_splitter) {
    int64_t count = 0;

    for (int64_t i = max_splitter; i >= min_splitter; i--) {
        count++;
    }
    
    return count;
}


int64_t minimum_number_of_splitters2(int64_t  number_of_splitters, int64_t number_of_houses) {
    int64_t begin = 0; 
    
    int64_t middle = number_of_splitters / 2;
//    if (number_of_splitters % 2 == 0) middle++; 
    
    int64_t end = number_of_splitters - 1; 
    int64_t  max_splitter = number_of_splitters + 1;
    
    while (begin <= end) {
        middle = (begin + end) / 2;
        if ((begin + end) % 2 == 0) middle++;

        int64_t pipe_count = get_pipe_count(max_splitter, middle + 2);  

        if (pipe_count == number_of_houses) {
            return get_number_of_splitters(middle + 2, max_splitter);
        }

        if (pipe_count > number_of_houses) {
            if (begin == middle) break;
            begin = middle;
        }
        else if (middle == end && pipe_count < number_of_houses) {
            return -1;
        } 
        else {
            end = middle;
        }
    }

    if (get_pipe_count(max_splitter, middle) > number_of_houses) {
        return get_number_of_splitters(middle + 2, max_splitter);
    }
    
    return -1;
}  


int main() {
    int64_t n, k; 
    cin >> n >> k;

    
    int64_t result = minimum_number_of_splitters2(k - 1, n);
    
    cout << result;
    
	return 0;
}
