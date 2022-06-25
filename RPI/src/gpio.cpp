#include "gpio.h"


void SetupGPIO(unsigned char gpioPinLazerInput, unsigned char gpioPinLed){
    if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
      printf("can't open /dev/mem \n");
      exit(-1);
    }
    gpio_map = mmap(
      NULL,             //Any adddress in our space will do
      BLOCK_SIZE,       //Map length
      PROT_READ|PROT_WRITE,// Enable reading & writting to mapped memory
      MAP_SHARED,       //Shared with other processes
      mem_fd,           //File to map
      GPIO_BASE         //Offset to GPIO peripheral
    );
    close(mem_fd); //No need to keep mem_fd open after mmap
    if (gpio_map == MAP_FAILED) {
      printf("mmap error %d\n", (int)gpio_map);//errno also set!
      exit(-1);
    }
    gpio = (volatile unsigned *)gpio_map;
    GPIO_CLR = 1 << gpioPinLazerInput;
    INP_GPIO(gpioPinLazerInput);

    INP_GPIO(gpioPinLed);
    OUT_GPIO(gpioPinLed);
    GPIO_CLR = 1 << gpioPinLed;


}
void SetGPIO(unsigned char pin){
  GPIO_SET = 1 << pin;
}
void ClearGPIO(unsigned char pin){
  GPIO_CLR = 1 << pin;
}
bool GetInputStart(unsigned char gpioNumber){
    return bool(GET_GPIO(gpioNumber));
}
