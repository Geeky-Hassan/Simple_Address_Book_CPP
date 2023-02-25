#include <iostream>
#include <vector>
#include <string>


// Define a Contact struct to store the name, address, and phone number of a person
struct Contact {
    std::string name;
    std::string address;
    std::string phone_number;
};

// Define a vector of Contacts to store the address book
std::vector<Contact> address_book;


// Define a function to add a new contact to the address book
void add_contact() {
    std::string name, address, phone_number;
    std::cout << "Enter name: "; 
    std::getline(std::cin, name);
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    
    // Check if phone number is 11 digits long
    if (phone_number.length() != 11) {
        std::cout << "Error: Phone number must be exactly 11 digits long.\n";
        return;
    }
    
    // Check if contact already exists
    for (const auto& contact : address_book) {
        if (contact.name == name || contact.phone_number == phone_number) {
            std::cout << "Error: Contact with same name or phone number already exists.\n";
            return; //exit the function if the phone number is invalid
        }
    }
    
    // Create a new Contact struct with the inputted name, address, and phone number
    Contact contact = {name, address, phone_number};
    
    // Add the new contact to the address book vector
    address_book.push_back(contact);
    std::cout << "Contact added.\n";
}

// This function allows the user to edit a contact in the address book.
void edit_contact() {
    
    // Prompt the user to enter the name or phone number of the contact to edit.
    std::string search_term;
    std::cout << "Enter name or phone number of contact to edit: ";
    
    // Get the search term from the user input.
    std::getline(std::cin, search_term);
    
    // Initialize a boolean variable to keep track of whether the contact was found.
    bool found_contact = false;
    
    // Loop through all the contacts in the address book.
    for (auto& contact : address_book) {
        
        // Check if the current contact matches the search term.
        if (contact.name == search_term || contact.phone_number == search_term) {
            
            // Set the boolean variable to true, since the contact was found.
            found_contact = true;
            
            // Prompt the user to enter a new name, address, and phone number for the contact.
            std::string name, address, phone_number;
            
            // Get the new name from the user input.
            std::cout << "Enter new name (or leave blank to keep existing name): ";
            std::getline(std::cin, name);
            
            // If the user entered a new name, update the contact's name.
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
    // If the contact was not found, print a message indicating that the contact was not found.
    if (!found_contact) {
        std::cout << "Contact not found.\n";
    }
}

void delete_contact() {
    // Prompt the user for the name or phone number of the contact to delete
    std::string search_term;
    std::cout << "Enter name or phone number of contact to delete: ";
    std::getline(std::cin, search_term);
    // Initialize a flag to keep track of whether the contact was found
    bool found_contact = false;
    // Loop through the address book and look for the contact with the given name or phone number
    for (auto it = address_book.begin(); it != address_book.end(); ++it) {
        if (it->name == search_term || it->phone_number == search_term) {
            // If the contact is found, set the flag and delete the contact
            found_contact = true;
            it = address_book.erase(it);
            std::cout << "Contact deleted.\n";
            // Exit the loop since we only want to delete one contact
            break;
        }
    }
    // If the contact was not found, print an error message
    if (!found_contact) {
        std::cout<< "Contact not found.\n";
    }
}

void view_all_contacts(const std::vector<Contact>& address_book) {
   // Check if the address book is empty
    if (address_book.empty()) {
        std::cout << "Address book is empty.\n";
    } else {
        // If the address book is not empty, print all the contacts
        std::cout << "All contacts:\n";
        for (const auto& contact : address_book) {
            std::cout << "Name: " << contact.name << "\n";
            std::cout << "Address: " << contact.address << "\n";
            std::cout << "Phone number: " << contact.phone_number << "\n";
            std::cout << "\n";
        }
    }
}

// This function searches for a contact in the address book by name or phone number
void search_contact(const std::vector<Contact>& address_book) {
    std::string search_term;
    std::cout << "Enter name or phone number to search for: ";
    std::getline(std::cin, search_term);
    
    // Initialize a variable to keep track of whether the contact was found
    bool found_contact = false;
    
    // Loop through each contact in the address book
    for (const auto& contact : address_book) {
        // If the contact's name or phone number matches the search term
        if (contact.name == search_term|| contact.phone_number == search_term) {
            // Mark the contact as found
            found_contact = true;
            std::cout << "Contact found:\n";
            std::cout << "Name: " << contact.name << "\n";
            std::cout << "Address: " << contact.address << "\n";
            std::cout << "Phone number: " << contact.phone_number << "\n";
            std::cout << "\n";
            // Break out of the loop, since we've found the contact
            break;
}
}
    //If contact is not there!
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
//You can use switch statement instead of using if else ladder here.
