/*
 * ProgressBar.h
 *
 *  Created on: Jun 8, 2020
 *      Author: sillpill
 */

#ifndef PROGRESSBAR_H_
#define PROGRESSBAR_H_
#include"util.h"
class ProgressBar {
private:
	static int SquareSize;
	int ScoreValue[3];//for the case of 3 ,4 and 5 matches

	int ProgressBarLength;
	int CascadesScore;
	static int TargetScore;
	static int moves;
	static int progress;


public:
	int getProgressBarLength();
	ProgressBar();
	ProgressBar(int,int);
	void setProgressBar(int,int);
	void setprogress(int);
	int getprogress();
	int getmoves();
	void  setmoves(int);
   void setTargetScore(int);
   int getTargetScore();
   void setSquareSize(int);
   int getSquareSize();
	int* getScoreValue();
  int getCascadesScore();


 ~ProgressBar(){}
};

#endif /* PROGRESSBAR_H_ */
