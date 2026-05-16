#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    std::vector<int> tempVector;

    int total_elements = numbers1.size() + numbers2.size();
    
    for (int i = 0; i < total_elements; ++i) {
        if (i % 2 == 0) {
            tempVector.push_back(numbers1[i / 2]);
        } else {
            tempVector.push_back(numbers2[i / 2]);
        }
    }

    numbers1.clear();
    for (int val : tempVector) {
        numbers1.push_back(val);
    }

    std::cout << "Interlaced vector (numbers1): ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}