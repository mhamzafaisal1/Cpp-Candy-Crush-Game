/*
 * Gem.h
 *
 *  Created on: Jun 2, 2020
 *      Author: sillpill
 */

#ifndef GEM_H_
#define GEM_H_
#include"AllGems.h"
#include"Coordinates.h"
class Gem :public Coordinates, public Gem1,public Gem2,public Gem3,public Gem4,public Gem5,public Gem6
{
	int Type;
	static int GemSize;
	static bool SwapOpenCheck;
public:
	Gem();
	void setType(int);
	int getType();
	static int getSize();
	void setGem(int,int,int);
	static void  RotateGem(Gem & obj);
    static void GemSwap (Gem A ,Gem B ,int Direction);
    static void FallFromTop(Gem & obj);
    static void CheckTypes(Gem,Gem,int&);
	static bool getSwapOpenCheck();
	static void setSwapOpenCheck(bool ch);
   static  void DrawGem(int,int);
    ~Gem(){};
};

#endif /* GEM_H_ */
