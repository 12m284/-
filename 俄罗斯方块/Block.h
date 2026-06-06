#pragma once
#include <graphcs.h> //需要安装easyx图形库

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
    void retate();//旋转
    voide draw(int leftMargin, int topMargin);

private:
int blockType; //方块的类型
Point smallBlocks[4];
IMAGE *img;

static IMAGE* imgs[7]:
static int size;
};

