#ifndef HEADER_H_
#define HEADER_H_

#include "plusheader.hpp"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#define F_CPU 16000000UL

#define BUTTON1 4
#define BUTTON2 5



/********************************************************************************
* setup: Initiates the game and displays the startup screen.
********************************************************************************/
void setup(void);


/********************************************************************************
* setup: Initiates all ports.
********************************************************************************/
void init_ports(void);


/********************************************************************************
* setup: Initiates timer1 and the necessary code.
********************************************************************************/
void init_timer(void);
  

/********************************************************************************
* setup: Initiates the game startup screen.
********************************************************************************/
void start_countdown(void);  

void update_score();
void game_loop();
void game_over();
void reset_game();


#endif /* HEADER_H_ */
