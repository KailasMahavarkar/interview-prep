#include <iostream>
#include <vector>
#include <string>
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

int main()
{
    // visualize `myGraphJson`!
    string myGraphJson = "{\"kind\":{\"graph\":true},"
                         "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
                         "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
    cout << myGraphJson;
}