# RestaurantManager
C++ code that manages a restaurant and (almost) all of its functions. 

Main:
The main method takes in user input (S to seat, O to order, C to clean table). These have to be done in cronoligical order (for example, a table can't order before being seated). It has an array of tables that are obtained from the .txt file. It also calls the other methods when neccessary.

Menu:
It goes through the provided .txt file and makes sure that all of the foods orderd are on the menu. It does this by making multiple MenuItem objects that are made using the .txt file. Then it compares the user's order input with the MenUItem and determines if it the resturant has it or not. 

MenuItem: 
This is the object created by using the .txt file. It has three parameters: its code, name, and price. 

Order:
Obtains the user input for the code of the items and adds it to an items array. It uses the items array to make a recipt that outputs the total. 

Table:
This is where most of the functions occur. It uses the .txt file to determine the capacity of the the table then seats the guests accordingly. After that it uses Order.cpp and Menu.cpp to make sure that the user's order is taken and to make sure that the dish is on the menu. After the table is finished ordering, it gives the recipt then cleans up the table. The four possiple statuses of the table are IDLE, SEATED, ORDERD, and SERVED which are in an enum, and can only be done in order (ex: table can't order before being seated). 
