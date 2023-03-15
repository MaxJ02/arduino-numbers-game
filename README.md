# arduino-numbers-game
Small "game" for arduino uno/nano which uses timers, two 8 segment displays and a LCD display.


This program uses the `avr/io.h`, `avr/interrupt.h`, `util/delay.h`, and `stdio.h` libraries, as well as a custom `lcd.h` library for interfacing with the LCD display.

The program initializes the push buttons as inputs with pull-up resistors and sets up a timer to count down from 3 seconds. It then enters a loop where it checks which game mode is selected and waits for the user to press one of the buttons to start the game.

During the game, the program checks if the button is pressed and increments the score accordingly. It also displays the score on the LCD screen.

When the timer runs out, the game is over and the program displays the final score and asks if the user wants to play again or exit. If the user chooses to play again, the program resets the game variables and starts a new round. If the user chooses to exit, the program ends.

