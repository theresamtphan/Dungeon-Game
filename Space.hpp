/*******************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the header file for the Space class.
********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Monster.hpp"

class Space{
    private:
        Space* up;
        Space* left;
        Space* down;
        Space* right;
        bool hasPlayer;
        int xCoordinate;
        int yCoordinate;
        std::string type;
    public:
        Space(int,int,std::string);
        int getX();
        int getY();
        void setSpaceUp(Space*);
        void setSpaceLeft(Space*);
        void setSpaceDown(Space*);
        void setSpaceRight(Space*);
        Space* getSpaceUp();
        Space* getSpaceLeft();
        Space* getSpaceDown();
        Space* getSpaceRight();
        virtual std::string getType();

        //for itemSpace
        virtual void removeItem();
        virtual std::string getItem();

        //for monsterSpace
        virtual Monster getMonster();
        virtual bool getHasMonster();
        virtual void monsterDied();

        //for trapSpace
        virtual void removeTrap();
        virtual std::string getTrap();

};
#endif