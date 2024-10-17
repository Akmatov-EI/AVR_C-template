// GPIO.cpp
#include "GPIO.h"

GPIO::GPIO(uint8_t pin, Direction dir) : _pin(pin) {
    if (_pin < 8) {
        _ddr = &DDRB;     
        _port = &PORTB;   
        _pinReg = &PINB;  
    } else if (_pin < 16) {
        _pin -= 8;
        _ddr = &DDRC;    
        _port = &PORTC;   
        _pinReg = &PINC;  
    } else {
        _pin -= 16;
        _ddr = &DDRD;     
        _port = &PORTD;   
        _pinReg = &PIND;  
    }
    configure(dir);
}

void GPIO::configure(Direction dir) {
    if (dir == OUTPUT) {
        *_ddr |= (1 << _pin);
    } else {
        *_ddr &= ~(1 << _pin);
    }
}

void GPIO::setHigh() {
    *_port |= (1 << _pin);
}

void GPIO::setLow() {
    *_port &= ~(1 << _pin);
}

bool GPIO::read() {
    return (*_pinReg & (1 << _pin)) != 0;
}
