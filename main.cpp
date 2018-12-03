#include <iostream>

using namespace std;


string helloName(string input) {
    return "hello " + input;

}

int main() {
    cout << helloName("world") << endl;
    return 0;

}
