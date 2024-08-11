#include "Table.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "Order.h"

using namespace std;

//enum can be used to replace booleans
Table::Table(int argTableId, int argCapacity)
{
  tableId = argTableId;
  capacity = argCapacity;
  status = IDLE;
  orderp = nullptr;
}

bool Table::seatParty(int argNumGuests)
{
    partySize = argNumGuests;
    
    if(partySize > capacity)
    {
        cout<<"Sorry, max "<<capacity<<" seats in Table "<<tableId<<"!"<<endl;
        return false;
       
    }
    
    if(status != IDLE)
    {
        cout<<"Table "<<tableId<<" already occupied!"<<endl;
        return false;
    }
    
    status = SEATED;
    cout<<"Party of "<<partySize<<" assigned to Table "<<tableId<<endl;
    return true;
}

//Need clarifacation
bool Table::placeOrder(string argItems, Menu *menup)
{
    status = ORDERED;
    items = argItems;
    if(status == SEATED || status == ORDERED)
    {
        //go through the string
        if(menup->find(items))
        {
            if(orderp == nullptr)
            {
                orderp = new Order(items, menup);
            }
            else
            {
                orderp->addItems(items, menup);
            }
            
            return true;
        }
        else
        {
            cout<<"No item with code "<<items<<endl;
            return false;
        }
        
    }
    return false;
}

bool Table::serve()
{
    if(status == ORDERED)
    {
        status = SERVED;
        cout<<"Food served in table "<<tableId<<endl;
        return true;
    }

    else
    {
        cout<<"Order not placed at Table "<<tableId<<" yet!"<<endl;
        return false;
    }
}

int Table::getStatus()
{
    if(status == IDLE)
    {
        return 1;
    }
    
    if(status == SEATED)
    {
        return 2;
    }
    
    if(status == ORDERED)
    {
        return 3;
    }
    
    else
    {
        return 4;
        
    }
}

bool Table::cleanup()
{
    if(status == SERVED)
    {
        status = IDLE;
        partySize = 0;
        
        cout<<"Table "<<tableId<<" is now closed. Here is the bill."<<endl;
        cout<<" "<<endl;
        cout<<"Receipt Table #"<<tableId<<" Party "<<partySize<<endl;
        orderp->printReceipt();
        
        return true;
    }
    
    else if(status == SEATED || ORDERED)
    {
       cout<<"Food not served for Table "<<tableId<<" yet!"<<endl;
        return false;
    }
    
    return false;
}