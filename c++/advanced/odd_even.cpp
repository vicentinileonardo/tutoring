#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool isEvenTurn = true; // Start with even

void printEven(int max) {
    for (int i = 0; i <= max; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return isEvenTurn; }); // Wait for even turn
        cout << i << " ";
        isEvenTurn = false;
        cv.notify_one(); // Notify odd thread
    }
}

void printOdd(int max) {
    for (int i = 1; i <= max; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !isEvenTurn; }); // Wait for odd turn
        cout << i << " ";
        isEvenTurn = true;
        cv.notify_one(); // Notify even thread
    }
}

int main() {
    int maxNumber = 10;

    thread t1(printEven, maxNumber);
    thread t2(printOdd, maxNumber);

    t1.join();
    t2.join();

    cout << endl;
    return 0;
}
