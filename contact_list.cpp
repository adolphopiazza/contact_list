#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
#include <iostream>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
using namespace std;

struct Contact {
    string firstName;
    string lastName;
    string mobilePhone;
    string email;
};

Contact addContact();
void deleteContact(vector <Contact> &contacts);
void showContacts(vector <Contact> contacts, bool itemRemoval = false);
void openFile(vector <Contact> &contacts);
void save(vector <Contact> contacts);
void clearBuffer();
vector <string> split(string data, string delimiter);

int main() {
    vector <Contact> contacts;
    int add;

    do {
        cout << "(1) to add more contacts" << endl;
        cout << "(2) to delete a contact" << endl;
        cout << "(3) to show all contacts" << endl;
        cout << "(8) to load data from a file" << endl;
        cout << "(9) to save data to a file" << endl;
        cout << "(0) to exit program -> ";
        cin >> add;
        clearBuffer();

        if (add == 1) {
            contacts.push_back(addContact());
        } else if (add == 2) {
            deleteContact(contacts);
        } else if (add == 3) {
            showContacts(contacts);
        } else if (add == 8) {
            openFile(contacts);
        } else if (add == 9) {
            save(contacts);
        }

        system(CLEAR);
    } while (add != 0);

    return 0;
}

Contact addContact() {
    Contact c1;

    system(CLEAR);
    cout << "========Add Contact========" << endl;
    cout << "\n\tFirst name: ";
    getline(cin, c1.firstName);
    cout << "\tLast name: ";
    getline(cin, c1.lastName);
    cout << "\tMobile Phone: ";
    getline(cin, c1.mobilePhone);
    cout << "\tYour email: ";
    getline(cin, c1.email);

    return c1;
}

void deleteContact(vector <Contact> &contacts) {
    int index;

    showContacts(contacts, true);
    if (contacts.size() < 1) {
        cout << "\nNothing to delete." << endl;
    } else {
        cout << "\nWhat are the index that you want to remove? -> ";
        cin >> index;
        clearBuffer();

        if (index > (contacts.size() - 1) || index < 0) {
            cout << "\t-> Invalid index." << endl;
        } else {
            contacts.erase(contacts.begin() + index);
            cout << "Index " << index << " was removed." << endl;
        }
    }

    cout << "Press enter to go back...";
    getchar();
}

void showContacts(vector <Contact> contacts, bool itemRemoval) {
    system(CLEAR);

    if (contacts.size() < 1) {
        cout << "\tThere is no contacts to show." << endl;
    } else {
        cout << "========Contacts(" << contacts.size() << ")========" << endl << endl;

        for (unsigned int i = 0; i < contacts.size(); i++) {
            cout << "\t(" << i << ")" << endl;
            cout << "\tName: " << contacts[i].firstName << " " << contacts[i].lastName << endl;
            cout << "\tMobile Phone: " << contacts[i].mobilePhone << endl;
            cout << "\tEmail: " << contacts[i].email << endl;
            cout << "========" << endl;
        }
    }

    if (!itemRemoval) {
        cout << "Press enter to go back ...";
        getchar();
    }
}

void openFile(vector <Contact> &contacts) {
    system(CLEAR);
    string nameOfFile;
    ifstream file;
    vector <string> tmp;
    string lineTmp;

    cout << "========OPEN FILE========" << endl;
    cout << "\n\tEnter the name of the file that you want to open: ";
    getline(cin, nameOfFile);

    file.open(nameOfFile + ".bido", ios::binary);
    if (file.is_open()) {
        while (getline(file, lineTmp)) {
            tmp = split(lineTmp, ",");

            Contact c1;
            c1.firstName = tmp[0];
            c1.lastName = tmp[1];
            c1.mobilePhone = tmp[2];
            c1.email = tmp[3];

            contacts.push_back(c1);
        }

        cout << "\tFile opened with success!" << endl;
    } else {
        cout << "\tFile do not exist in the current folder." << endl;
    }

    cout << "Press enter to go back...";
    getchar();
}

void save(vector <Contact> contacts) {
    system(CLEAR);
    string nameOfFile;
    ofstream file;

    if (contacts.size() < 1) {
        cout << "\tNothing to save." << endl;
    } else {
        cout << "========SAVE========" << endl;
        cout << "\n\tEnter the name of the file you want to save: ";
        getline(cin, nameOfFile);

        file.open(nameOfFile + ".bido", ios::binary);

        cout << "\tSaving..." << endl;
        for (unsigned int i = 0; i < contacts.size(); i++) {
            file << contacts[i].firstName << "," << contacts[i].lastName;
            file << "," << contacts[i].mobilePhone << "," << contacts[i].email << "\n";
        }

        file.close();
        cout << "\n\tAll contents are saved to " << nameOfFile << endl;
    }

    cout << "Press enter to go back...";
    getchar();
}

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

vector <string> split(string data, string delimiter) {
    int delimiterIndex;
    vector <string> splitted;

    while (true) {
        delimiterIndex = data.find(delimiter);

        if (delimiterIndex == -1) {
            delimiterIndex = data.find("\n");
            splitted.push_back(data.substr(0, delimiterIndex));
            break;
        }

        splitted.push_back(data.substr(0, delimiterIndex));
        data.erase(0, delimiterIndex + 1);
    }

    return splitted;
}
