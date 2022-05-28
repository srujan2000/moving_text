/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
void init_clock(void);
void init_port(void);
unsigned long reverseBits(int);
unsigned long pixels(int);
void send_Din(long,long);
void cs_high_low(void);
void enable(void);
void out_din(long);
void out_clk(long);
void out_cs(long);
void delay1(void);

#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
	long  shut_down   =  0x0000000CUL;
	long  brightness  =  0x0000000AUL;
	long  scan_limit  =  0x0000000BUL;
	long  decode_mode =  0x00000009UL;



//	long led_data1[8] = {0x000000FEUL,0x00000080UL,0x00000080UL,0x000000FEUL,0x00000080UL,0x00000080UL,0x00000080UL,0x000000FEUL};//'E'
//	long led_data2[8] = {0x000000FEUL,0x00000080UL,0x00000080UL,0x00000080UL,0x00000080UL,0x00000080UL,0x00000080UL,0x000000FEUL};//'C'
//	long led_data3[8] = {0x000000FEUL,0x00000080UL,0x00000080UL,0x000000FEUL,0x00000080UL,0x00000080UL,0x00000080UL,0x000000FEUL};//'E'
//	long led_data4[8] = {0x00000081UL,0x000000C1UL,0x000000A1UL,0x00000091UL,0x00000089UL,0x00000085UL,0x00000083UL,0x00000081UL};//'N'

	char led_data1[8] = {0xFE,0x80,0x80,0xFE,0x80,0x80,0x80,0xFE};//'E'
	char led_data2[8] = {0xFE,0x80,0x80,0x80,0x80,0x80,0x80,0xFE};//'C'
	char led_data3[8] = {0xFE,0x80,0x80,0xFE,0x80,0x80,0x80,0xFE};//'E'
	char led_data4[8] = {0x81,0xC1,0xA1,0x91,0x89,0x85,0x83,0x81};//'N'
	char led_data5[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	char led_data6[8]  =  {0x18,0x24,0x42,0x42,0x7E,0x42,0x42,0x42};//'A'
	char led_data7[8]  =  {0xFE,0x80,0x80,0x80,0x80,0x80,0x80,0xFE};//'C'
	char led_data8[8]  =  {0x18,0x24,0x42,0x42,0x7E,0x42,0x42,0x42};//'A'
	char led_data9[8]  =  {0xF8,0x84,0x84,0x84,0x84,0x84,0x84,0xF8};//'D'
	char led_data10[8] =  {0xFE,0x80,0x80,0xFE,0x80,0x80,0x80,0xFE};//'E'
	char led_data11[8] =  {0x82,0xC6,0xAA,0x92,0x82,0x82,0x82,0x82};//'M'
	char led_data12[8] =  {0x82,0x44,0x28,0x10,0x10,0x10,0x10,0x10};//'Y'
	char led_data0[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

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
  /* USER CODE BEGIN 2 */
  init_clock();
  init_port();
  out_cs(0x00000000UL);

  send_Din(scan_limit,0x00000007UL);
  send_Din(scan_limit,0x00000007UL);
  send_Din(scan_limit,0x00000007UL);
  send_Din(scan_limit,0x00000007UL);
  cs_high_low();

  send_Din(decode_mode,0x00000000UL);
  send_Din(decode_mode,0x00000000UL);
  send_Din(decode_mode,0x00000000UL);
  send_Din(decode_mode,0x00000000UL);
  cs_high_low();

  send_Din(brightness,0x00000005UL);
  send_Din(brightness,0x00000005UL);
  send_Din(brightness,0x00000005UL);
  send_Din(brightness,0x00000005UL);
  cs_high_low();

  send_Din(shut_down,0x00000001UL);
  send_Din(shut_down,0x00000001UL);
  send_Din(shut_down,0x00000001UL);
  send_Din(shut_down,0x00000001UL);
  cs_high_low();

  unsigned long val= 0,n;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  for(n=0;n<16;n++){
	    for(int shift=0;shift<9;shift++){

	      for(int k=0;k<3;k++){
	        for(char i=1;i<9;i++){
	          if(n<=0){
	          send_Din(i,led_data0[i-1]<<shift  | reverseBits((reverseBits(led_data0[i-1])<<(8-shift))&val));
	          }
	          if(n<=1){
	          send_Din(i,led_data0[i-1]<<shift | reverseBits((reverseBits(led_data0[i-1])<<(8-shift))&val));
	          }
	          if(n<=2){
	          send_Din(i,led_data0[i-1]<<shift | reverseBits((reverseBits(led_data0[i-1])<<(8-shift))&val));
	          }
	          if(n<=3){
	          send_Din(i,led_data0[i-1]<<shift | reverseBits((reverseBits(led_data1[i-1])<<(8-shift))&val));
	          }
	          if(n<=4 && n>0){
	          send_Din(i,led_data1[i-1]<<shift  | reverseBits((reverseBits(led_data2[i-1])<<(8-shift))&val));
	          }
	          if(n<=5 && n>1){
	          send_Din(i,led_data2[i-1]<<shift | reverseBits((reverseBits(led_data3[i-1])<<(8-shift))&val));
	          }
	          if(n<=6 && n>2){
	          send_Din(i,led_data3[i-1]<<shift | reverseBits((reverseBits(led_data4[i-1])<<(8-shift))&val));
	          }
	          if(n<=7 && n>3){
	          send_Din(i,led_data4[i-1]<<shift | reverseBits((reverseBits(led_data5[i-1])<<(8-shift))&val));
	          }
	          if(n<=8 && n>4){
	          send_Din(i,led_data5[i-1]<<shift | reverseBits((reverseBits(led_data6[i-1])<<(8-shift))&val));
	          }
	          if(n<=9 && n>5){
	          send_Din(i,led_data6[i-1]<<shift | reverseBits((reverseBits(led_data7[i-1])<<(8-shift))&val));
	          }
	          if(n<=10 && n>6){
	          send_Din(i,led_data7[i-1]<<shift | reverseBits((reverseBits(led_data8[i-1])<<(8-shift))&val));
	          }

	          if(n<=11 && n>7){
	          send_Din(i,led_data8[i-1]<<shift | reverseBits((reverseBits(led_data9[i-1])<<(8-shift))&val));
	          }

	           if(n<=12 && n>8){
	          send_Din(i,led_data9[i-1]<<shift | reverseBits((reverseBits(led_data10[i-1])<<(8-shift))&val));
	          }

	          if(n<=13 && n>9){
	          send_Din(i,led_data10[i-1]<<shift | reverseBits((reverseBits(led_data11[i-1])<<(8-shift))&val));
	          }

	          if(n<=14 && n>10){
	          send_Din(i,led_data11[i-1]<<shift | reverseBits((reverseBits(led_data12[i-1])<<(8-shift))&val));
	          }

	           if(n<=15 && n>11){
	          send_Din(i,led_data12[i-1]<<shift);
	          }

	          if(n>11){
	              for(int l=0;l<(n-12);l++){
	                  send_Din(i,0x00);
	              }
	            }
	          cs_high_low();
	        }
	      }
	      val = val+pixels(7-shift);
	     }
	      val = 0;
	    }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void init_clock(){
	  volatile long *clk_control;
	  clk_control =(long*)0x40023800;
	  *clk_control = 0x00000001UL; // Internal clk is selected

	  volatile long *clk_config;
	  clk_config = (long*)0x40023808;
	  *clk_config = 0x00000000UL;

	  volatile long *AHB1_clk;
	  AHB1_clk = (long*)0x40023830;
	  *AHB1_clk = 0x00000007UL;
}

void init_port(){
	volatile long *GPIOA_mode;
	 GPIOA_mode = (long*)0x40020000;
	 *GPIOA_mode = 0x00000001UL;

	 volatile long *GPIOB_mode;
	  GPIOB_mode = (long*)0x40020400;
	  *GPIOB_mode = 0x00000001UL;

	  volatile long *GPIOC_mode;
	 	GPIOC_mode = (long*)0x40020800;
	 	*GPIOC_mode = 0x00000001UL;
}

unsigned long reverseBits(int n) {
   long s=0,i=0;
    while(i<8){
        s = s*2+n%2;
        n = n/2;
        i++;
    }
    return s;
}

unsigned long pixels(int n){
    long p=1;
    if(n==0){
        return 1;
    }else{
        for(int i=1;i<=n;i++){
            p = 2*p;
        }
        return p;
    }
}

void send_Din(long addr,long data){
	 for(int i=7;i>=0;i--){
	      out_din((addr>>i)&0x00000001UL);
	      enable();
	    }

	    for(int i=7;i>=0;i--){
	      out_din((data>>i)&0x00000001UL);
	      enable();
	    }
}

void cs_high_low(){
   out_cs(0x00000001UL);
   delay1();
   out_cs(0x00000000UL);
}

void enable(){
  out_clk(0x00000001UL);
  delay1();
  out_clk(0x00000000UL);
  delay1();
}

void out_din(long data){
	volatile long *out; //PORTA
    out= (long*)0x40020014;
	*out = data;
}

void out_clk(long data){
	volatile long *out; //PORTB
	out= (long*)0x40020414;
	*out = data;
}

void out_cs(long data){
	volatile long *out; //PORTC
	out= (long*)0x40020814;
	*out = data;
}

void delay1(){
  volatile long i;
  for(i=0;i<30;i++);
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

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

/* USER CODE BEGIN 4 */

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
