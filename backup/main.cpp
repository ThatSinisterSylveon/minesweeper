#include <iostream>
#include <ncurses.h>
#include <vector>
#include <time.h>
#include "Point.h"
using namespace std;

void makeMap(vector<vector<Point>> &);

///###############################################################################

static int width;
static int height;
static int totalNumberOfMines;
static int currentMines = 0;

///###############################################################################

int main(){
    ///Game Start Logic
    vector<vector<Point>> gameMap; 
    makeMap(gameMap);

  
    initscr();
    printw("Hello World!");
    refresh();

    getch();




    
    endwin();
    
    return 0;
}

///###############################################################################

void makeMap(vector<vector<Point>> &gameMap){
    ///Build Board
    cout << "Width >" << flush;
    cin >> width;
    cout << "Height >" << flush;
    cin >> height;
    for (int i=0; i<height+1; i++){
        vector<Point> temp;
        for (int j=0; j<width+1; j++){
	    Point newPoint();
            temp.push_back(newPoint);
	}
	gameMap.push_back(temp);
    }
    ///Set Mines
    cout <<  "Mines >" << flush;
    cin >> totalNumberOfMines;
    srand(time(0));
    while(currentMines < totalNumberOfMines){
	unsigned int randX = rand() % width + 1;
	unsigned int randY = rand() % height + 1;
	if(!gameMap[randX][randY].getMine()){
	    gameMap[randX][randY].setMine(true);
	    currentMines += 1;
	}
    }
}




