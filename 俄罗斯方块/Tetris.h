#pragma once
#include <graphics.h>
#include <vector>
#include "Block.h"
using namespace std;

class Tetris
{
public:

	Tetris(int row, int clos, int left, int top, int blockSize);
	void init();//初始化
	void play();//开始游戏

private:
    void keyEvent();
    void updateWindow();

//返回距离上次调用该函数，间隔了多少时间（ms)
//第一次调用该函数，返回0
    int getDelay();
    void drop();
    voide clearLine();
    void moveLeftRight(int offset);
    void rotate();
    void drawScore();/绘制当前分数

private:
int delay;
bool update; //是否更新

//int map[20][10];
//0: 空白， 没有任何方块
//5： 表示第五种方块，其余同理
vector<vector<int>> map;
int row;
int col;
int leftMargin,;
int topMargin;
int blockSize;
IMAGE imgBg;//背景图片

Block* curBlock;
Block* nextBlock; //预告方块
Block bakBlock; //当前方块降落过程中，用来备份上一个合法位置的！

int score;//当前的分数
int level;//当前关卡
int lineCount; //当前已经消除了多少行
};
