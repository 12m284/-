#pragma once
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


private:
int delay;
bool update;
};
