/*
 * timer.c
 *
 *  Created on: Mar 31, 2022
 *      Author: MUHAMMEDERKAMOKUMUŞ
 */


#include"stm32f4xx_hal.h"
#include"timer.h"

void tim_init(void){

	__HAL_RCC_TIM7_CLK_ENABLE();

	SET_BIT(TIM7->CR1, TIM_CR1_CEN);

	//periyod = 2s
	//0,5 = 16Mhz/(32000 * 1000)

	TIM7->PSC= 31999;
	TIM7->ARR= 999;

	SET_BIT(TIM7->DIER, TIM_DIER_UIE);

	NVIC_EnableIRQ(TIM7_IRQn);


}

void TIM7_IRQHandler(void){

	TIM7->SR=0x0;
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);

}
