/*
 * Player.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: sillpill
 */


#include"Gem.h"
#include "Player.h"
int Player::lives=3;
int Player:: Level=1;
bool Player:: mouseCheck=false;
bool Player:: HintCheck=false;
bool Player:: swapper=true;
bool Player:: mouseCheck2=true;
int Player:: GemSwapCheck=0;
bool Player:: fallingGemsCheck=true;
 bool Player:: matched=false;
 int Player:: CurrentMoves=0;
 int Player::CurrentScore=0;
 void Player:: setName(string a)
 {
	 PlayerName=a;
 }
 int Player:: getlives()
 {
	 return lives;
 }
void Player:: setfallingGemsCheck(bool a)
{
	fallingGemsCheck=a;
}
bool Player::getfallingGemsCheck()
{
	return fallingGemsCheck;
}
void Player:: setCurrentScore(int a)
{
CurrentScore=a;
}
int Player:: getCurrentScore()
{
	return CurrentScore;
}
void Player:: setCurrentMoves(int a)
{
CurrentMoves=a;
}
int Player:: getCurrentMoves()
{
	return CurrentMoves;
}
void Player:: setmousecoor1(int x1, int y1)
{
	mousecoor[0]=x1;
	mousecoor[1]=y1;

}
bool  Player:: getmouseCheck()
{
	return mouseCheck;
}
void Player::setmouseCheck(bool a)
{
	mouseCheck=a;

}
bool  Player:: getmouseCheck2()
{
	return mouseCheck2;
}
void Player::setmouseCheck2(bool a)
{
	mouseCheck2=a;

}
void Player:: setswapper(bool a)
{
	swapper=a;
}
bool Player::getswapper()
{
	return swapper;
}

void Player:: setmousecoor2(int x1, int y1)
{

	mousecoor[2]=x1;
	mousecoor[3]=y1;
}
int* Player:: getmousecoor()
{

	return mousecoor;

}

