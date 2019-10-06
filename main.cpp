/*****************************************************************************
** Name: Theresa Phan
** Date: August 14, 2019
** Description: This is the main file. It contains input validation
** aand the main function. 
** This program is a dungeon game that has the player move through the spaces 
** of the dungeon and interact with some of the spaces such as obtaining
** the key to exit the dungeon, obtaining a better sword or shield, and
** fighting monsters along the way. The limiting factor of this game is the 
** hunger level of the player. If the player's hunger level gets to zero,
** the player will starve and die. 
******************************************************************************/

#include "Player.hpp"
#include "Monster.hpp"
#include "Space.hpp"
#include "itemSpace.hpp"
#include "monsterSpace.hpp"
#include "trapSpace.hpp"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

/***********************************************************************************************************
** https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
** Function referenced to split a string by a delimeter and push all the substrings into a vector
************************************************************************************************************/
std::vector<std::string> Split(std::string mystring, std::string delimiter)
{
    std::vector<std::string> subStringList;
    std::string token;
    while (true)
    {
        size_t findfirst = mystring.find_first_of(delimiter);
        if (findfirst == std::string::npos) //find_first_of returns npos if it couldn't find the delimiter anymore
        {
            subStringList.push_back(mystring); //push back the final piece of mystring
            return subStringList;
        }
        token = mystring.substr(0, mystring.find_first_of(delimiter));
        mystring = mystring.substr(mystring.find_first_of(delimiter) + 1);
        subStringList.push_back(token);
    }
    return subStringList;
}

/************************************************************************
* This function validates integer input.
* Cited Source: http://www.cplusplus.com/forum/beginner/58833/
* Edited to fit program needs. Reprompts if integer is not inputted or
* If the integer inputted is not between the low and high bound
*************************************************************************/
int validateIntInRange(int low, int high)
{
	int ret_integer;
	std::string str_number;

	while(true) {

        std::getline(std::cin, str_number);
		std::stringstream convert(str_number); //turns the string into a stream

		//checks for complete conversion to integer
		if(convert >> ret_integer && !(convert >> str_number) && ret_integer >= low && ret_integer <= high){
            return ret_integer;
        }
        std::cout << "\nInvalid input: Please enter a valid integer within " << low << " and " << high << ": ";
		std::cin.clear(); //just in case an error occurs with cin (eof(), etc)
	}
}

