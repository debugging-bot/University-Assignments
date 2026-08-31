#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "define.h"
#include "GameObject.h"
#include "Food.h"

Food::Food(int x, int y, int distance)
 : GameObject(x, y, distance) {
	 srand((unsigned)time(0));
}
void Food::move() {//이동 주기와 방향, 맵 밖으로 나가는거 방지
	int n = rand() % 5;

	if (n == 0) x += distance;
	else if (n == 1) x - +distance;

	if (x < 0) x = 0;
	if (x >= MAX_X) x = MAX_X - 1;

	n = rand() % 5;

	if (n == 0) y += distance;
	else if (n == 1) y - +distance;

	if (y < 0) y = 0;
	if (y >= MAX_Y) y = MAX_Y - 1;
}