Player::Player()
{
	Level=1;
	PlayerName=" ";
	ModeChoice=false;//this on default , if not chosen then the game will run in Normal mode


}
void Player:: CheckSwap()
{

	int storecoor[2];
	int s=Gem::getSize();
	cout<<"sss: "<<s<<endl;
	Gem A,B;
	int x1,y1,ty;
	int x=this->mousecoor[0];
	int y=this->mousecoor[1];

	int g1,g2;
	int x2=this->mousecoor[2];
	int y2=this->mousecoor[3];
	//cout<<"swapx2: "<<x2<<" swapy2: "<<y2<<endl;
	for(int i=0 ; i<this->getrows(); i++)
	{
		for(int j=0 ; j<getcols(); j++)
		{
			x1=this->getGemArray()[i][j].getx();//saving the current x and y coordinates of the GemArray
			y1=this->getGemArray()[i][j].gety();


			if(x< x1+s/2 && x> x1-s/2 && y> y1-s/2 && y< y1+s/2)//if condition for checking out that which block or gem the mouse is pointing towards
			{


				this->SwapGem[0].setx(x1);
				this->SwapGem[0].sety(y1);
				this->SwapGem[0].setType(getGemArray()[i][j].getType());
				//getGemArray()[i][j].setType(6);//to show background inorder to swap gems
		;
				if(i!=getrows()-1)
				{
					g1=this->getGemArray()[i+1][j].getx();
					g2=this->getGemArray()[i+1][j].gety();
					ty=this->getGemArray()[i+1][j].getType();

					if(x2<g1+s/2 && x2>g1-s/2 && y2>g2-s/2 && y2<g2+s/2)//checking downwards for second Gem
					{
						this->SwapGem[1].setx(g1);
						this->SwapGem[1].sety(g2);
						this->SwapGem[1].setType(ty);
						storecoor[0]=g1;//to show background inorder to swap gems
						storecoor[1]=g2;
					}
				}

				if(i!=0)
				{
					g1=this->getGemArray()[i-1][j].getx();
					g2=this->getGemArray()[i-1][j].gety();
					ty=this->getGemArray()[i-1][j].getType();


					if(x2<g1+s/2 && x2>g1-s/2 && y2>g2-s/2 && y2<g2+s/2)//upwards
					{
						this->SwapGem[1].setx(g1);
						this->SwapGem[1].sety(g2);
						this->SwapGem[1].setType(ty);
						storecoor[0]=g1;//to show background inorder to swap gems
						storecoor[1]=g2;//to show background inorder to swap gems
					}
				}

				if(j!=getcols()-1)
				{
					g1=this->getGemArray()[i][j+1].getx();//checking rightwards
					g2=this->getGemArray()[i][j+1].gety();
					ty=this->getGemArray()[i][j+1].getType();

					if(x2<g1+s/2 && x2>g1-s/2 && y2>g2-s/2 && y2<g2+s/2)
					{
						this->SwapGem[1].setx(g1);
						this->SwapGem[1].sety(g2);
						this->SwapGem[1].setType(ty);
						storecoor[0]=g1;//to show background inorder to swap gems
						storecoor[1]=g2;
					}
				}

				if(j!=0)
				{
					g1=this->getGemArray()[i][j-1].getx();//checking leftwards
					g2=this->getGemArray()[i][j-1].gety();
					ty=this->getGemArray()[i][j-1].getType();

					if(x2<g1+s/2 && x2>g1-s/2 && y2>g2-s/2 && y2<g2+s/2)
					{
						this->SwapGem[1].setx(g1);
						this->SwapGem[1].sety(g2);
						this->SwapGem[1].setType(ty);
						storecoor[0]=g1;//to show background inorder to swap gems
						storecoor[1]=g2;
					}
				}


				j=getcols();
				i=getrows();

			}
		}


	}


	//DrawGameBoard();


}
void Player::Showlives()
{
	 DrawRectangle(5, 600-5, 100, 80, colors[DARK_VIOLET]);
	 DrawRectangle(10, 600, 100, 80, colors[MAGENTA]);

	DrawString(10, 600+30,"LIVES: ",colors[WHITE]);
		      string b= Num2Str(lives);
		      DrawString(10+60+40-15, 600+30,b,colors[WHITE]);
}
void Player:: ShowCurrentMoves()
{
	DrawRectangle(10-5, 600-90-5, 100+50, 80, colors[DARK_VIOLET]);
	DrawRectangle(10, 600-90, 100+50, 80, colors[MAGENTA]);
	DrawString(10, 600+30-90,"Your Moves: ",colors[WHITE]);
    string b= Num2Str(CurrentMoves);
    DrawString(10+60+40+30, 600+30-90,b,colors[WHITE]);
}
void Player:: UpdateScore(int GemMatched)
{
	if(GemMatched>=3)
	{
  if(GemMatched==3)
  {
		 CurrentScore=CurrentScore+getScoreValue()[0];
  }
  else
	  if(GemMatched==4)
	  {
		  CurrentScore= CurrentScore+getScoreValue()[1];
	  }
  if(GemMatched==5)
  {
	  CurrentScore=CurrentScore+getScoreValue()[2];
  }
  if(GemMatched==8)
  {
	  cout<<"cascades: "<<getCascadesScore()<<endl;
	  CurrentScore=CurrentScore+ getCascadesScore();
  }
  if(getprogress()>500)
  setprogress(600);
  else
   setprogress(getprogress()+getSquareSize());
	}

  DrawString(830, 600,"TARGET: ",colors[BLACK]);
  string s=Num2Str(getTargetScore());
  DrawString(950, 600,s,colors[BLACK]);

  DrawString(830, 600+50,"SCORE: ",colors[BLACK]);
  string p=Num2Str(CurrentScore);
  DrawString(950, 600+50,p,colors[BLACK]);




}
void Player:: DrawLevel()
{
	 DrawRectangle(850-5, 150-5, 140, 80, colors[DARK_VIOLET]);
	 DrawRectangle(850, 150, 140, 80, colors[MAGENTA]);
	      DrawString(850+10, 150+30,"LEVEL: ",colors[WHITE]);
	      string b= Num2Str(getLevel());
	      DrawString(850+10+80, 150+30,b,colors[WHITE]);
}
void Player:: CheckLevel()
{
	 if(lives==0)
		 {
			 DrawRectangle(530, 350-20, 140, 60, colors[DARK_VIOLET]);
			 DrawString(550,350,"YOU LOST",colors[BLACK]);
			 setCurrentScore(0);
		     setCurrentMoves(0);
		     setprogress(0);
		     setLevel(1);
		     setTargetScore(300);
		     setmoves(4);
	          lives=3;
			/* Menu::setMenuCheck(false);
	         Menu::setwindow(0);
	     	glutPostRedisplay();
	     	*/
		 }
 if(CurrentMoves==getmoves() &&  CurrentScore<getTargetScore())//incase level is faled
 {
	/* if(lives==0)
	 {
		 DrawRectangle(530, 350-20, 140, 60, colors[DARK_VIOLET]);
		 DrawString(550,350,"YOU LOST",colors[BLACK]);
		 setCurrentScore(0);
	     setCurrentMoves(0);
	     setprogress(0);
	     setLevel(1);
	     setTargetScore(300);
	     setmoves(0);
          lives=3;

	 }
 */
	 lives-=1;

	 setCurrentScore(0);
     setCurrentMoves(0);
     setprogress(0);
	// this->setGemAttributes();
 }
 else if(CurrentMoves<=getmoves() && CurrentScore>=getTargetScore())//incase level is completed in lesser moves
 {
	 Level+=1;
	 setmoves(getmoves()+2);
	 cout<<getmoves()<<endl;
	 int newtarget=(getTargetScore()+300);
	 cout<<"target "<<newtarget<<endl;
	 setTargetScore(newtarget);
	 setCurrentMoves(0);
	 int sq=getTargetScore()/(getmoves());
	 cout<<"sqsize "<<sq<<endl;
	 setCurrentScore(0);
	 setSquareSize(sq);
     setprogress(0);

 }

}
void Player::DrawCurrentScore()
{
	 DrawString(850, 660,"SCORE: ",colors[BLACK]);
	  string p=Num2Str(getCurrentScore());
	  DrawString(950, 660,p,colors[BLACK]);
}
int Player::getLevel()
{
	return Level;
}
	void  Player::setLevel(int b)
	{
		Level=b;
	}

