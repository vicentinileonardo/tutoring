/*
Implement a Function to Swap Two Numbers Using Pointers without Using a Temporary Variable
*/

#include <iostream>
using namespace std;

void swapNumbers(int* a, int* b) {
    cout << "Before: a = " << *a << ", b = " << *b << endl;
    
    *a = *a + *b;
    cout << "1 step) a = " << *a << ", b = " << *b << endl;
   
    *b = *a - *b;
    cout << "2 step) a = " << *a << ", b = " << *b << endl;
    
    *a = *a - *b;
    cout << "3 step) a = " << *a << ", b = " << *b << endl;
}

int main() {
    int x = 5, y = 10;
    swapNumbers(&x, &y);
    cout << endl;
    cout << "In main" << endl;
    cout << "Swapped: x = " << x << ", y = " << y << endl;
    return 0;
}
