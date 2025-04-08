//
//  Display.cpp
//  Snake-CPP
//
//  Created by 허준서 on 4/8/25.
//

#include "Display.h"
#include "Snake.h"

void Display::draw() {
    printf("\033[H\033[J");
    
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (preyX == x && preyY == y) {
                printf("◆ ");
            }
            else printf(displayData[y][x] ? "■ " : "□ ");
        }
        printf("\n");
    }
}
