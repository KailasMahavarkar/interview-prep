#include <bits/stdc++.h>
using namespace std;

int main(){

    // int num = 5;
    // int *ptr = &num;

    // cout << "value is: " << *ptr << endl;
    // cout << "address is: " << ptr << endl;

    // ----------------------------------------

    // double d = 4.3;
    // double *p2 = &d;

    // cout << "address is: " << p2 << endl;
    // cout << "value is: " << *p2 << endl;
    // cout << "size is: " << sizeof(d) << " bytes" << endl;
    // cout << "size of pointer: " << sizeof(p2) << " bytes" << endl;


    // ----------------------------------------

    // pointer is pointing to garbage addres (dont do this);
    // int num = 5;
    // int *p = &num;
    // int **q = &p;
    
    // cout << p << endl;
    // cout << q << endl;

    int intArray[10] = {10, 20, 30};
    int *i = &intArray[0];
    cout << &i[0] << endl;

    cout << "---------" << endl;

    char charArray[10] = "kai";
    char *c = &charArray[0];

    cout << &c << endl;
    
    return 0;
}