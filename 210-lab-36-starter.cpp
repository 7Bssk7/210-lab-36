// COMSC-210 | Lab 36 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <string>
#include "StrBT.h"
using namespace std;

const int CODE_SIZE = 8;

// Function prototypes for menu output
void menu();
void ds_menu();

int main() {

    fstream inFile("codes.txt"); // Open the input file containing codes
    StrBinaryTree tree; // Create a BST object
    string code; // Temporary string to hold each code read from file
    int choice; // User's menu choice

    // Check if file opened successfully
    if(!inFile){
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    // Read codes line by line from file and insert them into the BST
    while(getline(inFile, code)){
        tree.insertNode(code);
    }
    inFile.close();

    // Output menu and get initial choice
    menu();
    cin >> choice;

    // Loop until user chooses option 6 (Exit)
    while(choice != 6){
        // Validate input: must be between 1 and 6
        if((choice < 1) || (choice > 6)){
            cout << "\nInvalid input, please enter your choice again!" << endl;
            menu();
            cin >> choice;
        }
        else{
            // Add a new code
            if(choice == 1){
                string inCode;
                cout << "\nInput your code(8 characters long): ";
                cin >> inCode;
                // Validate code length (must be exactly 8 characters)
                while( inCode.size() != CODE_SIZE){
                    cout << "\nInvalid input, please enter your code again!" << endl;
                    cout << "Input your code(8 characters long): ";
                    cin >> inCode;
                }
                tree.insertNode(inCode);
            }
            // Remove an existing code
            else if(choice == 2){
                string delCode;
                cout << "\nWhat code would you like to remove?(8 characters long) -> ";
                cin >> delCode;
                // Check if code exists before removing
                if(tree.searchNode(delCode)){
                    cout << delCode << " was found successfully" << endl;
                    tree.remove(delCode);
                    cout << delCode << " is removed from the BST" << endl;
                }
                else{
                    cout << "Code not found" << endl;
                }
            }
            // Search for a code
            else if(choice == 3){
                string srcCode;
                cout << "What code would you like to search for?(8 characters long) -> ";
                cin >> srcCode;
                // Search and report result
                if(tree.searchNode(srcCode)){
                    cout << srcCode << " was found successfully" << endl;
                }
                else{
                    cout << "Code not found" << endl;
                }

            }
            // Modify an existing code (remove old, insert new)
            else if(choice == 4){
                string oldCode, newCode;
                cout << "\nWhat code would you like to modify?(8 characters long) -> ";
                cin >> oldCode;
                // Check if old code exists
                if(tree.searchNode(oldCode)){
                    cout << oldCode << " was found successfully" << endl;

                    cout << "Modify " << oldCode << " : ";
                    cin >> newCode;
                    // Validate new code length
                    while( newCode.size() != CODE_SIZE){
                        cout << "\nInvalid input, please enter your code again!" << endl;
                        cout << "Modify " << oldCode << " : ";
                        cin >> newCode;
                    }

                    cout << oldCode << " modified successfully" << endl;
                    cout << "New code: " << newCode << endl;

                    // Remove old code and insert new on
                    tree.remove(oldCode);
                    tree.insertNode(newCode);
                }
                else{
                    cout << "Code not found" << endl;
                }
            }
            // Output the tree in chosen traversal order
            else if(choice == 5){
                int ds_choice;

                cout << "\nHow would you like to display the tree?" << endl;
                // Show output options
                ds_menu();
                cin >> ds_choice;
                // Validate input
                while((ds_choice < 1) || (ds_choice > 3)){
                    cout << "\nInvalid input, please enter your choice again!" << endl;
                    ds_menu();
                    cin >> ds_choice;
                }
                // Output based on the users input
                if(ds_choice == 1){
                    tree.displayInOrder();
                }
                else if(ds_choice == 2){
                    tree.displayPreOrder();
                }
                else if(ds_choice == 3){
                    tree.displayPostOrder();
                }
                
            }
            // Show menu again and get next choice
            menu();
            cin >> choice;
            
        }

    }
    
    

    return 0;
}

// menu() - outputs the main menu 
// arguments: none
// return: none, void function 
void menu(){
    cout << "\n1. Add code" << endl;
    cout << "2. Remove code" << endl;
    cout << "3. Search code" << endl;
    cout << "4. Modify code" << endl;
    cout << "5. Display code" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

// menu() - outputs the traversal options 
// arguments: none
// return: none, void function 
void ds_menu(){
    cout << "1.Display in order" << endl;
    cout << "2.Display preorder" << endl;
    cout << "3.Display postorder" << endl;
    cout << "Enter your choice: ";
}