/*
 * overcooked-8bit.c
 *
 * Created: 27/08/2018 12:49:26 AM
 * Author : wuhangqi25
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <stdint.h>
#include <stdlib.h>

#include "scheduler.h"
#include "timer.h"
#include "io.c"

#include "adc.c"
#include "engine.c"
#include "led_driver.c"

#include "overcooked.c"
#include "scene_game_level_one.c"
#include "scene_tutorial_level_one.c"

#define LOWER_THRESHOLD 50
#define UPPER_THRESHOLD 900

#define JOYSTICK_MIN 0
#define JOYSTICK_MAX 1024

#define JOYSTICK_UP_TIRGGERED    joyStickUpDown < LOWER_THRESHOLD
#define JOYSTICK_DOWN_TIRGGERED  joyStickUpDown > UPPER_THRESHOLD
#define JOYSTICK_LEFT_TIRGGERED  joyStickLeftRight < LOWER_THRESHOLD
#define JOYSTICK_RIGHT_TIRGGERED joyStickLeftRight > UPPER_THRESHOLD


#define SCENE_TUTORIAL 0
#define SCENE_GAME 1
#define SCENE_OVER 2

#define chefMoveSpeed 10


//--------Shared Variables----------------------------------------------------
uint8_t selectedScene = SCENE_TUTORIAL;
uint16_t resetCounter = 300;
uint16_t gameStartCounter = 300;
uint8_t gameIsReadyToStart = 1;

uint16_t score = 0;
uint8_t selectedChefShouldMove = 0;

Camera cam;
Coordinate camOffset;

//--------End Shared Variables------------------------------------------------

//--------Game related Functions ---------------------------------------------
void resetCamera() {
	cam.frame.origin.x = 0;
	cam.frame.origin.y = 0;
	cam.frame.size.width = 16;
	cam.frame.size.height = 16;
	camOffset.x = 0;
	camOffset.y = 0;
}

void resetGame() {
	scene_destory();
	scene_init();
	resetCamera();
	setupTutorialLevelOneScene();	
	selectedScene = SCENE_TUTORIAL;
	updateLEDMatrix(cam, camOffset);
}

void startGame() {
	scene_destory();
	scene_init();
	resetCamera();
	setupGameLevelOneScene();
	selectedScene = SCENE_GAME;
	updateLEDMatrix(cam, camOffset);
}

void handleJoyStickSingal(Direction d) {
	Sprite *selectedChef = getSelectedChef();
	switch(d) {
	case up:
		if (selectedChef->facingDirection == up) {
			selectedChefShouldMove = 1;
		} else {
			if (checkCollision(selectedChef, up, selectedChef->frame.origin)) {
				selectedChef->facingDirection = up;
				selectedChefShouldMove = 0;
				updateLEDMatrix(cam, camOffset);
			}
		}
		break;
	case down:
		if (selectedChef->facingDirection == down) {
			selectedChefShouldMove = 1;
		} else {
			if (checkCollision(selectedChef, down, selectedChef->frame.origin)) {
				selectedChef->facingDirection = down;
				selectedChefShouldMove = 0;
				updateLEDMatrix(cam, camOffset);
			}
		}
		break;
	case left:
		if (selectedChef->facingDirection == left) {
			selectedChefShouldMove = 1;
		} else {
			if (checkCollision(selectedChef, left, selectedChef->frame.origin)) {
				selectedChef->facingDirection = left;
				selectedChefShouldMove = 0;
				updateLEDMatrix(cam, camOffset);
			}
		}
		break;
	case right:
		if (selectedChef->facingDirection == right) {
			selectedChefShouldMove = 1;
		} else {
			if (checkCollision(selectedChef, right, selectedChef->frame.origin)) {
				selectedChef->facingDirection = right;
				selectedChefShouldMove = 0;
				updateLEDMatrix(cam, camOffset);
			}
		}
		break;
	}
	
	// if selected chef hold a ingredient then update ingredient location.
	/*
	Sprite *seletedIngredient = getSelectedIngredient();
	if (seletedIngredient != NULL) {
		switch(selectedChef->facingDirection) {
			case up:
				seletedIngredient->frame.origin.x = selectedChef->frame.origin.x + 1;
				seletedIngredient->frame.origin.y = selectedChef->frame.origin.y - 1;
				break;
			case down:
				seletedIngredient->frame.origin.x = selectedChef->frame.origin.x + 1;
				seletedIngredient->frame.origin.y = selectedChef->frame.origin.y + 2;
				break;
			case left:
				seletedIngredient->frame.origin.x = selectedChef->frame.origin.x - 1;
				seletedIngredient->frame.origin.y = selectedChef->frame.origin.y + 1;
				break;
			case right:
				seletedIngredient->frame.origin.x = selectedChef->frame.origin.x + 2;
				seletedIngredient->frame.origin.y = selectedChef->frame.origin.y + 1;
				break;
		}
	}
	*/
}

