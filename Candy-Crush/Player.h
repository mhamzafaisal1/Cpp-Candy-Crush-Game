/*
 * Player.h
 *
 *  Created on: Jun 4, 2020
 *      Author: sillpill
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<iostream>
using namespace std;
#include"TimeMode.h"
#include"NormalMode.h"
#include"GameBoard.h"
//#include"Menu.h"
#include<string>
#include <chrono>
#include <thread>
using namespace std;
class Player: public GameBoard,public NormalMode,public TimeMode
{
private:

	string PlayerName;
	bool ModeChoice;
	static int Level;
	Gem SwapGem[2];
	static int GemSwapCheck;

	 int mousecoor[4];
	 static bool mouseCheck;
	 static bool mouseCheck2;
	 static bool swapper;
	 static bool fallingGemsCheck;
	 static bool matched;
	 static bool HintCheck;
	 static int CurrentMoves;
	 static int CurrentScore;
	 static int lives;
public:
    void setName(string);
    static int getlives();
	Player(int r,int c,int ,int,int,int);
     void figureMatchcoor();
   void DrawLevel();
   void UpdateScore(int);
   void ShowCurrentMoves();
	Player();
	void Showlives();
	int* getmousecoor();
    void isMatching();
	void CheckSwap();
	void Swap( Gem & SwapGem1 , Gem & SwapGem2);
	void addSound();
	void GiveHint();


	bool getModeChoice();
	void setModeChoice(bool);

	bool getswapper();
	bool getmouseCheck();
	void setmouseCheck(bool);
	bool getHintCheck();
	void setCurrentScore(int);
	int getCurrentScore();
	void setCurrentMoves(int);
	int getCurrentMoves();
	void setHintCheck(bool);
	 bool checkforhint(int cx,int cy,int type, int d);
	bool getmouseCheck2();
		void setmouseCheck2(bool);
	void setswapper(bool);
	void  setfallingGemsCheck(bool a);
	bool getfallingGemsCheck();
	static int getLevel();

		void  setLevel(int);
	//friend void Menu::setLevel(int);
	 Gem* getSwapGem();
      int getDirectionOfGemSwap();
      void setmousecoor1(int , int );
      void setmousecoor2(int , int );
      void RefillGems();
      void CheckLevel();
      void DrawCurrentScore();

    ~Player(){};
};

#endif /* PLAYER_H_ */
