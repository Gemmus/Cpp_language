/*  File system

Std::filesystem abstracts path handling and directory creation. The library provides functionality to
resolve relative path to absolute path and operators for easy building of paths in a platform
independent way.

Std::filesystem::path has overloaded operators for creating a path by concatenating paths or strings.
The resulting path can be used to open files or for example, to create multiple directories.

Implement a program that asks user to enter directory names or enter a blank line to stop entry. The read names are
stored in a vector of strings. When user has stopped entering directory names the program forms a relative path from the
entered directory names. For example, if user entered “this”, “is”, and “test” the path is “this/is/test” (assuming posix
operating system, on windows the result).

To form a path use concatenation operator defined for std::filesystem::path. Then program creates the path using
create_directories (see: hMps://en.cppreference.com/w/cpp/filesystem/create_directory). AOer creating the directory, the
program opens a text file “result.txt” for wri=ng in the created directory and outputs the following thing both to screen
and the file:
            • Absolute path to the file (there is a func=on to get that)
            • Content of the string vector one per line
            • Rela=ve path to the file
Note that since C++17 ofstream (and fstream in general) constructor can take filesystem::path as parameter.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;

int main() {

    vector<string> directoryNames;
    string names;

    while (true) {
        cout << "Enter directory names or press Enter to quit: ";
        getline(cin, names);

        if (names.empty()) {
            break;
        }
        directoryNames.push_back(names);
    }

    filesystem::path relativePath;
    for (const auto& name : directoryNames) {
        relativePath /= name;
    }

    filesystem::create_directories(relativePath);

    filesystem::path filePath = relativePath / "result.txt";
    ofstream  outputFile(filePath);

    cout << "\nAbsolute path to the file: " << filesystem::absolute(filePath) << endl;
    outputFile << "Absolute path to the file: " << filesystem::absolute(filePath) << endl;
    cout << "Content of the string vector: " << endl;
    outputFile << "Content of the string vector: " << endl;
    for (const auto& name : directoryNames) {
        cout << name << endl;
        outputFile << name << endl;
    }
    cout << "Relative path to the file: " << relativePath << endl;
    outputFile << "Relative path to the file: " << relativePath << endl;

    outputFile.close();

    return 0;
}
