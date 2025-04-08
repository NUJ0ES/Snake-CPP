//
//  GameEngine.cpp
//  Snake-CPP
//
//  Created by 허준서 on 4/8/25.
//

#include "Snake.h"
#include "GameEngine.h"

void GameEngine::init() {
    snakeX = 4;
    snakeY = GRID_HEIGHT / 2;
    
    makePrey();
}

void GameEngine::transcribe() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            displayData[y][x] = snake[y][x];
        }
    }
}

void GameEngine::makePrey() {
    while (snake[preyY][preyX]) {
        preyX = rand() % GRID_WIDTH;
        preyY = rand() % GRID_HEIGHT;
    }
}

void GameEngine::next(double dt) {
    if (elapsed > 0.5) {
        if (direction == Direction::RIGHT) snakeX++;
        else if (direction == Direction::LEFT) snakeX--;
        else if (direction == Direction::UP) snakeY--;
        else if (direction == Direction::DOWN) snakeY++;
        
        isDirectionChangable = true;
        
        maintainLength();
        
        eat();
        
        snake[snakeY][snakeX] = length;
        
        elapsed = 0.0;
    }
    else elapsed += dt;
}

void GameEngine::maintainLength() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0 ; x < GRID_WIDTH; x++) {
            if (snake[y][x]) snake[y][x]--;
        }
    }
}

void GameEngine::setDirection(char key) {
    if (isDirectionChangable) {
        if (key == 'u' && direction != Direction::DOWN) direction = Direction::UP;
        else if (key == 'd' && direction != Direction::UP) direction = Direction::DOWN;
        else if (key == 'l' && direction != Direction::RIGHT) direction = Direction::LEFT;
        else if (key == 'r' && direction != Direction::LEFT) direction = Direction::RIGHT;
        
        isDirectionChangable = false;
    }
}

void GameEngine::eat() {
    if (preyX == snakeX && preyY == snakeY) {
        makePrey();
        length++;
        
        for (int y = 0; y < GRID_HEIGHT; y++) {
            for (int x = 0; x < GRID_WIDTH; x++) {
                if (snake[y][x]) snake[y][x]++;
            }
        }
    }
}

void GameEngine::handleCollision() {
    if (snakeX > GRID_WIDTH - 1 || snakeX < 0 || snakeY < 0 || snakeY > GRID_HEIGHT - 1) state = GameState::GAMEOVER;
    // TODO: End game if snake collides with itself
}
