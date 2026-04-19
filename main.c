/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    : main.c
  * @brief   : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"

void SystemClock_Config(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    GPIOC->MODER &= ~(GPIO_MODER_MODE0);
    GPIOC->MODER &= ~(GPIO_MODER_MODE1);
    GPIOC->MODER &= ~(GPIO_MODER_MODE2);
    GPIOC->MODER &= ~(GPIO_MODER_MODE3);

    GPIOC->MODER |= (1 << GPIO_MODER_MODE0_Pos);
    GPIOC->MODER |= (1 << GPIO_MODER_MODE1_Pos);
    GPIOC->MODER |= (1 << GPIO_MODER_MODE2_Pos);
    GPIOC->MODER |= (1 << GPIO_MODER_MODE3_Pos);

    GPIOC->OTYPER &= ~(GPIO_OTYPER_OT0);
    GPIOC->OTYPER &= ~(GPIO_OTYPER_OT1);
    GPIOC->OTYPER &= ~(GPIO_OTYPER_OT2);
    GPIOC->OTYPER &= ~(GPIO_OTYPER_OT3);

    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED0);
    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED1);
    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED2);
    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED3);

    GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD0);
    GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD1);
    GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD2);
    GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD3);

    int32_t count = 0;

    while (1)
    {
        for (int i = 0; i < 100000; i++);

        if (count == 0){
            GPIOC->ODR &= ~(GPIO_ODR_OD0 | GPIO_ODR_OD1 | GPIO_ODR_OD2 | GPIO_ODR_OD3);
        }
        else if (count == 1){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD1 | GPIO_ODR_OD2 | GPIO_ODR_OD3)) | GPIO_ODR_OD0;
        }
        else if (count == 2){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD0 | GPIO_ODR_OD2 | GPIO_ODR_OD3)) | GPIO_ODR_OD1;
        }
        else if (count == 3){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD2 | GPIO_ODR_OD3)) | (GPIO_ODR_OD0 | GPIO_ODR_OD1);
        }
        else if (count == 4){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD0 | GPIO_ODR_OD1 | GPIO_ODR_OD3)) | GPIO_ODR_OD2;
        }
        else if (count == 5){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD1 | GPIO_ODR_OD3)) | (GPIO_ODR_OD0 | GPIO_ODR_OD2);
        }
        else if (count == 6){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD0 | GPIO_ODR_OD3)) | (GPIO_ODR_OD1 | GPIO_ODR_OD2);
        }
        else if (count == 7){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD3)) | (GPIO_ODR_OD0 | GPIO_ODR_OD1 | GPIO_ODR_OD2);
        }
        else if (count == 8){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD0 | GPIO_ODR_OD1 | GPIO_ODR_OD2)) | GPIO_ODR_OD3;
        }
        else if (count == 9){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD1 | GPIO_ODR_OD2)) | (GPIO_ODR_OD0 | GPIO_ODR_OD3);
        }
        else if (count == 10){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD0 | GPIO_ODR_OD2)) | (GPIO_ODR_OD1 | GPIO_ODR_OD3);
        }
        else if (count == 11){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD2)) | (GPIO_ODR_OD0 | GPIO_ODR_OD1 | GPIO_ODR_OD3);
        }
        else if (count == 12){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD0 | GPIO_ODR_OD1)) | (GPIO_ODR_OD2 | GPIO_ODR_OD3);
        }
        else if (count == 13){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD1)) | (GPIO_ODR_OD0 | GPIO_ODR_OD2 | GPIO_ODR_OD3);
        }
        else if (count == 14){
            GPIOC->ODR = (GPIOC->ODR & ~(GPIO_ODR_OD0)) | (GPIO_ODR_OD1 | GPIO_ODR_OD2 | GPIO_ODR_OD3);
        }
        else if (count == 15){
            GPIOC->ODR |= (GPIO_ODR_OD0 | GPIO_ODR_OD1 | GPIO_ODR_OD2 | GPIO_ODR_OD3);
            count = 0;
        }

        count++;
    }
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
    RCC_OscInitStruct.MSIState = RCC_MSI_ON;
    RCC_OscInitStruct.MSICalibrationValue = 0;
    RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK |
                                 RCC_CLOCKTYPE_SYSCLK |
                                 RCC_CLOCKTYPE_PCLK1 |
                                 RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
}

void Error_Handler(void)
{
    __disable_irq();
    while (1)
    {
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif
