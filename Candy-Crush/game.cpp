//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include<cstdlib>
#include<ctime>
#include "util.h"
#include"GameBoard.h"
#include"CanvasSizing.h"
#include"Player.h"
#include"Menu.h"
#include"NormalMode.h"
#include"TimeMode.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
#include <chrono>
#include <thread>
#include"Variable.h"

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

Variable var;
void GameDisplay()/**/{

	//A.setMenuCheck(true);
	if(var.A.getMenuCheck()==false )
	{
		glClearColor(0.7, 0.7,
				0.9, 0 ); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		if(var.A.getwindow()==0)
			var.A.DisplayContentsOnScreen();
		if(var.A.getNameCheck()==0)
		{
			var.A.DisplayName();

		}
		if(var.A.getwindow()==1)//TIMEMODE
		{

			var.B.setModeChoice(true);
			var.A.setMenuCheck(true);
		}
		else if(var.A.getwindow()==2)//NORMAL MODE
		{
			var.B.setModeChoice(false);
			var.A.setMenuCheck(true);
		}
		else if(var.A.getwindow()==3)//SETTINGS
		{
			var.A.DisplaySettingContent();
			if(var.A.getsecondwindow()==1)
			{
				var.A.DisplayMethod();
			}
			else
				if(var.A.getsecondwindow()==2)
				{
					var.A.DisplayPlayerProfile();

				}
		}
		else if(var.A.getwindow()==4)//HIGHSCORES
		{
			var.A.DisplayHighScores();

		}
		else if (var.A.getwindow()==5)//LEVELS
		{
			var.A.DisplayLevels();
		}



	}
	else
	{

		if(var.B.getpause()==false)
		{


			glClearColor(0.66/*Red Component*/, 0.8,	//148.0/255/*Green Component*/,
					0.75/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
			glClear (GL_COLOR_BUFFER_BIT); //Update the colors
			if(var.A.getsecondwindow()==1)
			{
				var.A.DisplayMethod();
			}
			else

			{



				if(var.B.getModeChoice()==false)
				{
					var.B.DrawGameBoard();
					var.B.NormalMode::DrawProgressBar();//sends te number of Gems that have matched
					var.B.UpdateScore(0);
					var.B.Showlives();
					var.B.DrawLevel();
					var.B.ShowTargetMoves();
					var.B.ShowCurrentMoves();
					var.B.CheckLevel();



				}
				else
				{
					/*

			var.B.TimeMode::DrawProgressBar(0);
			var.B.TimeMode::UpdateScore(0);
			var.B.TimeMode::DrawLevel();
					 */
				}


				if(var.B.getInitialDisplayCheck()==false)
				{
					var.B.setGemAttributes();
					var.B.setInitialDisplayCheck(true);
					var.B.DrawGameBoard();

				}

				var.B.DrawHint();

				// var.B.GiveHint();
				var.B.DrawPlayMethod();
				var.B.DrawPlayPause();

				static int count=0;
				if(var.B.getswapper()==false)
				{
					if(count==600)
					{
						count=0;
					}
					count++;
					var.B.CheckSwap();
					var.B.Swap(var.B.getSwapGem()[0],var.B.getSwapGem()[1]);

					if(count%2==0)
						var.B.setCurrentMoves(var.B.getCurrentMoves()+1);

					var.B.CheckLevel();
					var.B.setmousecoor1(0,0);
					var.B.setmousecoor2(0,0);
					var.B.setmouseCheck(false);
					var.B.setswapper(true);

				}
				else
					var.B.DrawGameBoard();
				if(var.B.getfallingGemsCheck()==true)
				{
					var.B.isMatching();
					var.B.setfallingGemsCheck(false);
				}
				var.B.getSwapGem()[0].setx(0);
				var.B.getSwapGem()[0].sety(0);
				var.B.getSwapGem()[1].setx(0);
				var.B.getSwapGem()[1].sety(0);
				var.B.getSwapGem()[0].setType(0);
				var.B.getSwapGem()[1].setType(0);


				var.B.figureMatchcoor();
				var.B.RefillGems();
				if(var.B.getHintCheck()==true)
				{
					var.B.GiveHint();
					var.B.setHintCheck(false);
				}

			}

		}

	}

	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
void Timer(int m) {

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(80.0, Timer, 0);
	glutPostRedisplay();
}
void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed..


	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		//da+=10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if(var.A.getNameCheck()==0)
	{
		var.A.EnterName(key);
		if(key=='$')
		{
			var.A.setNameCheck(true);
		}

	}
	else
		if(var.A.getMenuCheck()==false)
		{
			if(key=='l' || key=='L')
			{

				var.A.setwindow(5);

			}
			else if(key=='H'|| key=='h')
			{
				if(var.A.getwindow()==3)//if settings are opened then
					var.A.setsecondwindow(1);
				else
				{
					var.A.setwindow(4);
				}
			}
			else if(key=='S'|| key=='s')
			{
				var.A.setwindow(3);
			}
			else if(key=='N'|| key=='n')
			{
				var.A.setwindow(2);
			}
			else if(key=='T' || key=='t')
			{
				var.A.setwindow(1);
			}
			else if(key=='B'|| key=='b')
			{
				var.A.setwindow(0);
				var.A.setsecondwindow(0);
			}
			else if(key=='p'|| key=='P')
			{
				var.A.setsecondwindow(2);
			}
		}
		else if(var.A.getMenuCheck()==true)
		{
			if(key=='p' || key=='P')
				var.B.setpause(true);
			else if(key=='R' || key=='r')
				var.B.setpause(false);
			else if (key=='W' || key=='w')
				var.A.setsecondwindow(1);
			else if(key=='B'|| key=='b')
				var.A.setsecondwindow(0);
			else if(key=='H'|| key=='h')
				var.B.setHintCheck(true);
		}
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	//glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */

//static bool thispressed=false;

void MousePressedAndMoved(int x, int y) {
	if(var.B.getmouseCheck()==false && var.A.getMenuCheck()==true)
	{
		int x1=x,y1=y;
		cout<<"x1yo: "<<x1<<"y1: "<<700-y1<<endl;
		var.B.setmousecoor1(x1,700-y1);
		var.B.setmouseCheck(true);
	}

	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;

}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout<<"Right Button Pressed"<<endl;

	}

	if(state==1)
	{
		cout<<"x: "<<x<<" y: "<<y<<endl;
	}
	if(var.B.getmouseCheck2()==true && var.A.getMenuCheck()==true)
	{
		int x2=x,y2=y;
		cout<<"x2: "<<x<<"y2: "<<705-y<<endl;
		var.B.setmousecoor2(x2,705-y2);
		var.B.setswapper(false);


	}

	glutPostRedisplay();

}

int main(int argc, char*argv[]) {


	int width =1000, height =700; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(200, 100); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
