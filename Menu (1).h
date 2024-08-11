#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include "MenuItem.h"

using namespace std;

class Menu
{
    public:
        Menu(ifstream &finput);

        //search for specific code & return MenuItem pointer
        //if code is not found, return NULL
        MenuItem *find(string code);

    private:
        MenuItem **items; //for array of MenuItem*
        int numItems;    //count of MenuItem objects
};
#endif // MENU_H