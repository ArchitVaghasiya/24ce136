#include <iostream>
#include <string>
using namespace std;

int superDigit(string n) {
    if (n.length() == 1)
        return stoi(n);
    long long sum = 0;
    for (char c : n)
        sum += c - '0';
    return superDigit(to_string(sum));
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    long long initialSum = 0;
    for (char c : n)
        initialSum += c - '0';
    initialSum *= k;

    cout << superDigit(to_string(initialSum)) << endl;

    return 0;
}
