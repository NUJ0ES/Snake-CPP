//
//  GameEngine.h
//  Snake-CPP
//
//  Created by 허준서 on 4/8/25.
//

#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "Snake.h"

class GameEngine {
public:
    enum class GameState {
        PLAYING, GAMEOVER
    };
    
    enum class Direction {
        UP, DOWN, LEFT, RIGHT
    };
    
    Direction direction = Direction::RIGHT;
    GameState state = GameState::PLAYING;
    
    int snake[GRID_HEIGHT][GRID_WIDTH] = { 0, };
    int snakeX, snakeY;
    int length = 3;
    
    double elapsed = 0.0;
    bool isDirectionChangable = true;
    int prevState = 0;
    
    void init();
    
    void transcribe();
    
    void makePrey();
    
    void next(double dt);
    
    void maintainLength();
    
    void setDirection(char key);
    
    void eat();
    
    void handleGameState();
};

#endif
