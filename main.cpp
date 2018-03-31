#include "mbed.h"

InterruptIn button(BUTTON2);
DigitalOut led(LED2);
DigitalOut flash(LED1);

void flip() {
    led = !led;
}

int main() {
    button.rise(&flip);  // attach the address of the flip function to the rising edge
    while(1) {           // wait around, interrupts will interrupt this!
        flash = !flash;
        wait(0.25);
    }
}