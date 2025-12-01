// COMSC-210 | Lab 36 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include "StrBT.h"
using namespace std;

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

    tree.displayInOrder();    

    return 0;
}