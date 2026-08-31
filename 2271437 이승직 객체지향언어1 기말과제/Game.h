#ifndef GAME_H
#define GAME_H

#include "define.h"

class GameObject;
class Game {
	char map[MAX_Y][MAX_X];//맵 생성
	GameObject *m[4];//Bomb, Human, Monster, Food 생성
	int state; // 0: 게임 중, 1: Monster가 winner, 2:Human이 winner
public:
	Game();
	~Game();
	void run();
	void update();
	void clear();
	void draw();
	bool doesEnd();
};

#endif