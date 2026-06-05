#include "Tetris.h"

Tetris::Tetris(int row, int clos, int left, int top, int blockSize)
{
  
}
  void Tetris::init()
{
      delay = 30;
}
  void Tetris::play()
{
  init();
  int timer = 0;
  while (1)
    {
      keyEvent();
     
      timer += getDelay();
      if  (timer > delay) {
           timer = 0;
          dorp();
           update = true;
    }
if (update) {
    update = false;
  //更新游戏画面
    updateWindow();
  //更新游戏的数据
  clearLine();


  
  }
}

   void  Tetris::keyEvent()
{
  update = true;
}

   void Tetris::updateWindow()
{
}


