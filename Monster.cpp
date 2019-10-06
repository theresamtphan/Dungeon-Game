/************************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the implementation file for the Monster class.
*************************************************************************/
#include "Monster.hpp"
#include <random>

/******************************
* Initializes the strength
* and HP to zero.
*******************************/
Monster::Monster(){
    strength = 0;
    HP = 0;
}

/******************************
* Initializes the strength
* and HP.
*******************************/
Monster::Monster(int str, int health){
    strength = str;
    HP = health;
}


/***************************************
* Decrease health of monster
****************************************/
void Monster::takeDamage(int damage){
    HP -= damage;
}

/**********************************
* Monster attacks the player
***********************************/
int Monster::attack(){
    return (rand() & strength) + 1;
}

/*******************************
* Return health of monster
*******************************/
int Monster::getHealth(){
    return HP;
}