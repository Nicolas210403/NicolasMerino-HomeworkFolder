#include<iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Enter an input, it can be a word or a sentence, press enter when you are ready to count the vowels: ";
    std::getline(std::cin, str);

    int vowelCount = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowelCount++;
        }
    }

    std::cout << "Number of vowels in your input is: " << vowelCount << std::endl;

    return 0;
}