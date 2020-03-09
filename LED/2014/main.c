#include	"config.h"
#include	"GPIO.h"
#include    "bsp_led.h" 

#define uchar unsigned char
typedef uchar bool;
sbit s0=P2^0;
sbit s1=P2^1;
sbit s2=P2^2;

//ģʽ0��ģʽ1�ڲ��л���־
uchar  mode0_next;
uchar  mode1_next;
uchar  mode2_next;
uchar  mode3_next;
uchar  button;
uchar mode;
uchar key;
unsigned char i ;

//ģʽʱ�������
#define MODE0_TIME    10000
#define MODE1_TIME    10000
#define MODE_0 1
#define MODE_1 2
#define MODE_2 3
#define MODE_3 4

//LED����
#define ture 1
#define false 0
#define BUTTON_PORT  P1

u16 cnt = 0;
int count0=0,count1=0;
void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;				//�ṹ����
	GPIO_InitStructure.Pin  = GPIO_Pin_All;	      // ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;				//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);	
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);		//��ʼ��
}

void Timer0() interrupt 1  //�жϷ�����
{
    TL0 = (256-100);  //��ʱ100us
    count0++;
	if (count0 % 2000==0)  mode0_next=ture;	 //0.2s
	if (count0 % 4000==0)  mode1_next=ture;	 //0.4
	if (count0 % 8000==0)  mode2_next=ture;	 //0.8
	if (count0 >8000)	   count0=0;
	  

}

void Timer1() interrupt 3  //�жϷ�����
{
    TH0 = (256-50);  //��ʱ50us
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
  TMOD |= 0x03; //T1���ò��䣬T0����Ϊ��ʽ3
  TH0 = (256-100);  //��ʱ100us
  TL0 = (256-50);      //��ʱ50u
  ET0 = 1;  //����ʱ��/������T0����жϣ�IE��
  ET1 = 1;  //����ʱ��/������T1����жϣ�IE��
  EA = 1;  //IE�������ܿ���
  TR0=1;   //������ʱ��/������T0������TCON��
  TR1=1;   //������ʱ��/������T1������TCON��
   
  while(1)
{
   if (s0  == 0)		   //����һ��L1��0.2s��˸
   {
     button=ture;        //��������
	 if	 (button==ture)
	 {
		 if (s0 == 0)
	     {
		   while (!s0);    //�ȴ������ɿ�
		   mode=MODE_0;
	     }	
	 }	
	}  					  //�������L1��0.4s��˸
   if (s1  == 0)
   {
     button=ture;        //��������
	 if	 (button==ture)
	 {
		 if (s1 == 0)
	     {
		   while (!s1);    //�ȴ������ɿ�
		   mode=MODE_1;
	     }	
	 }	
	}
   if (s2  == 0)		  //��������L1��0.8s��˸
   {
     button=ture;        //��������
	 if	 (button==ture)
	 {
		 if (s2 == 0)
	     {
		   while (!s2);    //�ȴ������ɿ�
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
