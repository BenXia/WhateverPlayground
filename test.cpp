#include <iostream>
using namespace std;

bool different(int a, int b) {
    return a - b;
}

int main(int argc, const char * argv[]) {
    bool result = different(11, 9);

    if ((11 - 9) == true) {
        cout << "(11 - 9) == true" << endl;
    }

    if (result == true) {
        cout << "different(11 - 9) == true" << endl;
    }
    if (((bool)(11 - 9)) == true) {
        cout << "((bool)(11 - 9)) == true" << endl;
    }

    cout << "result=" << result << "\ntrue=" << true << "\nfalse=" << false << endl;

    return 0;
}
