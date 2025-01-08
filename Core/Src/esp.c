#include "esp.h"
#include "string.h"
#include "OLED.h"
#include "usart.h"
#include "stdio.h"


void esp_init(void)
{
////	memset(g_usart_rx_buf,0,sizeof(g_usart_rx_buf));
//	printf("AT+RST\r\n");
//	HAL_Delay(3000);

////	memset(g_usart_rx_buf,0,sizeof(g_usart_rx_buf));
//	printf("AT+CWMODE=1\r\n");
//	HAL_Delay(3000);
////	if(strcmp((const char *)g_usart_rx_buf,"OK"))
////		return 1;
//	
//	printf("AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");
//	HAL_Delay(3000);
//	
////	memset(g_usart_rx_buf,0,sizeof(g_usart_rx_buf));
////	printf("AT+CWJAP=\"BK\",\"123456789\"\r\n");
//	printf("AT+CWJAP=\"%s\",\"%s\"\r\n",WIFI,WIFIASSWORD); //连接热点
//	HAL_Delay(3000);
////	if(strcmp((const char *)g_usart_rx_buf,"OK"))
////		return 2;
//	
////	memset(g_usart_rx_buf,0,sizeof(g_usart_rx_buf));
////	printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"ESP8266&k27cxs90Bxp\",\"7fc46f43dc9954fbb2a8a76d11dd9863c0e6b40bd5ec0e672aa890ca2f65bd00\",0,0,\"\"\r\n");
//	printf("AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n","NULL",username,passwd);//用户信息配置
//	HAL_Delay(3000);
////	if(strcmp((const char *)g_usart_rx_buf,"OK"))
//	//	return 3;
//	
//	printf("AT+MQTTCLIENTID=0,\"%s\"\r\n",ClintID);
//	HAL_Delay(3000);

//	//memset(g_usart_rx_buf,0,sizeof(g_usart_rx_buf));
//	printf("AT+MQTTCONN=0,\"%s\",1883,1\r\n",Url); //连接服务器
////	printf("AT+MQTTCONN=0,\"iot-06z00d9ipkcx6cf.mqtt.iothub.aliyuncs.com\",1883,1\r\n");
//	HAL_Delay(3000);
////	if(strcmp((const char *)g_usart_rx_buf,"OK"))
////		return 4;
//	
////	memset(g_usart_rx_buf,0,sizeof(g_usart_rx_buf));
//	printf("AT+MQTTSUB=0,\"%s\",1\r\n",subtopic); //订阅消息
////	printf("AT+MQTTSUB=0,\"/k27cxs90Bxp/ESP8266/user/get\",1\r\n");
//	HAL_Delay(3000);
////	if(strcmp((const char *)g_usart_rx_buf,"OK"))
////		return 5;

////	memset(g_usart_rx_buf,0,sizeof(g_usart_rx_buf));
//	
//	printf("AT+MQTTPUB=0,\"/k27cxs90Bxp/ESP8266/user/update\",\"{\\\"LED\\\":1}\",1,0\r\n");
//	HAL_Delay(3000);

//	printf("AT+MQTTPUB=0,\"/k27cxs90Bxp/ESP8266/user/update\",\"{\\\"LED\\\":0}\",1,0\r\n");
//	HAL_Delay(3000);
//	
////	return 0;
/******************************************/
    //HAL_UART_Transmit(&huart2,"AT+RST\r\n",strlen("AT+RST\r\n"),1000);
	printf("AT+RST\r\n");
	HAL_Delay(1000);
	
	printf("AT+RST\r\n");
	HAL_Delay(1000);
	
	printf("AT+CWMODE=1\r\n");
	HAL_Delay(1000);
	
	printf("AT+CWJAP=\"BK\",\"123456789\"\r\n");
	HAL_Delay(3000);
	
	printf("AT+MQTTUSERCFG=0,1,\"k27cxtvz9Br.mqtt_stm32|securemode=2\\,signmethod=hmacsha256\\,timestamp=1736306666884|\",\"mqtt_stm32&k27cxtvz9Br\",\"44412a32a725298cf6744d45b2230cfe75e8d03b6dfbf832d094b9d2ec5607eb\",0,0,\"\"\r\n");
	HAL_Delay(3000);
	
	printf("AT+MQTTCONN=0,\"iot-06z00d9ipkcx6cf.mqtt.iothub.aliyuncs.com\",1883,0\r\n");
	HAL_Delay(3000);
	
	printf("AT+MQTTSUB=0,\"/sys/k27cxtvz9Br/mqtt_stm32/thing/service/property/set\",0\r\n");
	HAL_Delay(3000);
	
	printf("AT+MQTTPUB=0,\"/sys/k27cxtvz9Br/mqtt_stm32/thing/event/property/post\",\"{\\\"params\\\":{\\\"temperature\\\":20\\,\\\"Humidity\\\":20}\\,\\\"version\\\":\\\"1.0.0\\\"}\",0,0\r\n");
	HAL_Delay(3000);




/******************************************/

//  printf("AT+MQTTSUB=0,\"/k27cxs90Bxp/ESP8266/user/get\",1\r\n");
//  HAL_Delay(3000);
  
  //HAL_UART_Transmit(&huart2,"AT+MQTTPUB=0,\"/k27cxtvz9Br/mqtt_stm32/user/update\",\"{\\\"LED\\\":1}\",1,0\r\n",strlen("AT+MQTTPUB=0,\"/k27cxtvz9Br/mqtt_stm32/user/update\",\"{\\\"LED\\\":1}\",1,0\r\n"),1000);
  //HAL_Delay(3000);
//  
//  printf("AT+MQTTPUB=0,\"/k27cxs90Bxp/ESP8266/user/update\",\"{\\\"LED\\\":0}\",1,0\r\n");
//  HAL_Delay(3000);
}


