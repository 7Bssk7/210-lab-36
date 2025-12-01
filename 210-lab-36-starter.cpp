// COMSC-210 | Lab 36 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include "StrBT.h"
using namespace std;

void menu();

int main() {

    fstream inFile("codes.txt");
    StrBinaryTree tree;
    string code;

    if(!inFile){
        cout << "Failed to open the file!" << endl;
        inFile.close();
        return 1;
    }

    while(getline(inFile, code)){
        tree.insertNode(code);
    }

    

    return 0;
}

void menu(){
    cout << "1. Add code" << endl;
    cout << "2. Remove code" << endl;
    cout << "3. Search code" << endl;
    cout << "4. Display code" << endl;
    cout << "5. Exit" << endl;
}