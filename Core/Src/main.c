/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "dht.h"
#include "stdio.h"
#include "string.h"
#include "esp.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define RXBUFFERSIZE    1                       /* 缓存大小 */
#define USART_REC_LEN   200                     /* 定义最大接收字节数 200 */

extern uint16_t g_usart_rx_sta;
extern uint8_t g_usart_rx_buf[USART_REC_LEN];
extern uint8_t g_rx_buffer[RXBUFFERSIZE];    /* HAL库使用的串口接收缓冲 */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern uint8_t Data[5];
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
  MX_USART1_UART_Init();
  MX_I2C2_Init();
  MX_TIM1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1, (uint8_t *)g_rx_buffer, RXBUFFERSIZE);
  OLED_Init();
  OLED_CLS();
  esp_init();
  //esp_init();
//**************连接阿里云*********************//
//  printf("AT+RST\r\n");
//  HAL_Delay(1000);
//   
//  printf("AT+CWMODE=1\r\n");
//  HAL_Delay(1000);
//  
//  printf("AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");
//  HAL_Delay(1000);
//  
//  printf("AT+CWJAP=\"BK\",\"123456789\"\r\n");
//  HAL_Delay(3000);
//  
//  printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"ESP8266&k27cxs90Bxp\",\"640616e1cc37022be1f47501555deb9bfffdb47d75e56808b15d2c6211b4f68a\",0,0,\"\"\r\n");
//  HAL_Delay(3000);
//  
//  printf("AT+MQTTCLIENTID=0,\"k27cxs90Bxp.ESP8266|securemode=2\\,signmethod=hmacsha256\\,timestamp=1735807505642|\"\r\n");
//  HAL_Delay(3000);
//  
//  printf("AT+MQTTCONN=0,\"iot-06z00d9ipkcx6cf.mqtt.iothub.aliyuncs.com\",1883,1\r\n");
//  HAL_Delay(3000);
///******************************************/

//  printf("AT+MQTTSUB=0,\"/k27cxs90Bxp/ESP8266/user/get\",1\r\n");
//  HAL_Delay(3000);
//  
//  printf("AT+MQTTPUB=0,\"/k27cxs90Bxp/ESP8266/user/update\",\"{\\\"LED\\\":1}\",1,0\r\n");
//  HAL_Delay(3000);
//  
//  printf("AT+MQTTPUB=0,\"/k27cxs90Bxp/ESP8266/user/update\",\"{\\\"LED\\\":0}\",1,0\r\n");
//  HAL_Delay(3000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	//HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
//	HAL_Delay(500);
	    if (g_usart_rx_sta & 0x8000)                                              
        {
			
			//HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
			if(strstr((const char*)g_usart_rx_buf,"{\"LED\":1}"))
			{
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
			}
			else if(strstr((const char*)g_usart_rx_buf,"{\"LED\":0}"))
			{
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
			}
            g_usart_rx_sta = 0;
        }
//		if (g_usart_rx_sta & 0x8000) 
//		{
//		// 提取实际的 JSON 数据部分，去掉前缀 "+MQTTSUBRECV:0,"
//			char *json_data = (char*)g_usart_rx_buf;
//			char *start = strchr(json_data, '{');  // 查找 JSON 数据的开始位置
//			if (start != NULL) 
//			{
//			// 找到 '{' 后的部分，确保我们只处理 JSON 数据
//				start++;  // 跳过 '{'
//			
//			// 打印提取的 JSON 数据进行调试
//				//printf("Extracted JSON: %s\n", start);

//			// 检查 LED 的值
//				if (strstr(start, "\"LED\":1")) 
//				{
//					HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);  // LED打开
//					//printf("LED ON\n");
//				} 
//				else if (strstr(start, "\"LED\":0")) 
//				{
//					HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);  // LED关闭
//					//printf("LED OFF\n");
//				}
//			}

//		// 清除接收状态
//		g_usart_rx_sta = 0;
//		}
	  if(DHT_Read())
	  {
		  OLED_ShowStr(50,0,"SD",2);
		  OLED_ShowNum(0,0,Data[0],3,16);
		  OLED_ShowStr(50,3,"T",2);
		  OLED_ShowNum(0,3,Data[2],3,16);
		
	  }
	  
		printf("AT+MQTTSUB=0,\"/sys/k27cxtvz9Br/mqtt_stm32/thing/service/property/set\",0\r\n");
		HAL_Delay(3000);
	
		//printf("AT+MQTTPUB=0,\"/sys/k27cxtvz9Br/mqtt_stm32/thing/event/property/post\",\"{\\\"params\\\":{\\\"temperature\\\":%d\\,\\\"Humidity\\\":%d}\\,\\\"version\\\":\\\"1.0.0\\\"}\",0,0\r\n",Data[2],Data[0]);
		//HAL_Delay(3000);
	  //HAL_UART_Transmit(&huart2,"AT+MQTTPUB=0,\"/sys/k27cxtvz9Br/mqtt_stm32/thing/event/property/post\",\"{\"params\":{\"temperature\":20\,\"Humidity\":30}\,\"version\":\"1.0.0\"}\",0,0",strlen("AT+MQTTPUB=0,\"/sys/k27cxtvz9Br/mqtt_stm32/thing/event/property/post\",\"{\"params\":{\"temperature\":20\,\"Humidity\":30}\,\"version\":\"1.0.0\"}\",0,0"),1000);
	  //HAL_Delay(2000);
	  //printf("AT+MQTTPUB=0,\"/k27cxs90Bxp/ESP8266/user/update\",\"{%d}\",1,0\r\n",Data[2]);
	  //HAL_Delay(2000);
//	  HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
//	  HAL_Delay(500);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
