/*******************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the header file for the trapSpace class.
********************************************************************/

#ifndef TRAPSPACE_HPP
#define TRAPSPACE_HPP
#include "Space.hpp"
#include <string>

class trapSpace : public Space{
    private:
        std::string trap;
    public:
        trapSpace(std::string, int, int);
        void removeTrap();
        std::string getTrap();
};
#endif