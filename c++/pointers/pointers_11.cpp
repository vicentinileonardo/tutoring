/*
Implement a Function to Reverse a String Using Pointers

Write a function that takes a char* pointing to a string and reverses it in-place using pointer arithmetic.

Use two pointers: one pointing to the beginning and the other to the end.
Swap characters and move the pointers inward until they meet.
The function is void since it modifies the input string in-place and not returning anything.
*/

#include <iostream>
using namespace std;

void reverseString(char* str) {
    char* end = str;        // Create a pointer `end` to the beginning of the string like `str`
    while (*end) end++;     // Move `end` pointer to the end of the string
    end--;                  // Move one step back to the last valid character, excluding the null terminator '\0'

    while (str < end) {     // while the two pointers don't meet at the middle of the string
        swap(*str, *end);   // `swap()` is a built-in function in C++ to swap two values (characters in this case)
        str++;
        end--;
    }
}

int main() {
    char str[] = "Ciao mondo!";
    cout << "Original: " << str << endl;    // Output: "Ciao mondo!"
    reverseString(str);                     // str represents the address of the first character of the string
    cout << "Reversed: " << str << endl;    // Output: "!odnom oaiC"

    return 0;
}
