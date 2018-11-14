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
void clearBuffer();

int main() {
    vector <Contact> contacts;
    int add;

    do {
        cout << "(1) to add more contacts, (2) to delete a contact, (3) to show all contacts, (0) to exit program -> ";
        cin >> add;
        clearBuffer();

        if (add == 1) {
            contacts.push_back(addContact());
        } else if (add == 2) {
            deleteContact(contacts);
        } else if (add == 3) {
            showContacts(contacts);
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

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
