#ifndef FOOD_H
#define FOOD_H

#include "GameObject.h"

class Food : public GameObject {//상속관계
public:
	 Food(int x, int y, int distance=1);//시작 위치와 이동거리
	 virtual ~Food() {} //소멸
	 virtual void move(); //움직이는 주기와 렘덤방향
	 virtual char getShape() { return '@'; }//실행 화면에 보이게 될 Foof
};

#endif