uint8_t checkHasColor(Coordinate cdt) {
	Coordinate c = _toRelativeCoordinate(cam.frame.origin, cdt);
	RGBColor color = renderPoint(cam, c);
	return (color.red != 0 || color.green != 0 || color.blue != 0);
}

uint8_t selectChefCanMove(Sprite *selectedChef) {
	Coordinate cp1;
	Coordinate cp2;
	switch(selectedChef->facingDirection) {
		case up:
			cp1.x = selectedChef->frame.origin.x;
			cp1.y = selectedChef->frame.origin.y - 1;
			cp2.x = selectedChef->frame.origin.x + 2;
			cp2.y = selectedChef->frame.origin.y - 1;
			return !checkHasColor(cp1) && !checkHasColor(cp2);
		case down:
			cp1.x = selectedChef->frame.origin.x;
			cp1.y = selectedChef->frame.origin.y + 3;
			cp2.x = selectedChef->frame.origin.x + 2;
			cp2.y = selectedChef->frame.origin.y + 3;
			return !checkHasColor(cp1) && !checkHasColor(cp2);
		case left:
			cp1.x = selectedChef->frame.origin.x - 1;
			cp1.y = selectedChef->frame.origin.y;
			cp2.x = selectedChef->frame.origin.x - 1;
			cp2.y = selectedChef->frame.origin.y + 2;
			return !checkHasColor(cp1) && !checkHasColor(cp2);
		case right:
			cp1.x = selectedChef->frame.origin.x + 3;
			cp1.y = selectedChef->frame.origin.y;
			cp2.x = selectedChef->frame.origin.x + 3;
			cp2.y = selectedChef->frame.origin.y + 2;
			return !checkHasColor(cp1) && !checkHasColor(cp2);
	} 
}

uint8_t selectChefCanRotate(Sprite *selectedChef, Direction d) {
	
}

//--------End Game Related Functions -----------------------------------------

