#ifndef POINT_H_
#define POINT_H_
#include <vector>
using namespace std;
class Point{
private:
    bool inGame;
    char appearance;
    bool mine;
    bool flag;
    int closeMines;
    bool revealed;
public:
    bool getRevealed();
    bool getInGame();
    bool getMine();
    char getAppearance();
    bool getFlag();
    int getCloseMines();
    void setRevealed(bool);
    void setMine(bool);
    void setCloseMines(int); ///Work on with & once vector is set up
    void setAppearance(char);
    void setFlag(bool);
    bool touch(vector<vector<Point>> &, int, int); ///work on once im ready for logic
    Point();
    Point(bool);
    
};



#endif
