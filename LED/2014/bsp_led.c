#include "gpio.h"    //#include< > ���������İ�װ·���µĿ���Ѱ�ұ�׼���ļ�����#include<stdio.h>���õľ���C:\Keil\c51\INC\stdio.h���ͷ�ļ�
#include "bsp_led.h"   // #include�� �� �ȵ���ǰ����Ŀ¼��Ѱ�ҿ������Զ�����ļ������û���ٵ�IDE���õ��Զ���·����Ѱ���ļ���


void LED_On(u8 led_port,u8 led_pin )
{
  GPIO_WritePin(led_port ,led_pin , ON);
}

void LED_Off(u8 led_port,u8 led_pin)
{
  GPIO_WritePin(led_port ,led_pin , OFF);
}

void LED_Toggle(u8 led_port,u8 led_pin)
{
  GPIO_TogglePin(led_port , led_pin );
}

void LED_LeftToRight(u8 Pinx)
{
  
  if (Pinx == 0) //������Left��LED
  {
    LED_Toggle(LED_PORT, LED[0]);  
  }
  else if (Pinx >= LEDs_NUM) //��Ϩ��Right��LED
  {
    LED_Toggle(LED_PORT, LED[LEDs_NUM-1]);
  }
  else //�ȵ����ұߵ�LED����Ϩ����ߵ�
  {   
    LED_Toggle(LED_PORT, LED[Pinx]);
    Pinx--;
    LED_Toggle(LED_PORT, LED[Pinx]);    
  }
}