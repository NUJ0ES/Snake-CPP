//
//  Snake.cpp
//  Snake-CPP
//
//  Created by 허준서 on 4/8/25.
//

#include "Snake.h"
#include "Display.h"
#include "GameEngine.h"

#define INTERVAL 1.0 / 60.0

int displayData[GRID_HEIGHT][GRID_WIDTH] = { 0, };
int preyX = 0;
int preyY = 0;

int main(int argc, const char * argv[]) {
    // Set random seed
    srand((unsigned)time(NULL));
    
    // Make class instances
    Display* display = new Display;
    GameEngine* gameEngine = new GameEngine;
    
    // Initialize prey's coordinate
    gameEngine->init();
    
    double prev = (double)clock() / CLOCKS_PER_SEC;
    
    
    // Main loop
    while (gameEngine->state == GameEngine::GameState::PLAYING) {
        // Limit FPS
        double curr = (double)clock() / CLOCKS_PER_SEC;
        double dt = curr - prev;
        if (dt < INTERVAL) continue;
        prev = curr;
        
        gameEngine->handleCollision();
        
        if (CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, kVK_LeftArrow)) {
            gameEngine->setDirection('l');
        }
        else if (CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, kVK_RightArrow)) {
            gameEngine->setDirection('r');
        }
        else if (CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, kVK_UpArrow)) {
            gameEngine->setDirection('u');
        }
        else if (CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, kVK_DownArrow)) {
            gameEngine->setDirection('d');
        }
        
        gameEngine->next(dt);
        
        gameEngine->transcribe();
        display->draw();
    }
    
    return 0;
}
