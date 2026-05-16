#include <iostream>
#include <vector>
#include <map>

int main() {
    std::map<int, int> numbers1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    std::map<int, int> numbers2 = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}, {6, 60}, {7, 70}, {8, 80}, {9, 90}};

    std::map<int, std::vector<int>> interlaced;

    std::map<int, int>::iterator it;
    for (it = numbers1.begin(); it != numbers1.end(); ++it) {
        std::vector<int> temp;
        temp.push_back(it->second);
        temp.push_back(numbers2[it->first]); 
        interlaced[it->first] = temp;
    }

    std::cout << "Interlaced map (numbers1): ";
    std::map<int, std::vector<int>>::iterator it2;
    for (it2 = interlaced.begin(); it2 != interlaced.end(); ++it2) {
        std::cout << it2->first << ": " << it2->second[0] << ", " << it2->second[1] << " ";
    }

    std::cout << std::endl;
    return 0;
}

