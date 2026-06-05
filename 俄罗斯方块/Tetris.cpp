#include "Tetris.h"
#include <time.h>
#include <stdlib.h>
Tetris::Tetris(int row, int clos, int left, int top, int blockSize)
{
  
}
  void Tetris::init()
{
      delay = 30;

      //配置随机种子
      srand(time(NULL));
}
  void Tetris::play()
{
  init();
  int timer = 0;
  while (1) {
    //接受用户的输入
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
}

   void  Tetris::keyEvent()
{
  update = true;
}

   void Tetris::updateWindow()
{
}


