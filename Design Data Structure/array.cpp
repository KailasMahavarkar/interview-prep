#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

class MyArray {
   private:
    int* m_data;
    int m_size;

   public:
    MyArray(int size) {
        m_size = size;
        m_data = new int[size];

        for (int i = 0; i < size; i++) {
            m_data[i] = 0;
        }
    }

    ~MyArray() {
        delete[] m_data;
    }

    int& operator[](int index) {
        return m_data[index];
    }
};

int main() {
    MyArray arr(5);  // create a new array with size 5

    arr[0] = 1;  // set the first element to 1
    arr[1] = 2;  // set the second element to 2

    cout << arr[0] << endl;  // prints 1
    cout << arr[1] << endl;  // prints 2
}