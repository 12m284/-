#pragma once
#include <graphcs.h> //需要安装easyx图形库
#include <vector>
using namespace std;
struct Point {
     int row;
     int col;
};



class Block
{
public:
    Block();
    void drop();
    void moveLeftRight(int offest);
    void rotate();//旋转
    voide draw(int leftMargin, int topMargin);
    static IMAGE** getImages();
    Block& operator=(const Block& other);

    bool blockInMap(const vector<vector<int>>&map);
     //Point* getSmallBlocks();
     void solidify(vector<vector<int>>& map);
     int get blockType();

private:
int blockType; //方块的类型
Point smallBlocks[4];
IMAGE *img;

static IMAGE* imgs[7]; //int* data[7]; //int** getData()
static int size;
};

