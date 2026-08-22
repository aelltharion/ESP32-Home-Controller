#include "Button.h"
#include "Config.h"

Button::Button(uint8_t pin)
: pin(pin)
{
    pinMode(pin, INPUT_PULLUP);
}

void Button::update()
{
    bool currentState = digitalRead(pin);

    if(lastReading != currentState)
    {
        debounceTime = millis();
    }

    if(millis() - debounceTime > debounceDelay)
    {
        if(buttonState != currentState)
        {
            buttonState = currentState;

            if(buttonState == LOW)
            {
                pressed = true;
            }
        }
    }
    lastReading = currentState;
}

bool Button::isPressed()
{
    bool result = pressed;
    pressed = false;

    return result;
}