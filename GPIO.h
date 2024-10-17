#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <stdint.h>

class GPIO {
public:
    enum Direction {
        INPUT,
        OUTPUT
    };

    GPIO(uint8_t pin, Direction dir);
    void configure(Direction dir);
    void setHigh();
    void setLow();
    bool read();

private:
    volatile uint8_t* _ddr;
    volatile uint8_t* _port;
    volatile uint8_t* _pinReg;
    uint8_t _pin;
};

#endif // GPIO_H
