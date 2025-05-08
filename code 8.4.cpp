#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::pair<std::string, int>> students;

    int n;
    std::cout << "Enter the number of students: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string name;
        int score;
        std::cout << "Enter name of student " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Enter score of " << name << ": ";
        std::cin >> score;
        students.push_back({name, score});
    }

    std::sort(students.begin(), students.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
    });

    std::cout << "\nRanked list of students:\n";
    for (int i = 0; i < students.size(); ++i) {
        std::cout << "Rank " << i + 1 << ": " << students[i].first << " with score " << students[i].second << std::endl;
    }

    return 0;
}
