#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("D:/text/input.txt");
    ofstream fout("D:/text/output.txt");

    Vector v1, v2(5), v3(nullptr, 0);

    fin >> v1 >> v2;

    fout << v1 << endl;
    fout << v2 << endl;

    v3 = v2;
    fout << v3 << endl;

    Vector v4(move(v3));
    fout << v4 << endl;

    Vector v5(v4);
    fout << v5 << endl;

    int a[5] = { 1, 2, 3, 4, 5 };
    bool res = v2 < Vector(a, 5);
    fout << boolalpha << res << endl;

    return 0;
}
