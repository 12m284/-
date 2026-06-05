#pragma once

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
Points smallBlocks[4];
};

