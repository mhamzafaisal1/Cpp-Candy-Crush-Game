/*
 * Menu.h
 *
 *  Created on: Jun 3, 2020
 *      Author: sillpill
 */

#ifndef MENU_H_
#define MENU_H_
#include"Player.h"
#include"Coordinates.h"

class Menu {
	string Name;
	 static int ModeChoice;
	static bool MenuCheck;
   Coordinates TimeMode;
   Coordinates NormalMode;
   Coordinates Method;
   Coordinates setting;
   Coordinates Level;

   static int window;
   static int secondwindow;
   static bool NameCheck;

public:
 //void writeProfile();
   string getName();

   void setName(string a);
   void setNameCheck(int);
   int getNameCheck();
   static void setwindow(int);
   int getwindow();
   void setsecondwindow(int);
   int getsecondwindow();
   void DisplayName();
   void DisplayPlayerProfile();
   static int getModeChoice();
   void setModeChoice(int);
   void setLevel(int);
	Menu();
	void DisplayHighScores();
	void DisplayContentsOnScreen();
	void DisplaySettingContent();
	void DisplayLevels();
	void CalcHighScores(int);
	void DisplayMethod();

   void EnterName( char );
   void SetLevel(int);
  static void setMenuCheck(bool);
  bool getMenuCheck();
 ~Menu(){

 }
};

#endif /* MENU_H_ */
