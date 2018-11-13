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
void deleteContact(vector <Contact> &contacts, int indexToDelete);
void showContacts(vector <Contact> contacts);

int main() {
    vector <Contact> contacts;
    bool running = true;
    int add;

    while (running) {
        cout << "(1) to add more contacts, (2) to delete a contact, (3) to show all contacts, (0) to exit program -> ";
        cin >> add;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (add == 1) {
            contacts.push_back(addContact());
        } else if (add == 2) {
            deleteContact(contacts, 0); //to finish
        } else if (add == 3) {
            showContacts(contacts);
        } else {
            running = false;
        }

        system("cls");
    }

    cout << "Number of contacts: " << contacts.size() << endl;

    return 0;
}

Contact addContact() {
    Contact c1;

    cout << "First name: ";
    getline(cin, c1.firstName);
    cout << "Last name: ";
    getline(cin, c1.lastName);
    cout << "Mobile Phone: ";
    getline(cin, c1.mobilePhone);
    cout << "Your email: ";
    getline(cin, c1.email);

    return c1;
}

void deleteContact(vector <Contact> &contacts, int indexToDelete) {
    contacts.erase(contacts.begin() + indexToDelete);
}

void showContacts(vector <Contact> contacts) {
    system("cls");

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

    cout << "Press enter to go back ...";
    getchar();
}
