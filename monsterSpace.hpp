/*******************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the header file for the monsterSpace class.
********************************************************************/

#ifndef MONSTERSPACE_HPP
#define MONSTERSPACE_HPP
#include "Space.hpp"
#include "Monster.hpp"

class monsterSpace : public Space{
    private:
        Monster mob;
        bool hasMonster;
    public:
        monsterSpace(Monster, int, int);
        Monster getMonster();
        bool getHasMonster();
        void monsterDied();
};
#endif