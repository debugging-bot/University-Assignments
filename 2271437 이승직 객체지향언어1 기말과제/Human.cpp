#include <iostream>
#include <string>
using namespace std;

#include "define.h"
#include "GameObject.h"
#include "Human.h"

Human::Human(int x, int y, int distance)
 : GameObject(x, y, distance) {
	srand((unsigned)time(0));
 }

void Human::move() {//입력값에 따라 이동
	cout << "왼쪽(a), 오른쪽(F), 위(D), 아래(S) >>";
	char c;
	cin >> c;
	
	switch (c) {
	case 'a':
		x--;
		if (x < 0) x = 0;
		break;
	case 'f':
		x++;
		if (x > MAX_X) x = MAX_X-1;
		break;
	case 'd':
		y--;
		if (y < 0) y = 0;
		break;
	case 's':
		y++;
		if (y > MAX_Y) y = MAX_Y - 1;
		break;
	}
}
