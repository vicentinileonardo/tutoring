/*
Implement a Function to Find the Length of a String Using Pointers
*/

#include <iostream>
using namespace std;

int getStringLength(const char* str) {
    /*
    ptr is a pointer to a constant character (const char*)
    You cannot modify the characters that ptr is pointing to
    You can move ptr to point to other memory locations.
    */
    const char* ptr = str; 
    while (*ptr) ptr++;
    return ptr - str;
}

int main() {
    char str[] = "Hello, world! 1234567890";
    cout << "Length: " << getStringLength(str) << endl;
    return 0;
}
