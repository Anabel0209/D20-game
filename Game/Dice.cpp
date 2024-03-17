#include <iostream>
#include <ctime>
#include "Dice.h"
using namespace std;

Dice::Dice(){

    //Seed the random number generator to ensure different results on each run
    srand(time(0));
}

int Dice::rollDice(string dice_notation){

    // Seed the random number generator to ensure different results on each run
   // std::srand(static_cast<unsigned int>(std::time(nullptr)));
        
    int x=0;    //num of dice to roll
    int y=0;    //dice type
    int z=0;    //optional value

    int result = 0; 

//parse the notation ex: 21d2+3

    size_t position_d = dice_notation.find('d');
    size_t position_plus = dice_notation.find('+');

    x = stoi(dice_notation.substr(0,position_d)); 

    if (position_plus != string::npos)
    {
        y = stoi(dice_notation.substr(position_d + 1, position_plus - 1));
        z = stoi(dice_notation.substr(position_plus + 1));
    }
    else
    {
		y = stoi(dice_notation.substr(position_d + 1));
	}



    //seeds the random number generator
    
    //cout << x << "\n" << y << "\n" << z;

    for (int i = 0; i < x ; i++){

        
        result += (rand()%y) +1 ; 
     }
 
return result + z;
};

