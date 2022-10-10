/*
 * CanvasSizing.cpp
 *
 *  Created on: Jun 2, 2020
 *      Author: sillpill
 */

#include "CanvasSizing.h"
bool CanvasSizing::Canvascheck=false;
	CanvasSizing::CanvasSizing()
	{
		CanvasSize[0]=600;
		CanvasSize[1]=600;
		rows=10;
		cols=10;
      Canvascheck=false;
	}
	CanvasSizing::CanvasSizing (int arr[])
	{
		CanvasSize[0]=arr[0];
		CanvasSize[1]=arr[1];
		rows=0;
		cols=0;

	}
	CanvasSizing::CanvasSizing(int r,int c,int a1,int a2)
	{
		CanvasSize[0]=a1;
				CanvasSize[1]=a2;
				rows=r;
				cols=c;
	}
	void CanvasSizing:: setCanvasSize(int r,int c,int a1,int a2)
	{
		CanvasSize[0]=a1;
						CanvasSize[1]=a2;
						rows=r;
						cols=c;
	}
	int* CanvasSizing:: getsize()
	{
		return CanvasSize;
	}
	 int CanvasSizing::getrows()
	 {
		 return rows;
	 }
	 int CanvasSizing::getcols()
	 {
		 return cols;
	 }