//--------User Defined FSMs---------------------------------------------------
enum JoyStickState { State_normal, State_selected };
int Task_JoyStickControl(int state) {
	uint16_t joyStickUpDown = ADC_read(3);
	uint16_t joyStickLeftRight = ADC_read(4);
	_delay_ms(10);
	
	if (selectedScene == SCENE_TUTORIAL) {
		switch(state) {
			case State_normal:
				if (JOYSTICK_LEFT_TIRGGERED) {
					// go to previous page of tutorial
					int currentX = cam.frame.origin.x;
					cam.frame.origin.x = currentX - 16 < 0 ? 0 : currentX - 16;
					updateLEDMatrix(cam, camOffset);
					return State_selected;
				} else if (JOYSTICK_RIGHT_TIRGGERED) {
					// go to next page of tutorial
					int currentX = cam.frame.origin.x;
					cam.frame.origin.x = currentX + 16 > 48 ? 48 : currentX + 16;
					updateLEDMatrix(cam, camOffset);
					return State_selected;
				} else {
					return State_normal;
				}
				break;
			case State_selected:
				if (JOYSTICK_RIGHT_TIRGGERED || JOYSTICK_LEFT_TIRGGERED) {
					return State_selected;
				} else {
					return State_normal;
				}
				break;
		}
	} 
	
	if (selectedScene == SCENE_GAME) {   
		if (!(JOYSTICK_LEFT_TIRGGERED || JOYSTICK_RIGHT_TIRGGERED || JOYSTICK_UP_TIRGGERED || JOYSTICK_DOWN_TIRGGERED)) {
			selectedChefShouldMove = 0;
		}
		//if more than one direction signal are triggered
		//compare signal and choose strongest one
		if (JOYSTICK_LEFT_TIRGGERED) {
			if (JOYSTICK_UP_TIRGGERED) {
				if (joyStickUpDown < joyStickLeftRight) {
					handleJoyStickSingal(up);
				} else {
					handleJoyStickSingal(left);
				}
			} else if (JOYSTICK_DOWN_TIRGGERED) {
				if (joyStickUpDown > (JOYSTICK_MAX - joyStickLeftRight)) {
					handleJoyStickSingal(down);
				} else {
					handleJoyStickSingal(left);
				}
			} else {
				handleJoyStickSingal(left);
			}
		} 
		if (JOYSTICK_RIGHT_TIRGGERED) {
			if (JOYSTICK_UP_TIRGGERED) {
				if ((JOYSTICK_MAX - joyStickUpDown) > joyStickLeftRight) {
					handleJoyStickSingal(up);
				} else {
					handleJoyStickSingal(right);
				}
			} else if (JOYSTICK_DOWN_TIRGGERED) {
				if (joyStickUpDown > joyStickLeftRight) {
					handleJoyStickSingal(down);
				} else {
					handleJoyStickSingal(right);
				}
			} else {
				handleJoyStickSingal(right);
			}
		}
		
		if (JOYSTICK_UP_TIRGGERED) {
			if (JOYSTICK_LEFT_TIRGGERED) {
				if (joyStickLeftRight < joyStickUpDown) {
					handleJoyStickSingal(left);
				} else {
					handleJoyStickSingal(up);
				}
			} else if (JOYSTICK_RIGHT_TIRGGERED) {
				if (joyStickUpDown > (JOYSTICK_MAX - joyStickLeftRight)) {
					handleJoyStickSingal(right);
				} else {
					handleJoyStickSingal(up);
				}
			} else {
				handleJoyStickSingal(up);
			}
		}
		if (JOYSTICK_DOWN_TIRGGERED) {
			if (JOYSTICK_LEFT_TIRGGERED) {
				if ((JOYSTICK_MAX - joyStickUpDown) > joyStickLeftRight) {
					handleJoyStickSingal(left);
				} else {
					handleJoyStickSingal(down);
				}
			} else if (JOYSTICK_RIGHT_TIRGGERED) {
				if (joyStickUpDown < joyStickLeftRight) {
					handleJoyStickSingal(right);
				} else {
					handleJoyStickSingal(down);
				}
			} else {
				handleJoyStickSingal(down);
			}
		}
	}
	return 0;
}

