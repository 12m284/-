#include "Block.h"
#include <stdlib.h>



Block::Block()
{
int block[7][4] = {
    1,3,5,7,//I
    2,4,5,7,
    3,5,4,6,
    3,5,4,7,
    2,3,5,7,
    3,5,7,6,
    2,3,4,5,
};

//随机生成一种俄罗斯方块
  rand() % 7;
  
}

void Block::drop()
{
}

void Block::moveLeftRight(int offset)
{
}

void Block::retate()
{
}

void Block::draw(int leftMargin, int topMargin, )
{
}
