/*
 * ProgressBar.cpp
 *
 *  Created on: Jun 8, 2020
 *      Author: sillpill
 */

#include "ProgressBar.h"
int ProgressBar:: SquareSize=0;

 int ProgressBar::TargetScore=0;
int ProgressBar::moves=4;
int ProgressBar:: progress=0;
ProgressBar::ProgressBar()
{
	SquareSize=75;
    TargetScore=300;
	ScoreValue[0]=50;//for the case of 3 ,4 and 5 matches
	ScoreValue[1]=60;
	ScoreValue[2]=70;
 ProgressBarLength=600;
 CascadesScore=100;
//for the starting at the first level
}

void ProgressBar::setprogress(int x)
{
	progress=x;
}
int ProgressBar::getprogress()
{
	return progress;
}

int* ProgressBar::getScoreValue()
{
	return ScoreValue;
}
int ProgressBar:: getProgressBarLength()
{
	return ProgressBarLength;
}
int ProgressBar:: getmoves()
{
	return moves;
}
int ProgressBar:: getCascadesScore()
{
	return CascadesScore;
}
void ProgressBar:: setmoves(int m)
{
	moves=m;
}
int ProgressBar:: getTargetScore()
{
	return TargetScore;
}
void ProgressBar::setTargetScore(int t)
		{
	TargetScore=t;

		}
void ProgressBar::setSquareSize(int s)
{
	SquareSize=s;
}
  int ProgressBar::getSquareSize()
  {
	  return SquareSize;
  }
