/**************************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the implementation file for the Player class.
***************************************************************************/

#include "Player.hpp"
#include <random>
#include <iostream>
#include <stdlib.h>

/*****************************************************
* Initializes the level to 1, hunger to 25
* and HP to 20. It also has a dynamic array that holds
* the items the player obtains. 
*****************************************************/
Player::Player(){
    level = 1;
    hunger = 25;
    HP = 20;
    backpack = new std::string[3];
    std::string tempBackPack[] = {"Wooden Sword","Pan Lid","noKey"};
    for(int i = 0; i < 3; i++){
        backpack[i] = tempBackPack[i];
    }
}

/**************************************
* Decrease health after being attacked
***************************************/
void Player::takeDamage(int damage){
    if(damage < 0){
        damage = 0;
    }
    HP -= damage;
    if(HP < 0){
        HP = 0;
    }
}

/*****************************
* Deal damage to an enemy
******************************/
int Player::attackEnemy(){
    if(backpack[0] == "Wooden Sword"){
        return (rand() % 6 + 1) + level;
    }else{
        return (rand() % 6 + 3) + level;
    }
}

/*******************************************
* Guard against an attack and heal for 2 hp
********************************************/
int Player::guard(){
    HP += 2;
    if(backpack[1] == "Pan Lid"){
        return (rand() %3 + 1) + level;
    }else{
        return (rand() %3 + 3) + level;
    }
}

/**********************************************************
* Increase stats for leveling up after defeating a monster
**********************************************************/
void Player::levelUp(){
    level += 1;
    HP += 2;
}

/*****************************
* Return the player's stats
******************************/
void Player::getStats(){
    std::cout << "\nLevel: " << level << "." << std::endl;
    std::cout << "HP: " << HP << "." << std::endl;
    std::cout << "Hunger: " << hunger << "." << std::endl;
}

/***************************************
* Print out everything in the backpack
****************************************/
void Player::checkBackPack(){
    std::cout << "\nWeapon: " << backpack[0] << "." << std::endl;
    std::cout << "Shield: " << backpack[1] << "." << std::endl;
    if(backpack[2] == "noKey"){
        std::cout << "You don't have the key to exit." << std::endl;
    }else{
        std::cout << "You have the key to exit the dungeon! Go find the door." << std::endl;
    }
}

/***********************
* Return player's hunger
************************/
int Player::getHunger(){
    return hunger;
}

/***********************
* Return player's HP
************************/
int Player::getHP(){
    return HP;
}

/******************************
* Holds key in dynamic array
******************************/
void Player::gotKey(){
    backpack[2] = "key";
}

/******************************
* Increases hunger by 5
******************************/
void Player::increaseHunger(){
    hunger += 5;
}

/************************************
* Holds steel sword in dynamic array
************************************/
void Player::gotSteelSword(){
    backpack[0] = "Steel Sword";
}

/************************************
* Holds steel shield in dynamic array
************************************/
void Player::gotSteelShield(){
    backpack[1] = "Steel Shield";
}

/************************************
* Decreases hunger by 1
************************************/
void Player::starve(){
    hunger -= 1;
}

/************************************
* Holds key when player has they key
************************************/
std::string Player::hasKey(){
    return backpack[2];
}

/************************************
* Player recovers 3 HP and decreases
* 2 points from hunger.
************************************/
void Player::recover(){
    HP += 3;
    hunger -= 2;
}