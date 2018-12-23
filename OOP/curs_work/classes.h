#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <graphics.h>
#include "constants.h"

class shapes
{
public:
	float getXpos() const;
    void setXpos(const float x);
	
	float getYpos() const;
    void setYpos(const float y);	
    
    int getClr() const;
    void setClr(const int color);	
    	
    
    
    virtual void move() = 0;
	virtual void draw() = 0;
    
    shapes(){}
    
protected:
	float x;
	float y;
	int color;
};



class circleCls : public shapes
{
public:
	void move();
	void draw();
	
	circleCls(float x, float y, int color):shapes(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class triangleCls : public shapes
{
public:
	void move();
    void draw();
	
	triangleCls(float x, float y, int color):shapes(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class triangLCls : public shapes
{
public:
	void move();
    void draw();
	
	triangLCls(float x, float y, int color):shapes(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class trianRCls : public shapes
{
public:
	void move();
    void draw();
	
	trianRCls(float x, float y, int color):shapes(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class rectangleCls : public shapes
{
public:
	void move();
	void draw();
	
	rectangleCls(float x, float y, int color):shapes(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};


#endif
