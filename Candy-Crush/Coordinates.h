/*
 * Coordinates.h
 *
 *  Created on: Jun 2, 2020
 *      Author: sillpill
 */

#ifndef COORDINATES_H_
#define COORDINATES_H_

class Coordinates {
private:
	int xcoor;
	int ycoor;
public:
	Coordinates();
	Coordinates(int,int);
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
    ~Coordinates(){}
};

#endif /* COORDINATES_H_ */
