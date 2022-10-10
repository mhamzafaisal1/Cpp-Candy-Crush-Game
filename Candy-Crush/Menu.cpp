/*
 * Menu.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: sillpill
 */

#include "Menu.h"
#include"fstream"
bool Menu::MenuCheck=false;
int Menu:: ModeChoice=-1;
int Menu:: window=0;
int Menu:: secondwindow=0;
bool Menu:: NameCheck=0;
int Menu:: getwindow()
{
	return window;
}
string Menu:: getName()
{
	return Name;
}
 void Menu::setName(string a)
 {
	 Name=a;
 }
void Menu:: setwindow( int s)
{
	window=s;
}
int Menu:: getsecondwindow()
{
	return secondwindow;
}
void Menu:: setNameCheck( int s)
{
	NameCheck=s;
}
int Menu:: getNameCheck()
{
	return NameCheck;
}
void Menu:: setsecondwindow( int s)
{
	secondwindow=s;
}
void Menu:: DisplayPlayerProfile()
{
	glClearColor(0.7/*Red Component*/, 0.7,	//148.0/255/*Green Component*/,
		   			0.9/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		   		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

		 DrawString(400, 600, "PLAYER PROFILE : ",colors[BLACK]);
		 DrawString(200, 600-50, "NAME ",colors[BLACK]);
		 DrawString(200+600, 600-50, "LEVELS COMPLETED ",colors[BLACK]);


		 DrawString(700, 50, "B.BACK TO MENU ", colors[WHITE] );
}
/*
void Menu::writeProfile()
{
	 ofstream outputFile;
			 if(Player::getlives()==0)
			 {
			  outputFile.open("PlayerProfile.txt", ios::out|ios::app);
			  outputFile << Name;
			  outputFile << Player::getLevel();

			 }
			  outputFile.close();
}
*/
Menu::Menu()
{


}

 int Menu:: getModeChoice()
{
	return  ModeChoice;
}
void Menu:: setModeChoice(int s)
{
	ModeChoice=s;

}

void Menu:: DisplayContentsOnScreen()
{
	float * color =colors[BLACK];
	 DrawString(300, 600, "GHOST", color );


	 DrawString(600, 600, "BUSTERS", color );
	 int x=500;
	 int y=600;
	 int size=180;
	 int ghostMouth;
	 		ghostMouth = rand() % 2 + 1;
	 		DrawRectangle(x - size / 2, y - size / 2, size, size, colors[ORANGE_RED]);
	 		DrawCircle(x,y+20, size / 4, colors[WHITE]);
	 		DrawRectangle(x - size / 4, y - (size / 4) + 5, 2 * size / 4, size / 4+20,
	 				colors[WHITE]); //height=30 and width=15
	 		DrawCircle(x - size / 4, y - (size / 4), size / 12, colors[WHITE]); //legs of the ghost , inrementing x =10 to make more legs along x axis
	 		DrawCircle(x - size / 4 + 30, y - (size / 4), size / 12, colors[WHITE]);
	 		DrawCircle(x - size / 4 + 60, y - (size / 4), size / 12, colors[WHITE]);
	 		DrawCircle(x - size / 4 + 90, y - (size / 4), size / 12, colors[WHITE]);

	 		//eyes
	 		DrawCircle(x - 15, y + (size / 4), 7, colors[BLACK]);
	 		DrawCircle(x + 15, y + (size / 4), 7, colors[BLACK]);
	 		//smile
	 		if (ghostMouth == 1) {
	 			DrawRoundRect(x-20 , y+20 , 40, 2, colors[BLACK], 10.0);
	 		} else {
	 			DrawRoundRect(x - 10, y + (size / 4) - 15, 20, 2, colors[WHITE], 10.0);
	 			DrawRoundRect(x - 10, y + (size / 4) - 15, 20, 2, colors[BLACK], 2.0);
	 		}

	 		int Bx=500;
	 		int By=100;

	 		//DRAWING BORDER
	 		{
              float *buttoncolour= colors[DARK_VIOLET];
              float *BC=colors[WHITE];
              DrawRoundRect( Bx/2-25 ,By/4, Bx+100, By+360, colors[MAGENTA], 40.0);
              int wx=50;
              {
            	  DrawRoundRect( Bx/2-25+150-5 ,(By/4)-5,  300,wx, BC, 0);
            	  DrawRoundRect( Bx/2-25+150 ,(By/4),  300,wx, buttoncolour, 0);
            	  DrawString(Bx/2-25+150+75, (By/4)+20, "L-LEVELS", color );
              }
              //wx+=50;
              {
            	  DrawRoundRect( Bx/2-25+150-5 ,(By/4)+2*wx-5,  300,wx, BC, 0);
            	  DrawRoundRect( Bx/2-25+150 ,(By/4)+2*wx,  300,wx, buttoncolour, 0);
            	  DrawString(Bx/2-25+150+75, (By/4)+2*wx+20, "H-HIGH SCORES", color );
              }
              //wx+=50;
              {
            	  DrawRoundRect( Bx/2-25+150-5 ,(By/4)+4*wx-5,  300,wx, BC, 0);
            	  DrawRoundRect( Bx/2-25+150 ,(By/4)+4*wx,  300,wx, buttoncolour, 0);
            	  DrawString(Bx/2-25+150+75, (By/4)+4*wx+20, "S-SETTINGS", color );
              }
              //wx+=50;
              {

            	  DrawRoundRect( Bx/2-25+150-5 ,(By/4)+6*wx-5,  300,wx, BC, 0);
            	  DrawRoundRect( Bx/2-25+150 ,(By/4)+6*wx,  300,wx, buttoncolour, 0);
            	  DrawString(Bx/2-25+150+75, (By/4)+6*wx+20, "N-NORMAL MODE", color );
              }
              //wx+=50;
              {  DrawRoundRect( Bx/2-25+150-5 ,(By/4)+8*wx-5,  300,wx, BC, 0);
            	  DrawRoundRect( Bx/2-25+150 ,(By/4)+8*wx,  300,wx, buttoncolour, 0);
            	  DrawString(Bx/2-25+150+75, (By/4)+8*wx+20, "T-TIME MODE", color );
              }

	 		}

	 		 Gem1::DrawGem(90,670);
	 		  DrawString(10, 670-60, "Assignment Live Wire", color );
	 		       Gem2::DrawGem(90,670-250);
	 		      DrawString(0, 670-60-250, "Over Productive Friend", color );
	 		       Gem3::DrawGem(90,670-250-250);
	 		      DrawString(10, 670-60-250-250, "MidTerm DOOM Boi", color );
	 		       Gem4::DrawGem(900,700-150);
	 		      DrawString(900-70, 700-60-150, "DC Rewind", color );
	 		       Gem5::DrawGem(900,700-250-150);
	 		      DrawString(900-70, 700-60-250-150, "Project Inferno", color );


}
	void Menu::DisplaySettingContent()
	{
		glClearColor(0.7/*Red Component*/, 0.7,	//148.0/255/*Green Component*/,
						0.9/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
				glClear (GL_COLOR_BUFFER_BIT); //Update the colors
				int midy=350;
				int midx=500;
				 DrawRoundRect(midx-200, midy+200, 400,100 ,colors[DARK_VIOLET] , 9.0);
				   DrawString(midx-200+100, midy+200+40, "P. PLAYER PROFILE", colors[WHITE] );
				 DrawRoundRect(midx-200, midy-200, 400,100 ,colors[DARK_VIOLET] , 9.0);
				   DrawString(midx-200+100, midy-200+40, "H. HOW TO PLAY", colors[WHITE] );

				   DrawString(700, 50, "B.BACK TO MENU ", colors[WHITE] );
	}
	void Menu::DisplayLevels()
	{
		glClearColor(0.7/*Red Component*/, 0.7,	//148.0/255/*Green Component*/,
						0.9/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
				glClear (GL_COLOR_BUFFER_BIT); //Update the colors
              static int current=1;
              string s;
				int midx=350;
                  int y=200;

				   DrawString(midx-100, y, "LEVEL ", colors[WHITE] );
				   float *lockec=colors[GRAY];
				   float *unlocked=colors[GREEN];

				   {

					  s= Num2Str(current);
					   DrawString(midx-100+80, y,s , colors[WHITE]);
					   DrawRoundRect(midx-100+60-80, y-30, 150,60 ,colors[DARK_VIOLET] , 9.0);
				   y+=230;

				   DrawString(midx-100, y, "LEVEL", colors[WHITE] );
				   s= Num2Str(current+1);
				   DrawString(midx-100+80, y, s, colors[WHITE] );
				   y+=230;
				   DrawString(midx-100, y, "LEVEL", colors[WHITE] );
				   s= Num2Str(current+1+1);
				   DrawString(midx-100+80, y, s, colors[WHITE] );
                  }


				   DrawString(700, 50, "B.BACK TO MENU ", colors[WHITE] );
	}

	void Menu::DisplayMethod()
	{
		glClearColor(0.0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
						0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
				glClear (GL_COLOR_BUFFER_BIT); //Update the colors

				int y=600;
	DrawString(100, y, "Normi , is BS CS Student at FAST NUCES ,struggling under the ", colors[WHITE] );
	y-=20;
	DrawString(100, y, "wicked spells of GHOSTS.She awaits a ghost buster to save her", colors[WHITE] );
	y-=20;
	DrawString(100, y, "from the pressing assignments and inferiority complex.About to ", colors[WHITE] );
	y-=20;
	DrawString(100, y, "burn out,this is your chance to save the world one fast nuces ", colors[WHITE] );
	y-=20;
	DrawString(100, y, "child at a time. ", colors[WHITE] );

    Gem1::DrawGem(100,400);
    Gem2::DrawGem(100,340);
    DrawString(160, 400, "Swap the same type of Ghosts to bust them and earn points. ", colors[WHITE] );
    DrawString(160, 340, "Each swap is one move , you must meet the target in given moves.", colors[WHITE] );
    y=250;
    DrawString(100, y,"For Time Mode you must struggle against depleting progress bar", colors[WHITE] );
    DrawString(100, y-20, "to complete the level by meeting the target ", colors[WHITE] );
    DrawString(100, y-40, "You shall have three live through the game.Upon a failed level", colors[WHITE] );
    DrawString(100, y-60, "a life would be taken and you will have one chance at that level again ", colors[WHITE] );
	DrawString(700, 50, "B.BACK TO MENU ", colors[WHITE] );

	}
void Menu:: DisplayName()
{
	 int Bx=500;
		   int By=100;
		     DrawRoundRect( Bx/2-25 ,By/4, Bx+100, By+360, colors[MAGENTA], 40.0);
		     DrawRoundRect( Bx/2-25 ,By/4, Bx+100, By+360, colors[MAGENTA], 40.0);
		     DrawString(300, 400, "	ENTER YOUR NAME BELOW: ",colors[BLACK]);

			   DrawString(400, 400-50,getName(),colors[BLACK]);
			   DrawRoundRect( 400 ,400-250, 200, 60, colors[DARK_VIOLET], 10.0);
			   DrawString(400+60, 400-250+30,"$.Enter",colors[WHITE]);
}
   void Menu::EnterName(char digit)
   {
	   setName(getName()+digit);


   }
   void Menu::SetLevel(int)
   {

   }
   void Menu:: DisplayHighScores()
   {
	   glClearColor(0.7/*Red Component*/, 0.7,	//148.0/255/*Green Component*/,
	   			0.9/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	   		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	 DrawString(400, 600, "HIGHSCORES: ",colors[BLACK]);
	 DrawString(700, 50, "B.BACK TO MENU ", colors[WHITE] );
   }

     void  Menu::setMenuCheck(bool A)
     {
    	 MenuCheck=A;
     }
     bool  Menu::getMenuCheck()
     {
    	 return MenuCheck;
     }
