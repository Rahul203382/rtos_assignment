/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include<FreeRTOS.h>
#include<FreeRTOSConfig.h>
#include<task.h>
#include"led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void vAperiodicTask1(void *pvParam)
{
	for( ; ; )
	{
		led_toggle(12);
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
	vTaskDelete(NULL);
}

void vAperiodicTask2(void *pvParam)
{
	for( ; ; )
	{
		led_toggle(13);
		vTaskDelay(2000 / portTICK_RATE_MS);
	}
	vTaskDelete(NULL);
}
void vAperiodicTask3(void *pvParam)
{
	for( ; ; )
	{
		led_toggle(14);
		vTaskDelay(3000 / portTICK_RATE_MS);
	}
	vTaskDelete(NULL);
}
void vAperiodicTask4(void *pvParam)
{
	for( ; ; )
	{
		led_toggle(15);
		vTaskDelay(4000 / portTICK_RATE_MS);
	}
	vTaskDelete(NULL);
}



int main(void)
{
	led_init(12);
	led_init(13);
	led_init(14);
	led_init(15);

	xTaskCreate(vAperiodicTask1, "TAST1", configMINIMAL_STACK_SIZE, NULL, 4, NULL);

	xTaskCreate(vAperiodicTask2, "TAST2", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
	xTaskCreate(vAperiodicTask3, "TAST3", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
	xTaskCreate(vAperiodicTask4, "TAST4", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
	vTaskStartScheduler();

	while(1);
}











