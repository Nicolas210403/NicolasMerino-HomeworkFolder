#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class CustomException : public std::exception {
private:
    std::string message;
public:
    explicit CustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("You cannot divide by zero.");
    }
    return static_cast<double>(numerator) / denominator;
}

int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds.");
    }
    return arr[index];
}

void nestedFunction() {     
    throw CustomException("Error in nestedFunction");
}

void outerFunction() {     
    try {
        nestedFunction();
    } catch (const CustomException& e) {
        std::cout << "Caught exception in outerFunction: " << e.what() << std::endl;
        throw; 
    }
}

int main() {
    try {
        outerFunction();
    } catch (const CustomException& e) {
        std::cout << "Caught rethrown exception in main: " << e.what() << "\n" << std::endl;
    }

    int numerator = 0;
    int denominator = 0;
    
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    try {
        double result = divide(numerator, denominator);
        std::cout << "Result: " << result << "\n" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n" << std::endl;
    }

    int size = 0;
    int index = 0;

    std::cout << "Enter array size: ";
    std::cin >> size;
    std::cout << "Enter index to access: ";
    std::cin >> index;

    std::vector<int> safeArray(size > 0 ? size : 1, 0);

    try {
        // Pass internal contiguous storage array data cleanly without using raw pointer variables
        int value = accessArray(safeArray.data(), size, index);
        std::cout << "Value: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}