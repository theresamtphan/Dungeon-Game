/**************************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the implementation file for the trapSpace class.
***************************************************************************/

#include "trapSpace.hpp"
#include <string>

/****************************************
* Constructor for space with an item
****************************************/
trapSpace::trapSpace(std::string t, int x, int y) : Space(x, y, "trapSpace"){
    trap = t;
}

/****************************************
* Removes the item from the space
****************************************/
void trapSpace::removeTrap(){
    trap = "";
}

/******************
* Returns trap
*******************/
std::string trapSpace::getTrap(){
    return trap;
}