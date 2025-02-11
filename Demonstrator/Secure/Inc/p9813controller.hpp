#ifndef P9813CONTROLLER_HPP
#define P9813CONTROLLER_HPP

extern "C"{
#include "stm32l5xx_nucleo.h"
}

class P9813Controller{
  private:
    uint8_t r;
    uint8_t g;
    uint8_t b;

    GPIO_TypeDef *GPIOx;
    uint16_t dataPIN;
    uint16_t clockPIN;

    uint32_t bgr;
    uint32_t sequence;

    void send32bitSequence(uint32_t sequence);
    void writeColor();

  public:
    /**
      * @brief  create LED Strip Controller
      * @note   ----
      * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L5 family
      * @param  GPIO_Pin_data specifies the pin to the p9813 data line
      * @param  GPIO_Pin_clock specifies the pin to the p9813 clock line
      * @retval P9813Controller
      */
    P9813Controller(){}
    P9813Controller(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_data, uint16_t GPIO_Pin_clock);
    ~P9813Controller(){}

    /**
      * @brief  Set an RGB color value to the RGB-Strip
      * @note   ----
      * @param  r color RED (values betwwen 0 no red and 255 fully red)
      * @param  g colorvalue GREEN
      * @param  b colorvalue BLUE
      * @retval success or not
      */
    bool setRGB(
      uint8_t r,
      uint8_t g,
      uint8_t b
    );
};

#endif
