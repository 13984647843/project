#include	"config.h"
#include	"GPIO.h"
#include    "bsp_led.h" 

#define uchar unsigned char
typedef uchar bool;
sbit s0=P2^0;
sbit s1=P2^1;
sbit s2=P2^2;

//模式0、模式1内部切换标志
uchar  mode0_next;
uchar  mode1_next;
uchar  mode2_next;
uchar  mode3_next;
uchar  button;
uchar mode;
uchar key;
unsigned char i ;

//模式时间和种类
#define MODE0_TIME    10000
#define MODE1_TIME    10000
#define MODE_0 1
#define MODE_1 2
#define MODE_2 3
#define MODE_3 4

//LED控制
#define ture 1
#define false 0
#define BUTTON_PORT  P1

u16 cnt = 0;
int count0=0,count1=0;
void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;				//结构定义
	GPIO_InitStructure.Pin  = GPIO_Pin_All;	      // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
	GPIO_InitStructure.Mode = GPIO_OUT_PP;				//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);	
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);		//初始化
}

void Timer0() interrupt 1  //中断服务函数
{
    TL0 = (256-100);  //定时100us
    count0++;
	if (count0 % 2000==0)  mode0_next=ture;	 //0.2s
	if (count0 % 4000==0)  mode1_next=ture;	 //0.4
	if (count0 % 8000==0)  mode2_next=ture;	 //0.8
	if (count0 >8000)	   count0=0;
	  

}

void Timer1() interrupt 3  //中断服务函数
{
    TH0 = (256-50);  //定时50us
    count1 ++;
	if (count1 == 400) 	 //20ms
	{
	  button=ture;
	  count1=0;
	}

}

void main()
{

  GPIO_config();
  TMOD |= 0x03; //T1设置不变，T0设置为方式3
  TH0 = (256-100);  //定时100us
  TL0 = (256-50);      //定时50u
  ET0 = 1;  //允许定时器/计数器T0溢出中断（IE）
  ET1 = 1;  //允许定时器/计数器T1溢出中断（IE）
  EA = 1;  //IE，开启总开关
  TR0=1;   //开启定时器/计数器T0计数（TCON）
  TR1=1;   //开启定时器/计数器T1计数（TCON）
   
  while(1)
{
   if (s0  == 0)		   //区间一，L1以0.2s闪烁
   {
     button=ture;        //消除抖动
	 if	 (button==ture)
	 {
		 if (s0 == 0)
	     {
		   while (!s0);    //等待按键松开
		   mode=MODE_0;
	     }	
	 }	
	}  					  //区间二，L1以0.4s闪烁
   if (s1  == 0)
   {
     button=ture;        //消除抖动
	 if	 (button==ture)
	 {
		 if (s1 == 0)
	     {
		   while (!s1);    //等待按键松开
		   mode=MODE_1;
	     }	
	 }	
	}
   if (s2  == 0)		  //区间三，L1以0.8s闪烁
   {
     button=ture;        //消除抖动
	 if	 (button==ture)
	 {
		 if (s2 == 0)
	     {
		   while (!s2);    //等待按键松开
		   mode=MODE_2;
	     }	
	 }	
	}    
   if(mode==MODE_0)
   {
	   if(mode0_next==ture)
	   {
	    mode0_next=false;
	    LED_Toggle(GPIO_P0, LED0_Pin);
	   }
	}
   if(mode==MODE_1)
   {
	   if(mode1_next==ture)
	   {
	    mode1_next=false;
	    LED_Toggle(GPIO_P0, LED0_Pin);
	   }
	}
   if(mode==MODE_2)
   {
	   if(mode2_next==ture)
	   {
	    mode2_next=false;
	    LED_Toggle(GPIO_P0, LED0_Pin);
	   }
	}
  
}
}
