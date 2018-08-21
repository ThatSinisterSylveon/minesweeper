#include "Point.h"
#include <curses.h>
using namespace std;

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

void Point::setMine(bool newMine){
    mine = newMine;
}

void Point::setCloseMines(vector<vector<Point>>&){
    
}

void Point::setAppearance(char newChar){
    appearance= newChar;
}

void Point::setFlag(bool newFlag){
    flag = newFlag;
}

void Point::touch(){
    
}

Point::Point(){
    inGame = true;
    appearance = '#';
    mine = false;
    flag = false;
    closeMines = 0;
    
}

Point::Point(bool){
    inGame = false;
    appearance = '-';
    mine = false;
    flag = false;
    closeMines = 0;
}
