/*
 * GameBoard.cpp
 *
 *  Created on: Jun 9, 2020
 *      Author: sillpill
 */

#include"GameBoard.h"

  bool GameBoard:: pause=false;
	bool GameBoard::InitialDisplayCheck = false;
	GameBoard::GameBoard()
	{
		GemArray = new Gem*[this->getcols()];
		for (int i = 0; i < this->getcols(); i++)
		{
			GemArray[i] = new Gem[this->getrows()];
		}
		Matchcoor = new Gem*[this->getcols()];
		for (int i = 0; i < this->getcols(); i++)
		{
			Matchcoor[i] = new Gem[this->getrows()];

	    }
	}


	void GameBoard::DrawGameBoard()
	{
		int adjustment=30;
		int BorderWidth = 10;
		int widthOnEnds = (1000 - (this->getsize()[0])) / 2;
		int heightOnEnds = (700 - (this->getsize()[1])) / 2;
		int rec1x, rec1y;

		rec1x = (1000 - (this->getsize()[0])) / 2; //subtracting from 1000 , width of screen to the size of gem board width
		rec1y = (700 - (this->getsize()[1])) / 2+adjustment;

		DrawRectangle(rec1x, rec1y, this->getsize()[0], this->getsize()[1],
				colors[MIDNIGHT_BLUE]);

		/* The following code is for the border of the Gem Board*/
		float * BorderColour=colors[ROYAL_BLUE];
		rec1x = (1000 - (this->getsize()[0])) / 2 - BorderWidth;
		DrawRectangle(rec1x, rec1y, BorderWidth, this->getsize()[1],
				BorderColour);
		rec1x = widthOnEnds + this->getsize()[0];
		DrawRectangle(rec1x, rec1y, BorderWidth, this->getsize()[1],
				BorderColour);
		rec1x = widthOnEnds - BorderWidth;
		rec1y = heightOnEnds + getsize()[1]+adjustment;
		DrawRectangle(rec1x, rec1y, this->getsize()[1] + 2 * BorderWidth,
				BorderWidth, BorderColour);
		rec1y = heightOnEnds - BorderWidth+adjustment;
		DrawRectangle(rec1x, rec1y, this->getsize()[1] + 2 * BorderWidth,
				BorderWidth, BorderColour);
		for(int i=0 ; i<this->getrows(); i++)
		{

			for (int j = 0; j < this->getcols(); j++)
			{
				if (GemArray[i][j].getType() == 1) {
					GemArray[i][j].Gem1::DrawGem(GemArray[i][j].getx(),GemArray[i][j].gety());

				} else if (GemArray[i][j].getType() == 2) {
					GemArray[i][j].Gem2::DrawGem(GemArray[i][j].getx(),GemArray[i][j].gety());

				} else if (GemArray[i][j].getType() == 3) {
					GemArray[i][j].Gem3::DrawGem(GemArray[i][j].getx(),GemArray[i][j].gety());

				} else if (GemArray[i][j].getType() == 4) {
					GemArray[i][j].Gem4::DrawGem(GemArray[i][j].getx(),GemArray[i][j].gety());

				} else if (GemArray[i][j].getType() == 5) {
					GemArray[i][j].Gem5::DrawGem(GemArray[i][j].getx(),GemArray[i][j].gety());

				}
				else if(GemArray[i][j].getType() == 6)
				{
					GemArray[i][j].Gem::DrawGem(GemArray[i][j].getx(),GemArray[i][j].gety());
				}
				else if(GemArray[i][j].getType() == -8)
				{
					GemArray[i][j].Gem6::DrawGem(GemArray[i][j].getx(),GemArray[i][j].gety());
				}
			}

		}
	}

	Coordinates GameBoard:: getMouseClick()
	{
		return MouseClick;
	}
	void GameBoard::DrawPlayPause() {
		float size = 50;
		float height = 50;
		float widthOnEnds = (1000 - (this->getsize()[0])) / 2;
		float heightOnEnds = (800 - (this->getsize()[1])) / 2;
		float rec1x, rec1y;
		rec1x = this->getsize()[0] + widthOnEnds + 2 * size;
		rec1y = heightOnEnds + (getsize()[1]) / 2;
		DrawRoundRect(rec1x-5, rec1y-5, size, height, colors[DARK_VIOLET], 7.0);//play
		DrawRoundRect(rec1x, rec1y, size, height, colors[MAGENTA], 7.0);//play
		{
			DrawRectangle(rec1x + 10, rec1y + 10, 5, 30, colors[BLACK]);
			DrawTriangle(rec1x + 10, rec1y + 25, rec1x + 40, rec1y + 25 + 15,
					rec1x + 40, rec1y + 25 - 15, colors[BLACK]);
		}
		DrawString(rec1x-10 , rec1y - 20, "R.Resume", colors[BLACK]);
		size = 50;
		height = 50;
		widthOnEnds = (1000 - (this->getsize()[0])) / 2;
		heightOnEnds = (800 - (this->getsize()[1])) / 2;

		rec1x = this->getsize()[0] + widthOnEnds + 2 * size;
		rec1y = heightOnEnds + (getsize()[1]) / 2 + 2 * size;
		DrawRoundRect(rec1x-5, rec1y-5, size, height, colors[DARK_VIOLET], 7.0);//pause
		DrawRoundRect(rec1x, rec1y, size, height, colors[MAGENTA], 7.0);//pause
		{
			DrawRectangle(rec1x + 25, rec1y + 5, 5, 40, colors[RED]);
			DrawTriangle(rec1x + 10, rec1y + 25, rec1x + 40, rec1y + 25 + 15,
					rec1x + 40, rec1y + 25 - 15, colors[BLACK]);
			DrawRectangle(rec1x + 10, rec1y + 10, 5, 30, colors[BLACK]);
		}
		int x=rec1x+25;
		int y=rec1y+25;
		DrawString(rec1x , rec1y - 20, "P.Pause", colors[BLACK]);
		//cout<<"x: "<<MouseClick.getx()<<" y: "<<MouseClick.gety()<<endl;


	}
	 bool GameBoard:: getpause()
	 {
		 return pause;
	 }
	    void GameBoard:: setpause(bool a)
	    {
	    	pause=a;
	    }


	void GameBoard::DrawHint() {
		float size = 100;
		float height = 50;

		float heightOnEnds = (800 - (this->getsize()[1])) / 2;
		float rec1x, rec1y;
		rec1x = 50;
		rec1y = heightOnEnds + (getsize()[1]) / 2;
		DrawRoundRect(rec1x-5, rec1y-5, size+30, height, colors[DARK_VIOLET], 7.0);
		DrawRoundRect(rec1x, rec1y, size+30, height, colors[MAGENTA], 7.0);
		string n = "H.HINT";

		DrawString(rec1x + 25, rec1y + 15, n, colors[WHITE]);
	}
	void GameBoard::DrawPlayMethod() {
		float size = 100;
		float height = 50;

		float heightOnEnds = (800 - (this->getsize()[1])) / 2;
		float rec1x, rec1y;
		rec1x = 50;
		rec1y = 2 * heightOnEnds;
		DrawRoundRect(rec1x-5, rec1y-5, size+30, height, colors[DARK_VIOLET], 7.0);
		DrawRoundRect(rec1x, rec1y, size+30, height, colors[MAGENTA], 7.0);
		string n = "W.HELP";
		DrawString(rec1x + 25, rec1y + 15, n, colors[WHITE]);
	}
	/*The following fiunction is to set the type and the coordinates of the gem initially*/
	void GameBoard::setGemAttributes()
	{
    srand(time(0));



/* the following is the algorithm to save the coordinates of the gems in the gem array */
 int startx = (1000-this->getsize()[0])/2+( this->GemArray[0][0].getSize())/2;


 int starty=700-50;//-this->getsize()[1])/2+ this->getsize()[1]-(this->GemArray[0][0].getSize())/2;


 for(int i=0 ; i<this->getrows(); i++)
  {
	 startx = (1000-this->getsize()[0])/2+( this->GemArray[0][0].getSize())/2;

  	for(int j=0 ; j<getcols() ; j++)
  	{
  		GemArray[i][j].sety(starty);
  		GemArray[i][j].setx(startx);

  		startx+=60;
  	}
  	starty-=60;
  }
 int ty;
 int g1=0,g2=0;

 int adjacent[2][4];
 for(int i=0 ; i<2 ; i++)
 {
	 for(int j=0 ; j<4 ; j++)
	 {
		 adjacent[i][j]=-1;
	 }
 }

 for(int i=0 ; i<getcols(); i++)
 {
	 int temp1=-10,temp2=-10;
	 this->getGemArray()[0][i].setType(rand()%5+1);
	 ty=this->getGemArray()[0][i].getType();
	 if(i!=0)
	 {
		 temp1=this->getGemArray()[0][i-1].getType();
	 }
	 if(i>1)
	 {
		 temp2=this->getGemArray()[0][i-1-1].getType();
	 }

	 while(ty==temp2 && ty==temp1)
	 {
		 this->getGemArray()[0][i].setType(rand()%5+1);
		 ty=this->getGemArray()[0][i].getType();
	 }
 }
 for(int i=1 ; i<getrows(); i++)
 {
	 for(int j=0 ; j<getcols(); j++)
	 {

		 this->getGemArray()[i][j].setType(rand()%5+1); //randomly generates a type for the gem
		 ty=this->getGemArray()[i][j].getType();
		 if(i!=getrows()-1)//Downwards
		 {
			 g1=this->getGemArray()[i+1][j].getType();//gets the type of the gem below it
			 if(i!=getrows()-1-1)//check to avoi dgoing out of memory when moving downwards
				 g2=this->getGemArray()[i+1+1][j].getType();
			 if(g1==g2 )//over here we checked if below us there are three gems of the same type in a row, if not it is chamged
			 {

				 adjacent[0][0]=g1;
			 }
			 else
			 {
				 adjacent[1][0]=g1;
			 }
		 }
		 if(j!=getcols()-1)//rightwards
		 {
			 g1=0;
			 g2=0;
			 g1=this->getGemArray()[i][j+1].getType();//gets the type of the gem below it
			 if(j!=getcols()-1-1)//check to avoi dgoing out of memory when moving downwards
				 g2=this->getGemArray()[i][j+1+1].getType();
			 if(g1==g2 )//over here we checked if below us there are three gems of the same type in a row, if not it is chamged
			 {

				 adjacent[0][1]=g1;
			 }
			 else
			 {
				 adjacent[1][1]=g1;
			 }
		 }
		 if(i!=0)//upwards
		 {
			 g1=0;
			 g2=0;
			 g1=this->getGemArray()[i-1][j].getType();//gets the type of the gem below it
			 if(i!=1)//check to avoi dgoing out of memory when moving downwards
				 g2=this->getGemArray()[i-1-1][j].getType();
			 if(g1==g2 )//over here we checked if below us there are three gems of the same type in a row, if not it is chamged
			 {
				 adjacent[0][2]=g1;
			 }
			 else
			 {
				 adjacent[1][2]=g1;//saving the coordinate next to it to check at the end
			 }

		 }

		 if(j!=0)//leftwards
		 {
			 g1=0;
			 g2=0;
			 g1=this->getGemArray()[i][j-1].getType();//gets the type of the gem below it
			 if(j!=1)//check to avoi dgoing out of memory when moving downwards
				 g2=this->getGemArray()[i][j-1-1].getType();
			 if(g1==g2 )//over here we checked if below us there are three gems of the same type in a row, if not it is chamged
			 {

				 adjacent[0][3]=g1;
			 }
			 else
			 {
				 adjacent[1][3]=g1;
			 }
		 }
		 int pp=-1,xx=-1;
		 if(adjacent[1][0]==adjacent[1][2] && adjacent[1][0]!=-1 && adjacent[1][2]!=-1)
			 pp=adjacent[1][0];
		 if(adjacent[1][1]==adjacent[1][3] && adjacent[1][3]!=-1 && adjacent[1][1]!=-1  )
			 xx=adjacent[1][1];
		 while(ty==adjacent[0][0] || ty==adjacent[0][1] || ty==adjacent[0][2] || ty==adjacent[0][3]|| ty==pp|| ty==xx)
		 {
			 ty=rand()%5+1;

		 }
		 this->getGemArray()[i][j].setType(ty);


	 }
 }
 for(int i=0 ; i<this->getrows(); i++)
    {
    	for(int j=0 ; j<this->getcols();j++)
    	{
    		cout<<GemArray[i][j].getType();


    	}
    	cout<<endl;

    }

	}
	int GameBoard::getInitialDisplayCheck()
	{
		return InitialDisplayCheck;
	}
	void GameBoard::setInitialDisplayCheck(bool check)
		{
			 InitialDisplayCheck=check;;
		}
	GameBoard::~GameBoard()
	{
			for(int i= 0 ; i<this->getcols() ; i++ )
				delete[] GemArray[i];
			delete[] GemArray;
			for(int i= 0 ; i<this->getcols() ; i++ )
							delete[] Matchcoor[i];
						delete[] Matchcoor;
		}
	Gem ** GameBoard::getGemArray()
	{
		return GemArray;
	}
	Gem ** GameBoard::getMatchcoor()
	{
		return Matchcoor;
	}
