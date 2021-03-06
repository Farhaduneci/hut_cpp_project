#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
    string first, last, nCode, bDay;
    bool pos;
public:
    User(string first, string last, string nCode, string bDay, bool pos) {
        this -> first = first;
        this -> last = last;
        this -> nCode = nCode;
        this -> bDay = bDay;
        this -> pos = pos;
    }

    bool saveToFile() {
        string userCode = this -> nCode;
        string fileName = (userCode).append(".user");
        ofstream fileStream;
        try {
            fileStream.open("./Users/" + fileName); // open the file, or create it.
            fileStream << "Name: " << this -> first << endl;
            fileStream << "Last: " << this -> last << endl;
            fileStream << "nCode: " << this -> nCode << endl;
            fileStream << "bDay: " << this -> bDay << endl;
            fileStream.close(); // We always need to close our files.
        } catch (const exception& ex) {
            cerr << ex.what() << endl;
            system("pause");
            return false;
        }
        return true;
    }

    ~User() = default;
};