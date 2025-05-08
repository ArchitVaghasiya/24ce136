#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {
    std::map<std::string, std::vector<std::string>> directory;

    int choice;
    std::string folder, filename;

    while (true) {
        std::cout << "\nDirectory Management System\n";
        std::cout << "1. Add Folder\n";
        std::cout << "2. Add File to Folder\n";
        std::cout << "3. Display Directory Structure\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore();
        if (choice == 1) {
            std::cout << "Enter folder name to add: ";
            std::getline(std::cin, folder);
            if (directory.find(folder) == directory.end()) {
                directory[folder] = std::vector<std::string>();
                std::cout << "Folder added successfully.\n";
            } else {
                std::cout << "Folder already exists.\n";
            }

        } else if (choice == 2) {
            std::cout << "Enter folder name to add file to: ";
            std::getline(std::cin, folder);
            if (directory.find(folder) != directory.end()) {
                std::cout << "Enter file name: ";
                std::getline(std::cin, filename);
                directory[folder].push_back(filename);
                std::cout << "File added to folder.\n";
            } else {
                std::cout << "Folder does not exist. Please add it first.\n";
            }

        } else if (choice == 3) {
            std::cout << "\nDirectory Structure:\n";
            for (auto it = directory.begin(); it != directory.end(); ++it) {
                std::cout << "Folder: " << it->first << "\n";
                for (const auto& file : it->second) {
                    std::cout << "  - " << file << "\n";
                }
            }

        } else if (choice == 4) {
            std::cout << "Exiting Directory Management System.\n";
            break;

        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
