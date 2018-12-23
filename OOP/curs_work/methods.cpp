#include "classes.h"
#include <math.h>
#include "constants.h"
#define N 0.1

float t = 0; 
float r = 0; 
float s = 0; 
float g = 0; 
float k = 0; 


float shapes::getXpos() const{
	return x;
}

void shapes::setXpos(const float x){
	shapes::x = x;
}

float shapes::getYpos() const{
	return y;
}

void shapes::setYpos(const float y){
	shapes::y = y;
}

int shapes::getClr() const{
	return color;
}

void shapes::setClr(const int color){
	shapes::color = color;
}




void circleCls::move(){
	
	x = x + 15 * cos(t);
	y = y + 15 * sin(t);
	t+= N;
	
}

void circleCls::draw(){
	setcolor(getClr());
	circle(getXpos(), 
		   getYpos(), 10);
}


void rectangleCls::move(){
	
	x = x + 15 * cos(r);
	y = y + 15 * sin(r);
	r+= N;
}

void rectangleCls::draw(){
	setcolor(getClr());
	rectangle(getXpos(), getYpos(),
			  getXpos() + RECTAN_SIZE/ 2, 
			  getYpos() + RECTAN_SIZE );
}

void triangleCls::move(){
	
	x = x + 15 * cos(s);
	y = y + 15 * sin(s);
	s+= N;
}

void triangleCls::draw(){
	setcolor(color);
	line(x, y, x + 17, y + 60);
	line(x, y, x - 17, y + 60);
	line(x - 19, y + 60, 
		 x + 19, y + 60);
}

void triangLCls::move(){
	
	x = x + 15 * cos(k);
	y = y + 15 * sin(k);
	k+= N;
}

void triangLCls::draw(){
	setcolor(color);
	line(x, y, x + 17, y + 60);
	line(x, y, x , y + 60);
	line(x - 1, y + 60, 
		 x + 18, y + 60);
}

void trianRCls::move(){
	
	x = x + 15 * cos(g);
	y = y + 15 * sin(g);
	g+= N;
}

void trianRCls::draw(){
	setcolor(color);
	line(x, y, x-17 , y + 60);
	line(x, y, x , y + 60);
	line(x - 18, y + 60, 
		 x + 1, y + 60);
}

