/*
Bit Manipulation: Count Set Bits in an Integer

Count the number of 1s in the binary representation of an integer.
*/

#include <iostream>
using namespace std;

void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;     // check if the last bit is set
        cout << "count: " << count << "\n";
        n >>= 1;            // right shift by 1 bit
        printBinary(n);
    }
    return count;
}



int main() {
    int n = 112342329;
    cout << "Number: " << n << endl;
    cout << "Binary representation of " << n << ": ";
    printBinary(n);
    cout << "----------------------------------\n";  

    int count = countSetBits(n);
    cout << "----------------------------------\n";
    cout << "Number of set bits in " << n << ": " << count << endl;
    return 0;
}
