#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

bool isWordChar(char ch) {
    return isalnum(ch);
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "Error: Cannot open input.txt\n";
        return 1;
    }

    const int MAX_LINE_LENGTH = 1000;
    const int INITIAL_CAPACITY = 10;

    char** lines = new char*[INITIAL_CAPACITY];
    int capacity = INITIAL_CAPACITY;
    int lineCount = 0;

    char buffer[MAX_LINE_LENGTH];
    int totalChars = 0;
    int totalWords = 0;

    while (file.getline(buffer, MAX_LINE_LENGTH)) {
        int len = strlen(buffer);
        totalChars += len + 1;

        if (lineCount >= capacity) {
            int newCap = capacity * 2;
            char** newLines = new char*[newCap];
            for (int i = 0; i < lineCount; ++i)
                newLines[i] = lines[i];
            delete[] lines;
            lines = newLines;
            capacity = newCap;
        }

        lines[lineCount] = new char[len + 1];
        strcpy(lines[lineCount], buffer);
        lineCount++;

        bool inWord = false;
        for (int i = 0; i < len; ++i) {
            if (isWordChar(buffer[i])) {
                if (!inWord) {
                    totalWords++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    file.close();

    cout << "File Statistics:\n";
    cout << "Total lines: " << lineCount << "\n";
    cout << "Total words: " << totalWords << "\n";
    cout << "Total characters (incl. spaces & punctuation): " << totalChars << "\n";

    for (int i = 0; i < lineCount; ++i)
        delete[] lines[i];
    delete[] lines;

    return 0;
}
