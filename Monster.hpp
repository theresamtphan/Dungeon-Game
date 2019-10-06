/*****************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the header file for the Monster class.
*****************************************************************/

#ifndef MONSTER_HPP
#define MONSTER_HPP

class Monster{
    private:
        int strength;
        int HP;
    public:
        Monster();
        Monster(int, int);
        void takeDamage(int);
        int attack();
        int getHealth();
};
#endif