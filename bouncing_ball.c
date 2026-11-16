#include "terminal_draw.h"
#include <stdbool.h>


 typedef struct {
    int x;
    int y;
 } Position;


 typedef struct {
    Position ballPosition;
    Color ballColor;
    char ballCharacter;
 } Ball;


void draw_hline(int x, int y, int length, char c, Color color) {
    int width, height;
    get_screen_size(&width, &height);
    for(int i = 0; i < length; i++){
        draw_char(x+i, y, c, color);
    }
}


 void draw_vline(int x, int y, int length, char c, Color color) {
    int width, height;
    get_screen_size(&width, &height);
    for (int i = 0; i < length; i++) {
        draw_char(x, y + i, c, color);
    }
}


 void drawBall(Ball *ball) {
    int cx = ball->ballPosition.x;
    int cy = ball->ballPosition.y;
    char fill = ball->ballCharacter;
    Color color = ball->ballColor;

    draw_char(cx - 1, cy - 1, fill, color);
    draw_char(cx,     cy - 1, fill, color);
    draw_char(cx + 1, cy - 1, fill, color);

    draw_char(cx - 2, cy, fill, color);
    draw_char(cx - 1, cy, fill, color);
    draw_char(cx,     cy, fill, color);
    draw_char(cx + 1, cy, fill, color);
    draw_char(cx + 2, cy, fill, color);

    draw_char(cx - 1, cy + 1, fill, color);
    draw_char(cx,     cy + 1, fill, color);
    draw_char(cx + 1, cy + 1, fill, color);

 }


Color getNextColor(Color color)
{
    if (color + 1 == NUM_COLORS)
        return 0;        
    else
        return color + 1;
}


char getNextFillChar(char c)
{
    if (c == 'O') {
        return 'X';
    } else {
        return 'O';
    }
}


bool isCollidingX(Ball *ball, int screenWidth) {
    int cx = ball->ballPosition.x;

    if (cx - 2 <= 0)
        return true;

    if (cx + 2 >= screenWidth - 1)
        return true;

    return false;
}



 bool isCollidingY(Ball *ball, int screenHeight) {
    int cy = ball->ballPosition.y;

    if (cy - 1 <= 0)
        return true;

    if (cy + 1 >= screenHeight - 1)
        return true;

    return false;
}

int main(void)
{
    int screenWidth, screenHeight;
    get_screen_size(&screenWidth, &screenHeight);

    Ball ball;
    ball.ballPosition.x = screenWidth / 2;
    ball.ballPosition.y = screenHeight / 2;
    ball.ballColor = RED;
    ball.ballCharacter = 'O';


    int dx = 1;
    int dy = 1;

    while (1)
    {
        clear_screen();

        draw_hline(0, 0, screenWidth, '-', BLUE);                    
        draw_hline(0, screenHeight - 1, screenWidth, '-', BLUE);     
        draw_vline(0, 0, screenHeight, '|', BLUE);                   
        draw_vline(screenWidth - 1, 0, screenHeight, '|', BLUE);     

        drawBall(&ball);

        ball.ballPosition.x += dx;
        ball.ballPosition.y += dy;

        if (isCollidingX(&ball, screenWidth)) {
        dx = -dx;
        ball.ballColor = getNextColor(ball.ballColor);
        }

        if (isCollidingY(&ball, screenHeight)) {
        dy = -dy;
        ball.ballCharacter = getNextFillChar(ball.ballCharacter);
        }



        sleep_ms(30);
    }

    return 0;
}
