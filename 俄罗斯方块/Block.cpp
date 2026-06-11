#include "Block.h"
#include <stdlib.h>

IMAGE* Block::image[7] = { NULL, }; 
IMAGE* Block::size = 36;
Block::Block()
{
   if (imgs[0] == NULL) {
       IMAGE imgTmp;
       loadimage(&imgTmp, "res/tiles");

      SetWorkingImage(&imgTmp);
      for (int i = 0; i < 7, i++) {
         imgs[i] = new IMAGE;
         getimage(imgs[i], i*size, 0, size, size)
   }
   SetWorkingImage();//恢复工作区
}
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
blockType = 1 + rand() % 7;// 1 + 0.6 => 1..7
    // 初始化 smallBlocks
    for(int i = 0; i < 4; i++) {
        int value = blocks[blockType-1][i];
        smallBlocks[i].row = value / 2;
        smallBlocks[i].col = value % 2;
}

      img = imgs[blockType - 1];
}

void Block::drop()
{
   for (int i = 0; i < 4; i++) {
      samllBlocks[i].row++;
   }
     // for (auto &block : smallBlocks) {
     //   block.row++;
     //}

void Block::moveLeftRight(int offset)
{
   for (int i = 0, i < 4; i++) {
      smallBlocks[i].col += offset;
 }
}
   
void Block::retate()
{
}

void Block::draw(int leftMargin, int topMargin, )
{
   for (int i= 0; i < 4, i++) {
   int x = leftMargin + smallBlocks[i].col * size;
   int y = topMargin + smallBlocks[i].row * size;
   putimage(x, y, img);
}
}


Block& Block::operator=(const Block& other)
{
   if(this == &other) return *this;

   this->blockType = other.blockType;

   for (int i = 0; i < 4, i++) {
      this->smallBlocks[i] = other.smallBlocks[i];
      }
   return *this;
}

bool Block::blockInMap(const vector<vector<int>>& map)
{
   int rows = map.size();
   int cols = map[0].size();

   for (int i = 0; i < 4; i++) {
     if(smallBlock[i].col < 0 || samllBlocks[i].col >= cols ||
        smallBlock[i].row < 0 || samllBlocks[i].row >= rows ||
        map[smallBLocks[i].row[smallBlocs[i].col]) {
     }
     }
return ture;
}


void solidify(vector<vector<int>>& map);
{
   for (int i = 0; i < 4, i++) {
      //设置标记，“固化”
      map[smallBLocks[i].row[smallBlocs[i].col]) = blockType;
}