void Player:: Swap( Gem & SwapGem1 , Gem & SwapGem2)
{
	bool check1=false;
	bool check2=false;

	//setCurrentMoves(getCurrentMoves()+1);//with each swap there is increase in current moves
	for(int i=0 ;i<getrows() ;i++)

	{
		for(int j=0 ; j<getcols();j++)
		{

			if( SwapGem1 .getx()!=0 &&  SwapGem1 .gety()!=0 &&   SwapGem2.getx()!=0 &&  SwapGem2 .gety()!=0)
			{  if(this->getGemArray()[i][j].getx()== SwapGem1.getx() && getGemArray()[i][j].gety()==  SwapGem1 .gety())
			{
				if(check1==false)
				{
					this->getGemArray()[i][j].setType( SwapGem2 .getType());
					check1=true;
				}
			}
			else
				if(this->getGemArray()[i][j].getx()== SwapGem2 .getx() && getGemArray()[i][j].gety()==  SwapGem2 .gety())
				{
					if(check2==false)
					{
						this->getGemArray()[i][j].setType( SwapGem1 .getType());
						check2=true;
					}
				}
			}


		}

	}

}
void Player::isMatching()
{
	int count=0;
	int ty;
	int g1=0,g2=0;
	for(int i=0 ; i<getrows(); i++)
	{
		for(int j=0 ; j<getcols(); j++)
		{


			ty=this->getGemArray()[i][j].getType();

			int check=1;
			count=0;
			for(int k=0 ; k<4 ; k++)
			{
				if(i<getrows()-check)
				{
					g1=this->getGemArray()[i+check][j].getType();
					//cout<<"g1: "<<g1<<" ";
					if(g1==ty)
					{
						count++;
					}
					else
						k=5;
				}
				check++;
				//	 cout<<endl;
			}

			//cout<<"count: "<<count<<endl;
			if(count>1)
			{
				for(int s=0 ;  s<count+1 ; s++)
			{
				this->getGemArray()[i+s][j].setType(-8);
			}
			}
			count=0;
			check=1;
			for(int k=0 ; k<4 ; k++)
			{
				if(j < getcols()-check)
				{
					g1=this->getGemArray()[i][j+check].getType();
					//cout<<"g1: "<<g1<<" ";
					if(g1==ty)
					{
						count++;
					}
					else
						k=5;
				}
				check++;
				//	 cout<<endl;
			}

			if(count>1)
			{
				for(int s=0 ;  s<count+1 ; s++)
				{
					this->getGemArray()[i][j+s].setType(-8);
				}
			}
		}

	}
	count=0;
	for(int i=0 ; i<getrows() ; i++)
	{
		for(int j=0 ; j<getcols()  ; j++)
		{
			if(getGemArray()[i][j].getType()==-8)
				count++;
		}
	}
	//cout<<"count: "<<count<<endl;
if(count>=2)
{

	if(ModeChoice==false)
	{

			UpdateScore(count+1);
		NormalMode::DrawProgressBar();//sends te number of Gems that have matched

	}
	else
	{

	  UpdateScore(count+1);
		TimeMode::DrawProgressBar(getprogress());

	}
}



	DrawGameBoard();
	/* using namespace std::this_thread;     // sleep_for, sleep_until
     using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
     using std::chrono::system_clock;

    // sleep_for(5ns);
     sleep_until(system_clock::now() + 1s);
	 */
	int match;
	bool toprowcheck=false;
	bool nomatch=true;
	while(toprowcheck==false)
	{
		for(int i=0 ; i<getrows(); i++)
		{
			for(int j=0 ; j<getcols() ; j++)
			{
				match=getGemArray()[i][j].getType();
				if(match==-8)
				{
					nomatch=false;
					if(i!=0)
					{
						int temp ;
						temp=getGemArray()[i-1][j].getType();//stroring a gem above it
						getGemArray()[i][j].setType(temp);//setting this new gem as 3
						getGemArray()[i-1][j].setType(-8);//setting the above one as -8;

					}
				}

			}
		}
		int count=0;
		for(int k=0 ; k<getcols() ; k++ )
		{
			if(getGemArray()[0][k].getType()==-8)
			{
				count++;
			}
		}
		if(count>0 || nomatch==true)
		{
			toprowcheck=true;
		}
	}
	//for checking cascades
	int count2=0;
	for(int i=0 ; i<getrows() ; i++)
		{
			for(int j=0 ; j<getcols()  ; j++)
			{
				if(getGemArray()[i][j].getType()==-8)
				count2++;
			}
		}
	if(count2>count)
	{

		if(ModeChoice==false)
		{

				UpdateScore(8);
			NormalMode::DrawProgressBar();//sends te number of Gems that have matched

		}
	}
	DrawGameBoard();
	/*
if(nomatch==false)
{
using namespace std::this_thread;     // sleep_for, sleep_until
   using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
   using std::chrono::system_clock;

  // sleep_for(5ns);
   sleep_until(system_clock::now() + 1s);
}
	 */
	//allgorithm for swapping back of gem incase nothing matched

	if(nomatch==true)
	{

		bool check1=false;
		bool check2=false;

		for(int i=0 ;i<getrows() ;i++)

		{
			for(int j=0 ; j<getcols();j++)
			{

				if(SwapGem[0].getx()!=0 && SwapGem[0].gety()!=0 &&  SwapGem[1].getx()!=0 &&SwapGem[1].gety()!=0)
				{  if(this->getGemArray()[i][j].getx()==SwapGem[0].getx() && getGemArray()[i][j].gety()== SwapGem[0].gety())
				{
					if(check1==false)
					{
						this->getGemArray()[i][j].setType(SwapGem[0].getType());
						check1=true;
					}
				}
				else
					if(this->getGemArray()[i][j].getx()==SwapGem[1].getx() && getGemArray()[i][j].gety()== SwapGem[1].gety())
					{
						if(check2==false)
						{
							this->getGemArray()[i][j].setType(SwapGem[1].getType());
							check2=true;
						}
					}
				}


			}

		}
	}

}
void Player::figureMatchcoor()
{

	int g1,g2,ty;

	g1=0;
	g2=0;
	int MissingGems=0;
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
		if(getMatchcoor()[0][i].getType()==0)
		{
			ty=this->getGemArray()[0][i].getType();
			if(ty==-8)
			{
				MissingGems++;
				this->getMatchcoor()[0][i].setType(rand()%5+1);
				ty=getMatchcoor()[0][i].getType();


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
					this->getMatchcoor()[0][i].setType(rand()%5+1);
					ty=this->getMatchcoor()[0][i].getType();
				}

				this->getMatchcoor()[0][i].setx(this->getGemArray()[0][i].getx());
				this->getMatchcoor()[0][i].sety(690);
			}
		}
	}



	for(int i=1 ; i<getrows(); i++)
	{
		for(int j=0 ; j<getcols(); j++)
		{
			if(getMatchcoor()[i][j].getType()==0)
			{
				ty=this->getGemArray()[i][j].getType();

				if(ty==-8)
				{
					MissingGems++;

					this->getMatchcoor()[i][j].setType(rand()%5+1); //randomly generates a type for the gem
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
					this->getMatchcoor()[i][j].setType(ty);
					this->getMatchcoor()[i][j].setx(this->getGemArray()[i][j].getx());
					this->getMatchcoor()[i][j].sety(690);
				}
			}
		}
	}