/****************
* Main Function
****************/
int main(){

    //Initialize player object
    Player player;

    //Initialize booleans for where the player can move
    bool moveUp;
    bool moveLeft;
    bool moveRight;
    bool moveDown;

    //Initialize regular space objects
    Space* space12 = new Space(1,2,"normal");
    Space* space22 = new Space(2,2,"normal");
    Space* space23 = new Space(2,3,"normal");
    Space* space32 = new Space(3,2,"normal");
    Space* space24 = new Space(2,4,"normal");
    Space* space26 = new Space(2,6,"normal");
    Space* space35 = new Space(3,5,"normal");
    Space* space44 = new Space(4,4,"normal");
    Space* space46 = new Space(4,6,"normal");
    Space* space54 = new Space(5,4,"normal");

    //Initialize item spaces
    itemSpace* space16 = new itemSpace("key",1,6);
    itemSpace* space14 = new itemSpace("apple",1,4);
    itemSpace* space42 = new itemSpace("Steel Sword",4,2);
    itemSpace* space56 = new itemSpace("Steel Shield",5,6);

    //Initialize monster spaces
    Monster mob1(2,10);
    monsterSpace* space11 = new monsterSpace(mob1,1,1);
    Monster mob2(6,8);
    monsterSpace* space25 = new monsterSpace(mob2,2,5);
    Monster mob3(6,12);
    monsterSpace* space45 = new monsterSpace(mob3,4,5);
    Monster boss(10,15);
    monsterSpace* space64 = new monsterSpace(boss,6,4);

    //Initialize trap spaces
    trapSpace* space34 = new trapSpace("spikeFloor",3,4);
    trapSpace* space55 = new trapSpace("poisonGas",5,5);

    //Pushing all spaces into a vector for deletion later
    std::vector<Space*> spaceVector;
    spaceVector.push_back(space11);
    spaceVector.push_back(space12);
    spaceVector.push_back(space14);
    spaceVector.push_back(space16);
    spaceVector.push_back(space22);
    spaceVector.push_back(space23);
    spaceVector.push_back(space24);
    spaceVector.push_back(space25);
    spaceVector.push_back(space26);
    spaceVector.push_back(space32);
    spaceVector.push_back(space34);
    spaceVector.push_back(space35);
    spaceVector.push_back(space42);
    spaceVector.push_back(space44);
    spaceVector.push_back(space45);
    spaceVector.push_back(space46);
    spaceVector.push_back(space54);
    spaceVector.push_back(space55);
    spaceVector.push_back(space56);
    spaceVector.push_back(space64);

    //Set space pointers to eachother
    space11->setSpaceUp(space12);
    space12->setSpaceDown(space11);

    space12->setSpaceRight(space22);
    space22->setSpaceLeft(space12);

    space22->setSpaceRight(space32);
    space32->setSpaceLeft(space22);

    space22->setSpaceUp(space23);
    space23->setSpaceDown(space22);

    space32->setSpaceRight(space42);
    space42->setSpaceLeft(space32);

    space23->setSpaceUp(space24);
    space24->setSpaceDown(space23);

    space24->setSpaceLeft(space14);
    space14->setSpaceRight(space24);

    space24->setSpaceUp(space25);
    space25->setSpaceDown(space24);

    space25->setSpaceUp(space26);
    space26->setSpaceDown(space25);

    space25->setSpaceRight(space35);
    space35->setSpaceLeft(space25);

    space26->setSpaceLeft(space16);
    space16->setSpaceRight(space26);

    space35->setSpaceRight(space45);
    space45->setSpaceLeft(space35);

    space45->setSpaceUp(space46);
    space46->setSpaceDown(space45);

    space45->setSpaceDown(space44);
    space44->setSpaceUp(space45);

    space46->setSpaceRight(space56);
    space56->setSpaceLeft(space46);

    space44->setSpaceRight(space54);
    space54->setSpaceLeft(space44);

    space54->setSpaceRight(space64);
    space64->setSpaceLeft(space54);

    space34->setSpaceUp(space35);
    space35->setSpaceDown(space34);

    space45->setSpaceRight(space55);
    space55->setSpaceLeft(space45);

    //Game begins. Player begins at space23 (X: 2, y: 3)
    Space* currentSpace = space23;
    std::cout << "\n|--------------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|               You've woken up in a dark dungeon... distraught, hungry, and confused...                       |" << std::endl;
    std::cout << "|   You notice a backpack next to you. You check the contents and find a wooden sword and a measely pan lid.   |" << std::endl;
    std::cout << "|                 You think to yourself... 'Is this a prank? What am I doing here?'                            |" << std::endl;
    std::cout << "| Stomach rumbling, the only thing you know for certain is that you need to get out before you starve to death |" << std::endl;
    std::cout << "|                                Your adventure(?) begins here.                                                |" << std::endl;
    std::cout << "|                              (Note: This game is pretty hard :D)                                             |" << std::endl;
    std::cout << "|--------------------------------------------------------------------------------------------------------------|" << std::endl;

    std::cout << "\nPress enter to continue..." << std::endl;
    std::cin.ignore();
    
    //Game exits when player hunger reaches 0, player HP reaches 0, or when Boss health reaches 0 (player wins)
    while(player.getHunger() > 0 && player.getHP() > 0 && space64->getMonster().getHealth() > 0){
        //Print out character in room and possible ways to go
        if(currentSpace->getSpaceUp() == NULL){
            moveUp = false;
            std::cout << "|-------------------------|" << std::endl;
        }else if (currentSpace->getSpaceUp() != NULL){
            moveUp = true;
            std::cout << "|-----------   -----------|" << std::endl;
        }
            std::cout << "|                         |" << std::endl;
        if(currentSpace->getSpaceLeft() == NULL && currentSpace->getSpaceRight() == NULL){
            moveLeft = false;
            moveRight = false;
            std::cout << "|          | O            |" << std::endl;
            std::cout << "|          T-|-D          |" << std::endl;
            std::cout << "|            ^            |" << std::endl;
        }else if(currentSpace->getSpaceLeft() != NULL && currentSpace->getSpaceRight() == NULL){
            moveLeft = true;
            moveRight = false;
            std::cout << "           | O            |" << std::endl;
            std::cout << "           T-|-D          |" << std::endl;
            std::cout << "             ^            |" << std::endl;
        }else if(currentSpace->getSpaceLeft() == NULL && currentSpace->getSpaceRight() != NULL){
            moveLeft = false;
            moveRight = true;
            std::cout << "|          | O             " << std::endl;
            std::cout << "|          T-|-D           " << std::endl;
            std::cout << "|            ^             " << std::endl;
        }else{
            moveRight = true;
            moveLeft = true;
            std::cout << "           | O             " << std::endl;
            std::cout << "           T-|-D           " << std::endl;
            std::cout << "             ^             " << std::endl;
        }
            std::cout << "|           / \\           |" << std::endl;
            std::cout << "|                         |" << std::endl;
        if(currentSpace->getSpaceDown() == NULL){
            moveDown = false;
            std::cout << "|-------------------------|" << std::endl;
        }else if(currentSpace->getSpaceDown() != NULL){
            moveDown = true;
            std::cout << "|-----------   -----------|" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Possible ways to go: ";
        std::string moveOptions = "";
        if(moveUp == true){
            moveOptions += "Up ";
        }
        if(moveLeft == true){
            moveOptions += "Left ";
        }
        if(moveRight == true){
            moveOptions += "Right ";
        }
        if(moveDown == true){
            moveOptions += "Down ";
        }
        moveOptions = moveOptions.substr(0,moveOptions.length()-1);
        std::cout << moveOptions << ".\n";
        std::cout << "Current Hunger: " << player.getHunger() << ".\n";
        std::cout << std::endl << "What would you like to do? " << std::endl;
        std::cout << "1: Move to another space." << std::endl;
        std::cout << "2: Check your backpack." << std::endl;
        std::cout << "3: Check your status." << std::endl;
        std::cout << "4: Rest to recover HP.. but lose more hunger." << std::endl; 
        std::cout << "\nPlease select your option: ";
        int playerOption = validateIntInRange(1,4);

        //Switch statement for player option
        switch(playerOption){
            //Move to a space
            case 1:{
                //Another switch statement here for whether the player
                //Lands on a normal, item, or monster space
                std::vector<std::string> moveVector = Split(moveOptions, " ");
                std::cout << "\nWhat direction would you like to move?" << std::endl;
                for(int i = 0; i < moveVector.size(); i++){
                    std::cout << i+1 << ": " << moveVector.at(i) << std::endl;
                }

                int moveChoice = validateIntInRange(1,moveVector.size()) - 1;
                if(moveVector.at(moveChoice) == "Up"){
                    std::cout << "\nMoving up..." << std::endl;
                    currentSpace = currentSpace->getSpaceUp();
                }else if(moveVector.at(moveChoice) == "Left"){
                    std::cout << "\nMoving left..." << std::endl;
                    currentSpace = currentSpace->getSpaceLeft();
                }else if(moveVector.at(moveChoice) == "Right"){
                    std::cout << "\nMoving right..." << std::endl;
                    currentSpace = currentSpace->getSpaceRight();
                }else if(moveVector.at(moveChoice) == "Down"){
                    std::cout << "\nMoving down..." << std::endl;
                    currentSpace = currentSpace->getSpaceDown();
                }

                if(currentSpace == space64){
                    if(player.hasKey() == "noKey"){
                        std::cout << "\nThe doorway is locked.. Seems like this is the exit though." << std::endl;
                        std::cout << "Returning to previous space. " <<std::endl;
                        currentSpace = space54;
                    }else{
                        std::cout << "\nThe doorway is locked... but you unlock it with your key!" << std::endl;
                    }
                }

                //Logic for type of space the player is on (normal space, item space, monster space)
                if(currentSpace->getType() == "normal"){
                    std::cout << "\nThere's nothing to do in this room." << std::endl;
                }else if(currentSpace->getType() == "itemSpace"){
                    if(currentSpace->getItem() != ""){
                        std::cout << "\nThere seems to be something laying on the floor..." << std::endl;
                        std::cout <<"You've found a(n) : " << currentSpace->getItem() << "!" << std::endl;
                        if(currentSpace->getItem() == "key"){
                            std::cout << "This must unlock the door to exit the dungeon! (Probably)" << std::endl;
                            player.gotKey();
                        }else if(currentSpace->getItem() == "apple"){
                            std::cout << "It looks pristine! (Somehow).. You consume it and reduce your hunger." << std::endl;
                            player.increaseHunger();
                        }else if(currentSpace->getItem() == "Steel Sword"){
                            std::cout << "You replace your wooden sword for this much more durable and stronger sword." << std::endl;
                            player.gotSteelSword();
                        }else if(currentSpace->getItem() == "Steel Shield"){
                            std::cout << "This should guard you better against monsters. You replace your pan lid." << std::endl;
                            player.gotSteelShield();
                        }
                        currentSpace->removeItem();
                    }else{
                        std::cout << "There used to be an item here (You think.. your memory is fading)." << std::endl;
                    }
                }
                else if(currentSpace->getType() == "monsterSpace"){
                    if(currentSpace->getHasMonster() == true){
                        if(currentSpace == space64){
                            //ASCII art referenced from: https://www.asciiart.eu/mythology/monsters
                            std::cout << "\nThat's a gigantic monster! He's blocking the way out of the dungeon.. Defeat it!" << std::endl;
                            std::cout << "                        _,--~~~," << std::endl;
                            std::cout << "                       .'        `." << std::endl;
                            std::cout << "                       |           ;" << std::endl;
                            std::cout << "                       |           :" << std::endl;
                            std::cout << "                      /_,-==/     .'" << std::endl;
                            std::cout << "                    /'`\\*  ;      :      " << std::endl;
                            std::cout << "                  :'    `-        :      " << std::endl;
                            std::cout << "                 `~*,'     .     :      " << std::endl;
                            std::cout << "                    :__.,._  `;  :      " << std::endl;
                            std::cout << "                    `\\'    )  '  `,     " << std::endl;
                            std::cout << "                         \\-/  '     )     " << std::endl;
                            std::cout << "                         :'          \\ _" << std::endl;
                            std::cout << "                          `~---,-~    `,)" << std::endl;
                            std::cout << "          ___                   \\     /~`\\" << std::endl;
                            std::cout << "    \\---__ `;~~~-------------~~~(| _-'    `," << std::endl;
                            std::cout << " ---, ' \\`-._____     _______.---'         \\" << std::endl;
                            std::cout << " \\--- `~~-`,      ~~~~~~                     `," << std::endl;
                            std::cout << "\\----      )                                   \\" << std::endl;
                            std::cout << "\\----.  __ /                                    `-" << std::endl;
                            std::cout << " \\----'` -~____  " << std::endl;
                            std::cout << "               ~~~~~--------,.___     '" << std::endl;
                            std::cout << "                                 ```\\_'" << std::endl;
                        }else{
                            std::cout << "\nYou've encountered a monster! You must fight!" << std::endl;
                        }
                        Monster tempMob = currentSpace->getMonster();
                        while(player.getHP() > 0 && tempMob.getHealth() > 0){
                            std::cout << "\nYour HP: " << player.getHP() << std::endl;
                            std::cout << "Monster's HP: " << tempMob.getHealth() << std::endl;
                            std::cout << "\nWhat is your action?!" << std::endl;
                            std::cout << "1: Attack the monster" << std::endl;
                            std::cout << "2: Defend and recover some HP" << std::endl;
                            std::cout << "Your choice: " << std::endl;
                            int battleChoice = validateIntInRange(1,2);
                            switch(battleChoice){
                                case 1:{
                                    int playerDamage = player.attackEnemy();
                                    std::cout << "\nYou attack the monster for: " << playerDamage << "!\n";
                                    int monsterDamage = tempMob.attack();
                                    std::cout << "The monster counter-attacks for: " << monsterDamage << "!\n";
                                    player.takeDamage(monsterDamage);
                                    tempMob.takeDamage(playerDamage);
                                    break;
                                }
                                case 2:{
                                    std::cout << "\nYou brace for the monster's attack and recover some HP." << std::endl;
                                    int monsterDamage = tempMob.attack();
                                    int blockDamage = player.guard();
                                    std::cout << "The monster strikes for " <<  monsterDamage << ", but you block for " <<  blockDamage << "!" << std::endl;
                                    player.takeDamage(monsterDamage-blockDamage);
                                    break;
                                }
                            }
                            if(player.getHP() <= 0){
                                std::cout << "\nYou have fainted... GAME OVER" << std::endl;
                                for(int i = 0; i < spaceVector.size(); i++){
                                    delete spaceVector.at(i);
                                }
                                return 0;
                            }
                            if(tempMob.getHealth() <= 0){
                                std::cout << "\nYou've defeated the monster and have leveled up!" << std::endl;
                                std::cout << "Your stats are now:" << std::endl;
                                player.levelUp();
                                player.getStats();
                                currentSpace->monsterDied();
                                if(currentSpace == space64){
                                    std::cout << "\nYou've defeated the large monster and see daylight in the exit!" << std::endl;
                                    std::cout << "Congratulations! You still don't know how you ended up there... but you're out now!" << std::endl;
                                    for(int i = 0; i < spaceVector.size(); i++){
                                        delete spaceVector.at(i);
                                    }
                                    return 0;
                                }
                            }
                        }
                    }else{
                        std::cout << "\nThe remains of a monster are left... (gross!)" << std::endl;
                    }
                }
                else if(currentSpace->getType() == "trapSpace"){
                    if(currentSpace->getTrap() != ""){
                        if(currentSpace->getTrap() == "poisonGas"){
                            std::cout << "\nThe room is filling up with poison gas!" << std::endl;
                            std::cout << "You have lost 2 health and 2 hunger";
                            player.starve();
                            player.starve();
                            player.takeDamage(2);
                        }else if(currentSpace->getTrap() == "spikeFloor"){
                            std::cout << "\nSpikes rise from the floor! Luckily, only one spike pierced your pinky toe.." << std::endl;
                            std::cout << "You lose 3 health." << std::endl;
                            player.takeDamage(3);
                        }
                        currentSpace->removeTrap();
                    }else{
                        std::cout << "\nThe remains of the trap you encountered still haunt you. Nothing happens though." << std::endl;
                    }
                }
                player.starve();
                std::cout << "Hunger decreased by 1" << std::endl;
                break;
            }
            //Check bag for inventory
            case 2:{
                player.checkBackPack();
                std::cout << std::endl;
                break;
            }
            //Check status
            case 3:{
                player.getStats();
                std::cout << std::endl;
                break;
            }
            //Rest to recover HP but lose hunger
            case 4:{
                std::cout << "\nYou recover 3 hp!... but become a little hungrier." << std::endl;
                player.recover();
                break;
            }
        }
        if(player.getHunger() < 1 || player.getHP() < 1){
            std::cout << "\nYou've starved to death... or you have no HP. GAME OVER" << std::endl;
            for(int i = 0; i < spaceVector.size(); i++){
                delete spaceVector.at(i);
            }
            return 0;
        }
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();

    }
}