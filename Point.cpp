#include "Point.h"
#include <curses.h>
#include <iostream>
using namespace std;

bool Point::getRevealed(){
    return revealed;
}

bool Point::getInGame(){
    return inGame;
}

bool Point::getMine(){
    return mine;
}

char Point::getAppearance(){
    return appearance;
}

bool Point::getFlag(){
    return flag;
}

int Point::getCloseMines(){
    return closeMines;
}

void Point::setRevealed(bool newRevealed){
    revealed = newRevealed;
}

void Point::setMine(bool newMine){
    mine = newMine;
}

void Point::setCloseMines(int newCloseMines){
    closeMines = newCloseMines;
    
}

void Point::setAppearance(char newChar){
    appearance= newChar;
}

void Point::setFlag(bool newFlag){
    flag = newFlag;
}

bool Point::touch(vector<vector<Point>> &gameMap, int X,int Y){
   
    revealed == true;
    
    if(mine == true){
	return true;
    }else if(closeMines >= 1){
	char tempChar = '0';
	appearance = tempChar + closeMines;
    }else if (closeMines == 0){
	appearance = ' ';
    }else if(closeMines == 0){
	for (int w=-1; w<=1;w++){
	    for (int h=-1; h<=1;h++){
		if(((w!=2)&&(h!=2)) && gameMap[X+w][Y+h].getMine()==false){
		    gameMap[X+w][Y+h].touch(gameMap, X+w, Y+h);
		}
	    }
	}
	}
}

Point::Point(){
    inGame = true;
    appearance = '#';
    mine = false;
    flag = false;
    closeMines = 0;
    revealed = false;
}

Point::Point(bool){
    inGame = false;
    appearance = '-';
    mine = false;
    flag = false;
    closeMines = 0;
    revealed = false;
}
