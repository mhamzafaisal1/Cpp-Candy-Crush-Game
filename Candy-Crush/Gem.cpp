/*
 * Gem.cpp
 *
 *  Created on: Jun 2, 2020
 *      Author: sillpill
 */

#include "Gem.h"
 bool Gem:: SwapOpenCheck=false;;
int Gem:: GemSize=60;
	Gem::Gem()
	{
      Type=0;


	}
	bool Gem:: getSwapOpenCheck()
		{
			return SwapOpenCheck;
		}
	void Gem::setSwapOpenCheck(bool ch)
		{
			SwapOpenCheck=ch;

		}
	void Gem:: setType(int x)
	{
		Type=x;

	}
	int Gem::getType()
	{
		return Type;
	}
	void Gem:: DrawGem(int x,int y)
	{
		int size=getSize();
	DrawRectangle(x - size / 2, y - size / 2, size, size, colors[YELLOW]);
	}
	void Gem::setGem(int x,int y,int ty)
	{
		this->setx(x);
		this->sety(y);
		Type=ty;
	}
	 void Gem:: RotateGem(Gem & obj)// a gem can be passed and using the type , it will be rotated
	{

	}
	 int Gem:: getSize()
	 {
		 return GemSize;
	 }
   void Gem::GemSwap (Gem A ,Gem B ,int direction)//swaps the Gems when the mouse moves the key as such
    {
	   /* Direction=1 , upwards swap
	    * direction=2 Downwards Swap
	    * direction=3 rightwards swap
	    * direction=4 leftwards Swap
	    */
      //  Gem obj1=&A;
	   Gem obj;
	   obj.setx(A.getx());
	   obj.sety(A.gety());
	   obj.setType(A.getType());
	   Gem obj2;
	   	   obj2.setx(B.getx());
	   	   obj2.sety(B.gety());
	   	   obj2.setType(B.getType());
	   	   cout<<"suudasd\n";
	   	   for(int i=0 ; i<2 ; i++)
	   	   {
	   if(obj.getType()==1)
	   	       	     {
	   	       	          obj.Gem1::DrawGem(obj2.getx(), obj2.gety());

	   	       	     }
	   	       	     else if(obj.getType()==2)
	   	       	     {
	   	       	    	 obj.Gem2::DrawGem( obj2.getx(), obj2.gety());
	   	       	     }
	   	       	     else if(obj.getType()==3)
	   	       	     {
	   	       	    	 obj.Gem3::DrawGem( obj2.getx(), obj2.gety());
	   	       	     }
	   	       	     else if(obj.getType()==4)
	   	       	     {
	   	       	    	 obj.Gem4::DrawGem( obj2.getx(), obj2.gety());
	   	       	     }
	   	       	     else if(obj.getType()==5)
	   	       	     {
	   	       	    	 obj.Gem5::DrawGem( obj2.getx(), obj2.gety());
	   	       	     }
	   obj.setx(B.getx());
	   obj.sety(B.gety());
	   obj.setType(B.getType());

	   	   obj2.setx(A.getx());
	   	   obj2.sety(A.gety());
	   	   obj2.setType(A.getType());

	   	   }


    }
    void Gem:: CheckTypes(Gem obj,Gem B, int & direction)
    {
    	static bool check=true;
    	int steps=10;
    	static int movex1;

    	    	static int movey1;
    	    	static int movex2;
    	    	static int movey2;
    	if(check==true)
    	{
    	 movex1=obj.getx();
    	 movey1=obj.gety();
    	 movex2=B.getx();
    	 movey2=B.gety();
    	check=false;
    	}

    		if(obj.getType()==1)
    	     {
    	          obj.Gem1::DrawGem(movex1,movey1);
    	     }
    	     else if(obj.getType()==2)
    	     {
    	    	 obj.Gem2::DrawGem(movex1,movey1);
    	     }
    	     else if(obj.getType()==3)
    	     {
    	    	 obj.Gem3::DrawGem(movex1,movey1);
    	     }
    	     else if(obj.getType()==4)
    	     {
    	    	 obj.Gem4::DrawGem(movex1,movey1);
    	     }
    	     else if(obj.getType()==5)
    	     {
    	    	 obj.Gem5::DrawGem(movex1,movey1);
    	     }

    	    		if(B.getType()==1)
    	    	     {
    	    	          B.Gem1::DrawGem(movex2,movey2);
    	    	     }
    	    	     else if(B.getType()==2)
    	    	     {
    	    	    	 B.Gem2::DrawGem(movex2,movey2);
    	    	     }
    	    	     else if(B.getType()==3)
    	    	     {
    	    	    	 B.Gem3::DrawGem(movex2,movey2);
    	    	     }
    	    	     else if(B.getType()==4)
    	    	     {
    	    	    	 B.Gem4::DrawGem(movex2,movey2);
    	    	     }
    	    	     else if(B.getType()==5)
    	    	     {
    	    	    	 B.Gem5::DrawGem(movex2,movey2);
    	    	     }
            if(direction==1)
            {
            	movey1+=steps;
            	movey2-=steps;
            }
            else if(direction==2)
            {
            	movey1-=10;
            	movey2+=10;
            }
            else if(direction==3)
                       {
                       	movex1+=10;
                       	movex2-=10;
                       }
            else if(direction==4)
                       {
                       	movex1-=10;
                       	movex2+=10;
                       }

            	if(movey1==obj.gety()&& movex1==obj.getx())
            	{

            		check=true;
            	}

    }

