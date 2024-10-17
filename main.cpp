#include <avr/io.h>
#include <util/delay.h>
#include "GPIO.h"
#define delay(ms) _delay_ms(ms)

int main() {
    GPIO led(5, GPIO::OUTPUT);  // Пин на выход
    //GPIO button(1, GPIO::INPUT); // Пин на вход

    while (true) {
        led.setHigh();
       delay(100);
       led.setLow();
       delay(100);
    }

    return 0;
}
