#include "Tetris.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "Block.h>

const int SPEED_NORMAL = 500;
const int SPEED_QUICK = 50;

Tetris::Tetris(int rows, int cols, int left, int top, int blockSize)
{
  this->rows = rows;
  this->cols = cols;
  this->leftMargin = left;
  this->topMargin = top;
  this->blockSize = blockSize;

   for (int i = 0; i < rows; i++) {
     vector<int> mapRow;
     for (int j = 0; j < cols; j++) {
       mapRow.push_back(0);
     }
     map.push_back(mapRow);
   }
  
}
  void Tetris::init()
{
  
      delay = SPEED_NORMAL;

      //配置随机种子
      srand(time(NULL));
      //创建游戏窗口
      initgraph(938, 896);
  
       //加载背景图片
      loadimage(&imgBg, "res/bg2.png");
       //初始化游戏区中的数据
 
  for (int i = 0; i < rows; i++) {
   for (int j = 0; j < cols, j++) {
      map[i][j] = 0;
}
}
  void Tetris::play()
{
  init();

nextBlock = new Block;//生成预告方块
curBlock = nextBlock;//更新当前方块
nextBlock = new Block;//再生成下一个方块
  
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
 unsigned char ch ;//char类型最小最大值是-128和127，解决办法，改成现在的类型无符号类型(最小最大值是0..255
bool rotateFlag = false;
int dx = 0;
  if (_kbhit()) {
    ch = _getch();
    //下面是常识，不需要记
    // 如果按下方向按键，会自动返回两个字符
    //如果按下 向上方向键， 会先后返回： 224 72 
    //如果按下 向下方向键， 会先后返回： 224 80
    //如果按下 向左方向键， 会先后返回： 224 75
    //如果按下 向右方向键， 会先后返回： 224 77 
    if (ch == 224) {
      ch = _getch();
      switch (ch) {
        case 72:
        rotateFlag = true;
        break;
        case 80;
           delay = SPEED_QUICK;
        break;
        case 75;
            dx = -1;
        break;
        case 77;
        dx = 1;
        default:
        break;
      }
  }
}
 if (rotateFlag） {
   //实现旋转
   }

  if (dx != 0) {
 
 }

   void Tetris::updateWindow()
{
  putimage(0, 0, &imgBg); //绘制背景图片
  
 IMAGE** imgs = Block::getImages();
BeginBetchDraw();
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; i++) {
      if(map[i][j] == 0)contime;

      int x = j * lockSize + leftMargin;
      int y = i * blockSize + topMargin;
      putimage(x, y, img[map[i][j]-1]);
        }
  }
  curBlock >draw(leftMargin, topMargin);
  nextBlock->draw(689, 150);

  EndBlockDraw();
}

//第一次调用，返回0
//返回距离上一次调用，间隔了多少ms
int Tetris::getDelay()
{
  static unsigned long long lastTime = 0;
  
  usigned long long currentTime = GetTickCount();

  if(lastTime == 0) {
    lastTime = currentTime;
    return 0;
  }
  else {
    int ret = currentTime - lastTime;
    lastTime = currentTime;
    return ret;
  }
}

void Tetris::drop()
{
  bakBlock = *curBlock;
  curBlock->dorp();

  if (!curBlock->blockInMap(map)) {
      //把这个方块“固化”
      bakBlock.solidify(map);
      delete curBlock;
      curBlock = nextBlock;
    nextBlock = new Block;
  }
}

void Tetris::clearLine()
{
}

