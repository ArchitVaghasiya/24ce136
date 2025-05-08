#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

void toLower(char* word) {
    for (int i = 0; word[i]; i++)
        word[i] = tolower(word[i]);
}

bool isWordChar(char ch) {
    return isalnum(ch);
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile || !outFile) {
        cout << "Error\n";
        return 1;
    }

    const int MAX = 10000;
    char* buffer = new char[MAX];
    inFile.read(buffer, MAX - 1);
    buffer[inFile.gcount()] = '\0';

    char* words[1000];
    int count[1000];
    int totalWords = 0;

    char word[100];
    int wlen = 0;

    for (int i = 0; buffer[i]; i++) {
        if (isWordChar(buffer[i])) {
            word[wlen++] = tolower(buffer[i]);
        } else if (wlen > 0) {
            word[wlen] = '\0';
            wlen = 0;

            bool found = false;
            for (int j = 0; j < totalWords; j++) {
                if (strcmp(word, words[j]) == 0) {
                    count[j]++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                words[totalWords] = new char[strlen(word) + 1];
                strcpy(words[totalWords], word);
                count[totalWords] = 1;
                totalWords++;
            }
        }
    }

    outFile << "Word Frequencies:\n";
    for (int i = 0; i < totalWords; i++) {
        outFile << words[i] << ": " << count[i] << "\n";
        delete[] words[i];
    }

    delete[] buffer;
    inFile.close();
    outFile.close();

    cout << "Done. See output.txt\n";
    return 0;
}
