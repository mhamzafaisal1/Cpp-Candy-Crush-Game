/*
 * GameBoard.h
 *
 *  Created on: Jun 9, 2020
 *      Author: sillpill
 */


#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include"CanvasSizing.h"
#include"Coordinates.h"
#include"Gem.h"
#include"util.h"
#include<ctime>
#include<cstdlib>
class GameBoard : public CanvasSizing
{
private:
	Gem ** GemArray;
	Gem ** Matchcoor;
    Coordinates ScoreCoor;
    Coordinates MenuCoor;
    Coordinates HintCoor;
    Coordinates PlayPause[2];
    Coordinates PlayMethod;
    Coordinates MouseClick;
    static bool pause;
    static bool InitialDisplayCheck;
public:

       bool getpause();
    void setpause(bool);
	GameBoard();
	GameBoard(int ,int , int ,int);
	Coordinates getMouseClick();
	void DrawPlayMethod();
	void DrawGameBoard();
	void DrawPlayPause();
	Gem ** getMatchcoor();

    void DrawHint();
    void setGemAttributes();
    int getInitialDisplayCheck();
    void setInitialDisplayCheck(bool check);
    Gem ** getGemArray();
    ~GameBoard();

	};

#endif
