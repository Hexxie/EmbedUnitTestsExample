#include <stdint.h>

void LedDriver_Create(uint16_t *virtualLeds);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn();
