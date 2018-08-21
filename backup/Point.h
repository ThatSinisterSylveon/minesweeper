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
public:
    bool getMine();
    char getAppearance();
    bool getFlag();
    int getCloseMines();
    void setMine(bool);
    void setCloseMines(vector<vector<Point>>&); ///Work on with & once vector is set up
    void setAppearance(char);
    void setFlag(bool);
    void touch(); ///work on once im ready for logic
    Point();
    Point(bool);  
};



#endif
