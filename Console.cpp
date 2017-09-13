#include "Console.h"

Console::Console(){};
Console::~Console(){};

Console* Console::_instance = 0;
bool Console::_status = Free;

Console* Console::Instance(){
	if (_instance == 0) {
		_instance = new Console();
	}
	return _instance;
}

const bool Console::status(){
	return _status;
}

void Console::drawText(
	 const int x,
	 const int y,
	 const string str,
	 const int textColor,
	 const int backgroundColor,
	const bool checkStatus)
{
	bool isReady = false;

	while (!isReady) {
		if ((_status == Free && checkStatus) || (_status == Busy && !checkStatus)) {
			if (checkStatus)
				_status = Busy;

			setColor(textColor, backgroundColor, false);
			gotoXY(x, y, false);
			cout << str;

			if (checkStatus)
				_status = Free;
			isReady = true;
		}
	}
}

void Console::setColor(
	 const int textColor, 
	 const int backgroundColor,
	const bool checkStatus)
{
	bool isReady = false;

	while (!isReady) {
		if((_status == Free && checkStatus) || (_status == Busy && !checkStatus)) {
			if (checkStatus)
				_status = Busy;

			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hStdOut, static_cast<WORD>((backgroundColor << 4) | textColor));

			if (checkStatus)
				_status = Free;
			isReady = true;
		}
	}
}

void Console::gotoXY(
	 const int x,
	 const int y,
	const bool checkStatus)
{
	bool isReady = false;

	while (!isReady) {
		if ((_status == Free && checkStatus) || (_status == Busy && !checkStatus)) {
			if (checkStatus)
				_status = Busy;

			COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hStdOut, coord);

			if (checkStatus)
				_status = Free;
			isReady = true;
		}
	}
}

void Console::fillLine(
	 const string mid,
	 int width,
	 const int x,
	 const int y,
	 const bool hasNewline,
	 const bool checkStatus)
{
	bool isReady = false;

	while (!isReady) {
		if ((_status == Free && checkStatus) || (_status == Busy && !checkStatus)) {
			if (checkStatus)
				_status = Busy;

			if (width < 1) width = 1;

			if (x > 0 || y > 0)
				gotoXY(x, y, false);

			for (int i = 0; i < width; i++)
				cout << mid;

			if (hasNewline)
				cout << "\n";

			if (checkStatus)
				_status = Free;
			isReady = true;
		}
	}
}

void Console::fillLine(
	 const string begin,
	 const string mid,
	 const string end,
	 int width,
	 const int x,
	 const int y,
	 const bool hasNewline,
	 const bool checkStatus)
{
	bool isReady = false;

	while (!isReady) {
		if ((_status == Free && checkStatus) || (_status == Busy && !checkStatus)) {
			if (checkStatus)
				_status = Busy;

			if (width < 3) width = 3;

			if (x > 0 || y > 0)
				gotoXY(x, y, false);

			cout << begin;

			for (int i = 0; i < width - 2; i++)
				cout << mid;

			cout << end;

			if (hasNewline)
				cout << "\n";

			if (checkStatus)
				_status = Free;
			isReady = true;
		}
	}
}

void Console::fillSquare(
	 const string mid,
	 int width,
	 int height,
	 const int x,
	 const int y,
	 const bool checkStatus)
{
	bool isReady = false;

	while (!isReady) {
		if ((_status == Free && checkStatus) || (_status == Busy && !checkStatus)) {
			if (checkStatus)
				_status = Busy;

			if (width < 1) width = 1;
			if (height < 1) height = 1;

			for (int i = 0; i < height; i++)
				fillLine(mid, width, x, y + i, true, false);

			if (checkStatus)
				_status = Free;
			isReady = true;
		}
	}
}

void Console::fillSquare(
	 const string begin,
	 const string mid,
	 const string end,
	 int width,
	 int height,
	 const int x,
	 const int y,
	 const bool checkStatus)
{
	bool isReady = false;

	while (!isReady) {
		if ((_status == Free && checkStatus) || (_status == Busy && !checkStatus)) {
			if (checkStatus)
				_status = Busy;

			if (width < 3) width = 3;
			if (height < 1) height = 1;

			for (int i = 0; i < height; i++)
				fillLine(begin, mid, end, width, x, y + i, true, false);

			if (checkStatus)
				_status = Free;
			isReady = true;
		}
	}
}