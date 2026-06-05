#include "Tetris.h"

Tetris::Tetris(int row, int clos, int left, int top, int blockSize)
{
  
}
  void Tetris::init()
{
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
        
           updateWindow();
    }
  }
   void  Tetris::keyEvent()
{
}

   void Tetris::updateWindow()
{
}


