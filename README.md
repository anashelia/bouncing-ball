BOUNCING BALL
=============

A simple terminal-based animation program written in C that simulates a
bouncing ball moving around inside the borders of your terminal window.


OVERVIEW
--------

The program draws a rectangular border around the terminal screen and
animates a ball bouncing around inside it. The animation runs in an
infinite loop until you terminate the program (e.g., with Ctrl+C).


WHAT IT DOES
------------

  * Draws a blue rectangular border around the entire terminal window
    using '-' for horizontal lines and '|' for vertical lines.

  * Draws a ball (a small 5x3 character sprite) that moves diagonally
    across the screen, one cell per frame.

  * When the ball hits the LEFT or RIGHT wall:
      - Its horizontal direction is reversed.
      - Its COLOR changes to the next color in the sequence:
        black -> red -> green -> yellow -> blue -> magenta -> cyan ->
        white -> black -> ...

  * When the ball hits the TOP or BOTTOM wall:
      - Its vertical direction is reversed.
      - Its FILL CHARACTER toggles between 'O' and 'X'.

  * The screen is cleared and redrawn every frame, with a 30 millisecond
    delay between frames to control the animation speed.


FILES
-----

  bouncing_ball.c
      The main program. Contains the Ball structure, drawing helpers
      (draw_hline, draw_vline, drawBall), collision detection
      (isCollidingX, isCollidingY), color/character cycling helpers, and
      the main animation loop.

  terminal_draw.h
      A header-only terminal drawing library. Provides:
        - clear_screen()      : clears the terminal
        - get_screen_size()   : returns terminal width and height
        - draw_char()         : draws a colored character at (x, y)
        - print_at()          : prints formatted text at (x, y)
        - sleep_ms()          : sleeps for a given number of milliseconds
        - Color enum          : BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA,
                                CYAN, WHITE


BUILDING
--------

The program consists of bouncing_ball.c and the header-only library
terminal_draw.h. Since the library is header-only, you only need to
compile the .c file.

Using GCC:

    gcc bouncing_ball.c -o bouncing_ball

Using Clang:

    clang bouncing_ball.c -o bouncing_ball

Using MSVC (from a Developer Command Prompt):

    cl bouncing_ball.c


RUNNING
-------

On Linux / macOS / Unix:

    ./bouncing_ball

On Windows:

    gcc bouncing_ball.c -o bouncing_ball
    .\bouncing_ball.exe

To stop the animation, press Ctrl+C.


PLATFORM SUPPORT
----------------

  Windows
      Uses the Windows Console API (windows.h):
        - SetConsoleCursorPosition  for cursor movement
        - SetConsoleTextAttribute   for colors
        - Sleep                     for timing

  Linux / macOS / Unix
      Uses ANSI escape sequences for cursor movement and colors,
      ioctl (TIOCGWINSZ) for terminal size detection, and usleep for
      timing.


NOTES
-----

  * On Unix-like systems, sleep_ms() uses usleep(), which may require
    _DEFAULT_SOURCE or _BSD_SOURCE to be defined, depending on your
    compiler and C standard settings.

  * The terminal should be large enough to display the border and ball
    comfortably (at least a few dozen columns and rows).

  * The program does not restore the terminal to its original state on
    exit; the cursor is simply left wherever it was last placed, and
    the screen can be cleared with the `clear` command afterward.


LICENSE
-------

This program is provided as-is for educational and demonstration
purposes. Use and modify it freely.