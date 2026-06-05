#pragma once

class Block
{
public:
    Block();
    void drop();
    void moveLeftRight(int offest);
    void retate();
    voide draw(int leftMargin, int topMargin);

private:
int blockType; //方块的类型
};

