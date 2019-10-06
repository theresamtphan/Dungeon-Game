/**************************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the implementation file for the monsterSpace class.
***************************************************************************/

#include "monsterSpace.hpp"
#include "Monster.hpp"

/****************************************
* Constructor for space with a monster
*****************************************/
monsterSpace::monsterSpace(Monster mon, int x, int y) : Space(x,y,"monsterSpace"){
    mob = mon;
    hasMonster = true;
}

/*************************************************
* Functions that Return the monster on the space
**************************************************/
Monster monsterSpace::getMonster(){
    return mob;
}

/******************************
* Functions that gets monster
*******************************/
bool monsterSpace::getHasMonster(){
    return hasMonster;
}

/******************************
* Functions sets hasMonster to 
* false for when monster dies
*******************************/
void monsterSpace::monsterDied(){
    hasMonster = false;
}