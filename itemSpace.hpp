/*****************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the header file for the itemSpace class.
*****************************************************************/

#ifndef ITEMSPACE_HPP
#define ITEMSPACE_HPP
#include "Space.hpp"
#include <string>

class itemSpace : public Space{
    private:
        std::string item;
    public:
        itemSpace(std::string, int, int);
        void removeItem();
        std::string getItem();
};
#endif