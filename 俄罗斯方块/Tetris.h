#pragma once
class Tetris
{
public:

	Tetris(int row, int clos, int left, int top, int blockSize);
	void init();
	void play();

private:
    void keyEvent();
    void updateWindow();
};
