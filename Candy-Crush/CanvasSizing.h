/*
 * CanvasSizing.h
 *
 *  Created on: Jun 2, 2020
 *      Author: sillpill
 */

#ifndef CANVASSIZING_H_
#define CANVASSIZING_H_

class CanvasSizing {
int CanvasSize[2];
	int rows;
	int cols;
	static bool Canvascheck;

public:
	void setCanvasSize(int,int,int,int);
	CanvasSizing();
 CanvasSizing (int arr[]);
 CanvasSizing(int,int,int ,int);
 int getrows();
 int getcols();
 int* getsize();
	~CanvasSizing(){}
};

#endif /* CANVASSIZING_H_ */
