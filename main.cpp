#include <iostream>
#include <ncurses.h>
#include <vector>
#include <time.h>
#include "Point.h"
using namespace std;

void makeMap(vector<vector<Point>> &);

void keyPress(vector<vector<Point>> &, int);
///###############################################################################

static int width;
static int height;
static int totalNumberOfMines;
static int currentMines = 0;
static int cursorX = 1;
static int cursorY = 1;

///###############################################################################

int main(){
    bool running = true;
    bool gettingKeys;
    vector<vector<Point>> gameMap; 
    makeMap(gameMap);

  
    initscr();
    int ch;
    ///Game Loop
    while(running == true){
	///Get Key Press
	move(cursorY,cursorX);
	ch = getch();
	keyPress(gameMap, ch);
	for(int i=1;i<width;i++){
	    for(int j=1;j<height;j++){
		move(j,i);
		printw("%c", gameMap[i][j].getAppearance());
	    }
	}
    }

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

    for (int i=1; i<height; i++){
        for (int j=1; j<width; j++){
   	    int tempMines = 0;
	    for (int w=-1; w<=1;w++){
		for (int h=-1; h<=1;h++){
		    if((w!=2) && (h!=2)){
			if(gameMap[i+w][j+h].getMine()==true){
			    tempMines++;
			}
		    }
		}
	    }

	gameMap[i][j].setCloseMines(tempMines);
	}
    }
    
}



void keyPress(vector<vector<Point>> &gameMap, int ch){
    if(ch==KEY_LEFT){
	if(cursorX > 0){
	    cursorX--;
	    return;
	}else{
	    return;
	    }
    }else if(ch==KEY_UP){
	if(cursorY > 0){
	    cursorY--;
	    return;
	}else{
	    return;
	}	
    }else if(ch==KEY_RIGHT){
	if(cursorX < width){
	    cursorX++;
	    return;
	}else{
	    return;
	}	
    }else if(ch==KEY_DOWN){
	if(cursorY < height){
	    cursorY++;
	    return;
	}else{
	    return;
	}
    }
    else if(ch=10){ ///Enter
	bool shutdown = gameMap[cursorX][cursorY].touch(gameMap, cursorX, cursorY);
	return;
    }
}



