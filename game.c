#include "game.h"
#include "lcd.h"

volatile uint8_t game_mode = 0;
volatile uint8_t countdown = 0;
volatile uint8_t timer_option = 0;
volatile uint8_t game_over = 0;
volatile uint8_t player1_score = 0;
volatile uint8_t player2_score = 0;

void init_ports() {
  // Set push button pins as inputs with pull-up resistors
  DDRB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2));
  PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);

  // Set LCD pins as outputs
  DDRD = 0xFF;
}

void init_lcd() {
  // Initialize LCD display
  lcd_init(LCD_DISP_ON);
}

void init_timer() {
  // Set up Timer/Counter1 for 1 second intervals
  TCCR1B |= (1 << WGM12); // CTC mode
  TIMSK1 |= (1 << OCIE1A); // Enable interrupt on compare match A
  OCR1A = 15624; // Set compare match value for 1 second at 16MHz
  TCCR1B |= (1 << CS12) | (1 << CS10); // Start timer with prescaler 1024
}

void start_countdown() {
  // Display countdown on LCD screen
  lcd_gotoxy(6, 1);
  lcd_puts("Ready?");
  _delay_ms(1000);
  lcd_gotoxy(6, 1);
  lcd_puts("3");
  _delay_ms(1000);
  lcd_gotoxy(6, 1);
  lcd_puts("2");
  _delay_ms(1000);
  lcd_gotoxy(6, 1);
  lcd_puts("1");
  _delay_ms(1000);
}

void update_score() {
  if (!(PINB & (1 << PB0))) {
    player1_score++;
  }
  if (!(PINB & (1 << PB1))) {
    if (game_mode == 1) {
      player2_score++;
    }
    else {
      player1_score++;
    }
  }
  if (!(PINB & (1 << PB2))) {
    if (game_mode == 1) {
      player1_score++;
    }
    else {
      player2_score++;
    }
  }
  lcd_gotoxy(0, 0);
  lcd_printf("P1: %d P2: %d", player1_score, player2_score);
}

void game_loop() {
  while (!game_over) {
    if (countdown > 0) {
      start_countdown();
      countdown = 0;
      TCNT1 = 0; // Reset timer
    }
    if (timer_option == 0) {
      if (TCNT1 >= 31250) { // 2 seconds at 16MHz with prescaler 1024
        game_over = 1;
      }
    }
    else if (timer_option == 1) {
      if (TCNT1 >= 46875) { // 3 seconds at 16MHz with prescaler 1024
        game_over = 1;
      }
    }
    else {
      if (TCNT1 >= 62500) { // 4 seconds at 16MHz with prescaler 1024
        game_over = 1;
      }
    }
    update_score();
  }
  game_over();
}