;
}
void Player:: RefillGems()
{
	/* the following is an algorithm which detects -8 which is the type of gem which has been disappeared that
	 * is "poof". it detects and generates a type of gem to fit in that place in a way that , there is no chain of gems
	 * of more than three. this new gem generated to be placed in that position is temporarily placed in a dummy array called
	 * matchcoor , inorder that they may be filled by falling from the top
	 */


	/* The following Algorithm is for , making the gems fall from top by keeping the coordinates of the matched gems
	 * in the Matchcoor as 0 and then they would continuously drop downwards till they reach the coordinates
	 * of the missing gem in GemArray that they were supposed to reach
	 */
	int MissingGems=0;
	for(int i=0 ; i<getrows() ; i++)
	{
		for(int j=0 ; j<getcols() ; j++)
		{
			if(getGemArray()[i][j].getType()==-8)
			{
				MissingGems++;
			}
		}
	}
	static bool checksteps=false;
	int ty=0;
	int steps;
	static int b=700;
	steps=10;
	b=b-steps;

	static int GemsFixed=0;
	for(int i=0 ; i<getrows() ; i++)
	{
		for(int j=0 ; j<getcols() ; j++)
		{
			ty=this->getMatchcoor()[i][j].getType();

			if(ty!=0)
			{
				if(this->getMatchcoor()[i][j].getType()==1)
				{
					Gem1::DrawGem(this->getMatchcoor()[i][j].getx(),this->getMatchcoor()[i][j].gety());
				}
				if(this->getMatchcoor()[i][j].getType()==2)
				{
					Gem2::DrawGem(this->getMatchcoor()[i][j].getx(),this->getMatchcoor()[i][j].gety());
				}
				if(this->getMatchcoor()[i][j].getType()==3)
				{
					Gem3::DrawGem(this->getMatchcoor()[i][j].getx(),this->getMatchcoor()[i][j].gety());
				}
				if(this->getMatchcoor()[i][j].getType()==4)
				{
					Gem4::DrawGem(this->getMatchcoor()[i][j].getx(),this->getMatchcoor()[i][j].gety());
				}
				if(this->getMatchcoor()[i][j].getType()==5)
				{
					Gem5::DrawGem(this->getMatchcoor()[i][j].getx(),this->getMatchcoor()[i][j].gety());
				}


				//cout<<"initial y: "<<getMatchcoor()[i][j].gety()<<endl;
				this->getMatchcoor()[i][j].sety(getMatchcoor()[i][j].gety()-steps );
				//cout<<" coordinates : "<<getMatchcoor()[i][j].gety()<<endl;

				if(this->getMatchcoor()[i][j].gety()==this->getGemArray()[i][j].gety())
				{

					this->getGemArray()[i][j].setType(this->getMatchcoor()[i][j].getType());
					this->getMatchcoor()[i][j].setType(0);
					this->getMatchcoor()[i][j].sety(0);
					this->getMatchcoor()[i][j].sety(0);

					GemsFixed++;

				}



			}


		}
	}
	checksteps=true;

	int count=0;

	for(int i=0 ; i<getrows(); i++)
	{
		for(int j=0 ; j<getcols() ; j++)
		{
			if(getMatchcoor()[i][j].getType()==0)
			{
				count++;
			}

		}
	}
	if(count==(10*10))
	{
		setfallingGemsCheck(true);
	}

}


