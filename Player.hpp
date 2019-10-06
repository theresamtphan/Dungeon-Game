/*******************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the header file for the Player class.
********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include <string>

class Player{
    private:
        int level;
        int hunger;
        int HP;
        std::string *backpack;        
    public:
        Player();
        void takeDamage(int);
        int attackEnemy();
        int guard();
        void levelUp();
        void getStats();
        void checkBackPack();
        int getHunger();
        int getHP();
        void gotKey();
        void increaseHunger();
        void gotSteelSword();
        void gotSteelShield();
        void starve();
        std::string hasKey();
        void recover();
};  
#endif