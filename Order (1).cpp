#include "Order.h"
#include <sstream>
#include <iomanip>
Order::Order(string OrderString, Menu *menup)
{
    numItems = 0;
    addItems(OrderString, menup);
}

void Order::addItems(string OrderString, Menu *menup)
{
    istringstream ss(OrderString);
    string itemCode;
    while(ss >> itemCode)
    {
        MenuItem *singleItem = menup->find(itemCode);
        if(numItems <= MAX_ITEMS_IN_ORDER)
        {
            if(singleItem != nullptr)
            {
                items[numItems++] = singleItem;
            }
        }
    }
}

void Order::printReceipt()
{
    double receiptTotal = 0.0; // Initialize receiptTotal to 0.0
    cout << left << setw(4) << "Code" << setw(20) << "Name" << setw(8) << "Price" << endl;
    for(int i = 0; i < numItems; i++)
    {
        receiptTotal += items[i]->getPrice();
        cout << left << setw(4) << items[i]->getCode() << setw(20) << items[i]->getName() << fixed << setprecision(2) << setw(8) << items[i]->getPrice() << endl;
    }
    
    cout << right << setw(30) << "Total" << setw(8) << fixed << setprecision(2) << receiptTotal << endl;
}