bool Player::checkforhint(int cx,int cy,int type, int d)
{

	int g1,g2;
	for(int i=0 ; i<getrows(); i++)
	{
		for(int j=0 ; j<getcols(); j++)
		{
			if(cx==this->getGemArray()[i][j].getx() && cy==this->getGemArray()[i][j].gety())
			{


				if(d==0|| d==1)//that is direction is upwards or downwards
				{
					if(j<getcols()-2)//checking rightwards to see if gem matcches
					{
						g1=this->getGemArray()[i][j+1].getType();

					}
					if(j>0)
					{
						g2=this->getGemArray()[i][j-1].getType();
					}
					if(g1==type)//highlight the gem thathas matched to be swapped
					{
						Gem7::DrawGem(cx,cy);
						Gem7::DrawGem(getGemArray()[i][j+1].getx(),getGemArray()[i][j+1].gety());
						return true;
					}
					else if(g2==type)
					{
						Gem7::DrawGem(cx,cy);
						Gem7::DrawGem(getGemArray()[i][j-1].getx(),getGemArray()[i][j-1].gety());
						return true;
					}

				}


			}
		}
	}
	return false;
}

void Player::GiveHint()
{


	int ty;
	int g1=0,g2=0;
	bool check;
	Gem array [4][2];
	for(int i=0 ; i<getrows(); i++)
	{
		for(int j=0 ; j<getcols(); j++)
		{
			ty=this->getGemArray()[i][j].getType();
			if(i<getrows()-2)//UPWARDS
			{
				g1=this->getGemArray()[i+1][j].getType();
				if(i<getrows()-3)
				{
					g2=this->getGemArray()[i+1+1][j].getType();
				}
				if(ty==g1 && g2!=ty)
				{


					check=checkforhint(this->getGemArray()[i+1+1][j].getx(),this->getGemArray()[i+1+1][j].gety(),ty,0);
					if(check)
					{

						i=getrows();
						j=getcols();
					}
				}
				else  if(ty==g2 && g1!=ty)
				{

					check=checkforhint(this->getGemArray()[i+1][j].getx(),this->getGemArray()[i+1][j].gety(),ty,0);
					if(check)
					{

						i=getrows();
						j=getcols();
					}
				}

			}
		}
	}

}


bool Player::getModeChoice()
{
	return ModeChoice;
}
void Player::setModeChoice(bool val)
{
ModeChoice=val;
}


Gem* Player::getSwapGem()
{
	return SwapGem;
}



bool Player:: getHintCheck()
{
	return HintCheck;
}
void Player::setHintCheck(bool a)
{
	HintCheck=a;
}

