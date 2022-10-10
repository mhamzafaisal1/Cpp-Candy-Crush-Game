/*
 * AllGmes.cpp
 *
 *  Created on: Jun 2, 2020
 *      Author: sillpill
 */

#include "AllGems.h"

	void Gem1::DrawGem(int x, int y) {


		int size= Gem:: getSize();
		static int ghostMouth=2;
		if(ghostMouth==600)
			{
			ghostMouth=2;
			}

		DrawRectangle(x - size / 2, y - size / 2, size, size, colors[ORANGE_RED]);
		DrawCircle(x, y + (size / 4) - 5, size / 4, colors[WHITE]);
		DrawRectangle(x - size / 4, y - (size / 4) + 5, 2 * size / 4, size / 4,
				colors[WHITE]); //height=30 and width=15
		DrawCircle(x - size / 4, y - (size / 4), size / 12, colors[WHITE]); //legs of the ghost , inrementing x =10 to make more legs along x axis
		DrawCircle(x - size / 4 + 10, y - (size / 4), size / 12, colors[WHITE]);
		DrawCircle(x - size / 4 + 20, y - (size / 4), size / 12, colors[WHITE]);
		DrawCircle(x - size / 4 + 30, y - (size / 4), size / 12, colors[WHITE]);

		//eyes
		DrawCircle(x - 5, y + (size / 4), 4.0, colors[BLACK]);
		DrawCircle(x + 5, y + (size / 4), 4.0, colors[BLACK]);
		//smile
		if (ghostMouth%20==0) {
			DrawRoundRect(x - 10, y + (size / 4) - 15, 20, 2, colors[BLACK], 10.0);

		}
		else if(ghostMouth%2 == 0)
		{
			DrawRoundRect(x - 10, y + (size / 4) - 15, 20, 2, colors[WHITE], 10.0);
			DrawRoundRect(x - 10, y + (size / 4) - 15, 20, 2, colors[BLACK], 2.0);

		}
		ghostMouth+=2;


	}
	void Gem2::DrawGem(int x, int y) {
		int size= Gem:: getSize();
		static int ghostMouth=2;
				if(ghostMouth==600)
					{
					ghostMouth=2;
					}
		DrawRectangle(x - size / 2, y - size / 2, size, size, colors[RED]);
		DrawRectangle(x - 15, y, 31, 30 - 3, colors[LIGHT_CYAN]); //rectangle HEAD
		DrawRoundRect(x - size / 2 + 5, y - 30, size - 10, 25, colors[BLACK], 6.0); //BODY
		DrawRoundRect(x - 15, y - 15, 30, 25, colors[LIGHT_CYAN], 9.0); //ROUNDED LOWER FACE
		//EYES
		DrawTriangle(x - 5, y + 5, x - 10, y + 15, x, y + 15, colors[BLACK]);
		DrawTriangle(x + 8, y + 5, x + 8 + 5, y + 15, x + 8 - 4, y + 15,
				colors[BLACK]);

		//TEETH
		if (ghostMouth%20==0) {
			DrawRectangle(x - 10, y - 5, 20, 5, colors[BLACK]);
			DrawTriangle(x - 10 + 2, y - 15, x - 10, y - 5, x - 10 + 4, y - 5,
					colors[BLACK]);
			DrawTriangle(x + 5 + 2, y - 15, x + 5, y - 5, x + 5 + 4, y - 5,
					colors[BLACK]);

		}
		else if(ghostMouth%2 == 0)
		{
			int x1 = x - 2;
			DrawRectangle(x1 - 10, y - 5, 20, 5, colors[BLACK]);
			DrawTriangle(x1 - 10 + 2, y - 15, x1 - 10, y - 5, x1 - 10 + 4, y - 5,
					colors[BLACK]);
			DrawTriangle(x1 + 5 + 2, y - 15, x1 + 5, y - 5, x1 + 5 + 4, y - 5,
					colors[BLACK]);

		}
		ghostMouth+=2;
	}
	void Gem3::DrawGem(int x, int y) {
		int size= Gem:: getSize();
		static int ghostMouth=2;
				if(ghostMouth==600)
					{
					ghostMouth=2;
					}
		DrawRectangle(x - size / 2, y - size / 2, size, size, colors[BEIGE]);
		DrawRectangle(x - 15, y, 31, 30 - 3, colors[GREEN]);	    //rectangle HEAD
		DrawRectangle(x - 15, y + 20, 31, 10 - 3, colors[BLACK]);	          //hair
		DrawCircle(x, y - 4, size / 4, colors[GREEN]);	            //lower FACE
		DrawRectangle(x - 10, y - size / 2 + 3, 20, 15, colors[GREEN]);	      //NECK

		//EYEBAGS
		DrawCircle(x - 8, y + 10 - 2, 5, colors[GRAY]);
		DrawCircle(x + 8, y + 10 - 2, 5, colors[GRAY]);
		//EYES
		DrawCircle(x - 8, y + 10, 5, colors[BLACK]);
		DrawCircle(x + 8, y + 10, 5, colors[BLACK]);
		//MOUTH
		if (ghostMouth%20==0) {
			DrawRectangle(x - 10, y - 10, 20, 8, colors[BLACK]);
			DrawRectangle(x - 10, y - 10, 20, 2, colors[WHITE]);
			DrawRectangle(x - 10, y - 10 + 6, 20, 2, colors[WHITE]);
		} else if(ghostMouth%2 == 0){
			DrawCircle(x, y - 5, 5, colors[BLACK]);

		}
		ghostMouth+=2;

	}
	void Gem4::DrawGem(int x, int y) {
		int size= Gem:: getSize();
		static int ghostMouth=2;
				if(ghostMouth==600)
					{
					ghostMouth=2;
					}
		DrawRectangle(x - size / 2, y - size / 2, size, size, colors[DEEP_PINK]);
		DrawCircle(x, y + size / 6, size / 4, colors[WHITE]);	            //head
		DrawRectangle(x - size / 4, y - size / 6, size / 2, size / 4,
				colors[WHITE]);	            //upper jaw
		DrawRectangle(x - size / 6, y - size / 3, size / 3, size / 3,
				colors[WHITE]);	            //lower jaw

		//teeth
		DrawRectangle(x - size / 4 + 4, y - size / 6, size / 12, size / 12,
				colors[BLACK]);
		DrawRectangle(x - size / 4 + 4 + 2 * 4, y - size / 6, size / 12, size / 12,
				colors[BLACK]);
		DrawRectangle(x - size / 4 + 4 + 4 * 4, y - size / 6, size / 12, size / 12,
				colors[BLACK]);

		DrawRectangle(x - size / 6 + 4, y - size / 3 + 5, size / 12, size / 12,
				colors[BLACK]);
		DrawRectangle(x - size / 6 + 4 + 2 * 4, y - size / 3 + 5, size / 12,
				size / 12, colors[BLACK]);
		//DrawRectangle(x-size/4+5, y-size/6 ,size/12, size/12, colors[BLACK]);
		//EYEs
		if (ghostMouth%30==0) {
			DrawCircle(x - size / 12, y + size / 4 - 4, 4, colors[BLACK]);
			DrawCircle(x + size / 12, y + size / 4 - 4, 4, colors[BLACK]);
		} else if(ghostMouth%2 == 0){
			DrawCircle(x - size / 3, y - size / 3, 4, colors[BLACK]);
			DrawCircle(x + size / 3, y - size / 3, 4, colors[BLACK]);

		}
		ghostMouth+=2;
		//NOSTRILS
		DrawCircle(x - 2, y + 2, 2, colors[BLACK]);
		DrawCircle(x + 2, y + 2, 2, colors[BLACK]);
		//LINE BETWEEN TEETH
		DrawRectangle(x - size / 6, y - 12, size / 3, 4, colors[BLACK]);

	}
	void Gem5::DrawGem(int x, int y) {
		int size= Gem:: getSize();
		static int ghostMouth=2;
				if(ghostMouth==600)
					{
					ghostMouth=2;
					}

		DrawRectangle(x - size / 2, y - size / 2, size, size, colors[INDIGO]);
		DrawTriangle(x, y + size / 6, x - size / 3, y - size / 4, x + size / 3,
				y - size / 4, colors[CORAL]);				//BODY
		DrawCircle(x, y + size / 6, size / 6 - 2, colors[BLACK]);			//FACE
		DrawTriangle(x, y + size / 3 + size / 6, x - size / 6 + 2, y + size / 6,
				x + (size / 6 - 2), y + size / 6, colors[BLACK]);			//HAT
		//LEGS
		DrawRectangle(x - 4, y - size / 3 - 5, 4, size / 6, colors[BLACK]);
		DrawRectangle(x + 3, y - size / 3 - 5, 4, size / 6, colors[BLACK]);

		int x1 = x, y1 = y;
		for (int i = 0; i < 15; i++) {
			DrawRectangle(x1 + size / 6 + 5, y1 - size / 6, 4, 4, colors[BLACK]);
			x1 -= 3;
			y1 += 1;
		}

		if (ghostMouth%20==0) {
			y1 = y + size / 4 - size / 6;
			x1 = x - size / 3;
			for (int i = 0; i < 3; i++) {

				DrawRectangle(x1 -= 5, y1 += 4, 3, 3, colors[GOLD]);
				DrawRectangle(x1 += 5, y1 += 4, 3, 3, colors[GOLD]);
			}
		} else if(ghostMouth%2 == 0){

		}
		ghostMouth+=2;
	}
	void Gem6::DrawGem(int x, int y)
	{
		int size=Gem::getSize();

				float * poof=colors[WHITE];
				DrawRectangle(x - size / 2, y - size / 2, size, size, colors[MIDNIGHT_BLUE]);
				DrawCircle(x, y, 15,poof );
			DrawCircle(x-10, y+10, 8,poof );
			DrawCircle(x-10+4, y+10, 4,poof );
			DrawCircle(x, y+10, 4,poof );
			DrawCircle(x+10, y+10, 8,poof );

			DrawCircle(x-10, y-10, 8,poof );
			DrawCircle(x-10-10, y-10, 5,poof );
			DrawCircle(x-10-10, y-10+8, 8,poof );
			DrawCircle(x, y-10+8-15, 8,poof );
			DrawCircle(x+10+5, y-10+8, 8,poof );
			DrawCircle(x, y+10+8, 8,poof );

			DrawCircle(x+10, y-10, 8,poof );



	}
	void Gem7::DrawGem(int x, int y)
	{
		float * select=colors[GREEN];
									DrawRectangle(x-30, y-30, 10, 60, select);//vertical left rectangle
									DrawRectangle(x+20, y-30, 10, 60, select);//vertical right rectangle
									DrawRectangle(x-30, y-30, 60, 10, select);//lower rectangle
									DrawRectangle(x-30, y+20, 60, 10, select);//upper rectangle
	}
