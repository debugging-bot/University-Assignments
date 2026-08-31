#ifndef HUMAN_H
#define HUMAN_H

#include "GameObject.h"

class Human : public GameObject {//상속관계
	int distance; // 한 번 이동 거리
 public:
	 Human(int x, int y, int distance=1);//시작 위치와 이동거리
	 virtual ~Human() {}//소멸
	 virtual void move();//입력값에 따라 움직이는 방향
	 virtual char getShape() { return 'H'; }//실행 화면에 보이게 될 Human

};

#endif