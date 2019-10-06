/**************************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the implementation file for the Space class.
***************************************************************************/

#include "itemSpace.hpp"
#include <string>

/************************************
* Constructor for space with an item
*************************************/
itemSpace::itemSpace(std::string i, int x, int y) : Space(x, y, "itemSpace"){
    item = i;
}

/*********************************
* Removes the item from the space
**********************************/
void itemSpace::removeItem(){
    item = "";
}

/***************
* returns item
****************/
std::string itemSpace::getItem(){
    return item;
}