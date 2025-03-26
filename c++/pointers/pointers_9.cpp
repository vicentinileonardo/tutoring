/*
Pointer with Structs

Define a Student struct and use pointers to assign values.

Illustrates struct manipulation using pointers.

---

Puntatore con Structs

Definire una struttura Student e utilizzare i puntatori per assegnare valori.

Illustra la manipolazione della struttura utilizzando i puntatori.
*/

#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
};

int main() {
    Student s1 = {"John", 18};
    Student* ptr = &s1;

    cout << "Student Name: " << ptr->name << endl;
    cout << "Student Age: " << ptr->age << endl;

    return 0;
}
