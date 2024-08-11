#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "Table.h"
#include "Order.h"

using namespace std;

int main()
{
    ifstream finput("config.txt");
    Menu menu(finput);

    Table **tables;
    int numTables;
    //read remaining file & get table information
    finput >> numTables;

    string line;
    getline(finput, line); //to read & get rid of extra information like  Tables:  table #, max seats

    tables = new Table* [numTables];
    int tableId, capacity;
    for(int i=0; i<numTables; i++) {
        finput >> tableId >> capacity;
        tables[i] = new Table(tableId, capacity);
    }
    
    //read the commands and process them!
    string command; //table number
    string option; //P, C, O, S
    int partyNumber;
    int isDigit = 0;
    
    while(cin>>command)
    {
        
        if(command == "C")
        {
            return 0;
        }
        
        else
        {
            int tableNum = stoi(command);
            
            cin>>option;
            
            //clean
            if(option == "C")
            {
               tables[tableNum-1]->cleanup();
            }
            
            
            //serve
            else if(option == "S")
            {
                tables[tableNum-1]->serve();
            }
            //order
            
            else if(option == "O")
            {
                int numItems;
                string order;
                bool aldOrdered = false;
                if((tables[tableNum-1]->getStatus()) == 3 || (tables[tableNum-1]->getStatus()) == 4)
                {
                    aldOrdered = true;
                }
                int itemsOrdered = 0;
                int orderLimit = 3;
                while(orderLimit > 0)
                {
                    cin>>order;
                    if(tables[tableNum-1]->placeOrder(order, &menu))
                    {
                        itemsOrdered++;
                    }
                    orderLimit--;
                }
                
                if(aldOrdered == true)
                {
                    cout<<itemsOrdered<<" additional items ordered for Table "<<tableNum<<endl;
                }
                    
                else
                {
                    cout<<itemsOrdered<<" items ordered for Table "<<tableNum<<endl;
                }
            }
            
            //seating
            else
            {
                string seating;
               
               if(option.length() == 2)
               {
                   seating = option.substr(1);
               }
               
               if(option.length() == 3)
               {
                    seating = option.substr(1,2);
               }   
               
               partyNumber = stoi(seating);
               
               tables[tableNum-1]->seatParty(partyNumber);
            }
        }
    }
}
