/*
 * NormalMode.cpp
 *
 *  Created on: Jun 8, 2020
 *      Author: sillpill
 */

#include "NormalMode.h"


void NormalMode::DrawProgressBar()
{

	DrawRectangle(200, 20,getprogress() , 30, colors[DARK_VIOLET]);
	DrawRectangle(200-10, 20,10 , 30, colors[BLACK]);
	DrawRectangle(800, 20,10 , 30, colors[BLACK]);
	DrawRectangle(200-10, 20+30,600+20 ,10, colors[BLACK]);
	DrawRectangle(200-10, 20-10,600+20 ,10, colors[BLACK]);


}
	void NormalMode:: ShowTargetMoves()
		{
		 DrawRectangle(10-5, 50-5, 140+30, 80, colors[DARK_VIOLET]);
			 DrawRectangle(10, 50, 140+30, 80, colors[MAGENTA]);
				      DrawString(10+10, 50+40,"Target Moves: ",colors[WHITE]);
				      string b= Num2Str(getmoves());
				      DrawString(10+10+70, 50+10,b,colors[BLACK]);
		}
