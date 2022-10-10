/*
 * Coordinates.cpp
 *
 *  Created on: Jun 2, 2020
 *      Author: sillpill
 */

#include "Coordinates.h"

Coordinates::Coordinates() {
	xcoor = 0;
	ycoor = 0;
}
Coordinates::Coordinates(int x, int y) {
	xcoor = x;
	ycoor = y;
}
void Coordinates::setx(int x) {
	xcoor = x;
}
void Coordinates::sety(int y) {
	ycoor = y;
}
int Coordinates::getx() {
	return xcoor;
}
int Coordinates::gety() {
	return ycoor;
}
