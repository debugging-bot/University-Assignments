#ifndef BOMB_H
#define BOMB_H

#include <string>
using namespace std;

#include "GameObject.h"

class Bomb : public GameObject {//상속관계
public:
	Bomb(int x, int y, int distance = 1);//시작 위치와 이동거리
	virtual ~Bomb() { }//소멸
	virtual void move();//움직이는 주기와 렘덤방향
	virtual char getShape() { return 'B'; } //실행 화면에 보이게 될 Bomb
};

#endif