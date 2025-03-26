/*
Implement strcpy() Using Pointers

Write your own version of `strcpy()` using pointer arithmetic.

Move through the source string using a pointer and copy each character to the destination.

*/

#include <iostream>
using namespace std;

// src is not modified, so it is declared as const
void myStrcpy(char* dest, const char* src) {
    /*
    each character from the source string is copied to the destination string
    we move the pointers to the next character in each iteration
    until the null character is encountered
    */
    while ((*dest++ = *src++) != '\0');
}

int main() {
    char src[] = "Hello";
    char dest[10];          // Destination string should be large enough to hold the source string
    
    myStrcpy(dest, src);
    cout << "Source string: " << src << endl; // Output: "Hello"
    cout << "Copied string: " << dest << endl; // Output: "Hello"
    
    return 0;
}
