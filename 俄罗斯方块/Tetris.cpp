#include "Tetris.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include "Block.h"

#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")

#define MAX_LEEVEL 5
#define REDCORDER_FILE "recorder.txt"
//const int SPEED_NORMAL = 500;//ms
const int SPEED_NORMAL[MAX_LEEVEL] = { 500, 300, 150, 100 ,80 };
const int SPEED_QUICK = 30;

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
  
      delay = SPEED_NORMAL[0];

      //配置随机种子
      srand(time(NULL));
      //创建游戏窗口
      initgraph(938, 896);
  
       //加载背景图片
      loadimage(&imgBg, "res/bg2.png");
       //初始化游戏区中的数据
 char data[20][10];
  for (int i = 0; i < rows; i++) {
   for (int j = 0; j < cols; j++) {
      map[i][j] = 0;
}
  }
    score = 0;
  lineCount - 0;
  level = 1;

  
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
    if (gameOver) {
      // 保存分数
      saveScore();

      //更新游戏结束界面
      displayOver();

      system("pause");
      init(); //重新开始开局
    }   
 }
}
//初始化最高分
ifstream file(REDCORDER_FILE);
  if (!file.is_opem()) {
    cout << REDCORDER_FILE << "打开失败" << endl;
    highestScore = 0;
    
  }
  else {
     file >> highestScore;
  }
  file.colse();//关闭文件

  gameOver = false;
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
        case 80:
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
 if (rotateFlag) {
   //实现旋转
    rotate():
    update = ture;
  
   }

  if (dx != 0) {
   moveLeftRight(dx);
   update = true;
 }

   void Tetris::updateWindow()
{
  putimage(0, 0, &imgBg); //绘制背景图片
  
 IMAGE** imgs = Block::getImages();
BeginBetchDraw();
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      if(map[i][j] == 0)contime;

      int x = j * lockSize + leftMargin;
      int y = i * blockSize + topMargin;
      putimage(x, y, img[map[i][j]-1]);
        }
  }
  curBlock >draw(leftMargin, topMargin);
  nextBlock->draw(689, 150);
  
  drawScore();//绘制分数
  
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

    //检查游戏是否结束
    checkOver();
  }
  delay = SPEED_NORMAL[level-1];
}

void Tetris::clearLine()
{
  int k = rows - 1;//存储数据的行数
  for (int i = rows - 1; i >= 0; i--) {
  //检查第i行是否满行
    int count = 0;
    for (int j = 0; j < cols; j++) {
      if (map[i][j]) {
        cout++;
      }
      map[k][j] = map[i][j];//一边扫描一边存储
    }
    if(count < cols) {//不是满行
      k--;
    }
  else { // count == cols 满行
    lines++;
  }
  }

  if (lines > 0) {
    // 计算得分
    int andScore[4] = { 10, 30, 60, 80 };//最高消4行80分
    score += addScore[lines - 1];
    
    
    mciSendString("play res/xiaochu1.mp3", 0, 0, 0);
    update = ture;

    //每100分一个级别 0 100 第一关 101 200第2关
     level = (score + 99)/ 100;
     if (level > MAX LEVEL) {
       gameOver = true;
     }
    lineCount += lines;
  }
}

void Tetris::moveLeftRight(int offset)
{
  bakBlock =*curBlock;//备份防止方块掉出边界
   curBlock->moveLeftRight(offset);
 
  if(!curBlock->blockInMap(map)) {
      *curBlock = barBlock;//如果方块位置不合法，则保持原样
  }
}

void Tetris::rotate
{
  if(curBlock->getblockType() == 7) return;
  bakBlock =*curBlock;
  curBlock->rotate();

  if(!curBlock->blockInMap(map)) {
      *curBlock = barBlock;
}
}

void Tetris::drawScore()
{
  //把分数整型变成字符串
  char scoreText[32];
  sprintf_s(scoreText, seizeof(scoreText), "%d", SSCORE);

  setcolor(RGB(180,180,180));

LOGFONT f;//设置字体变量
  gettextstyle(&f);//获取当前字体
  f.lfHeight = 60;
  f.lfWidth = 30;
  f.lfQuality = ANTIALTASED_QUALITY;//设置字体为“抗锯齿”效果
  strcpy_s（f.lfFaceName， sizeof(f.ifFaceName), -T("Segoe UI Black")) ;//字体名字（因为类型是CHAR所以改一下类型）
  settextstyle(&f);//设置当前字体为当前设置好的字体文件

  setbkmode(TRANSPARENT);//选做，让字体的背景设置为透明效果
  
  //绘制分数
  outtextxy(670, 727, scoreText);
//绘制消除了几行
  sprintf_s(scoreText,sizeof(scoreText), "%d",lineCount);
  gettextstyle(&f);
  int xPos = 224 f.lfWidth * strlen(scoreText);
    outtextxy(xPos,817, scoreText);

  //绘制当前是第几关
  sprintf_s(scoreText,sizeof(scoreText), "%d",level);
    outtextxy(224-30, 727, scoreText);

  sprintf_s(scoreText,sizeof(scoreText), "%d", highestScore);
    outtextxy(670, 817, scoreText);
}

void Tetris::checkOver()
{
  gameOver = (curBlock->blockInMap(map) == false);
  
}




