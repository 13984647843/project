
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/

/*************	功能说明	**************

本文件为STC15xxx系列的端口初始化程序,用户几乎可以不修改这个程序.


******************************************/

#include	"GPIO.h"


//========================================================================
// 函数: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// 描述: 初始化IO口.
// 参数: GPIOx: 结构参数,请参考timer.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0, 2012-10-22
//========================================================================
u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P5)				return 1;	//空操作
	if(GPIOx->Mode > GPIO_OUT_PP)	return 2;	//错误
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //推挽输出
	}
	return 0;	//成功
}
//=============================================================================================写
u8 GPIO_WritePin(u8 GPIO , u8 Pinx , bit Level)
 { 
	 if(GPIO > GPIO_P5)				return 1;	//??2ù×÷
	 if(Pinx > GPIO_Pin_All)	return 2;	//′í?ó
	 if(GPIO == GPIO_P0)
	  {
	   if(Level)
		  P0 &= (~Pinx);
	   else
	    P0 |= Pinx;
    }
	 if(GPIO == GPIO_P1)
	  {
	   if(Level)
		  P1 &= (~Pinx);
	   else
	    P1 |= Pinx ;
    }
		if(GPIO == GPIO_P2)
	  {
	   if(Level)
		  P2 &= (~Pinx);
	   else
	    P2 |= Pinx;
    }
		if(GPIO == GPIO_P3)
	  {
	   if(Level)
		  P3 &= (~Pinx);
	   else
	    P3 |= Pinx;
    }
		if(GPIO == GPIO_P3)
	  {
	   if(Level)
		  P4 &= (~Pinx);
	   else
	    P4 |= Pinx;
    }
		if(GPIO == GPIO_P3)
	  {
	   if(Level)
		  P5 &= (~Pinx);
	   else
	    P5 |= Pinx;
    }
		return 0;
 }
//=======================================================================
 u8 GPIO_ReadPin(u8 GPIO , u8 Pinx )
 { 
	 if(GPIO > GPIO_P5)				return 3;	//??2ù×÷
	 if(Pinx > GPIO_Pin_All)	return 2;	//′í?ó
	 if(GPIO == GPIO_P0)
	  {
      if ( P0 & Pinx != 0)
		  return 1;
	   else
	    return 0;
    }
	 if(GPIO == GPIO_P1)
	  {
      if ( P1 & Pinx != 0)
		  return 1;
	   else
	    return 0;
    }
	 if(GPIO == GPIO_P2)
	  {
      if ( P2 & Pinx != 0)
		  return 1;
	   else
	    return 0;
    }
	 if(GPIO == GPIO_P3)
	  {
      if ( P3 & Pinx != 0)
		  return 1;
	   else
	    return 0;
    }



	return 0;
 }	  

//====================================================================
u8 GPIO_TogglePin(u8 GPIO , u8 Pinx )
 { 
	 if(GPIO > GPIO_P5)				return 1;	//
	 if(Pinx > GPIO_Pin_All)	return 2;	//
	 if(GPIO == GPIO_P0)      P0 ^= Pinx;
	 if(GPIO == GPIO_P1)      P1 ^= Pinx;
	 if(GPIO == GPIO_P2)      P2 ^= Pinx;
	 if(GPIO == GPIO_P3)      P3 ^= Pinx;
	return 0;
 }
 