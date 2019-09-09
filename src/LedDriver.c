#include "LedDriver.h"
#include "RuntimeError.h"

const char* OUT_OF_BOUNDS_MSG = "LED Driver: out-of-bounds LED";
enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF=~ALL_LEDS_ON};

static uint16_t *ledsAddress;
static uint16_t ledsImage;

static uint16_t convertLedNumbertToBit(int ledNumber)
{
  return 1 << (ledNumber - 1);
}

static void updateHW(void)
{
  *ledsAddress = ledsImage;
}

void LedDriver_Create(uint16_t *virtualLeds)
{
  ledsAddress = virtualLeds;
  ledsImage = ALL_LEDS_OFF;
  *ledsAddress = ledsImage;
}

void LedDriver_TurnOn(int ledNumber)
{
  if((ledNumber >= 0) && (ledNumber <= 16))
  {
    ledsImage |= convertLedNumbertToBit(ledNumber);
    updateHW();
  } else {
    RUNTIME_ERROR(OUT_OF_BOUNDS_MSG, ledNumber);
  } 
}

void LedDriver_TurnOff(int ledNumber)
{
  if((ledNumber >= 0) && (ledNumber <= 16))
  {
    ledsImage &= ~convertLedNumbertToBit(ledNumber);  
    updateHW();
  } else {
    RUNTIME_ERROR(OUT_OF_BOUNDS_MSG, ledNumber);
  } 
}

void LedDriver_TurnAllOn(void)
{
  ledsImage = ALL_LEDS_ON;
  updateHW();
}
