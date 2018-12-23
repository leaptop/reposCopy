#include "constants.h"
#include "classes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <graphics.h>

main(){	
	srand(time(NULL));
	initwindow(750, 750);

					 
	circleCls circleObj( 220 ,150 ,15 );
	circleCls *Circle = &circleObj;
					 
	rectangleCls rectanObj( 200, 110,11);
	rectangleCls *Rectangle = &rectanObj;
					 
	triangleCls trianObj( 220, 49, 4);
	triangleCls *Triangle = &trianObj;
					 
	triangLCls trianLObj( 241, 160, 1);				 		    
	triangLCls *LTriangle = &trianLObj;
	
	trianRCls trianRObj(199, 160,  1);				 		    
	trianRCls *RTriangle = &trianRObj;
	
	shapes **array = new shapes*[ARR_SIZE];
	int count = 0;
	for(int i = 0; i < ARR_SIZE; i++){
		switch(count){
        	case 0:  array[i] = Rectangle; break;
        	case 1:  array[i] = Circle; break;
        	case 2:  array[i] = Triangle; break;
        	case 3:  array[i] = LTriangle; break;
        	case 4:  array[i] = RTriangle; break;
   	    }
   	    count++;
   	    if(count == 5) count = 0;
	}

	while(true){
		cleardevice();
		for(int i = 0; i < ARR_SIZE; i++){
			array[i] -> draw();
			array[i] -> move();
		}
		delay(10);
	} 
	closegraph();
}
