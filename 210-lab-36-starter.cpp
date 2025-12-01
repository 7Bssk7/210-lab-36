// COMSC-210 | Lab 36 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include "StrBST.h"
using namespace std;

int main() {

    fstream inFile("codes.txt");
    string code;

    if(!inFile){
        cout << "Failed to open the file!" << endl;
        inFile.close();
        return 1;
    }

    while(getline(inFile, code)){
        StrBinaryTree tree;

        tree.insertNode(code);
    }

    
    

    return 0;
}