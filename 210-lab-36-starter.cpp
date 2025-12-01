// COMSC-210 | Lab 36 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <string>
#include "StrBT.h"
using namespace std;

void menu();
void ds_menu();

int main() {

    fstream inFile("codes.txt");
    StrBinaryTree tree;
    string code;
    int choice;

    if(!inFile){
        cout << "Failed to open the file!" << endl;
        inFile.close();
        return 1;
    }

    while(getline(inFile, code)){
        tree.insertNode(code);
    }

    menu();
    cin >> choice;
    while(choice != 5){
        if((choice < 1) || (choice > 5)){
            cout << "\nInvalid input, please enter your choice again!" << endl;
            menu();
            cin >> choice;
        }
        else{
            if(choice == 1){
                string inCode;
                cout << "\nInput your code(8 characters long): ";
                cin >> inCode;
                while((inCode.size() < 8) || (inCode.size() > 8) ){
                    cout << "\nInvalid input, please enter your code again!" << endl;
                    cout << "Input your code(8 characters long): ";
                    cin >> inCode;
                }
                tree.insertNode(inCode);
            }
            else if(choice == 2){
                string delCode;
                cout << "\nWhat code would you like to remove?(8 characters long) -> ";
                cin >> delCode;
                if(tree.searchNode(delCode)){
                    cout << delCode << " was found successfully" << endl;
                    tree.remove(delCode);
                    cout << delCode << " is removed from the BST" << endl;
                }
                else{
                    cout << "Code not found" << endl;
                }
            }
            else if(choice == 3){
                string srcCode;
                cout << "What code would you like to search for?(8 characters long) -> ";
                cin >> srcCode;
                if(tree.searchNode(srcCode)){
                    cout << srcCode << " was found successfully" << endl;
                }
                else{
                    cout << "Code not found" << endl;
                }

            }
            else if(choice == 4){
                int ds_choice;

                cout << "\nHow would you like to display the tree?" << endl;
                ds_menu();
                cin >> ds_choice;
                if((ds_choice < 1) || (ds_choice > 3)){
                    cout << "\nInvalid input, please enter your choice again!" << endl;
                    ds_menu();
                    cin >> ds_choice;
                }
                else{
                    if(ds_choice == 1){

                    }
                    else if(ds_choice == 2){

                    }
                    else if(ds_choice == 3){

                    }
                }
            }
            menu();
            cin >> choice;
            
        }

    }
    
    

    return 0;
}

void menu(){
    cout << "\n1. Add code" << endl;
    cout << "2. Remove code" << endl;
    cout << "3. Search code" << endl;
    cout << "4. Display code" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void ds_menu(){
    cout << "1.Display in order" << endl;
    cout << "2.Display preorder" << endl;
    cout << "3.Display postorder" << endl;
    cout << "Enter your choice: ";
}