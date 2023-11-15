/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7seg.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"
#include "mode4.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define CHANGE_1 100	// (*timer_interupt_duration)
#define CHANGE_2 25

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  /* Initialize initial value */
  // timer interupt
  set_timer(0, 2);	// change mode
  set_timer(1, 2);	// blink led
  set_timer(2, 2);	// scan 7-segment led
  // led
  HAL_GPIO_WritePin(V_RED_GPIO_Port, V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin|
						   H_RED_Pin|H_YELLOW_Pin|H_GREEN_Pin, SET);
  // button
  init_button_state();
  STATE button[MAX_BUTTON];
  button[0] = NORMAL;
  button[1] = NORMAL;
  button[2] = NORMAL;
  // finite state machine
  FSM_STATE state = MODE_1;
  setState1(INIT);
  mode1();
  TRAFFIC start_state = RED_GREEN;
  setState1(start_state);
  // 7-segment led
  HAL_GPIO_WritePin(GPIOB, ENV0_Pin|ENV1_Pin|ENH0_Pin|ENH1_Pin, SET);


  while (1)
  {
	  if (isPressed(0))
		  button[0] = PRESSED;
	  else if (isLongPressed(0))
		  button[0] = LONG_PRESSED;
	  else
		  button[0] = NORMAL;

	  if (isPressed(1))
  		  button[1] = PRESSED;
  	  else if (isLongPressed(1))
  		  button[1] = LONG_PRESSED;
  	  else
  		  button[1] = NORMAL;

	  if (isPressed(2))
  		  button[2] = PRESSED;
 	  else if (isLongPressed(0))
  		  button[2] = LONG_PRESSED;
  	  else
  		  button[2] = NORMAL;

	  switch (button[0])
	  {
	  case NORMAL:
		  break;
	  case PRESSED:
		  // increase mode
		  if (state >= MODE_4)
		  {
			  state = MODE_1;
		  }
		  else
		  {
			  state++;
		  }
		  // set up environment
		  switch(state)
		  {
		  case MODE_1:
			  setState1(INIT);
			  break;
		  case MODE_2:
			  setState2(MODE2_INIT);
			  break;
		  case MODE_3:
			  setState3(MODE3_INIT);
			  break;
		  case MODE_4:
			  setState4(MODE4_INIT);
			  break;
		  break;
		  }
	  case LONG_PRESSED:
		  break;
	  default:
		  break;
	  }

	  switch (button[1])
	  {
	  case NORMAL:
		  // increase led duration
		  break;
	  case PRESSED:
		  break;
	  case LONG_PRESSED:
		  break;
	  default:
		  break;
	  }

	  switch (button[2])
	  {
	  case NORMAL:
		  // set time duration for led
		  break;
	  case PRESSED:
		  break;
	  case LONG_PRESSED:
		  break;
	  default:
		  break;
	  }

	  switch (state)
	  {
	  case MODE_1:
		  mode1();
		  break;
	  case MODE_2:
		  switch (button[1])
	  	  {
	  	  case NORMAL:
	  		  break;
	  	  case PRESSED:
	  		  // increase led duration
	  		  setState2(MODE2_INCREASE);
	  		  break;
	  	  case LONG_PRESSED:
	  		  break;
	  	  default:
	  		  break;
	  	  }

		  switch (button[2])
		  {
		  case NORMAL:
			  break;
		  case PRESSED:
			  // set time duration for led
			  setState2(MODE2_SET_TIME);
			  break;
		  case LONG_PRESSED:
			  break;
		  default:
			  break;
		  }

		  mode2();
		  displayVertical(2);
		  blinkRed();
		  break;
	  case MODE_3:
		  switch (button[1])
	  	  {
	  	  case NORMAL:
	  		  break;
	  	  case PRESSED:
	  		  // increase led duration
	  		  setState2(MODE2_INCREASE);
	  		  break;
	  	  case LONG_PRESSED:
	  		  break;
	  	  default:
	  		  break;
	  	  }

		  switch (button[2])
		  {
		  case NORMAL:
			  break;
		  case PRESSED:
			  // set time duration for led
			  setState2(MODE2_SET_TIME);
			  break;
		  case LONG_PRESSED:
			  break;
		  default:
			  break;
		  }

		  mode3();
		  displayVertical(3);
		  blinkYellow();
		  break;
	  case MODE_4:
		  switch (button[1])
	  	  {
	  	  case NORMAL:
	  		  break;
	  	  case PRESSED:
	  		  // increase led duration
	  		  setState2(MODE2_INCREASE);
	  		  break;
	  	  case LONG_PRESSED:
	  		  break;
	  	  default:
	  		  break;
	  	  }

		  switch (button[2])
		  {
		  case NORMAL:
			  break;
		  case PRESSED:
			  // set time duration for led
			  setState2(MODE2_SET_TIME);
			  break;
		  case LONG_PRESSED:
			  break;
		  default:
			  break;
		  }

		  mode4();
		  displayVertical(4);
		  blinkGreen();
		  break;
	  default:
		  break;
	  }

	  update7seg();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin|H_RED_Pin
                          |H_YELLOW_Pin|H_GREEN_Pin|SEG0_Pin|SEG1_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ENV0_Pin|ENV1_Pin|ENH0_Pin|ENH1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : V_RED_Pin V_YELLOW_Pin V_GREEN_Pin H_RED_Pin
                           H_YELLOW_Pin H_GREEN_Pin SEG0_Pin SEG1_Pin
                           SEG2_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin */
  GPIO_InitStruct.Pin = V_RED_Pin|V_YELLOW_Pin|V_GREEN_Pin|H_RED_Pin
                          |H_YELLOW_Pin|H_GREEN_Pin|SEG0_Pin|SEG1_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ENV0_Pin ENV1_Pin ENH0_Pin ENH1_Pin */
  GPIO_InitStruct.Pin = ENV0_Pin|ENV1_Pin|ENH0_Pin|ENH1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON0_Pin BUTTON1_Pin BUTTON2_Pin */
  GPIO_InitStruct.Pin = BUTTON0_Pin|BUTTON1_Pin|BUTTON2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	run_timer(0);
	run_timer(1);
	run_timer(2);
	run_timer(3);
	run_timer(4);
	getKey(0);
	getKey(1);
	getKey(2);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
