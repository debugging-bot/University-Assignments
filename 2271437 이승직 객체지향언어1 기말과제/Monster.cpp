#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "define.h"
#include "GameObject.h"
#include "Monster.h"



Monster::Monster(int x, int y, int distance)
 : GameObject(x, y, distance) {
	 srand((unsigned)time(0));
}
void Monster::move() {//이동 주기와 방향, 맵 밖으로 나가는거 방지
	int n = rand() % 2;

	if (n == 0) x = x + distance;
	else x = x - distance;

	if (x < 0) x = 0;
	if (x >= MAX_X) x = MAX_X - 1;

	n = rand() % 2;
	if (n == 0) y = y + distance;
	else y = y - distance;

	if (y < 0) y = 0;
	if (y >= MAX_Y) x = MAX_Y - 1;
}
