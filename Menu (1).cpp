#include "Menu.h"

Menu::Menu(ifstream &finput) {
    string line, name, code;
    double price;
    finput >> numItems;
    getline(finput, line);
//reads all of the text in the .txt file 
    items = new MenuItem* [numItems];
    for(int i=0; i<numItems; i++) {
        finput >> code >> name >> price;
        items[i] = new MenuItem(code, name, price);
    }
}

//search for specific code & return MenuItem pointer
//if code is not found, return NULL
MenuItem* Menu::find(string code) {
    for(int i=0; i<numItems; i++)
        if (code == items[i]->getCode())
            return items[i];  
    return NULL;
}