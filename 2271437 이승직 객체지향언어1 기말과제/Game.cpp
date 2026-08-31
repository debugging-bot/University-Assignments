#include <iostream>
using namespace std;

#include "Game.h"
#include "GameObject.h"
#include "Human.h"
#include "Monster.h"
#include "Food.h"
#include "Bomb.h"
#include "define.h"

Game::Game() {
    for (int i = 0; i < MAX_Y; i++)
        for (int j = 0; j < MAX_X; j++)
            map[i][j] = '-';//맵 생성
    m[0] = new Bomb(15, 6, 2);//Bomb객제 생성
    m[1] = new Monster(5, 5, 2);//Monster객제 생성
    m[2] = new Human(0, 0, 1);//Human객제 생성
    m[3] = new Food(9, 9, 1);//Food객제 생성
    state = 0; // 게임 중
}

Game::~Game() {//객체 소멸
    for (int i = 0; i < 4; i++)
        delete m[i];
}

void Game::run() {
    cout << "** Human의 Food 먹기 게임을 시작합니다.**" << endl;

    update(); // 초기 좌표에 따른 맵 설정
    draw(); // 초기 게임 맵을 보여줌

    while (!doesEnd()) {
        clear(); // 현재의 맵 지움
        for (int i = 0; i < 4; i++)
            m[i]->move();
        update(); // 움직인 후 좌표 변경에 따른 맵 갱신
        draw(); // 맵 그리기
    }
    if (state == 1)
        cout << "Monster is Winner!!" << endl;
    else if (state == 2)
        cout << "Human is Winner!!" << endl;
}

bool Game::doesEnd() {
    if (m[1]->collide(m[2])) { // Human died
        state = 1;
        return true;
    }
    if (m[1]->collide(m[3])) { // Monster ate Food
        state = 1;
        return true;
    }
    if (m[2]->collide(m[3])) {// Human ate Food
        state = 2;
        return true;
    }
    if (m[0]->collide(m[1])) {// Monster died
        state = 2;
        return true;
    }
    return false;
}

void Game::update() {
    for (int i = 3; i >= 0; i--) // Food 부터 먼저 그려서 Food를 먹는 경우 보이지 않게 하기위해, 
        //Monster가 Bomb에 부딛히면 죽기떄문에 Bomb를 나중에 생성해서 화면에 Monster가 아니라 Bomb표시
        map[m[i]->getY()][m[i]->getX()] = m[i]->getShape();
}

void Game::clear() {
    for (int i = 0; i < 4; i++)
        map[m[i]->getY()][m[i]->getX()] = '-';//초기화
}

void Game::draw() {//멥을 그림
    cout << endl;
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++)
            cout << map[i][j];
        cout << endl;
    }
}