enum CountingEventState { State_standby, State_counting, State_finished };
int Task_ResetListener(int state) {
	uint8_t pickButton = ~PINA & 0x04;
	uint8_t chopButton = ~PINA & 0x02;
	uint8_t changeButton = ~PINA & 0x01;
	switch(state) {
		case State_standby:
			if (pickButton && chopButton && changeButton) {
				resetCounter --;
				LCD_DisplayString(1, "Game will reset in 3..");
				gameIsReadyToStart = 0;
				return State_counting;
			} else {
				return State_standby;
			}
			break;
		case State_counting:
			if (pickButton && chopButton && changeButton) {
				resetCounter --;
				if (resetCounter == 200) {
					LCD_DisplayString(1, "Game will reset in 2..");
				}
				if (resetCounter == 100) {
					LCD_DisplayString(1, "Game will reset in 1..");
				}
				if (resetCounter == 0) {
					resetGame();
					LCD_DisplayString(1, "Game reset completed.");
					resetCounter = 300;
					return State_finished;
				} else {
					return State_counting;
				}
			} else {
				LCD_DisplayString(1, "Game reset canceled.");
				gameIsReadyToStart = 1;
				resetCounter = 300;
				return State_standby;
			}
			break;
		case State_finished:
			if (!chopButton && !pickButton && !changeButton) {
				gameIsReadyToStart = 1;
				return State_standby;
			} else {
				return State_finished;
			}
			break;
	}
}

int Task_GameStartListener(int state) {
	if (selectedScene == SCENE_TUTORIAL) {
		uint8_t pickButton = ~PINA & 0x04;
		switch(state) {
			case State_standby:
			if (gameIsReadyToStart && pickButton) {
				gameStartCounter --;
				LCD_DisplayString(1, "Game will start in 3..");
				return State_counting;
			} else {
				return State_standby;
			}
			break;
			case State_counting:
			if (gameIsReadyToStart && pickButton) {
				gameStartCounter --;
				if (gameStartCounter == 200) {
					LCD_DisplayString(1, "Game will start in 2..");
				} 
				if (gameStartCounter == 100) {
					LCD_DisplayString(1, "Game will start in 1..");
				} 
				if (gameStartCounter == 0) {
					startGame();
					gameStartCounter = 300;
					return State_standby;
				} else {
					return State_counting;
				}
			} else {
				if (gameIsReadyToStart) {
					LCD_DisplayString(1, "Game start is canceled.");
				}
				gameStartCounter = 300;
				return State_standby;
			}
			break;
		}
	} else {
		return State_standby;
	}
}

int Task_updateChefLocation(int state) {
	if (selectedScene == SCENE_GAME) {
		Sprite *selectedChef = getSelectedChef();
		if (selectedChefShouldMove) {
			if (selectChefCanMove(selectedChef)) {
				switch(selectedChef->facingDirection) {
					case up:
						selectedChef->frame.origin.y --;
						break;
					case down:
						selectedChef->frame.origin.y ++;
						break;
					case left:
						selectedChef->frame.origin.x --;
						break;
					case right:
						selectedChef->frame.origin.x ++;
						break;
				}
				updateLEDMatrix(cam, camOffset);
			}
		}
	}
	return 0;
}

enum ButtonState { State_pressing, State_released };
int Task_ChangeButtonControl(int state) {
	if (selectedScene == SCENE_GAME) {
		uint8_t pickDropButton = (~PINA & 0x04) >> 2;
		uint8_t chopButton     = (~PINA & 0x02) >> 1;
		uint8_t changeButton   = ~PINA & 0x01;
		if ((pickDropButton + chopButton + changeButton) > 1 ) {
			return 0;
		}
		switch(state) {
			case State_released:
				if (changeButton) {
					if (chefOne->state & MASK_SELECTED) {
						chefOne->state &= ~MASK_SELECTED;
						chefTwo->state |= MASK_SELECTED;
					} else {
						chefTwo->state &= ~MASK_SELECTED;
						chefOne->state |= MASK_SELECTED;
					}
					updateLEDMatrix(cam, camOffset);
					return State_pressing;
				} else {
					return State_released;
				}
				break;
			case State_pressing:
				if (changeButton) {
					return State_pressing;
				} else {
					return State_released;
				}
				break;
		}
	} else {
		return 0;
	}
}

