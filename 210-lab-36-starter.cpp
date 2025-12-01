// COMSC-210 | Lab 36 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <string>
#include "StrBT.h"
using namespace std;

void menu();

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

    /*
    while(getline(inFile, code)){
        tree.insertNode(code);
    }
    */    

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
                tree.displayInOrder();
            }
            else if(choice == 2){

            }
            else if(choice == 3){

            }
            else if(choice == 4){

            }
            menu();
            cin >> choice;
        }

    }
    
    

    return 0;
}

void menu(){
    cout << "1. Add code" << endl;
    cout << "2. Remove code" << endl;
    cout << "3. Search code" << endl;
    cout << "4. Display code" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}