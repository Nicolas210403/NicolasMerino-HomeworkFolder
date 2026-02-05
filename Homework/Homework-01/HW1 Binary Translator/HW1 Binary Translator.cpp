#include <iostream>
#include <bitset>
#include <cstring>
#include <cstdint>
#include <stdint.h>
using namespace std;

  
int main () {
    
    char c;
    int i;
    float f;

    uint32_t bitRepresentation;  

    cout << "Enter a letter or character: ";   // Getting char, int, and float values from user input.
    cin >> c;
    cout << "Enter a whole integer: ";
    cin >> i;
    cout << "Enter a decimal: ";
    cin >> f;

    cout << "The binary value of " << c << " is: " << bitset<8>(c) << endl;  // Binary conversion and output.
    cout << "The binary value of " << i << " is: " << bitset<32>(i) << endl;
    memcpy(&bitRepresentation, &f, sizeof(f));
    cout << "The binary value of " << f << " is: " << bitset<32>(bitRepresentation) << endl;


    return 0;
}