int Task_PickDropButtonControl(int state) {
	if (selectedScene == SCENE_GAME) {
		uint8_t pickDropButton = (~PINA & 0x04) >> 2;
		uint8_t chopButton     = (~PINA & 0x02) >> 1;
		uint8_t changeButton   = ~PINA & 0x01;
		if ((pickDropButton + chopButton + changeButton) > 1 ) {
			return 0;
		}
		switch(state) {
			case State_released:
			if (pickDropButton) {
				handlePickDrop();
				return State_released;
			}
			break;
			case State_pressing:
				if (pickDropButton) {
					return State_pressing;
				} else {
					return State_released;
				}
				break;
		}
	} else {
		return 0;
	}
}




//--------End User Defined FSMS-----------------------------------------------

int main(void)
{
	// Set input and output pins
	DDRA = 0x00; PORTA = 0xff;
	DDRB = 0xff; PORTB = 0x00;
	DDRC = 0xff; PORTC = 0x00;
	DDRD = 0xff; PORTD = 0x00;
	
	LCD_init();
	ADC_init();
	
	scene_init();
	setupTutorialScene();
	cam.frame.origin.x = 0;
	cam.frame.origin.y = 0;
	cam.frame.size.width = 16;
	cam.frame.size.height = 16;
	camOffset.x = 0;
	camOffset.y = 0;
	updateLEDMatrix(cam, camOffset);
	
	// Tasks declaration
	static task task1, task2, task3, task4, task5;
	task *tasks[] = { &task1, &task2, &task3, &task4, &task5};
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);
	
	// Period for the tasks
	unsigned long int task1TempPeriod = 10;
	unsigned long int task2TempPeriod = 10;
	unsigned long int task3TempPeriod = 10;
	unsigned long int task4TempPeriod = 1000 / chefMoveSpeed;  
	unsigned long int task5TempPeriod = 10;
	
	//Calculating GCD
	unsigned long int tmpGCD = 1;
	tmpGCD = findGCD(task1TempPeriod, task2TempPeriod);
	tmpGCD = findGCD(tmpGCD, task3TempPeriod);
	tmpGCD = findGCD(tmpGCD, task4TempPeriod);
	tmpGCD = findGCD(tmpGCD, task5TempPeriod);

	//Greatest common divisor for all tasks or smallest time unit for tasks.
	unsigned long int GCD = tmpGCD;
	
	//Recalculate GCD periods for scheduler
	unsigned long int task1Period = task1TempPeriod/GCD;
	unsigned long int task2Period = task2TempPeriod/GCD;
	unsigned long int task3Period = task3TempPeriod/GCD;
	unsigned long int task4Period = task4TempPeriod/GCD;
	unsigned long int task5Period = task5TempPeriod/GCD;

	
	//Setup tasks
	task1.period = task1Period;
	task1.elapsedTime = 0;
	task1.TickFct = &Task_JoyStickControl;
	task1.state = State_normal;
	
	task2.period = task2Period;
	task2.elapsedTime = 0;
	task2.TickFct = &Task_ResetListener;
	task2.state = State_standby;
	
	task3.period = task3Period;
	task3.elapsedTime = 0;
	task3.TickFct = &Task_GameStartListener;
	task3.state = State_standby;
	
	task4.period = task4Period;
	task4.elapsedTime = 0;
	task4.TickFct = &Task_updateChefLocation;
	task4.state = 0;
	
	task5.period = task5Period;
	task5.elapsedTime = 0;
	task5.TickFct = &Task_ChangeButtonControl;
	task5.state = State_released;
	
	// Set the timer and turn it on
	TimerSet(GCD);
	TimerOn();
	
	unsigned short i;
	while(1) {
		for ( i = 0; i < numTasks; i++ ) {
			if ( tasks[i]->elapsedTime == tasks[i]->period ) {
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				tasks[i]->elapsedTime = 0;
			}
			tasks[i]->elapsedTime += 1;
		}
		while(!TimerFlag);
		TimerFlag = 0;
	}
	
	// Error: Program should not exit!
	return 0;
}



