#include <iostream>
#include <windows.h>

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Cell {
	public:
		Cell(int x,
			 int y,
			 int textColor = 15,
			 int backgroundColor = 0,
			 int width = 2,
			 int height = 2)
		{
			x_ = x;
			y_ = y;
			width_ = width;
			height_ = height;
			textColor_ = textColor;
			backgroundColor_ = backgroundColor;
		};

		void draw();
	private:
		int x_;
		int y_;
		int width_;
		int height_;
		int textColor_;
		int backgroundColor_;
};