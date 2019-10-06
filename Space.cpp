/**************************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the implementation file for the Space class.
***************************************************************************/

#include "Space.hpp"
#include <iostream>

/**************************************************************
* This function initializes the directions (up, left, right,
* and down) to NULL. It also initializes the xCoordinate,
* yCoordinate, hasPlayer to false, and type.
**************************************************************/
Space::Space(int x, int y, std::string t){
    up = NULL;
    left = NULL;
    right = NULL;
    down = NULL;
    xCoordinate = x;
    yCoordinate = y;
    hasPlayer = false;
    type = t;
}

/*********************
* gets xCoordinate
**********************/
int Space::getX(){
    return xCoordinate;
}

/*********************
* gets yCoordinate
**********************/
int Space::getY(){
    return yCoordinate;
}

/*************************************
* Set the space above another space
**************************************/
void Space::setSpaceUp(Space* s){
    up = s;
}

/*************************************
* Set the space left of another space
**************************************/
void Space::setSpaceLeft(Space* s){
    left = s;
}

/*************************************
* Set the space above of another space
**************************************/
void Space::setSpaceDown(Space* s){
    down = s;
}

/*************************************
* Set the space right of another space
**************************************/
void Space::setSpaceRight(Space* s){
    right = s;
}

/*******************
* Get the up space
********************/
Space* Space::getSpaceUp(){
    return up;
}

/************************
* Get the left space
*************************/
Space* Space::getSpaceLeft(){
    return left;
}

/************************
* Get the down space
*************************/
Space* Space::getSpaceDown(){
    return down;
}

/************************
* Get the right space
*************************/
Space* Space::getSpaceRight(){
    return right;
}

/*******************************************************
* Return whether it is a normal, item, or monster space
********************************************************/
std::string Space::getType(){
    return type;
}

/***************************
* Get item when not in use
****************************/
std::string Space::getItem(){
    //Not Used
    return "This is not used";
}

/*****************
* Removes item
******************/
void Space::removeItem(){
    //Not used
}

/*****************
* Gets monster
******************/
Monster Space::getMonster(){
    //Not used
}

/*****************
* Gets hasMonster
******************/
bool Space::getHasMonster(){

}

/*******************
* When monster dies
********************/
void Space::monsterDied(){

}

/*******************
* Removes Trap
********************/
void Space::removeTrap(){

}

/*******************
* Gets trap
********************/
std::string Space::getTrap(){
    
}

