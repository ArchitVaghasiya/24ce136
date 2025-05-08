#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> wordCount;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        wordCount[word]++;
    }

    cout << "Word Frequency Distribution:\n";
    for (const auto& entry : wordCount) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
