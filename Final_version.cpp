#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string address;
    std::string phone_number;
};

std::vector<Contact> address_book;


void add_contact() {
    std::string name, address, phone_number;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    // Check if contact already exists
    for (const auto& contact : address_book) {
        if (contact.name == name || contact.phone_number == phone_number) {
            std::cout << "Error: Contact with same name or phone number already exists.\n";
            return;
        }
    }
    Contact contact = {name, address, phone_number};
    address_book.push_back(contact);
    std::cout << "Contact added.\n";
}


void edit_contact() {
    std::string search_term;
    std::cout << "Enter name or phone number of contact to edit: ";
    std::getline(std::cin, search_term);
    bool found_contact = false;
    for (auto& contact : address_book) {
        if (contact.name == search_term || contact.phone_number == search_term) {
            found_contact = true;
            std::string name, address, phone_number;
            std::cout << "Enter new name (or leave blank to keep existing name): ";
            std::getline(std::cin, name);
            if (!name.empty()) {
                contact.name = name;
            }
            std::cout << "Enter new address (or leave blank to keep existing address): ";
            std::getline(std::cin, address);
            if (!address.empty()) {
                contact.address = address;
            }
            std::cout << "Enter new phone number (or leave blank to keep existing phone number): ";
            std::getline(std::cin, phone_number);
            if (!phone_number.empty()) {
                contact.phone_number = phone_number;
            }
            std::cout << "Contact updated.\n";
            break;
        }
    }
    if (!found_contact) {
        std::cout << "Contact not found.\n";
    }
}

void delete_contact() {
    std::string search_term;
    std::cout << "Enter name or phone number of contact to delete: ";
    std::getline(std::cin, search_term);
    bool found_contact = false;
    for (auto it = address_book.begin(); it != address_book.end(); ++it) {
        if (it->name == search_term || it->phone_number == search_term) {
            found_contact = true;
            it = address_book.erase(it);
            std::cout << "Contact deleted.\n";
            break;
        }
    }
    if (!found_contact) {
        std::cout<< "Contact not found.\n";
    }
}

void view_all_contacts(const std::vector<Contact>& address_book) {
    if (address_book.empty()) {
        std::cout << "Address book is empty.\n";
    } else {
        std::cout << "All contacts:\n";
        for (const auto& contact : address_book) {
            std::cout << "Name: " << contact.name << "\n";
            std::cout << "Address: " << contact.address << "\n";
            std::cout << "Phone number: " << contact.phone_number << "\n";
            std::cout << "\n";
        }
    }
}

void search_contact(const std::vector<Contact>& address_book) {
    std::string search_term;
    std::cout << "Enter name or phone number to search for: ";
    std::getline(std::cin, search_term);
    bool found_contact = false;
    for (const auto& contact : address_book) {
        if (contact.name == search_term|| contact.phone_number == search_term) {
found_contact = true;
std::cout << "Contact found:\n";
std::cout << "Name: " << contact.name << "\n";
std::cout << "Address: " << contact.address << "\n";
std::cout << "Phone number: " << contact.phone_number << "\n";
std::cout << "\n";
break;
}
}
if (!found_contact) {
std::cout << "Contact not found.\n";
}
}

int main() {
std::string command;
while (true) {
std::cout << "Enter a command (add, edit, delete, view, search, or quit): ";
std::getline(std::cin, command);
if (command == "add") {
add_contact();
} else if (command == "edit") {
edit_contact();
} else if (command == "delete") {
delete_contact();
} else if (command == "view") {
view_all_contacts(address_book);
} else if (command == "search") {
search_contact(address_book);
} else if (command == "quit") {
std::cout << "Goodbye!\n";
break;
} else {
std::cout << "Invalid command.\n";
}
}
return 0;
}