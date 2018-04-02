/
*********************************************************************************************************
*	                                  
*	ģ������ : LEDָʾ������ģ��
*	�ļ����� : bsp_led.c
*	��    �� : V2.0
*	˵    �� : ����LEDָʾ��
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		v0.1    2009-12-27 armfly  �������ļ���ST�̼���汾ΪV3.1.2
*		v1.0    2011-01-11 armfly  ST�̼���������V3.4.0�汾��
*       v2.0    2011-10-16 armfly  ST�̼���������V3.5.0�汾��
*	Copyright (C), 2010-2011, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "stm32f10x.h"
#include <stdio.h>

#include "bsp_led.h"

/*
	������STM32F103ZE-EK������LEDָʾ�ƿ��߷��䣺
	LED1 : PF6  �͵�ƽ����
	LED2 : PF7  �͵�ƽ����	
	LED3 : PF8  �͵�ƽ����
	LED4 : PF9  �͵�ƽ����		
*/
#define GPIO_PORT_LED1	GPIOF
#define GPIO_PORT_LED2	GPIOF
#define GPIO_PORT_LED3	GPIOF
#define GPIO_PORT_LED4	GPIOF

#define GPIO_PIN_LED1	GPIO_Pin_6
#define GPIO_PIN_LED2	GPIO_Pin_7
#define GPIO_PIN_LED3	GPIO_Pin_8
#define GPIO_PIN_LED4	GPIO_Pin_9

#define GPIO_CLK_LED1	RCC_APB2Periph_GPIOF
#define GPIO_CLK_LED2	RCC_APB2Periph_GPIOF
#define GPIO_CLK_LED3	RCC_APB2Periph_GPIOF
#define GPIO_CLK_LED4	RCC_APB2Periph_GPIOF

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitLed
*	����˵��: ��ʼ��LEDָʾ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_InitLed(void)
{FOD
	GPIO_InitTypeDef GPIO_InitStructure;

#if 1	/* ���ú궨��ķ�ʽ��ʼ��GPIO���Ա����޸�GPIO���� */
	/* ��GPIOF��ʱ�� */
	RCC_APB2PeriphClockCmd(GPIO_CLK_LED1 | GPIO_CLK_LED2 | GPIO_CLK_LED3 | GPIO_CLK_LED4, ENABLE);

	/* �������е�LEDָʾ��GPIOΪ�������ģʽ */
	/* ���ڽ�GPIO����Ϊ���ʱ��GPIO����Ĵ�����ֵȱʡ��0����˻�����LED����
		�����Ҳ�ϣ���ģ�����ڸı�GPIOΪ���ǰ�����޸�����Ĵ�����ֵΪ1 */
	GPIO_SetBits(GPIO_PORT_LED1,  GPIO_PIN_LED1);
	GPIO_SetBits(GPIO_PORT_LED2,  GPIO_PIN_LED2);
	GPIO_SetBits(GPIO_PORT_LED3,  GPIO_PIN_LED3);
	GPIO_SetBits(GPIO_PORT_LED4,  GPIO_PIN_LED4);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	

	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_LED1;
	GPIO_Init(GPIO_PORT_LED1, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_LED2;
	GPIO_Init(GPIO_PORT_LED2, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_LED3;
	GPIO_Init(GPIO_PORT_LED3, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_LED4;
	GPIO_Init(GPIO_PORT_LED4, &GPIO_InitStructure);
#else
	/* ��GPIOF��ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);

	/* �������е�LEDָʾ��GPIOΪ�������ģʽ */
	/* ���ڽ�GPIO����Ϊ���ʱ��GPIO����Ĵ�����ֵȱʡ��0����˻�����LED����
		�����Ҳ�ϣ���ģ�����ڸı�GPIOΪ���ǰ�����޸�����Ĵ�����ֵΪ1 */
	GPIO_SetBits(GPIOF,  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
#endif
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_LedOn
*	����˵��: ����ָ����LEDָʾ�ơ�
*	��    �Σ�_no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��������
*********************************************************************************************************
*/
void bsp_LedOn(uint8_t _no)
{
	_no--;
	
	if (_no == 0)
	{
		GPIO_PORT_LED1->BRR = GPIO_PIN_LED1;
	}
	else if (_no == 1)
	{
		GPIO_PORT_LED2->BRR = GPIO_PIN_LED2;
	}
	else if (_no == 2)
	{
		GPIO_PORT_LED3->BRR = GPIO_PIN_LED3;
	}
	else if (_no == 3)
	{
		GPIO_PORT_LED4->BRR = GPIO_PIN_LED4;
	}		
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_LedOff
*	����˵��: Ϩ��ָ����LEDָʾ�ơ�
*	��    �Σ�_no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��������
*********************************************************************************************************
*/
void bsp_LedOff(uint8_t _no)
{
	_no--;
	
	if (_no == 0)
	{
		GPIO_PORT_LED1->BSRR = GPIO_PIN_LED1;
	}
	else if (_no == 1)
	{
		GPIO_PORT_LED2->BSRR = GPIO_PIN_LED2;
	}
	else if (_no == 2)
	{
		GPIO_PORT_LED3->BSRR = GPIO_PIN_LED3;
	}
	else if (_no == 3)
	{
		GPIO_PORT_LED4->BSRR = GPIO_PIN_LED4;
	}		
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_LedToggle
*	����˵��: ��תָ����LEDָʾ�ơ�
*	��    �Σ�_no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��������
*********************************************************************************************************
*/
void bsp_LedToggle(uint8_t _no)
{
	_no--;
	
	if (_no == 0)
	{
		GPIO_PORT_LED1->ODR ^= GPIO_PIN_LED1;
	}
	else if (_no == 1)
	{
		GPIO_PORT_LED2->ODR ^= GPIO_PIN_LED2;
	}
	else if (_no == 2)
	{
		GPIO_PORT_LED3->ODR ^= GPIO_PIN_LED3;
	}
	else if (_no == 3)
	{
		GPIO_PORT_LED4->ODR ^= GPIO_PIN_LED4;
	}		
}

/****************************************************************************************************************************************************************************

                                                                                                                   ģ������ : ��ʱ��ģ��
	                                                                                                           �ļ����� : bsp_timer.c
*****************************************************************************************************************************************************************************

/*
*********************************************************************************************************
*	                                  
*	ģ������ : ��ʱ��ģ��
*	�ļ����� : bsp_timer.c
*	��    �� : V2.0
*	˵    �� : ����systick�жϣ�ʵ�����ɸ������ʱ��
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		v0.1    2009-12-27 armfly  �������ļ���ST�̼���汾ΪV3.1.2
*		v1.0    2011-01-11 armfly  ST�̼���������V3.4.0�汾��
*       v2.0    2011-10-16 armfly  ST�̼���������V3.5.0�汾��
*
*	Copyright (C), 2010-2011, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "stm32f10x.h"
#include <stdio.h>

#include "bsp_timer.h"
#include "bsp_button.h"

/* 
	�ڴ˶������ɸ������ʱ��ȫ�ֱ���
	ע�⣬��������__IO �� volatile����Ϊ����������жϺ���������ͬʱ�����ʣ��п�����ɱ����������Ż���
*/
#define TMR_COUNT	4		/* �����ʱ���ĸ�������1��������bsp_DelayMS()ʹ�� */

SOFT_TMR g_Tmr[TMR_COUNT];

/* ȫ������ʱ�䣬��λ10ms������uIP */
__IO int32_t g_iRunTime = 0;

static void bsp_SoftTimerDec(SOFT_TMR *_tmr);

void bsp_InitTimer(void)
{
	uint8_t i;
	
	/* �������е������ʱ�� */
	for (i = 0; i < TMR_COUNT; i++)
	{
		g_Tmr[i].count = 0;
		g_Tmr[i].flag = 0;
	}
	
	/* 
		����systic�ж�����Ϊ1ms��������systick�жϡ�
    	��������� \Libraries\CMSIS\CM3\CoreSupport\core_cm3.h 
    	
    	Systick�ж�������(\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup\arm\
    		startup_stm32f10x_hd.s �ļ��ж���Ϊ SysTick_Handler��
    	SysTick_Handler������ʵ����stm32f10x_it.c �ļ���
    	SysTick_Handler����������SysTick_ISR()�������ڱ��ļ�ĩβ��
    */	
	SysTick_Config(SystemCoreClock / 1000);
}

/*
*********************************************************************************************************
*	�� �� ��: SysTick_ISR
*	����˵��: SysTick�жϷ������ÿ��1ms����1��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
extern void TOUCH_Scan(void);
void SysTick_ISR(void)
{
	static uint8_t s_count = 0;
	uint8_t i;

	for (i = 0; i < TMR_COUNT; i++)
	{
		bsp_SoftTimerDec(&g_Tmr[i]);
	}

	g_iRunTime++;	/* ȫ������ʱ��ÿ1ms��1 */	
	if (g_iRunTime == 0x7FFFFFFF)
	{
		g_iRunTime = 0;
	}
		
	TOUCH_Scan();	/* ������ɨ����� */
	if (++s_count >= 10)
	{
		s_count = 0;



		/* 
			����Ĵ���ʵ�����а����ļ�⡣�������ÿ��10msһ�ξ����ˣ�һ����40ms���˲�����Ϳ���
			��Ч���˵���е������ɵİ���������
		*/
	//	bsp_KeyPro();		/* �ú����� bsp_button.c ��ʵ�� */
	}
	
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_SoftTimerDec
*	����˵��: ÿ��1ms�����ж�ʱ��������1�����뱻SysTick_ISR�����Ե��á�
*	��    �Σ�_tmr : ��ʱ������ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void bsp_SoftTimerDec(SOFT_TMR *_tmr)
{
	if (_tmr->flag == 0)
	{
		if (_tmr->count > 0)
		{
			/* �����ʱ����������1�����ö�ʱ�������־ */
			if (--_tmr->count == 0)
			{
				_tmr->flag = 1;
			}
		}
	}
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_DelayMS
*	����˵��: ms���ӳ٣��ӳپ���Ϊ����1ms
*	��    �Σ�n : �ӳٳ��ȣ���λ1 ms�� n Ӧ����2
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_DelayMS(uint32_t n)
{
	/* ���� n = 1 �������������� */
	if (n <= 1)
	{
		n = 2;
	}
	
	__set_PRIMASK(1);  		/* ���ж� */
	g_Tmr[0].count = n;
	g_Tmr[0].flag = 0;
	__set_PRIMASK(0);  		/* ���ж� */

	while (1)
	{
		CPU_IDLE();	/* �˴��ǿղ������û����Զ��壬��CPU����IDLE״̬���Խ��͹��ģ���ʵ��ι�� */

		/* �ȴ��ӳ�ʱ�䵽 */
		if (g_Tmr[0].flag == 1)
		{
			break;
		}
	}
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_StartTimer
*	����˵��: ����һ����ʱ���������ö�ʱ���ڡ�
*	��    �Σ�	_id     : ��ʱ��ID��ֵ��1,TMR_COUNT-1�����û���������ά����ʱ��ID���Ա��ⶨʱ��ID��ͻ��
*						  ��ʱ��ID = 0 ������bsp_DelayMS()����
*				_period : ��ʱ���ڣ���λ1ms
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_StartTimer(uint8_t _id, uint32_t _period)
{
	if (_id >= TMR_COUNT)
	{
		/* while(1); ���� */
		return;
	}

	__set_PRIMASK(1);  		/* ���ж� */
	g_Tmr[_id].count = _period;
	g_Tmr[_id].flag = 0;
	__set_PRIMASK(0);  		/* ���ж� */
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_CheckTimer
*	����˵��: ��ⶨʱ���Ƿ�ʱ
*	��    �Σ�	_id     : ��ʱ��ID��ֵ��1,TMR_COUNT-1�����û���������ά����ʱ��ID���Ա��ⶨʱ��ID��ͻ��
*						  0 ����
*				_period : ��ʱ���ڣ���λ1ms
*	�� �� ֵ: ���� 0 ��ʾ��ʱδ���� 1��ʾ��ʱ��
*********************************************************************************************************
*/
uint8_t bsp_CheckTimer(uint8_t _id)
{
	if (_id >= TMR_COUNT)
	{
		return 0;
	}

	if (g_Tmr[_id].flag == 1)
	{
		g_Tmr[_id].flag = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_GetRunTime
*	����˵��: ��ȡCPU����ʱ�䣬��λ1ms
*	��    �Σ���
*	�� �� ֵ: CPU����ʱ�䣬��λ1ms
*********************************************************************************************************
*/
int32_t bsp_GetRunTime(void)
{
	int runtime; 

	__set_PRIMASK(1);  		/* ���ж� */
	
	runtime = g_iRunTime;	/* ������Systick�жϱ���д����˹��жϽ��б��� */
		
	__set_PRIMASK(0);  		/* ���ж� */

	return runtime;
}
/****************************************************************************************************************************************************************************

                                                                                                                   ģ������ : ��������ģ��
  	                                                                                                           �ļ����� : bsp_button.c
*****************************************************************************************************************************************************************************
/*
*********************************************************************************************************
*	                                  
*	ģ������ : ��������ģ��
*	�ļ����� : bsp_button.c
*	��    �� : V2.0
*	˵    �� : ʵ�ְ����ļ�⣬��������˲����ƣ����Լ�������¼���
*				(1) ��������
*				(2) ��������
*				(3) ������
*				(4) ����ʱ�Զ�����
*				(5) ��ϼ�
*
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		v0.1    2009-12-27 armfly  �������ļ���ST�̼���汾ΪV3.1.2
*		v1.0    2011-01-11 armfly  ST�̼���������V3.4.0�汾��
*       v2.0    2011-10-16 armfly  ST�̼���������V3.5.0�汾��
*
*	Copyright (C), 2010-2011, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "stm32f10x.h"
#include <stdio.h>

#include "bsp_button.h"

static BUTTON_T s_BtnUser;		/* USER �� */
static BUTTON_T s_BtnTamper;	/* TAMPER �� */
static BUTTON_T s_BtnWakeUp;	/* WAKEUP �� */
static BUTTON_T s_BtnUp;		/* ҡ��UP�� */
static BUTTON_T s_BtnDown;		/* ҡ��DOWN�� */
static BUTTON_T s_BtnLeft;		/* ҡ��LEFT�� */
static BUTTON_T s_BtnRight;		/* ҡ��RIGHT�� */
static BUTTON_T s_BtnOk;		/* ҡ��OK�� */

static BUTTON_T s_BtnUserTamper;/* ��ϼ���USER��TAMPER�� */

static KEY_FIFO_T s_Key;		/* ����FIFO����,�ṹ�� */

static void bsp_InitButtonVar(void);
static void bsp_InitButtonHard(void);
static void bsp_DetectButton(BUTTON_T *_pBtn);

/*
	������STM32F103ZE-EK �������߷��䣺
	USER��     : PG8  (�͵�ƽ��ʾ����)
	TAMPEER��  : PC13 (�͵�ƽ��ʾ����)
	WKUP��     : PA0  (!!!�ߵ�ƽ��ʾ����)
	ҡ��UP��   : PG15 (�͵�ƽ��ʾ����)
	ҡ��DOWN�� : PD3  (�͵�ƽ��ʾ����)
	ҡ��LEFT�� : PG14 (�͵�ƽ��ʾ����)
	ҡ��RIGHT��: PG13 (�͵�ƽ��ʾ����)
	ҡ��OK��   : PG7 (�͵�ƽ��ʾ����)

	���庯���жϰ����Ƿ��£�����ֵ1 ��ʾ���£�0��ʾδ����
*/
static uint8_t IsKeyDownUser(void) 		{if (GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_8) == Bit_SET) return 0; return 1;}
static uint8_t IsKeyDownTamper(void) 	{if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == Bit_SET) return 0; return 1;}
static uint8_t IsKeyDownWakeUp(void) 	{if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == Bit_SET) return 1; return 0;}
static uint8_t IsKeyDownUp(void) 		{if (GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_15) == Bit_SET) return 0; return 1;}
static uint8_t IsKeyDownDown(void) 		{if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == Bit_SET) return 0; return 1;}
static uint8_t IsKeyDownLeft(void) 		{if (GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_14) == Bit_SET) return 0; return 1;}
static uint8_t IsKeyDownRight(void) 	{if (GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_13) == Bit_SET) return 0; return 1;}
static uint8_t IsKeyDownOk(void) 		{if (GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_7) == Bit_SET) return 0; return 1;}
static uint8_t IsKeyDownUserTamper(void) {if (IsKeyDownUser() && IsKeyDownTamper()) return 1; return 0;}	/* ��ϼ� */

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitButton
*	����˵��: ��ʼ������
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_InitButton(void)
{
	bsp_InitButtonVar();		/* ��ʼ���������� */
	bsp_InitButtonHard();		/* ��ʼ������Ӳ�� */
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_PutKey
*	����˵��: ��1����ֵѹ�밴��FIFO��������������ģ��һ��������
*	��    �Σ�_KeyCode : ��������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_PutKey(uint8_t _KeyCode)
{
	s_Key.Buf[s_Key.Write] = _KeyCode;

	if (++s_Key.Write  >= KEY_FIFO_SIZE)
	{
		s_Key.Write = 0;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_GetKey
*	����˵��: �Ӱ���FIFO��������ȡһ����ֵ��
*	��    �Σ���
*	�� �� ֵ: ��������
*********************************************************************************************************
*/
uint8_t bsp_GetKey(void)
{
	uint8_t ret;

	if (s_Key.Read == s_Key.Write)
	{
		return KEY_NONE;
	}
	else
	{
		ret = s_Key.Buf[s_Key.Read];

		if (++s_Key.Read >= KEY_FIFO_SIZE)
		{
			s_Key.Read = 0;
		}
		return ret;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_KeyState
*	����˵��: ��ȡ������״̬
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
uint8_t bsp_KeyState(uint8_t _ucKeyID)
{
	uint8_t ucState = 0;

	switch (_ucKeyID)
	{
		case KID_TAMPER:
			ucState = s_BtnTamper.State;
			break;

		case KID_WAKEUP:
			ucState = s_BtnWakeUp.State;
			break;

		case KID_USER:
			ucState = s_BtnUser.State;
			break;

		case KID_JOY_UP:
			ucState = s_BtnUp.State;
			break;

		case KID_JOY_DOWN:
			ucState = s_BtnDown.State;
			break;

		case KID_JOY_LEFT:
			ucState = s_BtnLeft.State;
			break;

		case KID_JOY_RIGHT:
			ucState = s_BtnRight.State;
			break;

		case KID_JOY_OK:
			ucState = s_BtnOk.State;
			break;
	}

	return ucState;
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitButtonHard
*	����˵��: ��ʼ������Ӳ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void bsp_InitButtonHard(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*
	������STM32F103ZE-EK �������߷��䣺
	USER��     : PG8  (�͵�ƽ��ʾ����)
	TAMPEER��  : PC13 (�͵�ƽ��ʾ����)
	WKUP��     : PA0  (!!!�ߵ�ƽ��ʾ����)
	ҡ��UP��   : PG15 (�͵�ƽ��ʾ����)
	ҡ��DOWN�� : PD3  (�͵�ƽ��ʾ����)
	ҡ��LEFT�� : PG14 (�͵�ƽ��ʾ����)
	ҡ��RIGHT��: PG13 (�͵�ƽ��ʾ����)
	ҡ��OK��   : PG7 (�͵�ƽ��ʾ����)
	*/
			
	/* ��1������GPIOA GPIOC GPIOD GPIOF GPIOG��ʱ��
	   ע�⣺����ط�����һ����ȫ��
	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC
			| RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOG, ENABLE);
	
	/* ��2�����������еİ���GPIOΪ��������ģʽ(ʵ����CPU��λ���������״̬) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	/* PA0 */
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	/* PC13 */
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOD, &GPIO_InitStructure);	/* PD3 */
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_13
					  | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOG, &GPIO_InitStructure);	/* PG7,8,13,14,15 */
}
	
/*
*********************************************************************************************************
*	�� �� ��: bsp_InitButtonVar
*	����˵��: ��ʼ����������
*	��    �Σ�strName : ���������ַ���
*			  strDate : ���̷�������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void bsp_InitButtonVar(void)
{
	/* �԰���FIFO��дָ������ */
	s_Key.Read = 0;
	s_Key.Write = 0;

	/* ��ʼ��USER����������֧�ְ��¡����𡢳��� */
	s_BtnUser.IsKeyDownFunc = IsKeyDownUser;		/* �жϰ������µĺ��� */
	s_BtnUser.FilterTime = BUTTON_FILTER_TIME;		/* �����˲�ʱ�� */
	s_BtnUser.LongTime = BUTTON_LONG_TIME;			/* ����ʱ�� */
	s_BtnUser.Count = s_BtnUser.FilterTime / 2;		/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnUser.State = 0;							/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnUser.KeyCodeDown = KEY_DOWN_USER;			/* �������µļ�ֵ���� */
	s_BtnUser.KeyCodeUp = KEY_UP_USER;				/* ��������ļ�ֵ���� */
	s_BtnUser.KeyCodeLong = KEY_LONG_USER;			/* �������������µļ�ֵ���� */
	s_BtnUser.RepeatSpeed = 0;						/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnUser.RepeatCount = 0;						/* ���������� */		

	/* ��ʼ��TAMPER����������֧�ְ��� */
	s_BtnTamper.IsKeyDownFunc = IsKeyDownTamper;	/* �жϰ������µĺ��� */
	s_BtnTamper.FilterTime = BUTTON_FILTER_TIME;	/* �����˲�ʱ�� */
	s_BtnTamper.LongTime = 0;						/* ����ʱ��, 0��ʾ����� */
	s_BtnTamper.Count = s_BtnTamper.FilterTime / 2;	/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnTamper.State = 0;							/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnTamper.KeyCodeDown = KEY_DOWN_TAMPER;		/* �������µļ�ֵ���� */
	s_BtnTamper.KeyCodeUp = KEY_UP_TAMPER;			/* ��������ļ�ֵ���� */
	s_BtnTamper.KeyCodeLong = 0;					/* �������������µļ�ֵ���� */
	s_BtnTamper.RepeatSpeed = 0;					/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnTamper.RepeatCount = 0;					/* ���������� */	

	/* ��ʼ��WAKEUP����������֧�ְ��� */
	s_BtnWakeUp.IsKeyDownFunc = IsKeyDownWakeUp;	/* �жϰ������µĺ��� */
	s_BtnWakeUp.FilterTime = BUTTON_FILTER_TIME;	/* �����˲�ʱ�� */
	s_BtnWakeUp.LongTime = 0;						/* ����ʱ�� */
	s_BtnWakeUp.Count = s_BtnWakeUp.FilterTime / 2;	/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnWakeUp.State = 0;							/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnWakeUp.KeyCodeDown = KEY_DOWN_WAKEUP;		/* �������µļ�ֵ���� */
	s_BtnWakeUp.KeyCodeUp = KEY_UP_WAKEUP;			/* ��������ļ�ֵ���룬0��ʾ����� */
	s_BtnWakeUp.KeyCodeLong = 0;					/* �������������µļ�ֵ���룬0��ʾ����� */
	s_BtnWakeUp.RepeatSpeed = 0;					/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnWakeUp.RepeatCount = 0;					/* ���������� */	

	/* ��ʼ��UP����������֧�ְ��¡�����������10ms�� */
	s_BtnUp.IsKeyDownFunc = IsKeyDownUp;			/* �жϰ������µĺ��� */
	s_BtnUp.FilterTime = BUTTON_FILTER_TIME;		/* �����˲�ʱ�� */
	s_BtnUp.LongTime = 20;							/* ����ʱ�� */
	s_BtnUp.Count = s_BtnUp.FilterTime / 2;			/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnUp.State = 0;								/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnUp.KeyCodeDown = KEY_DOWN_JOY_UP;			/* �������µļ�ֵ���� */
	s_BtnUp.KeyCodeUp = 0;							/* ��������ļ�ֵ���룬0��ʾ����� */
	s_BtnUp.KeyCodeLong = 0;						/* �������������µļ�ֵ���룬0��ʾ����� */
	s_BtnUp.RepeatSpeed = 2;						/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnUp.RepeatCount = 0;						/* ���������� */		

	/* ��ʼ��DOWN����������֧�ְ��¡�����������10ms�� */
	s_BtnDown.IsKeyDownFunc = IsKeyDownDown;		/* �жϰ������µĺ��� */
	s_BtnDown.FilterTime = BUTTON_FILTER_TIME;		/* �����˲�ʱ�� */
	s_BtnDown.LongTime = 20;							/* ����ʱ�� */
	s_BtnDown.Count = s_BtnDown.FilterTime / 2;		/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnDown.State = 0;							/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnDown.KeyCodeDown = KEY_DOWN_JOY_DOWN;		/* �������µļ�ֵ���� */
	s_BtnDown.KeyCodeUp = 0;						/* ��������ļ�ֵ���룬0��ʾ����� */
	s_BtnDown.KeyCodeLong = 0;						/* �������������µļ�ֵ���룬0��ʾ����� */
	s_BtnDown.RepeatSpeed = 2;						/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnDown.RepeatCount = 0;						/* ���������� */		

	/* ��ʼ��LEFT����������֧�ְ��� */
	s_BtnLeft.IsKeyDownFunc = IsKeyDownLeft;		/* �жϰ������µĺ��� */
	s_BtnLeft.FilterTime = BUTTON_FILTER_TIME;		/* �����˲�ʱ�� */
	s_BtnLeft.LongTime = 20;							/* ����ʱ�� */
	s_BtnLeft.Count = s_BtnLeft.FilterTime / 2;		/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnLeft.State = 0;							/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnLeft.KeyCodeDown = KEY_DOWN_JOY_LEFT;		/* �������µļ�ֵ���� */
	s_BtnLeft.KeyCodeUp = 0;						/* ��������ļ�ֵ���룬0��ʾ����� */
	s_BtnLeft.KeyCodeLong = 0;						/* �������������µļ�ֵ���룬0��ʾ����� */
	s_BtnLeft.RepeatSpeed = 2;						/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnLeft.RepeatCount = 0;						/* ���������� */	

	/* ��ʼ��RIGHT����������֧�ְ��� */
	s_BtnRight.IsKeyDownFunc = IsKeyDownRight;		/* �жϰ������µĺ��� */
	s_BtnRight.FilterTime = BUTTON_FILTER_TIME;		/* �����˲�ʱ�� */
	s_BtnRight.LongTime = 20;						/* ����ʱ�� */
	s_BtnRight.Count = s_BtnRight.FilterTime / 2;	/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnRight.State = 0;							/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnRight.KeyCodeDown = KEY_DOWN_JOY_RIGHT;	/* �������µļ�ֵ���� */
	s_BtnRight.KeyCodeUp = 0;						/* ��������ļ�ֵ���룬0��ʾ����� */
	s_BtnRight.KeyCodeLong = 0;						/* �������������µļ�ֵ���룬0��ʾ����� */
	s_BtnRight.RepeatSpeed = 2;						/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnRight.RepeatCount = 0;						/* ���������� */	

	/* ��ʼ��OK����������֧�ְ��� */
	s_BtnOk.IsKeyDownFunc = IsKeyDownOk;			/* �жϰ������µĺ��� */
	s_BtnOk.FilterTime = BUTTON_FILTER_TIME;		/* �����˲�ʱ�� */
	s_BtnOk.LongTime = 0;							/* ����ʱ�� */
	s_BtnOk.Count = s_BtnOk.FilterTime / 2;			/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnOk.State = 0;								/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnOk.KeyCodeDown = KEY_DOWN_JOY_OK;			/* �������µļ�ֵ���� */
	s_BtnOk.KeyCodeUp = KEY_UP_JOY_OK;				/* ��������ļ�ֵ���룬0��ʾ����� */
	s_BtnOk.KeyCodeLong = 0;						/* �������������µļ�ֵ���룬0��ʾ����� */
	s_BtnOk.RepeatSpeed = 0;						/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnOk.RepeatCount = 0;						/* ���������� */	

	/* ��ʼ����ϰ���������֧�ְ��� */
	s_BtnUserTamper.IsKeyDownFunc = IsKeyDownUserTamper;	/* �жϰ������µĺ��� */
	s_BtnUserTamper.FilterTime = BUTTON_FILTER_TIME;		/* �����˲�ʱ�� */
	s_BtnUserTamper.LongTime = 0;							/* ����ʱ�� */
	s_BtnUserTamper.Count = s_BtnUserTamper.FilterTime / 2;	/* ����������Ϊ�˲�ʱ���һ�� */
	s_BtnUserTamper.State = 0;								/* ����ȱʡ״̬��0Ϊδ���� */
	s_BtnUserTamper.KeyCodeDown = KEY_DOWN_USER_TAMPER;		/* �������µļ�ֵ���� */
	s_BtnUserTamper.KeyCodeUp = 0;							/* ��������ļ�ֵ���룬0��ʾ����� */
	s_BtnUserTamper.KeyCodeLong = 0;						/* �������������µļ�ֵ���룬0��ʾ����� */
	s_BtnUserTamper.RepeatSpeed = 0;						/* �����������ٶȣ�0��ʾ��֧������ */
	s_BtnUserTamper.RepeatCount = 0;						/* ���������� */
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_DetectButton
*	����˵��: ���һ��������������״̬�����뱻�����Եĵ��á�
*	��    �Σ������ṹ����ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void bsp_DetectButton(BUTTON_T *_pBtn)
{
	/* ���û�г�ʼ�������������򱨴�
	if (_pBtn->IsKeyDownFunc == 0)
	{
		printf("Fault : DetectButton(), _pBtn->IsKeyDownFunc undefine");
	}
	*/

	if (_pBtn->IsKeyDownFunc())
	{
		if (_pBtn->Count < _pBtn->FilterTime)
		{
			_pBtn->Count = _pBtn->FilterTime;
		}
		else if(_pBtn->Count < 2 * _pBtn->FilterTime)
		{
			_pBtn->Count++;
		}
		else
		{
			if (_pBtn->State == 0)
			{
				_pBtn->State = 1;

				/* ���Ͱ�ť���µ���Ϣ */
				if (_pBtn->KeyCodeDown > 0)
				{
					/* ��ֵ���밴��FIFO */
					bsp_PutKey(_pBtn->KeyCodeDown);
				}
			}

			if (_pBtn->LongTime > 0)
			{
				if (_pBtn->LongCount < _pBtn->LongTime)
				{
					/* ���Ͱ�ť�������µ���Ϣ */
					if (++_pBtn->LongCount == _pBtn->LongTime)
					{
						/* ��ֵ���밴��FIFO */
						bsp_PutKey(_pBtn->KeyCodeLong);						
					}
				}
				else
				{
					if (_pBtn->RepeatSpeed > 0)
					{
						if (++_pBtn->RepeatCount >= _pBtn->RepeatSpeed)
						{
							_pBtn->RepeatCount = 0;
							/* ��������ÿ��10ms����1������ */
							bsp_PutKey(_pBtn->KeyCodeDown);												
		
						}
					}
				}
			}
		}
	}
	else
	{
		if(_pBtn->Count > _pBtn->FilterTime)
		{
			_pBtn->Count = _pBtn->FilterTime;
		}
		else if(_pBtn->Count != 0)
		{
			_pBtn->Count--;
		}
		else
		{
			if (_pBtn->State == 1)
			{
				_pBtn->State = 0;

				/* ���Ͱ�ť�������Ϣ */
				if (_pBtn->KeyCodeUp > 0)
				{
					/* ��ֵ���밴��FIFO */
					bsp_PutKey(_pBtn->KeyCodeUp);			
				}
			}
		}

		_pBtn->LongCount = 0;
		_pBtn->RepeatCount = 0;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_KeyPro
*	����˵��: ������а�����������״̬�����뱻�����Եĵ��á�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_KeyPro(void)
{
	bsp_DetectButton(&s_BtnUser);		/* USER �� */
	bsp_DetectButton(&s_BtnTamper);		/* TAMPER �� */
	bsp_DetectButton(&s_BtnWakeUp);		/* WAKEUP �� */
	bsp_DetectButton(&s_BtnUp);			/* ҡ��UP�� */
	bsp_DetectButton(&s_BtnDown);		/* ҡ��DOWN�� */
	bsp_DetectButton(&s_BtnLeft);		/* ҡ��LEFT�� */
	bsp_DetectButton(&s_BtnRight);		/* ҡ��RIGHT�� */
	bsp_DetectButton(&s_BtnOk);			/* ҡ��OK�� */
	bsp_DetectButton(&s_BtnUserTamper);	/* ��ϼ� */
}
/****************************************************************************************************************************************************************************

                                                                                                                   ģ������ : TFTҺ����ʾ������ģ��
	                                                                                                           �ļ����� : bsp_tft_lcd.c
*****************************************************************************************************************************************************************************
/*
*********************************************************************************************************
*
*	ģ������ : TFTҺ����ʾ������ģ��
*	�ļ����� : bsp_tft_lcd.c
*	��    �� : V2.3
*	˵    �� : ����������������TFT��ʾ���ֱ���Ϊ240x400��3.0���������PWM������ڹ��ܡ�
*				֧�ֵ�LCD�ڲ�����оƬ�ͺ��У�SPFD5420A��OTM4001A��R61509V
*				����оƬ�ķ��ʵ�ַΪ:  0x60000000
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		v1.0    2011-08-21 armfly  ST�̼���汾 V3.5.0�汾��
*					a) ȡ�����ʼĴ����Ľṹ�壬ֱ�Ӷ���
*		V2.0    2011-10-16 armfly  ����R61509V������ʵ��ͼ����ʾ����
*		V2.1    2012-07-06 armfly  ����RA8875������֧��4.3����
*		V2.2    2012-07-13 armfly  �Ľ�LCD_DispStr������֧��12�����ַ�;�޸�LCD_DrawRect,�����һ����������
*		V2.3    2012-08-08 armfly  ���ײ�оƬ�Ĵ���������صĺ����ŵ��������ļ���֧��RA8875
*
*	Copyright (C), 2010-2011, ���������� www.armfly.com
*
*********************************************************************************************************
*/

/*
	������ʾ��
	TFT��������һ���12864������ʾ���Ŀ����������������������˴��ڻ�ͼ�Ļ��ƣ�������ƶ��ڻ��ƾֲ�ͼ��
	�Ƿǳ���Ч�ġ�TFT������ָ��һ����ͼ���ڣ�Ȼ�����еĶ�д�Դ�Ĳ��������������֮�ڣ����������ҪCPU��
	�ڴ��б���������Ļ���������ݡ�
*/

#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>
#include "bsp_timer.h"
#include "bsp_tft_lcd.h"
#include "LCD_SPFD5420.h"
#include "LCD_RA8875.h"
#include "fonts.h"

/* ����3����������Ҫ����ʹ����ͬʱ֧�ֲ�ͬ���� */
uint16_t g_ChipID = IC_4001;		/* ����оƬID */
uint16_t g_LcdHeight = 240;			/* ��ʾ���ֱ���-�߶� */
uint16_t g_LcdWidth = 400;			/* ��ʾ���ֱ���-��� */
uint8_t s_ucBright;					/* �������Ȳ��� */

static void LCD_CtrlLinesConfig(void);
static void LCD_FSMCConfig(void);

/*
*********************************************************************************************************
*	�� �� ��: LCD_InitHard
*	����˵��: ��ʼ��LCD
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_InitHard(void)
{
	uint16_t id;

	/* ����LCD���ƿ���GPIO */
	LCD_CtrlLinesConfig();

	/* ����FSMC�ӿڣ��������� */
	LCD_FSMCConfig();

	/* FSMC���ú������ӳٲ��ܷ��������豸  */
	bsp_DelayMS(20);

	id = SPFD5420_ReadID();  	/* ��ȡLCD����оƬID */
	if ((id == 0x5420) || (id ==  0xB509))
	{
		SPFD5420_InitHard();	/* ��ʼ��5420��4001��Ӳ�� */
		/* g_ChipID �ں����ڲ������� */
	}
	else
	{
		if (RA8875_ReadID() == 0x75)
		{
			g_ChipID = IC_8875;
			RA8875_InitHard();	/* ��ʼ��RA8875оƬ */
		}
		else
		{
			/* ���δ�ܳɹ�ʶ����ȱʡ��4001������ */
			g_ChipID = IC_4001;
			g_LcdHeight = LCD_30_HEIGHT;
			g_LcdWidth = LCD_30_WIDTH;
		}
	}

	/* ����Դ� */
	LCD_ClrScr(CL_BLACK);	/* ��ɫ */
}


/*
*********************************************************************************************************
*	�� �� ��: LCD_GetChipDescribe
*	����˵��: ��ȡLCD����оƬ���������ţ�������ʾ
*	��    �Σ�char *_str : �������ַ�������˻�����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_GetChipDescribe(char *_str)
{
	switch (g_ChipID)
	{
		case IC_5420:
			strcpy(_str, CHIP_STR_5420);
			break;

		case IC_4001:
			strcpy(_str, CHIP_STR_4001);
			break;

		case IC_61509:
			strcpy(_str, CHIP_STR_61509);
			break;

		case IC_8875:
			strcpy(_str, CHIP_STR_8875);
			break;

		default:
			strcpy(_str, "Unknow");
			break;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_GetHeight
*	����˵��: ��ȡLCD�ֱ���֮�߶�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
uint16_t LCD_GetHeight(void)
{
	return g_LcdHeight;
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_GetWidth
*	����˵��: ��ȡLCD�ֱ���֮���
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
uint16_t LCD_GetWidth(void)
{
	return g_LcdWidth;
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DispOn
*	����˵��: ����ʾ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DispOn(void)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_DispOn();
	}
	else	/* 61509, 5420, 4001 */
	{
		SPFD5420_DispOn();
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DispOff
*	����˵��: �ر���ʾ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DispOff(void)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_DispOff();
	}
	else	/* 61509, 5420, 4001 */
	{
		SPFD5420_DispOff();
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_ClrScr
*	����˵��: �����������ɫֵ����
*	��    �Σ�_usColor : ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_ClrScr(uint16_t _usColor)
{
	if (g_ChipID == IC_8875)	/* RA8875 ��֧ */
	{
		RA8875_ClrScr(_usColor);
	}
	else	/* 5420��4001��61509 ��֧ */
	{
		SPFD5420_ClrScr(_usColor);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DispStr
*	����˵��: ��LCDָ�����꣨���Ͻǣ���ʾһ���ַ���
*	��    �Σ�
*		_usX : X���꣬����3.0���������ΧΪ��0 - 399��
*		_usY : Y���꣬����3.0���������ΧΪ ��0 - 239��
*		_ptr  : �ַ���ָ��
*		_tFont : ����ṹ�壬������ɫ������ɫ(֧��͸��)��������롢���ּ��Ȳ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DispStr(uint16_t _usX, uint16_t _usY, char *_ptr, FONT_T *_tFont)
{
	uint32_t i;
	uint8_t code1;
	uint8_t code2;
	uint32_t address;
	uint8_t buf[24 * 24 / 8];	/* ���֧��24������ */
	uint8_t m, width;
	uint8_t font_width,font_height, font_bytes;
	uint16_t x, y;
	const uint8_t *pAscDot;
	const uint8_t *pHzDot;

	/* �������ṹΪ��ָ�룬��ȱʡ��16���� */
	if (_tFont->usFontCode == FC_ST_12)
	{
		font_height = 12;
		font_width = 12;
		font_bytes = 24;
		pAscDot = g_Ascii12;
		pHzDot = g_Hz12;
	}
	else
	{
		/* ȱʡ��16���� */
		font_height = 16;
		font_width = 16;
		font_bytes = 32;
		pAscDot = g_Ascii16;
		pHzDot = g_Hz16;
	}

	/* ��ʼѭ�������ַ� */
	while (*_ptr != 0)
	{
		code1 = *_ptr;	/* ��ȡ�ַ������ݣ� �����ݿ�����ascii���룬Ҳ���ܺ��ִ���ĸ��ֽ� */
		if (code1 < 0x80)
		{
			/* ��ascii�ַ������Ƶ�buf */
			memcpy(buf, &pAscDot[code1 * (font_bytes / 2)], (font_bytes / 2));
			width = font_width / 2;
		}
		else
		{
			code2 = *++_ptr;
			if (code2 == 0)
			{
				break;
			}

			/* ����16�����ֵ����ַ
				ADDRESS = [(code1-0xa1) * 94 + (code2-0xa1)] * 32
				;
			*/
			#ifdef USE_SMALL_FONT
				m = 0;
				while(1)
				{
					address = m * (font_bytes + 2);
					m++;
					if ((code1 == pHzDot[address + 0]) && (code2 == pHzDot[address + 1]))
					{
						address += 2;
						memcpy(buf, &pHzDot[address], font_bytes);
						break;
					}
					else if ((pHzDot[address + 0] == 0xFF) && (pHzDot[address + 1] == 0xFF))
					{
						/* �ֿ�������ϣ�δ�ҵ��������ȫFF */
						memset(buf, 0xFF, font_bytes);
						break;
					}
				}
			#else	/* ��ȫ�ֿ� */
				/* �˴���Ҫ�����ֿ��ļ����λ�ý����޸� */
				address = ((code1-0xa1) * 94 + (code2-0xa1)) * font_bytes + HZK16_ADDR;
				memcpy(buf, (const uint8_t *)address, font_bytes);
			#endif

				width = font_width;
		}

		y = _usY;
		/* ��ʼˢLCD */
		for (m = 0; m < font_height; m++)	/* �ַ��߶� */
		{
			x = _usX;
			for (i = 0; i < width; i++)	/* �ַ���� */
			{
				if ((buf[m * ((2 * width) / font_width) + i / 8] & (0x80 >> (i % 8 ))) != 0x00)
				{
					LCD_PutPixel(x, y, _tFont->usTextColor);	/* ����������ɫΪ����ɫ */
				}
				else
				{
					LCD_PutPixel(x, y, _tFont->usBackColor);	/* ����������ɫΪ���ֱ���ɫ */
				}

				x++;
			}
			y++;
		}

		if (_tFont->usSpace > 0)
		{
			/* ������ֵ�ɫ��_tFont->usBackColor�������ּ����ڵ���Ŀ�ȣ���ô��Ҫ������֮�����(��ʱδʵ��) */
		}
		_usX += width + _tFont->usSpace;	/* �е�ַ���� */
		_ptr++;			/* ָ����һ���ַ� */
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_PutPixel
*	����˵��: ��1������
*	��    �Σ�
*			_usX,_usY : ��������
*			_usColor  ��������ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_PutPixel(uint16_t _usX, uint16_t _usY, uint16_t _usColor)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_PutPixel(_usX, _usY, _usColor);
	}
	else
	{
		SPFD5420_PutPixel(_usX, _usY, _usColor);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_GetPixel
*	����˵��: ��ȡ1������
*	��    �Σ�
*			_usX,_usY : ��������
*			_usColor  ��������ɫ
*	�� �� ֵ: RGB��ɫֵ
*********************************************************************************************************
*/
uint16_t LCD_GetPixel(uint16_t _usX, uint16_t _usY)
{
	uint16_t usRGB;

	if (g_ChipID == IC_8875)
	{
		usRGB = RA8875_GetPixel(_usX, _usY);
	}
	else
	{
		usRGB = SPFD5420_GetPixel(_usX, _usY);
	}

	return usRGB;
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DrawLine
*	����˵��: ���� Bresenham �㷨����2��仭һ��ֱ�ߡ�
*	��    �Σ�
*			_usX1, _usY1 ����ʼ������
*			_usX2, _usY2 ����ֹ��Y����
*			_usColor     ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DrawLine(uint16_t _usX1 , uint16_t _usY1 , uint16_t _usX2 , uint16_t _usY2 , uint16_t _usColor)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_DrawLine(_usX1 , _usY1 , _usX2, _usY2 , _usColor);
	}
	else
	{
		SPFD5420_DrawLine(_usX1 , _usY1 , _usX2, _usY2 , _usColor);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DrawPoints
*	����˵��: ���� Bresenham �㷨������һ��㣬������Щ�����������������ڲ�����ʾ��
*	��    �Σ�
*			x, y     ����������
*			_usColor ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DrawPoints(uint16_t *x, uint16_t *y, uint16_t _usSize, uint16_t _usColor)
{
	uint16_t i;

	for (i = 0 ; i < _usSize - 1; i++)
	{
		LCD_DrawLine(x[i], y[i], x[i + 1], y[i + 1], _usColor);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DrawRect
*	����˵��: ����ˮƽ���õľ��Ρ�
*	��    �Σ�
*			_usX,_usY���������Ͻǵ�����
*			_usHeight �����εĸ߶�
*			_usWidth  �����εĿ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DrawRect(uint16_t _usX, uint16_t _usY, uint8_t _usHeight, uint16_t _usWidth, uint16_t _usColor)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_DrawRect(_usX, _usY, _usHeight, _usWidth, _usColor);
	}
	else
	{
		SPFD5420_DrawRect(_usX, _usY, _usHeight, _usWidth, _usColor);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DrawCircle
*	����˵��: ����һ��Բ���ʿ�Ϊ1������
*	��    �Σ�
*			_usX,_usY  ��Բ�ĵ�����
*			_usRadius  ��Բ�İ뾶
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DrawCircle(uint16_t _usX, uint16_t _usY, uint16_t _usRadius, uint16_t _usColor)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_DrawCircle(_usX, _usY, _usRadius, _usColor);
	}
	else
	{
		SPFD5420_DrawCircle(_usX, _usY, _usRadius, _usColor);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DrawBMP
*	����˵��: ��LCD����ʾһ��BMPλͼ��λͼ����ɨ����򣺴����ң����ϵ���
*	��    �Σ�
*			_usX, _usY : ͼƬ������
*			_usHeight  ��ͼƬ�߶�
*			_usWidth   ��ͼƬ���
*			_ptr       ��ͼƬ����ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DrawBMP(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_DrawBMP(_usX, _usY, _usHeight, _usWidth, _ptr);
	}
	else
	{
		SPFD5420_DrawBMP(_usX, _usY, _usHeight, _usWidth, _ptr);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DrawIcon
*	����˵��: ��LCD�ϻ���һ��ͼ�꣬�Ľ��Զ���Ϊ����
*	��    �Σ�
*			_usX, _usY : ͼƬ������
*			_usHeight  ��ͼƬ�߶�
*			_usWidth   ��ͼƬ���
*			_ptr       ��ͼƬ����ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DrawIcon(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr)
{
	const uint16_t *p;
	uint16_t usNewRGB;
	uint16_t x, y;		/* ���ڼ�¼�����ڵ�������� */

	p = _ptr;
	for (y = 0; y < _usHeight; y++)
	{
		for (x = 0; x < _usWidth; x++)
		{
			usNewRGB = *p++;	/* ��ȡͼ�����ɫֵ��ָ���1 */
			/* ��ͼ���4��ֱ���и�Ϊ���ǣ��������Ǳ���ͼ�� */
			if ((y == 0 && (x < 6 || x > _usWidth - 7)) ||
				(y == 1 && (x < 4 || x > _usWidth - 5)) ||
				(y == 2 && (x < 3 || x > _usWidth - 4)) ||
				(y == 3 && (x < 2 || x > _usWidth - 3)) ||
				(y == 4 && (x < 1 || x > _usWidth - 2)) ||
				(y == 5 && (x < 1 || x > _usWidth - 2))	||

				(y == _usHeight - 1 && (x < 6 || x > _usWidth - 7)) ||
				(y == _usHeight - 2 && (x < 4 || x > _usWidth - 5)) ||
				(y == _usHeight - 3 && (x < 3 || x > _usWidth - 4)) ||
				(y == _usHeight - 4 && (x < 2 || x > _usWidth - 3)) ||
				(y == _usHeight - 5 && (x < 1 || x > _usWidth - 2)) ||
				(y == _usHeight - 6 && (x < 1 || x > _usWidth - 2))
				)
			{
				;
			}
			else
			{
				LCD_PutPixel(x + _usX, y + _usY, usNewRGB);
			}
		}
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_DrawIconActive
*	����˵��: ��LCD�ϻ���һ������ѡ�е�ͼ��
*	��    �Σ�
*			_usX, _usY : ͼƬ������
*			_usHeight  ��ͼƬ�߶�
*			_usWidth   ��ͼƬ���
*			_ptr       ��ͼƬ����ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_DrawIconActive(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr)
{
	const uint16_t *p;
	uint16_t usNewRGB;
	uint16_t x, y;		/* ���ڼ�¼�����ڵ�������� */

	p = _ptr;
	for (y = 0; y < _usHeight; y++)
	{
		for (x = 0; x < _usWidth; x++)
		{
			usNewRGB = *p++;	/* ��ȡͼ�����ɫֵ��ָ���1 */
			if ((y == 0 && (x < 6 || x > _usWidth - 7)) ||
				(y == 1 && (x < 4 || x > _usWidth - 5)) ||
				(y == 2 && (x < 3 || x > _usWidth - 4)) ||
				(y == 3 && (x < 2 || x > _usWidth - 3)) ||
				(y == 4 && (x < 1 || x > _usWidth - 2)) ||
				(y == 5 && (x < 1 || x > _usWidth - 2))	||

				(y == _usHeight - 1 && (x < 6 || x > _usWidth - 7)) ||
				(y == _usHeight - 2 && (x < 4 || x > _usWidth - 5)) ||
				(y == _usHeight - 3 && (x < 3 || x > _usWidth - 4)) ||
				(y == _usHeight - 4 && (x < 2 || x > _usWidth - 3)) ||
				(y == _usHeight - 5 && (x < 1 || x > _usWidth - 2)) ||
				(y == _usHeight - 6 && (x < 1 || x > _usWidth - 2))
				)
			{
				;
			}
			else
			{
				/* ����ԭʼ���ص����ȣ�ʵ��ͼ�걻����ѡ�е�Ч�� */
				uint16_t R,G,B;
				uint16_t bright = 15;

				/* rrrr rggg gggb bbbb */
				R = (usNewRGB & 0xF800) >> 11;
				G = (usNewRGB & 0x07E0) >> 5;
				B =  usNewRGB & 0x001F;
				if (R > bright)
				{
					R -= bright;
				}
				else
				{
					R = 0;
				}
				if (G > 2 * bright)
				{
					G -= 2 * bright;
				}
				else
				{
					G = 0;
				}
				if (B > bright)
				{
					B -= bright;
				}
				else
				{
					B = 0;
				}

				LCD_PutPixel(_usX + x, _usY + y, (R << 11) + (G << 5) + B);
			}
		}
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_CtrlLinesConfig
*	����˵��: ����LCD���ƿ��ߣ�FSMC�ܽ�����Ϊ���ù���
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void LCD_CtrlLinesConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);

	/* ʹ�� FSMC, GPIOD, GPIOE �� AFIO ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE |
	                     RCC_APB2Periph_AFIO, ENABLE);

	/* ���� PD.00(D2), PD.01(D3), PD.04(NOE), PD.05(NWE), PD.08(D13), PD.09(D14),
	 PD.10(D15), PD.14(D0), PD.15(D1) Ϊ����������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
	                            GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 |
	                            GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* ���� PE.07(D4), PE.08(D5), PE.09(D6), PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10),
	 PE.14(D11), PE.15(D12) Ϊ����������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 |
	                            GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 |
	                            GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* ���� PD.13(A18 (RS))  Ϊ����������� ,��ΪA16*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* ���� PD.7(NE1 (LCD/CS)) Ϊ����������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_FSMCConfig
*	����˵��: ����FSMC���ڷ���ʱ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void LCD_FSMCConfig(void)
{
	FSMC_NORSRAMInitTypeDef  init;
	FSMC_NORSRAMTimingInitTypeDef  timing;

	/*-- FSMC Configuration ------------------------------------------------------*/
	/*----------------------- SRAM Bank 4 ----------------------------------------*/
	/* FSMC_Bank1_NORSRAM4 configuration */
	timing.FSMC_AddressSetupTime = 1;
	timing.FSMC_AddressHoldTime = 0;
	timing.FSMC_DataSetupTime = 2;
	timing.FSMC_BusTurnAroundDuration = 0;
	timing.FSMC_CLKDivision = 0;
	timing.FSMC_DataLatency = 0;
	timing.FSMC_AccessMode = FSMC_AccessMode_A;

	/*
	 LCD configured as follow:
	    - Data/Address MUX = Disable
	    - Memory Type = SRAM
	    - Data Width = 16bit
	    - Write Operation = Enable
	    - Extended Mode = Enable
	    - Asynchronous Wait = Disable
	*/
	init.FSMC_Bank = FSMC_Bank1_NORSRAM1;
	init.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	init.FSMC_MemoryType = FSMC_MemoryType_SRAM;
	init.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
	init.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
	init.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;	/* ע��ɿ��������Ա */
	init.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	init.FSMC_WrapMode = FSMC_WrapMode_Disable;
	init.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
	init.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
	init.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
	init.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
	init.FSMC_WriteBurst = FSMC_WriteBurst_Disable;

	init.FSMC_ReadWriteTimingStruct = &timing;
	init.FSMC_WriteTimingStruct = &timing;

	FSMC_NORSRAMInit(&init);

	/* - BANK 3 (of NOR/SRAM Bank 1~4) is enabled */
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_SetBackLight
*	����˵��: ��ʼ������LCD�������GPIO,����ΪPWMģʽ��
*			���رձ���ʱ����CPU IO����Ϊ��������ģʽ���Ƽ�����Ϊ������������������͵�ƽ)����TIM3�ر� ʡ��
*	��    �Σ�_bright ���ȣ�0����255������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_SetBackLight(uint8_t _bright)
{
	s_ucBright =  _bright;	/* ���汳��ֵ */

	if (g_ChipID == IC_8875)
	{
		RA8875_SetBackLight(_bright);
	}
	else
	{
		SPFD5420_SetBackLight(_bright);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_GetBackLight
*	����˵��: ��ñ������Ȳ���
*	��    �Σ���
*	�� �� ֵ: �������Ȳ���
*********************************************************************************************************
*/
uint8_t LCD_GetBackLight(void)
{
	return s_ucBright;
}

/****************************************************************************************************************************************************************************

	                                                                                      ģ������ : TFTҺ����ʾ������ģ��
	                                                                                      �ļ����� : LCD_tft_lcd.h
*****************************************************************************************************************************************************************************
/*
*********************************************************************************************************
*
*	ģ������ : TFTҺ����ʾ������ģ��
*	�ļ����� : LCD_tft_lcd.h
*	��    �� : V2.0
*	˵    �� : ͷ�ļ�
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		v1.0    2011-08-21 armfly  ST�̼���汾 V3.5.0�汾��
*		v2.0    2011-10-16 armfly  ST�̼���汾 V3.5.0�汾���淶�����ӿڣ��Ż��ڲ��ṹ
*
*	Copyright (C), 2010-2011, ���������� www.armfly.com
*
*********************************************************************************************************
*/


#ifndef _BSP_TFT_LCD_H
#define _BSP_TFT_LCD_H

#include "stm32f10x.h"


/* ����LCD��ʾ����ķֱ��� */
#define LCD_30_HEIGHT	240		/* 3.0����� �߶ȣ���λ������ */
#define LCD_30_WIDTH	400		/* 3.0����� ��ȣ���λ������ */

#define LCD_43_HEIGHT	272		/* 4.3����� �߶ȣ���λ������ */
#define LCD_43_WIDTH	480		/* 4.3����� ��ȣ���λ������ */

#define LCD_70_HEIGHT	480		/* 7.0����� �߶ȣ���λ������ */
#define LCD_70_WIDTH	800		/* 7.0����� ��ȣ���λ������ */

/* ֧�ֵ�����оƬID */
enum
{
	IC_5420		= 0x5420,
	IC_4001		= 0x4001,
	IC_61509 	= 0xB509,
	IC_8875 	= 0x0075
};

#define CHIP_STR_5420	"SPFD5420A"
#define CHIP_STR_4001	"OTM4001A"
#define CHIP_STR_61509	"R61509V"
#define CHIP_STR_8875	"RA8875"

/* LCD ��ɫ���룬CL_��Color�ļ�д */
enum
{
	CL_WHITE        = 0xFFFF,	/* ��ɫ */
	CL_BLACK        = 0x0000,	/* ��ɫ */
	CL_GREY         = 0xF7DE,	/* ��ɫ */
	CL_BLUE         = 0x001F,	/* ��ɫ */
	CL_BLUE2        = 0x051F,	/* ǳ��ɫ */
	CL_RED          = 0xF800,	/* ��ɫ */
	CL_MAGENTA      = 0xF81F,	/* ����ɫ�����ɫ */
	CL_GREEN        = 0x07E0,	/* ��ɫ */
	CL_CYAN         = 0x7FFF,	/* ����ɫ����ɫ */
	CL_YELLOW       = 0xFFE0,	/* ��ɫ */
	CL_MASK			= 0x9999	/* ��ɫ���룬�������ֱ���͸�� */
};

/* ������� */

/* ������� */
enum
{
	FC_ST_16 = 0,		/* ����15x16���� ����x�ߣ� */
	FC_ST_12 = 1		/* ����12x12���� ����x�ߣ� */
};

/* �������Խṹ, ����LCD_DispStr() */
typedef struct
{
	uint16_t usFontCode;	/* ������� 0 ��ʾ16���� */
	uint16_t usTextColor;	/* ������ɫ */
	uint16_t usBackColor;	/* ���ֱ�����ɫ��͸�� */
	uint16_t usSpace;		/* ���ּ�࣬��λ = ���� */
}FONT_T;

/* ��������� */
#define BRIGHT_MAX		255
#define BRIGHT_MIN		0
#define BRIGHT_DEFAULT	200
#define BRIGHT_STEP		5

/* �ɹ��ⲿģ����õĺ��� */
void LCD_InitHard(void);
void LCD_GetChipDescribe(char *_str);
uint16_t LCD_GetHeight(void);
uint16_t LCD_GetWidth(void);
void LCD_DispOn(void);
void LCD_DispOff(void);
void LCD_ClrScr(uint16_t _usColor);
void LCD_DispStr(uint16_t _usX, uint16_t _usY, char *_ptr, FONT_T *_tFont);
void LCD_PutPixel(uint16_t _usX, uint16_t _usY, uint16_t _usColor);
uint16_t LCD_GetPixel(uint16_t _usX, uint16_t _usY);
void LCD_DrawLine(uint16_t _usX1 , uint16_t _usY1 , uint16_t _usX2 , uint16_t _usY2 , uint16_t _usColor);
void LCD_DrawPoints(uint16_t *x, uint16_t *y, uint16_t _usSize, uint16_t _usColor);
void LCD_DrawRect(uint16_t _usX, uint16_t _usY, uint8_t _usHeight, uint16_t _usWidth, uint16_t _usColor);
void LCD_DrawCircle(uint16_t _usX, uint16_t _usY, uint16_t _usRadius, uint16_t _usColor);
void LCD_DrawBMP(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr);
void LCD_DrawIcon(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr);
void LCD_DrawIconActive(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr);
void LCD_SetBackLight(uint8_t _bright);
uint8_t LCD_GetBackLight(void);

/* ����3����������Ҫ����ʹ����ͬʱ֧�ֲ�ͬ���� */
extern uint16_t g_ChipID;			/* ����оƬID */
extern uint16_t g_LcdHeight;		/* ��ʾ���ֱ���-�߶� */
extern uint16_t g_LcdWidth;			/* ��ʾ���ֱ���-��� */

#endif
/****************************************************************************************************************************************************************************

	                                                                                      	ģ������ : ����ʽ����������ģ��
	                                                                                        �ļ����� : bsp_touch.h
*****************************************************************************************************************************************************************************

/*
*********************************************************************************************************
*
*	ģ������ : ����ʽ����������ģ��
*	�ļ����� : bsp_touch.c
*	��    �� : V1.0
*	˵    �� : ����TS2046оƬ �� RA8875���ô���
*	�޸ļ�¼ :
*		�汾��  ����        ����    ˵��
*       v1.0    2012-07-06 armfly  ST�̼���V3.5.0�汾��
*
*	Copyright (C), 2010-2012, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "stm32f10x.h"
#include <stdio.h>
#include <math.h>

#include "bsp_touch.h"
#include "bsp_tft_lcd.h"
#include "LCD_RA8875.h"
#include "bsp_timer.h"

/*
��1��������STM32������ + 3.0����ʾģ�飬 ��ʾģ���ϵĴ���оƬΪ TSC2046�������оƬ
	PG11  --> TP_CS
	PB5   --> TP_BUSY
	PA5   --> TP_SCK
	PA6   --> TP_MISO
	PA7   --> TP_MOSI
	PC5   --> TP_PEN_INT

��2��������STM32������ + 4.3���7����ʾģ�飨����RA8875оƬ)
	RA8875���ô������ӿڣ����ֱ��ͨ��FSMC����RA8875��ؼĴ������ɡ�


	������δʹ�ô����жϹ��ܡ���1ms���ڵ� Systick��ʱ�жϷ�������жԴ���ADCֵ���в�����
	�˲����������ʰ��³���40ms�󣬿�ʼ�ɼ�ADCֵ��ÿ1ms�ɼ�1�Σ������ɼ�10�Σ���Ȼ���
	��10�������������򣬶���2ͷ�����������м�һ������������Ͳ�����ƽ��ֵ��

	����2��У׼������У׼�󱣴�2��У׼���ADCֵ��ʵ�ʹ���ʱ������2��ֱ�߷��̼�����Ļ���ꡣ
	У׼�����б���ӿڣ���������Ҫ������ʾ��δ�����湦�ܡ�
	��ҿ����Լ��޸�  TOUCH_SaveParam() �� TOUCH_LoadParam() ��������ʵ�ֱ��湦�ܡ�

*/

/* TSC2046 Ƭѡ */
#define TSC2046_CS_1()	GPIOG->BSRR = 	GPIO_Pin_11
#define TSC2046_CS_0()	GPIOG->BRR  = 	GPIO_Pin_11

/* TSC2046 �ڲ�ADCͨ���� */
#define ADC_CH_X	1		/* Xͨ��������Xλ�� */
#define ADC_CH_Y	5		/* Yͨ��������Yλ�� */

#define SAMPLE_COUNT	10	/* ÿ�������ɼ����ٸ����� */

/*
������У׼�������Ļ�����Ľǵ�ƫ������
��1���� �� x1 = CALIB_OFFSET, y1 = CALIB_OFFSET
��2���� �� x2 = LCD_GetWidth() - CALIB_OFFSET, y2 = LCD_GetHeight() - CALIB_OFFSET
*/
#define CALIB_OFFSET	20
#define TP_X1	CALIB_OFFSET
#define TP_Y1	CALIB_OFFSET
#define TP_X2	(LCD_GetWidth() - CALIB_OFFSET)
#define TP_Y2	(LCD_GetHeight() - CALIB_OFFSET)

/* ��ЧADCֵ���ж�����. ̫�ӽ�ADC�ٽ�ֵ��������Ϊ��Ч */
#define ADC_VALID_OFFSET	2

//#define WaitTPReady() while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5))
#define WaitTPReady() {}

/* ����ģ���õ���ȫ�ֱ��� */
TOUCH_T g_tTP;

static void TSC2046_InitHard(void);
static uint16_t TSC2046_ReadAdc(uint8_t _ucCh);
static uint8_t	TOUCH_PressValid(uint16_t _usX, uint16_t _usY);
static uint16_t TOUCH_DataFilter(uint16_t *_pBuf, uint8_t _ucCount);
static void TOUCH_LoadParam(void);
static void TOUCH_SaveParam(void);
static int32_t CalTwoPoint(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x);
static int16_t TOUCH_TransX(uint16_t _usAdcX, uint16_t _usAdcY);
static int16_t TOUCH_TransY(uint16_t _usAdcX, uint16_t _usAdcY);

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitTouch
*	����˵��: ����STM32�ʹ�����صĿ��ߣ�ʹ��Ӳ��SPI1, Ƭѡ���������
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void TOUCH_InitHard(void)
{
	if (g_ChipID == IC_8875)
	{
		RA8875_TouchInit();

		g_tTP.usMaxAdc = 1023;	/* 10λADC */
	}
	else
	{
		TSC2046_InitHard();

		g_tTP.usMaxAdc = 4095;	/* 12λADC */
	}

	TOUCH_LoadParam();	/* ��ȡУ׼���� */

	g_tTP.Enable = 1;
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_ReadAdcX
*	����˵��: ��ô�����X����ADC����ֵ�� �ѽ����˲�����
*	��    �Σ���
*	�� �� ֵ: X ����ADCֵ
*********************************************************************************************************
*/
uint16_t TOUCH_ReadAdcX(void)
{
	uint16_t usAdc;

	__set_PRIMASK(1);  		/* ���ж� */
	usAdc = g_tTP.usAdcNowX;
	__set_PRIMASK(0);  		/* ���ж� */

	return usAdc;
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_ReadAdcY
*	����˵��: ��ô�����Y����ADC����ֵ�� �ѽ����˲�����
*	��    �Σ���
*	�� �� ֵ: Y ����ֵ������ֵ
*********************************************************************************************************
*/
uint16_t TOUCH_ReadAdcY(void)
{
	uint16_t usAdc;

	__set_PRIMASK(1);  		/* ���ж� */
	usAdc = g_tTP.usAdcNowY;
	__set_PRIMASK(0);  		/* ���ж� */

	return usAdc;
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_PutKey
*	����˵��: ��1������������ֵѹ�봥��FIFO��������������ģ��һ��������
*	��    ��: _usX, _usY ����ֵ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void TOUCH_PutKey(uint8_t _ucEvent, uint16_t _usX, uint16_t _usY)
{
	g_tTP.Event[g_tTP.Write] = _ucEvent;
	g_tTP.XBuf[g_tTP.Write] = TOUCH_TransX(_usX, _usY);
	g_tTP.YBuf[g_tTP.Write] = TOUCH_TransY(_usX, _usY);

	if (++g_tTP.Write  >= TOUCH_FIFO_SIZE)
	{
		g_tTP.Write = 0;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_GetKey
*	����˵��: �Ӵ���FIFO��������ȡһ������ֵ��
*	��    �Σ���
*	�� �� ֵ: 1��ʾ��δ���������
*********************************************************************************************************
*/
uint8_t TOUCH_GetKey(int16_t *_pX, int16_t *_pY)
{
	uint8_t ret;

	if (g_tTP.Read == g_tTP.Write)
	{
		return TOUCH_NONE;
	}
	else
	{
		ret = g_tTP.Event[g_tTP.Read];
		*_pX = g_tTP.XBuf[g_tTP.Read];
		*_pY = g_tTP.YBuf[g_tTP.Read];

		if (++g_tTP.Read >= TOUCH_FIFO_SIZE)
		{
			g_tTP.Read = 0;
		}
		return ret;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_InRect
*	����˵��: �жϵ�ǰ�����Ƿ�λ�ھ��ο���
*	��    �Σ�_usX, _usY: ��������
*			_usRectX,_usRectY: �������
*			_usRectH��_usRectW : ���θ߶ȺͿ��
*	�� �� ֵ: 1 ��ʾ�ڷ�Χ��
*********************************************************************************************************
*/
uint8_t TOUCH_InRect(uint16_t _usX, uint16_t _usY,
	uint16_t _usRectX, uint16_t _usRectY, uint16_t _usRectH, uint16_t _usRectW)
{
	if ((_usX > _usRectX) && (_usX < _usRectX + _usRectW)
		&& (_usY > _usRectY) && (_usY < _usRectY + _usRectH))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_Scan
*	����˵��: �������¼������򡣸ú����������Ե��ã�ÿms����1��. �� bsp_Timer.c
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void TOUCH_Scan(void)
{
	uint16_t usAdcX;
	uint16_t usAdcY;
	static uint16_t s_usXBuf[SAMPLE_COUNT];
	static uint16_t s_usYBuf[SAMPLE_COUNT];
	static uint8_t s_ucPos = 0;
	static uint8_t s_count = 0;
	static uint8_t s_down = 0;

	if (g_tTP.Enable == 0)
	{
		return;
	}

	/* ���ԭʼ��ADCֵ��δ�˲� */
	if (g_ChipID == IC_8875)
	{
		/* ������������ڷ���RA8875,�������δ����ɼ�������Ӱ����ʾ */
		if (RA8875_IsBusy())
		{
			return;
		}

		usAdcX = RA8875_TouchReadX();
		usAdcY = RA8875_TouchReadY();
	}
	else
	{
		usAdcX = TSC2046_ReadAdc(ADC_CH_X);
		usAdcY = TSC2046_ReadAdc(ADC_CH_Y);
	}

	if (TOUCH_PressValid(usAdcX, usAdcY))
	{
		/* ��ѹ40ms֮��ſ�ʼ�ɼ����� */
		if (s_count >= 40)
		{
			s_usXBuf[s_ucPos] = usAdcX;
			s_usYBuf[s_ucPos] = usAdcY;

			/* �ɼ�10ms���ݽ����˲� */
			if (++s_ucPos >= SAMPLE_COUNT)
			{
				s_ucPos = 0;

			   	/* ��ADC����ֵ��������˲� */
				g_tTP.usAdcNowX = TOUCH_DataFilter(s_usXBuf, SAMPLE_COUNT);
				g_tTP.usAdcNowY = TOUCH_DataFilter(s_usYBuf, SAMPLE_COUNT);

				if (s_down == 0)
				{
					s_down = 1;
					/* ���������¼� */
					TOUCH_PutKey(TOUCH_DOWN, g_tTP.usAdcNowX, g_tTP.usAdcNowY);
				}
				else
				{
					/* �����ƶ��¼� */
					TOUCH_PutKey(TOUCH_MOVE, g_tTP.usAdcNowX, g_tTP.usAdcNowY);
				}
			}
		}
		else
		{
			s_count++;
		}
	}
	else
	{
		if (s_count > 0)
		{
			if (--s_count == 0)
			{
				/* �����ͷ��¼� */
				TOUCH_PutKey(TOUCH_RELEASE, g_tTP.usAdcNowX, g_tTP.usAdcNowY);

				g_tTP.usAdcNowX = 0;
				g_tTP.usAdcNowY = 0;

				s_count = 0;
				s_down = 0;
			}
		}
		s_ucPos = 0;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: CalTwoPoint
*	����˵��: ����2��ֱ�߷��̣�����Yֵ
*	��    �Σ�2����������x������
*	�� �� ֵ: x��Ӧ��yֵ
*********************************************************************************************************
*/
static int32_t CalTwoPoint(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x)
{
	return y1 + ((int32_t)(y2 - y1) * (x - x1)) / (x2 - x1);
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_TransX
*	����˵��: ������ADCֵת��Ϊ��������
*	��    �Σ���
*	�� �� ֵ: X ����ֵ������ֵ
*********************************************************************************************************
*/
static int16_t TOUCH_TransX(uint16_t _usAdcX, uint16_t _usAdcY)
{
	uint16_t x;
	int32_t y;

	if (g_tTP.XYChange == 0)
	{
		x = _usAdcX;
		if (x == 0)
		{
			y = 0;
		}
		else
		{
			y = CalTwoPoint(g_tTP.usAdcX1, TP_X1, g_tTP.usAdcX2, TP_X2, x);
		}
	}
	else
	{
		x = _usAdcY;
		if (x == 0)
		{
			y = 0;
		}
		else
		{
			y = CalTwoPoint(g_tTP.usAdcY1, TP_X1, g_tTP.usAdcY2, TP_X2, x);
		}
	}
	return y;
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_TransY
*	����˵��: ������ADCֵת��Ϊ��������
*	��    �Σ���
*	�� �� ֵ: Y ����ֵ������ֵ
*********************************************************************************************************
*/
static int16_t TOUCH_TransY(uint16_t _usAdcX, uint16_t _usAdcY)
{
	int32_t x;
	int32_t y;

	if (g_tTP.XYChange == 0)
	{
		x = _usAdcY;
		if (x == 0)
		{
			y = 0;
		}
		else
		{
			y = CalTwoPoint(g_tTP.usAdcY1, TP_Y1, g_tTP.usAdcY2, TP_Y2, x);
		}
	}
	else
	{
		x = _usAdcX;
		if (x == 0)
		{
			y = 0;
		}
		else
		{
			y = CalTwoPoint(g_tTP.usAdcX1, TP_Y1, g_tTP.usAdcX2, TP_Y2, x);
		}
	}
	return y;
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_GetX
*	����˵��: ��õ�ǰ�ĵĴ�������X
*	��    �Σ���
*	�� �� ֵ: X ����ֵ������ֵ
*********************************************************************************************************
*/
int16_t TOUCH_GetX(void)
{
	return TOUCH_TransX(TOUCH_ReadAdcX(), TOUCH_ReadAdcY());
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_GetY
*	����˵��: ��õ�ǰ�ĵĴ�������Y
*	��    �Σ���
*	�� �� ֵ: Y ����ֵ������ֵ
*********************************************************************************************************
*/
int16_t TOUCH_GetY(void)
{
	return TOUCH_TransY(TOUCH_ReadAdcX(), TOUCH_ReadAdcY());
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitTouch
*	����˵��: ����STM32�ʹ�����صĿ��ߣ�ʹ��Ӳ��SPI1, Ƭѡ���������
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void TSC2046_InitHard(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	SPI_InitTypeDef   SPI_InitStructure;

	/* ����GPIOʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
		RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOG, ENABLE);

	/* ���� SPI1 ����ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);

	/* ���� PA5��PA6��PA7 Ϊ����������������� SCK, MISO and MOSI */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	/* ���� PG11 ��Ϊ������������� TP_CS  */
	TSC2046_CS_1();
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOG,&GPIO_InitStructure);

	/* ���� PB5 ����Ϊ�������룬���� TP_BUSY */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* ���� PC5 Ϊ��������ģʽ�����ڴ����ж� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* �����������壬SPI1�ʹ���Flash����(PB2����Ƭѡ)����Ҫ��PB2����Ϊ�� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	//�������
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_2);

	/* ���� SPI1����ģʽ */
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft; 		/* �������Ƭѡ */
	/*
		SPI_BaudRatePrescaler_64 ��ӦSCKʱ��Ƶ��Լ1M
		TSC2046 ��SCKʱ�ӵ�Ҫ�󣬸ߵ�ƽ�͵͵�ƽ��С200ns������400ns��Ҳ����2.5M

		ʾ����ʵ��Ƶ��
		SPI_BaudRatePrescaler_64 ʱ��SCKʱ��Ƶ��Լ 1.116M
		SPI_BaudRatePrescaler_32 ʱ��SCKʱ��Ƶ���� 2.232M
	*/
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1,&SPI_InitStructure);

	/* ʹ�� SPI1 */
	SPI_Cmd(SPI1,ENABLE);
}

/*
*********************************************************************************************************
*	�� �� ��: SPI_ShiftByte
*	����˵��: ��SPI���߷���һ���ֽڣ�ͬʱ���ؽ��յ����ֽ�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static uint8_t SPI_ShiftByte(uint8_t _ucByte)
{
	uint8_t ucRxByte;

	/* �ȴ����ͻ������� */
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

	/* ����һ���ֽ� */
	SPI_I2S_SendData(SPI1, _ucByte);

	/* �ȴ����ݽ������ */
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

	/* ��ȡ���յ������� */
	ucRxByte = SPI_I2S_ReceiveData(SPI1);

	/* ���ض��������� */
	return ucRxByte;
}

/*
*********************************************************************************************************
*	�� �� ��: SpiDelay
*	����˵��: ��SPI���߷���һ���ֽڣ�ͬʱ���ؽ��յ����ֽ�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SpiDelay(uint32_t DelayCnt)
{
	uint32_t i;

	for(i=0;i<DelayCnt;i++);
}

/*
*********************************************************************************************************
*	�� �� ��: TSC2046_ReadAdc
*	����˵��: ѡ��һ��ģ��ͨ��������ADC��������ADC�������
*	��    �Σ�_ucCh = 0 ��ʾXͨ���� 1��ʾYͨ��
*	�� �� ֵ: 12λADCֵ
*********************************************************************************************************
*/
static uint16_t TSC2046_ReadAdc(uint8_t _ucCh)
{
	uint16_t usAdc;

	TSC2046_CS_0();		/* ʹ��TS2046��Ƭѡ */

	/*
		TSC2046 �����֣�8Bit��
		Bit7   = S     ��ʼλ��������1
		Bit6:4 = A2-A0 ģ������ͨ��ѡ��A2-A0; ����6��ͨ����
		Bit3   = MODE  ADCλ��ѡ��0 ��ʾ12Bit;1��ʾ8Bit
		Bit2   = SER/DFR ģ��������ʽ��  1��ʾ�������룻0��ʾ�������
		Bit1:0 = PD1-PD0 ����ģʽѡ��λ
	*/
	SPI_ShiftByte((1 << 7) | (_ucCh << 4));			/* ѡ��ͨ��1, ����Xλ�� */

	/* ��ADC���, 12λADCֵ�ĸ�λ�ȴ���ǰ12bit��Ч�����4bit��0 */
	usAdc = SPI_ShiftByte(0x00);		/* ���͵�0x00����Ϊ����ֵ�������� */
	usAdc <<= 8;
	usAdc += SPI_ShiftByte(0x00);		/* ���12λ��ADC����ֵ */

	usAdc >>= 3;						/* ����3λ������12λ��Ч���� */

	TSC2046_CS_1();					/* ����Ƭѡ */

	return (usAdc);
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_DataFilter
*	����˵��: �Բ������ݽ����˲�
*	��    �Σ���
*	�� �� ֵ: X ����ֵ������ֵ
*********************************************************************************************************
*/
static uint16_t TOUCH_DataFilter(uint16_t *_pBuf, uint8_t _ucCount)
{
	uint8_t flag;
	uint8_t i;
	uint16_t usTemp;
	uint32_t uiSum;

	/* �������� */
    do
	{
		flag = 0;
		for (i = 0; i < _ucCount - 1; i++)
		{
			if (_pBuf[i] > _pBuf[i+1])
			{
				usTemp = _pBuf[i + 1];
				_pBuf[i+1] = _pBuf[i];
				_pBuf[i] = usTemp;
				flag = 1;
			}
		}
	}while(flag);

	uiSum = 0;
	for (i = 0; i < _ucCount / 3; i++)
	{
		uiSum += _pBuf[_ucCount / 3 + i];
	}
	usTemp = uiSum / (_ucCount / 3);
	return usTemp;
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_DispPoint1
*	����˵��: ��ʾ��1��У׼��
*	��    �Σ�_ucIndex = 0 : ��ʾ��1���㣻 _ucIndex = 1 ��ʾ��2����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void TOUCH_DispPoint(uint8_t _ucIndex)
{
	FONT_T tFont16;			/* ����һ������ṹ���������������������� */

	/* ����������� */
	{
		tFont16.usFontCode = FC_ST_16;	/* ������� 16���� */
		tFont16.usTextColor = CL_WHITE;		/* ������ɫ 0 �� 1 */
		tFont16.usBackColor = CL_BLUE;	/* ���ֱ�����ɫ */
		tFont16.usSpace = 0;			/* ���ּ�࣬��λ = ���� */
	}

/*
	��1���� �� x1 = CALIB_OFFSET, y1 = CALIB_OFFSET
	��2���� �� x2 = LCD_GetHeight() - CALIB_OFFSET, y2 = LCD_GetWidth - CALIB_OFFSET
*/
	if (_ucIndex == 0)
	{
		LCD_ClrScr(CL_BLUE);  		/* ������������ɫ */

		LCD_DispStr(50, 10, "У׼������", &tFont16);		/* ��(8,3)���괦��ʾһ������ */

		LCD_DrawCircle(TP_X1, TP_Y1, 6, CL_WHITE);
	}
	else
	{
		LCD_DrawCircle(TP_X1, TP_Y1, 6, CL_BLUE);		/* ������1���� */

		LCD_DrawCircle(TP_X2, TP_Y2, 6, CL_WHITE);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_PressValid
*	����˵��: �жϰ�ѹ�Ƿ���Ч������X, Y��ADCֵ���д����ж�
*	��    �Σ���
*	�� �� ֵ: 1 ��ʾ��Ч�� 0 ��ʾ��Ч
*********************************************************************************************************
*/
static uint8_t	TOUCH_PressValid(uint16_t _usX, uint16_t _usY)
{
	if ((_usX <= ADC_VALID_OFFSET) || (_usY <= ADC_VALID_OFFSET)
		|| (_usX >= g_tTP.usMaxAdc - ADC_VALID_OFFSET)
		|| (_usY >= g_tTP.usMaxAdc - ADC_VALID_OFFSET))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_WaitRelease
*	����˵��: �ȴ������ͷ�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void TOUCH_WaitRelease(void)
{
	uint8_t usCount;

	for (;;)
	{
		if (TOUCH_PressValid(TOUCH_ReadAdcX(), TOUCH_ReadAdcY()) == 0)
		{
			if (++usCount > 5)
			{
				break;
			}
		}
		else
		{
			usCount = 0;
		}
		bsp_DelayMS(10);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_Calibration
*	����˵��: ������У׼
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void TOUCH_Calibration(void)
{
	uint16_t usAdcX, usAdcX1, usAdcX2;
	uint16_t usAdcY, usAdcY1, usAdcY2;
	uint8_t usCount;

	TOUCH_DispPoint(0);	/* ��ʾ��1��У׼�� */

	TOUCH_WaitRelease(); 	/* �ȴ������ͷ� */

	usCount = 0;
	for (;;)
	{
		usAdcX = TOUCH_ReadAdcX();
		usAdcY = TOUCH_ReadAdcY();

		if (TOUCH_PressValid(usAdcX, usAdcY))
		{
			if (++usCount > 5)
			{
				/* ��ѹ��Ч, ����У׼��ADC����ֵ */
				usAdcX1 = usAdcX;
				usAdcY1 = usAdcY;
				break;
			}
		}
		else
		{
			usCount = 0;
		}
		bsp_DelayMS(10);
	}

	TOUCH_DispPoint(1);		/* ��ʾ��1��У׼�� */

	TOUCH_WaitRelease(); 	/* �ȴ������ͷ� */

	usCount = 0;
	for (;;)
	{
		usAdcX = TOUCH_ReadAdcX();
		usAdcY = TOUCH_ReadAdcY();

		if (TOUCH_PressValid(usAdcX, usAdcY))
		{
			if (++usCount > 5)
			{
				/* ��ѹ��Ч, ����У׼��ADC����ֵ */
				usAdcX2 = usAdcX;
				usAdcY2 = usAdcY;
				break;
			}
		}
		else
		{
			usCount = 0;
		}
		bsp_DelayMS(10);
	}

	/* ʶ������ X, Y �� ��ʾ���� X��Y �Ƿ���Ҫ���� */
	g_tTP.XYChange = 0;		/* 1��ʾX Y��Ҫ���� */
	if (LCD_GetHeight() < LCD_GetWidth())
	{
		if (abs(usAdcX1 - usAdcX2) < abs(usAdcY1 - usAdcY2))
		{
			g_tTP.XYChange = 1;
		}
	}
	else
	{
		if (abs(usAdcX1 - usAdcX2) > abs(usAdcY1 - usAdcY2))
		{
			g_tTP.XYChange = 1;
		}
	}

	g_tTP.usAdcX1 = usAdcX1;
	g_tTP.usAdcY1 = usAdcY1;

	g_tTP.usAdcX2 = usAdcX2;
	g_tTP.usAdcY2 = usAdcY2;

	/* �����һ�������Խ�У׼����������Flash ����EEPROM */
	TOUCH_SaveParam();
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_SaveParam
*	����˵��: ����У׼����	s_usAdcX1 s_usAdcX2 s_usAdcY1 s_usAdcX2
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void TOUCH_SaveParam(void)
{
#if 0
	/* ���������4���������� */
	uint16_t usBuf[5];

	usBuf[0] = g_tTP.usAdcX1;
	usBuf[1] = g_tTP.usAdcY1;

	usBuf[2] = g_tTP.usAdcX2;
	usBuf[3] = g_tTP.usAdcY2;

	usBuf[4] = g_tTP.XYChange;

#endif
}

/*
*********************************************************************************************************
*	�� �� ��: TOUCH_LoadParam
*	����˵��: ��ȡУ׼����
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void TOUCH_LoadParam(void)
{
#if 0
	/* ���������5���������� */
	uint16_t usBuf[5];

	/* ReadParamToBuf() */

	g_tTP.usAdcX1 = usBuf[0];
	g_tTP.usAdcY1 = usBuf[1];

	g_tTP.usAdcX2 = usBuf[2];
	g_tTP.usAdcY2 = usBuf[3];


	g_tTP.XYChange = usBuf[4];
#endif
}
/****************************************************************************************************************************************************************************

	                                                                                  ģ������ : RA8875оƬ����ģ��
	                                                                                �ļ����� : LCD_RA8875.c
*****************************************************************************************************************************************************************************
/*
*********************************************************************************************************
*
*	ģ������ : RA8875оƬ����ģ��
*	�ļ����� : LCD_RA8875.c
*	��    �� : V1.0
*	˵    �� : RA8875�ײ�������������
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		V1.0    2012-08-07 armfly  �����װ�
*
*	Copyright (C), 2011-2012, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "stm32f10x.h"
#include <stdio.h>
#include "LCD_RA8875.h"
#include "bsp_tft_lcd.h"

/*
�������� STM32F103VET6 ����֤ͨ����
	
	���߷�����
	
	LCDģ��� RS ����     �� PD13/FSMC_A18
	LCDģ��� CS Ƭѡ���� �� PD7/FSMC_NE1
	������ NWE, NOE, D15~D0 �Ӷ�Ӧ��FSMC���߼��ɡ�
*/

/* ����LCD�������ķ��ʵ�ַ */
#define RA8875_BASE		((uint32_t)(0x60000000 | 0x00000000))

#define RA8875_REG		*(__IO uint16_t *)(RA8875_BASE + (1 << 19))	  //a18��ΪRS
#define RA8875_RAM		*(__IO uint16_t *)(RA8875_BASE )

static __IO uint16_t s_usTouchX, s_usTouchY;	/* ������ADCֵ */
static __IO uint8_t s_ucRA8875Busy = 0;

/* ���浱ǰ��ʾ���ڵ�λ�úʹ�С���⼸�������� RA8875_SetDispWin() �������� */
static __IO uint16_t s_WinX, s_WinY, s_WinHeight, s_WinWidth;

static void RA8875_WriteReg(uint8_t _ucRegAddr, uint8_t _ucRegValue);
static uint8_t RA8875_ReadReg(uint8_t _ucRegAddr);

static void RA8875_SetCursor(uint16_t _usX, uint16_t _usY);
static void RA8875_SetReadCursor(uint16_t _usX, uint16_t _usY);
static void RA8875_SetTextCursor(uint16_t _usX, uint16_t _usY);

static void BTE_SetTarBlock(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint8_t _ucLayer);
static void BTE_SetOperateCode(uint8_t _ucOperate);
static void BTE_Start(void);


static void RA8875_Delaly1us(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);	/* �ӳ�, ��׼ */
}

static void RA8875_Delaly1ms(void)
{
	uint16_t i;

	for (i = 0; i < 5000; i++);	/* �ӳ�1us, ��׼ */
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_ReadID
*	����˵��: ��ȡLCD����оƬID
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
uint16_t RA8875_ReadID(void)
{
	return RA8875_ReadReg(0x00);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_WriteReg
*	����˵��: дRA8875�Ĵ���. RA8875�ļĴ�����ַ�����ݶ���8bit��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void RA8875_WriteReg(uint8_t _ucRegAddr, uint8_t _ucRegValue)
{
	s_ucRA8875Busy = 1;
	RA8875_REG = _ucRegAddr;	/* ���üĴ�����ַ */
	RA8875_RAM = _ucRegValue;	/* д��Ĵ���ֵ */
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_WriteReg
*	����˵��: дRA8875�Ĵ���. RA8875�ļĴ�����ַ�����ݶ���8bit��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static uint8_t RA8875_ReadReg(uint8_t _ucRegAddr)
{
	uint8_t value;

	RA8875_REG = _ucRegAddr;/* ���üĴ�����ַ */
	value = RA8875_RAM;		/* ��ȡ�Ĵ���ֵ */

	return value;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_InitHard
*	����˵��: ��ʼ��RA8875����оƬ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_InitHard(void)
{
	uint8_t ucGPIX;

	/* ��ȡ RA8875 оƬ��GPIX���ŵĵ�ƽ״̬��1��ʾ4.3������0��ʾ7����
	����ע�����ǰ���������Ϊ�˱���ͳһ�������̣���LCDģ��������Ӳ����ʶ��������Ʒʱ�������Զ�ʶ��
	*/
	ucGPIX = RA8875_ReadReg(0xC7);

	if (ucGPIX == 1)	/* 	GPIX = 1 ��ʾ 4.3 ���� 480x272 */
	{
		/* ��ʼ��PLL.  ����Ƶ��Ϊ25M */
		RA8875_REG = 0x88;
		RA8875_Delaly1us();		/* �ӳ�1us */
		RA8875_RAM = 10;	  	/* PLLDIVM [7] = 0 ;  PLLDIVN [4:0] = 10 */

	    RA8875_Delaly1ms();

		RA8875_REG = 0x89;
		RA8875_Delaly1us();		/* �ӳ�1us */
		RA8875_RAM = 2;		/* PLLDIVK[2:0] = 2, ����4 */

		/* RA8875 ���ڲ�ϵͳƵ�� (SYS_CLK) �ǽ���񵴵�·��PLL ��·��������Ƶ�ʼ��㹫ʽ���� :
		  SYS_CLK = FIN * ( PLLDIVN [4:0] +1 ) / ((PLLDIVM+1 ) * ( 2^PLLDIVK [2:0] ))
		          = 25M * (10 + 1) / ((0 + 1) * (2 ^ 2))
				  = 68.75MHz
		*/

		/* REG[88h]��REG[89h]���趨��Ϊ��֤PLL ����ȶ�����ȴ�һ�Ρ���Ƶʱ�䡹(< 100us)��*/
	    RA8875_Delaly1ms();

		/*
			����ϵͳ���ƼĴ����� ����pdf ��18ҳ:

			bit3:2 ɫ������趨 (Color Depth Setting)
				00b : 8-bpp ��ͨ��TFT �ӿڣ� i.e. 256 ɫ��
				1xb : 16-bpp ��ͨ��TFT �ӿڣ� i.e. 65K ɫ��	 ��ѡ�����

			bit1:0 MCUIF ѡ��
				00b : 8-λMCU �ӿڡ�
				1xb : 16-λMCU �ӿڡ� ��ѡ�����
		*/
		RA8875_WriteReg(0x10, (1 <<3 ) | (1 << 1));	/* ����16λMCU���ڣ�65Kɫ */

		/* REG[04h] Pixel Clock Setting Register   PCSR
			bit7  PCLK Inversion
				0 : PDAT ����PCLK ��Ե���� (Rising Edge) ʱ��ȡ����
				1 : PDAT ����PCLK ��Ե�½� (Falling Edge) ʱ��ȡ����
			bit1:0 PCLK Ƶ�������趨
				Pixel Clock  PCLK Ƶ�������趨��
				00b: PCLK Ƶ������= ϵͳƵ�����ڡ�
				01b: PCLK Ƶ������= 2 ����ϵͳƵ�����ڡ�
				10b: PCLK Ƶ������= 4 ����ϵͳƵ�����ڡ�
				11b: PCLK Ƶ������= 8 ����ϵͳƵ�����ڡ�
		*/
	    RA8875_WriteReg(0x04, 0x82);    /* ����PCLK���� */
	    RA8875_Delaly1ms();

	    //Horizontal set
	    //HDWR//Horizontal Display Width Setting Bit[6:0]
	 	//Horizontal display width(pixels) = (HDWR + 1)*8
	    RA8875_WriteReg(0x14, 0x3B);
	    RA8875_WriteReg(0x15, 0x00);

	    //HNDR//Horizontal Non-Display Period Bit[4:0]
	    //Horizontal Non-Display Period (pixels) = (HNDR + 1)*8
		RA8875_WriteReg(0x16, 0x01);

	    //HSTR//HSYNC Start Position[4:0]
	    //HSYNC Start Position(PCLK) = (HSTR + 1)*8
		RA8875_WriteReg(0x17, 0x00);

	    //HPWR//HSYNC Polarity ,The period width of HSYNC.
	    //HSYNC Width [4:0]   HSYNC Pulse width(PCLK) = (HPWR + 1)*8
		RA8875_WriteReg(0x18, 0x05);

	    //Vertical set
	    //VDHR0 //Vertical Display Height Bit [7:0]
	    //Vertical pixels = VDHR + 1
		RA8875_WriteReg(0x19, 0x0F);

	    //VDHR1 //Vertical Display Height Bit [8]
	    //Vertical pixels = VDHR + 1
		RA8875_WriteReg(0x1A, 0x01);

	    //VNDR0 //Vertical Non-Display Period Bit [7:0]
	    //Vertical Non-Display area = (VNDR + 1)
		RA8875_WriteReg(0x1B, 0x02);

	    //VNDR1 //Vertical Non-Display Period Bit [8]
	    //Vertical Non-Display area = (VNDR + 1)
		RA8875_WriteReg(0x1C, 0x00);

	    //VSTR0 //VSYNC Start Position[7:0]
	    //VSYNC Start Position(PCLK) = (VSTR + 1)
		RA8875_WriteReg(0x1D, 0x07);

	    //VSTR1 //VSYNC Start Position[8]
	    //VSYNC Start Position(PCLK) = (VSTR + 1)
		RA8875_WriteReg(0x1E, 0x00);

	    //VPWR //VSYNC Polarity ,VSYNC Pulse Width[6:0]
	    //VSYNC Pulse Width(PCLK) = (VPWR + 1)
	    RA8875_WriteReg(0x1F, 0x09);


	    g_LcdHeight = LCD_43_HEIGHT;
		g_LcdWidth = LCD_43_WIDTH;
	}
	else	/* GPIX = 0 ��ʾ7����(800x480) */
	{
	    g_LcdHeight = LCD_70_HEIGHT;
		g_LcdWidth = LCD_70_WIDTH;

		/* ��ʼ��PLL.  ����Ƶ��Ϊ25M */
		RA8875_REG = 0x88;
		RA8875_Delaly1us();		/* �ӳ�1us */
		RA8875_RAM = 12;	  	/* PLLDIVM [7] = 0 ;  PLLDIVN [4:0] = 10 */

	    RA8875_Delaly1ms();

		RA8875_REG = 0x89;
		RA8875_Delaly1us();		/* �ӳ�1us */
		RA8875_RAM = 2;		/* PLLDIVK[2:0] = 2, ����4 */

		/* RA8875 ���ڲ�ϵͳƵ�� (SYS_CLK) �ǽ���񵴵�·��PLL ��·��������Ƶ�ʼ��㹫ʽ���� :
		  SYS_CLK = FIN * ( PLLDIVN [4:0] +1 ) / ((PLLDIVM+1 ) * ( 2^PLLDIVK [2:0] ))
		          = 25M * (12 + 1) / ((0 + 1) * (2 ^ 2))
				  = 81.25MHz
		*/

		/* REG[88h]��REG[89h]���趨��Ϊ��֤PLL ����ȶ�����ȴ�һ�Ρ���Ƶʱ�䡹(< 100us)��*/
	    RA8875_Delaly1ms();

		/*
			����ϵͳ���ƼĴ����� ����pdf ��18ҳ:

			bit3:2 ɫ������趨 (Color Depth Setting)
				00b : 8-bpp ��ͨ��TFT �ӿڣ� i.e. 256 ɫ��
				1xb : 16-bpp ��ͨ��TFT �ӿڣ� i.e. 65K ɫ��	 ��ѡ�����

			bit1:0 MCUIF ѡ��
				00b : 8-λMCU �ӿڡ�
				1xb : 16-λMCU �ӿڡ� ��ѡ�����
		*/
		RA8875_WriteReg(0x10, (1 <<3 ) | (1 << 1));	/* ����16λMCU���ڣ�65Kɫ */

		/* REG[04h] Pixel Clock Setting Register (PCSR)
			bit7  PCLK Inversion
				0 : PDAT ����PCLK ��Ե���� (Rising Edge) ʱ��ȡ����
				1 : PDAT ����PCLK ��Ե�½� (Falling Edge) ʱ��ȡ����
			bit1:0 PCLK Ƶ�������趨
				Pixel Clock ,PCLK Ƶ�������趨��
				00b: PCLK Ƶ������= ϵͳƵ�����ڡ�
				01b: PCLK Ƶ������= 2 ����ϵͳƵ�����ڡ�
				10b: PCLK Ƶ������= 4 ����ϵͳƵ�����ڡ�
				11b: PCLK Ƶ������= 8 ����ϵͳƵ�����ڡ�
		*/
	    RA8875_WriteReg(0x04, 0x81);
	    RA8875_Delaly1ms();

	#if 1
		/* OTD9960 & OTA7001 ���� */
		RA8875_WriteReg(0x14, 0x63); // ˮƽ����800
		RA8875_WriteReg(0x15, 0x00);
		RA8875_WriteReg(0x16, 0x03);
		RA8875_WriteReg(0x17, 0x03);
		RA8875_WriteReg(0x18, 0x0B);
		RA8875_WriteReg(0x19, 0xDF);
		RA8875_WriteReg(0x1A, 0x01);
		RA8875_WriteReg(0x1B, 0x1F);
		RA8875_WriteReg(0x1C, 0x00);
		RA8875_WriteReg(0x1D, 0x16);
		RA8875_WriteReg(0x1E, 0x00);
		RA8875_WriteReg(0x1F, 0x01);

	#else	/* AT070TN92  setting */	   //����Ĳ����룬��#if1 #else ����ע��
	    //Horizontal set
	    //HDWR//Horizontal Display Width Setting Bit[6:0]
	 	//Horizontal display width(pixels) = (HDWR + 1)*8
	    RA8875_WriteReg(0x14, 0x4F);
	    RA8875_WriteReg(0x15, 0x05);

	    //HNDR//Horizontal Non-Display Period Bit[4:0]
	    //Horizontal Non-Display Period (pixels) = (HNDR + 1)*8
		RA8875_WriteReg(0x16, 0x0F);

	    //HSTR//HSYNC Start Position[4:0]
	    //HSYNC Start Position(PCLK) = (HSTR + 1)*8
		RA8875_WriteReg(0x17, 0x01);

	    //HPWR//HSYNC Polarity ,The period width of HSYNC.
	    //HSYNC Width [4:0]   HSYNC Pulse width(PCLK) = (HPWR + 1)*8
		RA8875_WriteReg(0x18, 0x00);

	    //Vertical set
	    //VDHR0 //Vertical Display Height Bit [7:0]
	    //Vertical pixels = VDHR + 1
		RA8875_WriteReg(0x19, 0xDF);

	    //VDHR1 //Vertical Display Height Bit [8]
	    //Vertical pixels = VDHR + 1
		RA8875_WriteReg(0x1A, 0x01);

	    //VNDR0 //Vertical Non-Display Period Bit [7:0]
	    //Vertical Non-Display area = (VNDR + 1)
		RA8875_WriteReg(0x1B, 0x0A);

	    //VNDR1 //Vertical Non-Display Period Bit [8]
	    //Vertical Non-Display area = (VNDR + 1)
		RA8875_WriteReg(0x1C, 0x00);

	    //VSTR0 //VSYNC Start Position[7:0]
	    //VSYNC Start Position(PCLK) = (VSTR + 1)
		RA8875_WriteReg(0x1D, 0x0E);

	    //VSTR1 //VSYNC Start Position[8]
	    //VSYNC Start Position(PCLK) = (VSTR + 1)
		RA8875_WriteReg(0x1E, 0x00);

	    //VPWR //VSYNC Polarity ,VSYNC Pulse Width[6:0]
	    //VSYNC Pulse Width(PCLK) = (VPWR + 1)
	    RA8875_WriteReg(0x1F, 0x01);
	#endif
	}

	/* ����TFT���� DISP  ����Ϊ�ߣ�ʹ�����. ������TFTģ���DISP�������ӵ�RA8875оƬ��GP0X�� */
	RA8875_WriteReg(0xC7, 0x01);	/* DISP = 1 */

	/* LCD ��ʾ/�ر�Ѷ�� (LCD Display on) */
	RA8875_WriteReg(0x01, 0x80);

	/* 	REG[40h] Memory Write Control Register 0 (MWCR0)

		Bit 7	��ʾģʽ�趨
			0 : ��ͼģʽ��
			1 : ����ģʽ��

		Bit 6	����д����/�ڴ�д�����趨
			0 : �趨����/�ڴ�д����Ϊ����ʾ��
			1 : �趨����/�ڴ�д����Ϊ��ʾ��

		Bit 5	����д����/�ڴ�д������˸�趨
			0 : �α겻��˸��
			1 : �α���˸��

		Bit 4   NA

		Bit 3-2  ��ͼģʽʱ���ڴ�д�뷽��
			00b : �� -> �ң�Ȼ���� -> �¡�
			01b : �� -> ��Ȼ���� -> �¡�
			10b : �� -> �£�Ȼ���� -> �ҡ�
			11b : �� -> �ϣ�Ȼ���� -> �ҡ�

		Bit 1 	�ڴ�д�����Զ����ӹ����趨
			0 : ���ڴ�д��ʱ���λ���Զ���һ��
			1 : ���ڴ�д��ʱ���λ�ò����Զ���һ��

		Bit 0 �ڴ��ȡ����Զ����ӹ����趨
			0 : ���ڴ��ȡʱ���λ���Զ���һ��
			1 : ���ڴ��ȡʱ���λ�ò����Զ���һ��
	*/
	RA8875_WriteReg(0x40, 0x00);	/* ѡ���ͼģʽ */


	/* 	REG[41h] Memory Write Control Register1 (MWCR1)
		д��Ŀ��λ�ã�ѡ��ͼ��1
	*/
	RA8875_WriteReg(0x41, 0x00);	/* ѡ���ͼģʽ, Ŀ��ΪCGRAM */

	RA8875_SetDispWin(0, 0, g_LcdHeight, g_LcdWidth);

	/* ���õ�ͼ�㣬ˮƽɨ�跽�򣬴�ֱɨ�跽�� */
	RA8875_REG = 0x20;
	RA8875_RAM = 0x00;

	RA8875_REG = 0x52;
	RA8875_REG = 0x00;
}

/*
*********************************************************************************************************
*	�� �� ��: BTE_SetTarBlock
*	����˵��: ����RA8875 BTEĿ�������Լ�Ŀ��ͼ��
*	��    ��:
*			uint16_t _usX : ˮƽ�������
*			uint16_t _usY : ��ֱ�������
*			uint16_t _usHeight : ����߶�
*			uint16_t _usWidth : ������
*			uint8_t _ucLayer �� 0 ͼ��1�� 1 ͼ��2
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void BTE_SetTarBlock(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint8_t _ucLayer)
{
	/* ����������� */
	RA8875_WriteReg(0x58, _usX);
	RA8875_WriteReg(0x59, _usX >> 8);

	RA8875_WriteReg(0x5A, _usY);
	if (_ucLayer == 0)	/* ͼ��2 */
	{
		RA8875_WriteReg(0x5B, _usY >> 8);
	}
	else
	{
		RA8875_WriteReg(0x5B, (1 << 7) | (_usY >> 8));	/* Bit7 ��ʾͼ�㣬 0 ͼ��1�� 1 ͼ��2*/
	}

	/* ���������� */
	RA8875_WriteReg(0x5C, _usWidth);
	RA8875_WriteReg(0x5D, _usWidth >> 8);

	/* ��������߶� */
	RA8875_WriteReg(0x5E, _usHeight);
	RA8875_WriteReg(0x5F, _usHeight >> 8);
}

/*
*********************************************************************************************************
*	�� �� ��: BTE_SetOperateCode
*	����˵��: �趨BTE ������͹�դ������
*	��    ��: _ucOperate : ������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void BTE_SetOperateCode(uint8_t _ucOperate)
{
	/*  �趨BTE ������͹�դ������  */
	RA8875_WriteReg(0x51, _ucOperate);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetFrontColor
*	����˵��: �趨ǰ��ɫ
*	��    ��: ��ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_SetFrontColor(uint16_t _usColor)
{
	s_ucRA8875Busy = 1;
	RA8875_WriteReg(0x63, (_usColor & 0xF800) >> 11);	/* R5  */
	RA8875_WriteReg(0x64, (_usColor & 0x07E0) >> 5);	/* G6 */
	RA8875_WriteReg(0x65, (_usColor & 0x001F));			/* B5 */
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetBackColor
*	����˵��: �趨����ɫ
*	��    ��: ��ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_SetBackColor(uint16_t _usColor)
{
	s_ucRA8875Busy = 1;
	RA8875_WriteReg(0x60, (_usColor & 0xF800) >> 11);	/* R5  */
	RA8875_WriteReg(0x61, (_usColor & 0x07E0) >> 5);	/* G6 */
	RA8875_WriteReg(0x62, (_usColor & 0x001F));			/* B5 */
	s_ucRA8875Busy = 0;
}


/*
*********************************************************************************************************
*	�� �� ��: BTE_Start
*	����˵��: ����BTE����
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void BTE_Start(void)
{
	s_ucRA8875Busy = 1;
	/* RA8875_WriteReg(0x50, 0x80);  ����ʹ�������������Ϊ�ڲ��Ѿ������� s_ucRA8875Busy ��־ */
	RA8875_REG = 0x50;	/* ���üĴ�����ַ */
	RA8875_RAM = 0x80;	/* д��Ĵ���ֵ */
}

/*
*********************************************************************************************************
*	�� �� ��: BTE_Wait
*	����˵��: �ȴ�BTE��������
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void BTE_Wait(void)
{
	while ((RA8875_REG & 0x40) == 0x40);
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_IsBusy
*	����˵��: RA8875�Ƿ�æ
*	��    ��: ��
*	�� �� ֵ: 1 ��ʾæ�� 0 ��ʾ����
*********************************************************************************************************
*/
uint8_t RA8875_IsBusy(void)
{
	if (s_ucRA8875Busy == 0)
	{
		return 0;
	}
	return 1;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_Layer1Visable
*	����˵��: RA8875 ͼ��1��ʾ��
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_Layer1Visable(void)
{
	/* 0x52 �Ĵ����� Bit2:0
		ͼ����ʾģʽ
		000b : ֻ��ͼ��1 ��ʾ��
		001b : ֻ��ͼ��2 ��ʾ��
		010b : ��ʾͼ��1 ��ͼ��2 �Ľ���/����ģʽ��
		011b : ��ʾͼ��1 ��ͼ��2 ��ͨ͸ģʽ��
		100b : Boolean OR��
		101b : Boolean AND��
		110b : ��������ģʽ (Floating window mode)��
		111b :������
	*/
	RA8875_WriteReg(0x52, RA8875_ReadReg(0x52) & 0xF8);	/* ֻ��ͼ��1 ��ʾ */
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_Layer2Visable
*	����˵��: ֻ��ʾͼ��2
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_Layer2Visable(void)
{
	/* 0x52 �Ĵ����� Bit2:0
		ͼ����ʾģʽ
		000b : ֻ��ͼ��1 ��ʾ��
		001b : ֻ��ͼ��2 ��ʾ��
		010b : ��ʾͼ��1 ��ͼ��2 �Ľ���/����ģʽ��
		011b : ��ʾͼ��1 ��ͼ��2 ��ͨ͸ģʽ��
		100b : Boolean OR��
		101b : Boolean AND��
		110b : ��������ģʽ (Floating window mode)��
		111b :������
	*/
	RA8875_WriteReg(0x52, (RA8875_ReadReg(0x52) & 0xF8) | 0x01);	/* ֻ��ͼ��2 ��ʾ */
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_TouchInit
*	����˵��: ��ʼ��������
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_TouchInit(void)
{
	RA8875_WriteReg(0xF0, (1 << 2));	/* ������������ж�λ */

	/*
		REG[71h] Touch Panel Control Register 1 (TPCR1)

		Bit7 N/A
		Bit6 �������ģʽ�趨
			0 : �Զ�ģʽ��
			1 : �ֶ�ģʽ��
		Bit5 ������������ADC �ο���ѹ(Vref)��Դ�趨
			0 : �ڲ������ο���ѹ��
			1 : �ⲿ����ο���ѹ��ADC �ο���ѹ׼λ= 1/2 VDD��
		Bit4-3 N/A
		Bit2 �����ж�Ѷ�ŵ�����������·ѡ��
			0: �ر�����������·��
			1: ��������������·��
		Bit1-0 ��������ֶ�ģʽ֮ѡ��λ
			00b : ����ģʽ�����ؿ��Ƶ�Ԫ��������ģʽ��
			01b : ��ⴥ���¼��������ڴ�ģʽ����������ⴥ���¼��ķ�
				�����¼��������������жϻ����ɻ�������֪(REG[F1h]
				Bit2)��
			10b : X ������ߢȡģʽ���ڴ�ģʽ����λ�õ�X �����ݻᱻ��
				���� REG[72h] ��REG[74h]��
			11b : Y ������ߢȡģʽ���ڴ�ģʽ����λ�õ�Y �����ݻᱻ��
				����REG[73h] and REG[74h]��
	*/
	RA8875_WriteReg(0x71, (0 << 6) | (0 << 5) | (1 << 2));	/* ѡ���Զ�ģʽ */

	/*
		REG[70h] Touch Panel Control Register 0 (TPCR0)

		Bit7 ������幦���趨
			0 : �رա�
			1 : ������
		Bit6-4 ������������ȡ��ʱ���趨
			000b : ADC ȡ��ʱ��Ϊ512 ��ϵͳƵ�����ڡ�
			001b : ADC ȡ��ʱ��Ϊ 1024 ��ϵͳƵ�����ڡ�
			010b : ADC ȡ��ʱ��Ϊ 2048 ��ϵͳƵ�����ڡ�
			011b : ADC ȡ��ʱ��Ϊ 4096 ��ϵͳƵ�����ڡ�
			100b : ADC ȡ��ʱ��Ϊ 8192 ��ϵͳƵ�����ڡ�
			101b : ADC ȡ��ʱ��Ϊ 16384 ��ϵͳƵ�����ڡ�
			110b : ADC ȡ��ʱ��Ϊ 32768 ��ϵͳƵ�����ڡ�
			111b : ADC ȡ��ʱ��Ϊ65536 ��ϵͳƵ�����ڡ�
		Bit3 ������廽��ģʽ
			0 : �رմ����¼�����ģʽ��
			1 : �����¼��ɻ���˯��ģʽ��
		Bit2-0 ������������ADC Ƶ���趨
			000b : ϵͳƵ�ʡ�
			001b : ϵͳƵ�� / 2��
			010b : ϵͳƵ�� / 4��
			011b : ϵͳƵ�� / 8��
			100b : ϵͳƵ�� / 16��
			101b : ϵͳƵ�� / 32��
			110b : ϵͳƵ�� / 64��
			111b : ϵͳƵ�� / 128��

		ע : ADC ������Ƶ���趨���ܳ���10MHz��
	*/
	RA8875_WriteReg(0x70, (1 << 7) | (3 << 4) | (0 << 3) | (2 << 0));	/* �����������ܣ� */
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_TouchReadX
*	����˵��: ��ȡXλ��ADC   �������������ʱ�жϷ��������ã���Ҫ����Ĵ������ʳ�ͻ )
*	��    ��: ��
*	�� �� ֵ: ADCֵ��10Bit
*********************************************************************************************************
*/
uint16_t RA8875_TouchReadX(void)
{
	uint16_t usAdc;
	uint8_t ucRegValue;

	/* �����ȡ�ж��¼���־ */
	ucRegValue = RA8875_ReadReg(0xF1);
	if (ucRegValue & (1 << 2))
	{
		usAdc = RA8875_ReadReg(0x72);	/* Bit9-2 */
		usAdc <<= 2;
		usAdc += (RA8875_ReadReg(0x74) & 0x03);

		s_usTouchX = usAdc;

		usAdc = RA8875_ReadReg(0x73);	/* Bit9-2 */
		usAdc <<= 2;
		usAdc += ((RA8875_ReadReg(0x74) & 0x0C) >> 2);

		s_usTouchY = usAdc;
	}
	else
	{
		s_usTouchX = 0;
		s_usTouchY = 0;
	}

	/*
		bit2 д�빦��?? ��������ж����λ
		0 : δ������
		1 : �����������жϡ�
		��ȡ����?? ��������ж�״̬
		0 : δ������������жϡ�
		1 : ������������жϡ�
	*/
	RA8875_WriteReg(0xF1, (1 << 2));	/* ��������� �Ż��´β��� */

	return s_usTouchX;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_TouchReadY
*	����˵��: ��ȡYλ��ADC �� �����ȵ��� RA8875_TouchReadX()
*	��    ��: ��
*	�� �� ֵ: ADCֵ��10Bit
*********************************************************************************************************
*/
uint16_t RA8875_TouchReadY(void)
{
	return s_usTouchY;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DispOn
*	����˵��: ����ʾ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DispOn(void)
{
	RA8875_WriteReg(0x01, 0x80);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DispOff
*	����˵��: �ر���ʾ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DispOff(void)
{
	RA8875_WriteReg(0x01, 0x00);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_PutPixel
*	����˵��: ��1������
*	��    �Σ�
*			_usX,_usY : ��������
*			_usColor  ��������ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_PutPixel(uint16_t _usX, uint16_t _usY, uint16_t _usColor)
{
	RA8875_SetCursor(_usX, _usY);	/* ���ù��λ�� */

	s_ucRA8875Busy = 1;
	RA8875_REG = 0x02; 			/* �����趨RA8875 �����ڴ�(DDRAM��CGRAM)��ȡ/д��ģʽ */
	RA8875_RAM = _usColor;
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_GetPixel
*	����˵��: ��ȡ1������
*	��    �Σ�
*			_usX,_usY : ��������
*			_usColor  ��������ɫ
*	�� �� ֵ: RGB��ɫֵ
*********************************************************************************************************
*/
uint16_t RA8875_GetPixel(uint16_t _usX, uint16_t _usY)
{
	uint16_t usRGB;

	RA8875_SetReadCursor(_usX, _usY);	/* ���ö�ȡ���λ�� */

	s_ucRA8875Busy = 1;
	RA8875_REG = 0x02;
	usRGB = RA8875_RAM;
	s_ucRA8875Busy = 0;

	return usRGB;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_ClrScr
*	����˵��: �����������ɫֵ����.RA8875֧��Ӳ����ɫ��䡣�ú������Ե�ǰ�������ʾ���ڽ�������. ��ʾ
*			 ���ڵ�λ�úʹ�С�� RA8875_SetDispWin() ������������
*	��    �Σ�_usColor : ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_ClrScr(uint16_t _usColor)
{
	/* Ҳ����ͨ��0x30-0x37�Ĵ�����û�õ�ǰ�������ʾ���� */

	/* ��ɫ��������, ����pdf ��162ҳ
	�˹���ʹ���ڽ�ѡ���ض�������������ǉ\�����ĳ��ǰ��ɫ��R8875 ����ĵ�ɫ�趨ΪBTE ǰ��ɫ��

	�������裺
		1. �趨Ŀ��ͼ���λ�� REG[58h], [59h], [5Ah], [5Bh]
		2. �趨BTE ��Ⱥ͸߶� REG[5Ch], [5Dh], [5Eh], [5Fh]
		3. �趨BTE ������͹�դ������  REG[51h] Bit[3:0] = 0Ch
		4. �趨ǰ��ɫ  REG[63h], [64h], [65h]
		5. ����BTE ����  REG[50h] Bit7 = 1
		6. ���״̬������ STSR Bit6��ȷ��BTE �Ƿ����
	*/
	BTE_SetTarBlock(s_WinX, s_WinY, s_WinHeight, s_WinWidth, 0);	/* ����BTEλ�úͿ�ȸ߶��Լ�Ŀ��ͼ�㣨0��1�� */
	BTE_SetOperateCode(0x0C);		/* �趨BTE ������͹�դ������  REG[51h] Bit[3:0] = 0Ch */
	RA8875_SetFrontColor(_usColor);	/* ����BTEǰ��ɫ */
	BTE_Start();					/* ����BTE ���� */
	BTE_Wait();						/* �ȴ��������� */
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DrawBMP
*	����˵��: ��LCD����ʾһ��BMPλͼ��λͼ����ɨ����򣺴����ң����ϵ���
*	��    �Σ�
*			_usX, _usY : ͼƬ������
*			_usHeight  ��ͼƬ�߶�
*			_usWidth   ��ͼƬ���
*			_ptr       ��ͼƬ����ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DrawBMP(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr)
{
	uint32_t index = 0;
	const uint16_t *p;

	/* ����ͼƬ��λ�úʹ�С�� ��������ʾ���� */
	RA8875_SetDispWin(_usX, _usY, _usHeight, _usWidth);

	s_ucRA8875Busy = 1;
	RA8875_REG = 0x02; 			/* ׼����д�Դ� */

	p = _ptr;
	for (index = 0; index < _usHeight * _usWidth; index++)
	{
		/*
			armfly : �����Ż�, �����͵�չ��
			RA8875_WriteRAM(_ptr[index]);

			�˴��ɿ�����DMA����
		*/
		RA8875_RAM = *p++;
	}
	s_ucRA8875Busy = 0;

	/* �˳����ڻ�ͼģʽ */
	RA8875_QuitWinMode();
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DrawLine
*	����˵��: ����RA8875��Ӳ�����ܣ���2��仭һ��ֱ�ߡ�
*	��    �Σ�
*			_usX1, _usY1 ����ʼ������
*			_usX2, _usY2 ����ֹ��Y����
*			_usColor     ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DrawLine(uint16_t _usX1 , uint16_t _usY1 , uint16_t _usX2 , uint16_t _usY2 , uint16_t _usColor)
{
	/* pdf ��131ҳ
		RA8875 ֧��ֱ�߻�ͼ���ܣ���ʹ�����Լ��׻���ٵ�MCU �Ϳ�����TFT ģ���ϻ�ֱ�ߡ�����
		��ֱ�ߵ���ʼ��REG[91h~94h] �������REG[95h~98h]��ֱ�ߵ���ɫREG[63h~65h]��Ȼ����
		����ͼ�趨REG[90h] Bit4 = 0, Bit0=0 ��REG[90h] Bit7 = 1��RA8875 �ͻὫֱ�ߵ�ͼ��д��
		DDRAM����Ե���TFT ģ���ϾͿ�����ʾ������ֱ�ߡ�
	*/

	/* ����������� */
	RA8875_WriteReg(0x91, _usX1);
	RA8875_WriteReg(0x92, _usX1 >> 8);
	RA8875_WriteReg(0x93, _usY1);
	RA8875_WriteReg(0x94, _usY1 >> 8);

	/* �����յ����� */
	RA8875_WriteReg(0x95, _usX2);
	RA8875_WriteReg(0x96, _usX2 >> 8);
	RA8875_WriteReg(0x97, _usY2);
	RA8875_WriteReg(0x98, _usY2 >> 8);

	RA8875_SetFrontColor(_usColor);	/* ����ֱ�ߵ���ɫ */

	s_ucRA8875Busy = 1;
	RA8875_WriteReg(0x90, (1 << 7) | (0 << 4) | (0 << 0));	/* ��ʼ��ֱ�� */
	while (RA8875_ReadReg(0x90) & (1 << 7));				/* �ȴ����� */
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DrawRect
*	����˵��: ����RA8875Ӳ�����ܻ��ƾ���
*	��    �Σ�
*			_usX,_usY���������Ͻǵ�����
*			_usHeight �����εĸ߶�
*			_usWidth  �����εĿ��
*			_usColor  ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DrawRect(uint16_t _usX, uint16_t _usY, uint8_t _usHeight, uint16_t _usWidth, uint16_t _usColor)
{
	/*
		RA8875 ֧�ַ��λ�ͼ���ܣ���ʹ�����Լ��׻���ٵ�MCU �Ϳ�����TFT ģ���ϻ����Ρ�����
	�����ε���ʼ��REG[91h~94h]�������REG[95h~98h]�����ε���ɫREG[63h~65h]��Ȼ����
	����ͼ�趨REG[90h] Bit4=1, Bit0=0 ��REG[90h] Bit7 = 1��RA8875 �ͻὫ���ε�ͼ��д��
	DDRAM����Ե���TFT ģ���ϾͿ�����ʾ�����ķ��Ρ����趨REG[90h] Bit5 = 1����ɻ���һ
	ʵ�ķ��� (Fill)

	 ---------------->---
	|(_usX��_usY)        |
	V                    V  _usHeight
	|                    |
	 ---------------->---
		  _usWidth
	*/

	/* ����������� */
	RA8875_WriteReg(0x91, _usX);
	RA8875_WriteReg(0x92, _usX >> 8);
	RA8875_WriteReg(0x93, _usY);
	RA8875_WriteReg(0x94, _usY >> 8);

	/* �����յ����� */
	RA8875_WriteReg(0x95, _usX + _usWidth);
	RA8875_WriteReg(0x96, (_usX + _usWidth) >> 8);
	RA8875_WriteReg(0x97, _usY + _usHeight);
	RA8875_WriteReg(0x98, (_usY + _usHeight) >> 8);

	RA8875_SetFrontColor(_usColor);	/* ������ɫ */

	s_ucRA8875Busy = 1;
	RA8875_WriteReg(0x90, (1 << 7) | (0 << 5) | (1 << 4) | (0 << 0));	/* ��ʼ������  */
	while (RA8875_ReadReg(0x90) & (1 << 7));							/* �ȴ����� */
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_FillRect
*	����˵��: ����RA8875Ӳ���������һ������Ϊ��ɫ
*	��    �Σ�
*			_usX,_usY���������Ͻǵ�����
*			_usHeight �����εĸ߶�
*			_usWidth  �����εĿ��
*			_usColor  ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_FillRect(uint16_t _usX, uint16_t _usY, uint8_t _usHeight, uint16_t _usWidth, uint16_t _usColor)
{
	/*
		RA8875 ֧�ַ��λ�ͼ���ܣ���ʹ�����Լ��׻���ٵ�MCU �Ϳ�����TFT ģ���ϻ����Ρ�����
	�����ε���ʼ��REG[91h~94h]�������REG[95h~98h]�����ε���ɫREG[63h~65h]��Ȼ����
	����ͼ�趨REG[90h] Bit4=1, Bit0=0 ��REG[90h] Bit7 = 1��RA8875 �ͻὫ���ε�ͼ��д��
	DDRAM����Ե���TFT ģ���ϾͿ�����ʾ�����ķ��Ρ����趨REG[90h] Bit5 = 1����ɻ���һ
	ʵ�ķ��� (Fill)

	 ---------------->---
	|(_usX��_usY)        |
	V                    V  _usHeight
	|                    |
	 ---------------->---
		  _usWidth
	*/

	/* ����������� */
	RA8875_WriteReg(0x91, _usX);
	RA8875_WriteReg(0x92, _usX >> 8);
	RA8875_WriteReg(0x93, _usY);
	RA8875_WriteReg(0x94, _usY >> 8);

	/* �����յ����� */
	RA8875_WriteReg(0x95, _usX + _usWidth);
	RA8875_WriteReg(0x96, (_usX + _usWidth) >> 8);
	RA8875_WriteReg(0x97, _usY + _usHeight);
	RA8875_WriteReg(0x98, (_usY + _usHeight) >> 8);

	RA8875_SetFrontColor(_usColor);	/* ������ɫ */

	s_ucRA8875Busy = 1;
	RA8875_WriteReg(0x90, (1 << 7) | (1 << 5) | (1 << 4) | (0 << 0));	/* ��ʼ������  */
	while (RA8875_ReadReg(0x90) & (1 << 7));							/* �ȴ����� */
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DrawCircle
*	����˵��: ����һ��Բ���ʿ�Ϊ1������
*	��    �Σ�
*			_usX,_usY  ��Բ�ĵ�����
*			_usRadius  ��Բ�İ뾶
*			_usColor  ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DrawCircle(uint16_t _usX, uint16_t _usY, uint16_t _usRadius, uint16_t _usColor)
{
	/*
		RA8875 ֧��Բ�λ�ͼ���ܣ���ʹ�����Լ��׻���ٵ�MCU �Ϳ�����TFT ģ���ϻ�Բ�����趨
		Բ�����ĵ�REG[99h~9Ch]��Բ�İ뾶REG[9Dh]��Բ����ɫREG[63h~65h]��Ȼ��������ͼ
		REG[90h] Bit6 = 1��RA8875 �ͻὫԲ��ͼ��д��DDRAM����Ե���TFT ģ���ϾͿ�����ʾ��
		����Բ�����趨REG[90h] Bit5 = 1����ɻ���һʵ��Բ (Fill)�����趨REG[90h] Bit5 = 0�����
		��������Բ (Not Fill
	*/
	/* ����Բ�İ뾶 */
	if (_usRadius > 255)
	{
		return;
	}

	/* ����Բ������ */
	RA8875_WriteReg(0x99, _usX);
	RA8875_WriteReg(0x9A, _usX >> 8);
	RA8875_WriteReg(0x9B, _usY);
	RA8875_WriteReg(0x9C, _usY >> 8);

	RA8875_WriteReg(0x9D, _usRadius);	/* ����Բ�İ뾶 */

	RA8875_SetFrontColor(_usColor);	/* ������ɫ */

	s_ucRA8875Busy = 1;
	RA8875_WriteReg(0x90, (1 << 6) | (0 << 5));				/* ��ʼ��Բ, �����  */
	while (RA8875_ReadReg(0x90) & (1 << 6));				/* �ȴ����� */
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_FillCircle
*	����˵��: ���һ��Բ
*	��    �Σ�
*			_usX,_usY  ��Բ�ĵ�����
*			_usRadius  ��Բ�İ뾶
*			_usColor   ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_FillCircle(uint16_t _usX, uint16_t _usY, uint16_t _usRadius, uint16_t _usColor)
{
	/*
		RA8875 ֧��Բ�λ�ͼ���ܣ���ʹ�����Լ��׻���ٵ�MCU �Ϳ�����TFT ģ���ϻ�Բ�����趨
		Բ�����ĵ�REG[99h~9Ch]��Բ�İ뾶REG[9Dh]��Բ����ɫREG[63h~65h]��Ȼ��������ͼ
		REG[90h] Bit6 = 1��RA8875 �ͻὫԲ��ͼ��д��DDRAM����Ե���TFT ģ���ϾͿ�����ʾ��
		����Բ�����趨REG[90h] Bit5 = 1����ɻ���һʵ��Բ (Fill)�����趨REG[90h] Bit5 = 0�����
		��������Բ (Not Fill
	*/
	/* ����Բ�İ뾶 */
	if (_usRadius > 255)
	{
		return;
	}

	/* ����Բ������ */
	RA8875_WriteReg(0x99, _usX);
	RA8875_WriteReg(0x9A, _usX >> 8);
	RA8875_WriteReg(0x9B, _usY);
	RA8875_WriteReg(0x9C, _usY >> 8);

	RA8875_WriteReg(0x9D, _usRadius);	/* ����Բ�İ뾶 */

	RA8875_SetFrontColor(_usColor);	/* ������ɫ */

	s_ucRA8875Busy = 1;
	RA8875_WriteReg(0x90, (1 << 6) | (1 << 5));				/* ��ʼ��Բ, ���  */
	while (RA8875_ReadReg(0x90) & (1 << 6));				/* �ȴ����� */
	s_ucRA8875Busy = 0;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetFont
*	����˵��: �ı�ģʽ�������������塢�о���־�
*	��    �Σ�
*			_ucFontType : ��������: RA_FONT_16, RA_FONT_24, RA_FONT_32
*			_ucLineSpace : �о࣬���ص�λ (0-31)
*			_ucCharSpace : �־࣬���ص�λ (0-63)
*
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_SetFont(uint8_t _ucFontType, uint8_t _ucLineSpace, uint8_t _ucCharSpace)
{
	/*
		[29H]������ģʽ�£������趨���ּ���о� (��λ: ����) ��
		ֻ�е�5��bit��Ч��0-31
	*/
	if (_ucLineSpace >31)
	{
		_ucLineSpace = 31;
	}
	RA8875_WriteReg(0x29, _ucLineSpace);

	/*
		[2EH] �����ַ���ࣨ���ص�λ��0-63���������壨16*16��24*24��32*32��
	*/
	if (_ucCharSpace > 63)
	{
		_ucCharSpace = 63;
	}
	if (_ucFontType > RA_FONT_32)
	{
		_ucFontType = RA_FONT_16;
	}
	RA8875_WriteReg(0x2E, (_ucCharSpace & 0x3F) | (_ucFontType << 6));
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetFontZoom
*	����˵��: �ı�ģʽ���������ֵķŴ�ģʽ��1X,2X,3X, 4X
*	��    �Σ�
*			_ucHSize : ����ˮƽ�Ŵ�����0-3 �ֱ��Ӧ X1��X2��X3��X4
*			_ucVSize : ���ִ��÷Ŵ�����0-3 �ֱ��Ӧ X1��X2��X3��X4
*		�������������ö�٣�RA_SIZE_X1��RA_SIZE_X2��RA_SIZE_X3��RA_SIZE_X4
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_SetTextZoom(uint8_t _ucHSize, uint8_t _ucVSize)
{
	/*
		pdf ��22ҳ		[22H]
		bit7 ���ڶ��룬һ�㲻�ã�ȱʡ��0
		bit6 ����ͨ͸��һ�㲻�ã�ȱʡ��0
		bit4 ������ת90����һ�㲻�ã�ȱʡ��0
		bit3-2 ˮƽ�Ŵ���
		bit1-0 ��ֱ�Ŵ���
	*/
	RA8875_WriteReg(0x22, ((_ucHSize & 0x03) << 2) | ( _ucVSize & 0x03));
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DispAscii
*	����˵��: ��ʾASCII�ַ������ַ�����������RA8875�ڲ�ROM�е�ASCII�ַ�����8*16������֧�ֺ���.
*			������ɫ��������ɫ���Ƿ�ͨ͸�������ĺ�����������
*			void RA8875_SetFrontColor(uint16_t _usColor);
*			void RA8875_SetBackColor(uint16_t _usColor);
*	��    �Σ�_usX, _usY : ��ʾλ�ã����꣩
*			 _ptr : AascII�ַ�������0����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DispAscii(uint16_t _usX, uint16_t _usY, char *_ptr)
{
	/*
		RA8875 �ڽ�8x16 ���ASCII ����ROM���ṩʹ���߸�����ķ�ʽ���ض����� (Code) ������
		�֡��ڽ����ּ�֧��ISO/IEC 8859-1~4 �����׼�����⣬ʹ���߿���͸��REG[60h~62h] ѡ��
		����ǰ����ɫ���Լ�͸��REG[63h~65h] ѡ�񱳾���ɫ.

		ISO/IEC 8859-1���ֳ�Latin-1����ŷ���ԡ����ǹ��ʱ�׼����֯��ISO/IEC 8859�ĵ�һ��8λ�ַ�����
		����ASCIIΪ�������ڿ��õ�0xA0-0xFF�ķ�Χ�ڣ�����192����ĸ�����ţ����Թ�ʹ�ñ������ŵ�������ĸ����ʹ�á�

		ISO/IEC 8859-2 Latin-2����ŷ���ԡ����ǹ��ʱ�׼����֯��ISO/IEC 8859������һ��8λ�ַ��� .
		ISO/IEC 8859-3 ��ŷ�����ַ���
		ISO/IEC 8859-4 ��ŷ�����ַ���
	*/

	/*
	(1) Text mode  REG[40h] bit7=1
	(2) Internal Font ROM Select   REG[21h] bit7=0, bit5=0
	(3) Font foreground and background color Select  REG[63h~65h], REG[60h~62h]
	(4) Write the font Code  CMD_WR[02h]    DATA_WR[font_code]
	*/

	RA8875_SetTextCursor(_usX, _usY);

	RA8875_WriteReg(0x40, (1 << 7));	/* ����Ϊ�ı�ģʽ */

	/* ѡ��CGROM font; ѡ���ڲ�CGROM; �ڲ�CGROM ����ѡ��ISO/IEC 8859-1. */
	RA8875_WriteReg(0x2F, 0x00);
	RA8875_WriteReg(0x21, (0 << 7) | (0 << 5) | (0 << 1) | (0 << 0));

	s_ucRA8875Busy = 1;
	RA8875_REG = 0x02; 			/* �����趨RA8875 �����ڴ�(DDRAM��CGRAM)��ȡ/д��ģʽ */

	/* ��ʼѭ�������ַ� */
	while (*_ptr != 0)
	{
		RA8875_RAM = *_ptr;
		while ((RA8875_REG & 0x80) == 0x80);	/* ����ȴ��ڲ�д��������� */
		_ptr++;
	}
	s_ucRA8875Busy = 0;

	RA8875_WriteReg(0x40, (0 << 7));	/* ��ԭΪͼ��ģʽ */
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_DispStr
*	����˵��: ��ʾ�ַ������ַ�����������RA8875��ӵ��ֿ�оƬ��֧�ֺ���.
*			������ɫ��������ɫ���Ƿ�ͨ͸�������ĺ�����������
*			void RA8875_SetFrontColor(uint16_t _usColor);
*			void RA8875_SetBackColor(uint16_t _usColor);
*	��    �Σ�_usX, _usY : ��ʾλ�ã����꣩
*			 _ptr : AascII�ַ�������0����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_DispStr(uint16_t _usX, uint16_t _usY, char *_ptr)
{
	/*
		RA8875 ͸��ʹ�� �� �Ϻ���ͨ��˾ (Genitop Inc) �ⲿ����ʽ�����ڴ� (Font ROM)����֧�ָ���
		������д�뵽DDRAM �С�RA8875 ���Ϻ���ͨ��˾ (Genitop Inc) ���ݵĲ�Ʒ���� :
		GT21L16TW/GT21H16T1W ��GT23L16U2W ��GT23L24T3Y/GT23H24T3Y ��GT23L24M1Z ��
		�� GT23L32S4W/GT23H32S4W����Щ�������16x16, 24x24, 32x32 �� (Dot) �벻ͬ����

		������RA8875�����弯�ɵ��ֿ�оƬΪ ��ͨ�ֿ�оƬ_GT23l32S4W

		GT23L32S4W��һ���ں�11X12����15X16�㡢24X24����32X32����ĺ��ֿ�оƬ��֧��GB2312
		���꺺�֣����й����ű�ί�Ϸ���Ȩ����SCII�ַ������и�ʽΪ���ú��š��û�ͨ���ַ����룬���ñ���
		���ṩ�ķ�����������ַ�������оƬ�еĵ�ַ���ɴӸõ�ַ���������ַ�������Ϣ��
	*/

	/* �����ı���ʾλ�ã�ע���ı�ģʽ��д�����ͼ��ģʽ��д�����ǲ�ͬ�ļĴ��� */
	RA8875_SetTextCursor(_usX, _usY);

	RA8875_WriteReg(0x40, (1 << 7));	/* ����Ϊ�ı�ģʽ */

	/*
		Serial Flash/ROM Ƶ��Ƶ���趨
			0xb: SFCL Ƶ�� = ϵͳƵ��Ƶ��(��DMA Ϊ����״̬������ɫ�����Ϊ256 ɫ����SFCL Ƶ��
				�̶�Ϊ=ϵͳƵ��Ƶ��/ 2)
			10b: SFCL Ƶ�� =ϵͳƵ��Ƶ��/ 2
			11b: SFCL Ƶ�� =ϵͳƵ��Ƶ��/ 4

		������������ϵͳƵ��Ϊ 68MHz

		GT23L32S4W�ķ����ٶȣ�SPI ʱ��Ƶ�ʣ�20MHz(max.)

		�����Ҫ���� 4 ��Ƶ, 17MHz
	*/
	RA8875_WriteReg(0x06, (3 << 0));	/* ����Ϊ�ı�ģʽ */

	/* ѡ���ⲿ����ROM */
	RA8875_WriteReg(0x21, (0 << 7) | (1 << 5));

	/* 05H  REG[05h] Serial Flash/ROM Configuration Register (SROC)
		7	Serial Flash/ROM I/F # ѡ��
				0:ѡ��Serial Flash/ROM 0 �ӿڡ�[������RA8875�������ֿ�оƬ���� 0 �ӿ�]
				1:ѡ��Serial Flash/ROM 1 �ӿڡ�
		6	Serial Flash/ROM Ѱַģʽ
				0: 24 λѰַģʽ��
				��λ������Ϊ0��
		5	Serial Flash/ROM ����ģʽ
				0: ����ģʽ 0��
				1: ����ģʽ 3��
		4-3	Serial Flash /ROM ��ȡ���� (Read Cycle)
			00b: 4 bus ?? �޿����� (No Dummy Cycle)��
			01b: 5 bus ??1 byte �����ڡ�
			1Xb: 6 bus ??2 byte �����ڡ�
		2	Serial Flash /ROM ��ȡģʽ (Access Mode)
			0: ����ģʽ ��
			1: DMA ģʽ��
		1-0	Serial Flash /ROM I/F Data Latch ѡ��ģʽ
			0Xb: ��һģʽ��
			10b: ˫��ģʽ0��
			11b: ˫��ģʽ1��
	*/
	RA8875_WriteReg(0x05, (0 << 7) | (0 << 6) | (1 << 5) | (1 << 3) | (0 << 2) | (0 << 1));

	/*
		�����ⲿ����оƬ�ͺ�Ϊ GT23L32S4W, ����ΪGB2312,

		Bit1:0 ����ASCII�ַ��ĸ�ʽ��
			0 = NORMAL		 [�ʻ�ϸ, �ͺ��ֶ�������]
			1 = Arial		 [�ʻ��֣��ͺ��ֵײ�����]
			2 = Roman		 [�ʻ�ϸ, �ͺ��ֵײ�����]
			3 = Bold		 [����,������]
	 */
	RA8875_WriteReg(0x2F, (4 << 5) | (0 << 2) | (1 << 0));

	s_ucRA8875Busy = 1;
	RA8875_REG = 0x02; 			/* �����趨RA8875 �����ڴ�(DDRAM��CGRAM)��ȡ/д��ģʽ */

	/* ��ʼѭ�������ַ� */
	while (*_ptr != 0)
	{
		RA8875_RAM = *_ptr;
		while ((RA8875_REG & 0x80) == 0x80);
		_ptr++;
	}
	s_ucRA8875Busy = 0;

	RA8875_WriteReg(0x40, (0 << 7));	/* ��ԭΪͼ��ģʽ */
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetDispWin
*	����˵��: ������ʾ���ڣ����봰����ʾģʽ���ڴ�����ʾģʽ������д�Դ棬�����Զ����趨�����ڽ��е���
*	��    �Σ�
*		_usX : ˮƽ����
*		_usY : ��ֱ����
*		_usHeight: ���ڸ߶�
*		_usWidth : ���ڿ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_SetDispWin(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth)
{

	uint16_t usTemp;

	/* ����ϵͳʾ��ͼ�� ��������
			 -----------------------------
			|(0,0)                        |
			|     --------->              |
			|         |                   |
			|         |                   |
			|         |                   |
			|         V                   |
			|     --------->              |
			|                    (479,271)|
			 -----------------------------

		���Ͻ����������, ɨ�跽���ȴ����ң��ٴ��ϵ��¡�

		�����Ҫ��������ʽ������Ҫ��������������߼������ת��
	*/

	RA8875_WriteReg(0x30, _usX);
    RA8875_WriteReg(0x31, _usX >> 8);

	RA8875_WriteReg(0x32, _usY);
    RA8875_WriteReg(0x33, _usY >> 8);

	usTemp = _usWidth + _usX - 1;
	RA8875_WriteReg(0x34, usTemp);
    RA8875_WriteReg(0x35, usTemp >> 8);

	usTemp = _usHeight + _usY - 1;
	RA8875_WriteReg(0x36, usTemp);
    RA8875_WriteReg(0x37, usTemp >> 8);

	RA8875_SetCursor(_usX, _usY);

	/* ���浱ǰ������Ϣ������Ժ�ɫ��������Ч��.
	����һ��������ͨ����ȡ0x30-0x37�Ĵ�����õ�ǰ���ڣ�����Ч�ʽϵ� */
	s_WinX = _usX;
	s_WinY = _usY;
	s_WinHeight = _usHeight;
	s_WinWidth = _usWidth;
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetCursor
*	����˵��: ����д�Դ�Ĺ��λ�ã�ͼ��ģʽ��
*	��    �Σ�_usX : X����; _usY: Y����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void RA8875_SetCursor(uint16_t _usX, uint16_t _usY)
{
	/* �����ڴ�д�������� ��ע��0x80-83 �ǹ��ͼ�ε����꡿ */
	RA8875_WriteReg(0x46, _usX);
	RA8875_WriteReg(0x47, _usX >> 8);
	RA8875_WriteReg(0x48, _usY);
	RA8875_WriteReg(0x49, _usY >> 8);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetCursor
*	����˵��: ���ö��Դ�Ĺ��λ�á� �ܶ������Ŀ�����д���Ͷ��������ͬ�ļĴ���������RA8875�ǲ�ͬ�ġ�
*	��    �Σ�_usX : X����; _usY: Y����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void RA8875_SetReadCursor(uint16_t _usX, uint16_t _usY)
{
	/* �����ڴ���������� */
	RA8875_WriteReg(0x4A, _usX);
	RA8875_WriteReg(0x4B, _usX >> 8);
	RA8875_WriteReg(0x4C, _usY);
	RA8875_WriteReg(0x4D, _usY >> 8);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetTextCursor
*	����˵��: �����ı�д����λ��
*	��    �Σ�_usX : X����; _usY: Y����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void RA8875_SetTextCursor(uint16_t _usX, uint16_t _usY)
{
	/* �����ڴ���������� */
	RA8875_WriteReg(0x2A, _usX);
	RA8875_WriteReg(0x2B, _usX >> 8);
	RA8875_WriteReg(0x2C, _usY);
	RA8875_WriteReg(0x2D, _usY >> 8);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_QuitWinMode
*	����˵��: �˳�������ʾģʽ����Ϊȫ����ʾģʽ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_QuitWinMode(void)
{
	RA8875_SetDispWin(0, 0, g_LcdHeight, g_LcdWidth);
}

/*
*********************************************************************************************************
*	�� �� ��: RA8875_SetBackLight
*	����˵��: ����RA8875оƬ��PWM1��ؼĴ���������LCD����
*	��    �Σ�_bright ���ȣ�0����255������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void RA8875_SetBackLight(uint8_t _bright)
{
	if (_bright == 0)
	{
		/* �ر�PWM, PWM1����ȱʡ���LOW  */
		RA8875_WriteReg(0x8A, 0 << 6);
	}
	else if (_bright == BRIGHT_MAX)	/* ������� */
	{
		/* �ر�PWM, PWM1����ȱʡ���HIGH */
		RA8875_WriteReg(0x8A, 1 << 6);
	}
	else
	{
		/* ʹ��PWM1, ����ռ�ձȵ��� */

		/* 	REG[8Ah] PWM1 Control Register (P1CR)

			Bit7 ������ȵ��� (PWM1) �趨
				0 : �رգ���״̬�£�PWM1 ���׼λ���մ˻�����Bit6 ������
				1 : ������

			Bit6 PWM1 �ر�ʱ��׼λ
				0 : ��PWM �رջ���˯��ģʽʱ��PWM1 ���Ϊ��Low�� ״̬��
				1 : ��PWM �رջ���˯��ģʽʱ��PWM1 ���Ϊ��High�� ״̬��

			Bit5 ����

			Bit4 PWM1 ����ѡ��
				0 : PWM1 ���ܡ�
				1 : PWM1 �̶����һƵ��Ϊ�ⲿ��������Clock (Fin) Ƶ�� 1 /16 ��Clock

			Bit3-0  PWM1 ��·��Ƶ����Դѡ��PWM_CLK	������PWM���Ƶ�ʡ�
				0000b : SYS_CLK / 1 1000b : SYS_CLK / 256
				0001b : SYS_CLK / 2 1001b : SYS_CLK / 512
				0010b : SYS_CLK / 4 1010b : SYS_CLK / 1024
				0011b : SYS_CLK / 8 1011b : SYS_CLK / 2048
				0100b : SYS_CLK / 16 1100b : SYS_CLK / 4096
				0101b : SYS_CLK / 32 1101b : SYS_CLK / 8192
				0110b : SYS_CLK / 64 1110b : SYS_CLK / 16384
				0111b : SYS_CLK / 128 1111b : SYS_CLK / 32768

				��SYS_CLK�� ����ϵͳƵ�ʣ� ����SYS_CLK Ϊ20MHz�� ��Bit[3:0] =0001b ʱ��PWM1 Ƶ����ԴΪ10MHz��

				���ڰ�������4.3��ģ�飬SYS_CLK =  68.75MHz
				Bit3-0 ѡ��8ʱ��PWM_CLK = 68.75MHz / 256 = 0.2685546875 MHz = 268.55KHz��
				ʵ�������PWM����Ƶ�� = PWM_CLK / 256 = 1.049kHz������ʾ��������֤��PWMƵ�ʺ�׼��

				ѡ��10ʱ��Ƶ��256Hz���ң�����1KHz��Х����
		*/

		RA8875_WriteReg(0x8A, (1 << 7) | 10);

		/* REG[8Bh] PWM1 Duty Cycle Register (P1DCR) */
		RA8875_WriteReg(0x8B, _bright);
	}
}

/****************************************************************************************************************************************************************************

	                                                                                  	ģ������ : TFTҺ����ʾ������ģ��
                                                                                           	�ļ����� : SPFD5420_SPFD5420.c
*****************************************************************************************************************************************************************************
/*
*********************************************************************************************************
*
*	ģ������ : TFTҺ����ʾ������ģ��
*	�ļ����� : SPFD5420_SPFD5420.c
*	��    �� : V2.2
*	˵    �� : ����������������TFT��ʾ���ֱ���Ϊ240x400��3.0���������PWM������ڹ��ܡ�
*				֧�ֵ�LCD�ڲ�����оƬ�ͺ��У�SPFD5420A��OTM4001A��R61509V
*				����оƬ�ķ��ʵ�ַΪ:  0x60000000
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		v1.0    2011-08-21 armfly  ST�̼���汾 V3.5.0�汾��
*					a) ȡ�����ʼĴ����Ľṹ�壬ֱ�Ӷ���
*		V2.0    2011-10-16 armfly  ����R61509V������ʵ��ͼ����ʾ����
*		V2.1    2012-07-06 armfly  ����RA8875������֧��4.3����
*		V2.2    2012-07-13 armfly  �Ľ�SPFD5420_DispStr������֧��12�����ַ�;�޸�SPFD5420_DrawRect,�����
*								һ����������
*
*	Copyright (C), 2010-2011, ���������� www.armfly.com
*
*********************************************************************************************************
*/

/*
	������ʾ��
	TFT��������һ���12864������ʾ���Ŀ����������������������˴��ڻ�ͼ�Ļ��ƣ�������ƶ��ڻ��ƾֲ�ͼ��
	�Ƿǳ���Ч�ġ�TFT������ָ��һ����ͼ���ڣ�Ȼ�����еĶ�д�Դ�Ĳ��������������֮�ڣ����������ҪCPU��
	�ڴ��б���������Ļ���������ݡ�
*/

#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>
#include "bsp_tft_lcd.h"
#include "fonts.h"


/* ����LCD�������ķ��ʵ�ַ
	TFT�ӿ��е�RS��������FSMC_A0���ţ�������16bitģʽ��RS��ӦA1��ַ�ߣ����
	SPFD5420_RAM�ĵ�ַ��+2
*/
#define SPFD5420_BASE       ((uint32_t)(0x60000000 | 0x00000000))

#define SPFD5420_REG		*(__IO uint16_t *)(SPFD5420_BASE)
#define SPFD5420_RAM		*(__IO uint16_t *)(SPFD5420_BASE + (1 << 17))

static __IO uint8_t s_RGBChgEn = 0;		/* RGBת��ʹ��, 4001��д�Դ������RGB��ʽ��д��Ĳ�ͬ */

static void SPFD5420_Delaly10ms(void);
static void SPFD5420_WriteReg(__IO uint16_t _usAddr, uint16_t _usValue);
static uint16_t SPFD5420_ReadReg(__IO uint16_t _usAddr);
static void Init_5420_4001(void);
static void Init_61509(void);
static void SPFD5420_SetDispWin(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth);
static void SPFD5420_QuitWinMode(void);
static void SPFD5420_SetCursor(uint16_t _usX, uint16_t _usY);
static uint16_t SPFD5420_BGR2RGB(uint16_t _usRGB);

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_Delaly10ms
*	����˵��: �ӳٺ�������׼
*	��    ��:
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void SPFD5420_Delaly10ms(void)
{
	uint16_t i;

	for (i = 0; i < 50000; i++);
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_WriteReg
*	����˵��: �޸�LCD�������ļĴ�����ֵ��
*	��    �Σ�
*			SPFD5420_Reg ���Ĵ�����ַ;
*			SPFD5420_RegValue : �Ĵ���ֵ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void SPFD5420_WriteReg(__IO uint16_t _usAddr, uint16_t _usValue)
{
	/* Write 16-bit Index, then Write Reg */
	SPFD5420_REG = _usAddr;
	/* Write 16-bit Reg */
	SPFD5420_RAM = _usValue;
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_ReadReg
*	����˵��: ��ȡLCD�������ļĴ�����ֵ��
*	��    �Σ�
*			SPFD5420_Reg ���Ĵ�����ַ;
*			SPFD5420_RegValue : �Ĵ���ֵ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static uint16_t SPFD5420_ReadReg(__IO uint16_t _usAddr)
{
	/* Write 16-bit Index (then Read Reg) */
	SPFD5420_REG = _usAddr;
	/* Read 16-bit Reg */
	return (SPFD5420_RAM);
}


/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_SetDispWin
*	����˵��: ������ʾ���ڣ����봰����ʾģʽ��TFT����оƬ֧�ִ�����ʾģʽ�����Ǻ�һ���12864����LCD���������
*	��    �Σ�
*		_usX : ˮƽ����
*		_usY : ��ֱ����
*		_usHeight: ���ڸ߶�
*		_usWidth : ���ڿ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void SPFD5420_SetDispWin(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth)
{
	uint16_t px, py;
	/*
		240x400��Ļ��������(px,py)����:
		    R003 = 0x1018                  R003 = 0x1008
		  -------------------          -------------------
		 |(0,0)              |        |(0,0)              |
		 |                   |        |					  |
		 |  ^           ^    |        |   ^           ^   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |  ------>  |    |        |   | <------   |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |                   |        |					  |
		 |                   |        |                   |
		 |      (x=239,y=399)|        |      (x=239,y=399)|
		 |-------------------|        |-------------------|
		 |                   |        |                   |
		  -------------------          -------------------

		���հ�����������LCD�ķ����������������������ɨ�跽�����£�(����ͼ��1���Ǻ�)
		 --------------------------------
		|  |(0,0)                        |
		|  |     --------->              |
		|  |         |                   |
		|  |         |                   |
		|  |         |                   |
		|  |         V                   |
		|  |     --------->              |
		|  |                    (399,239)|
		 --------------------------------
	�����������������ת����ϵ��
		x = 399 - py;
		y = px;

		py = 399 - x;
		px = y;
	*/

	py = 399 - _usX;
	px = _usY;

	/* ������ʾ���� WINDOWS */
	SPFD5420_WriteReg(0x0210, px);						/* ˮƽ��ʼ��ַ */
	SPFD5420_WriteReg(0x0211, px + (_usHeight - 1));		/* ˮƽ�������� */
	SPFD5420_WriteReg(0x0212, py + 1 - _usWidth);		/* ��ֱ��ʼ��ַ */
	SPFD5420_WriteReg(0x0213, py);						/* ��ֱ������ַ */

	SPFD5420_SetCursor(_usX, _usY);
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_SetCursor
*	����˵��: ���ù��λ��
*	��    �Σ�_usX : X����; _usY: Y����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void SPFD5420_SetCursor(uint16_t _usX, uint16_t _usY)
{
	/*
		px��py ���������꣬ x��y����������
		ת����ʽ:
		py = 399 - x;
		px = y;
	*/

	SPFD5420_WriteReg(0x0200, _usY);  		/* px */
	SPFD5420_WriteReg(0x0201, 399 - _usX);	/* py */
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_BGR2RGB
*	����˵��: RRRRRGGGGGGBBBBB ��Ϊ BBBBBGGGGGGRRRRR ��ʽ
*	��    �Σ�RGB��ɫ����
*	�� �� ֵ: ת�������ɫ����
*********************************************************************************************************
*/
static uint16_t SPFD5420_BGR2RGB(uint16_t _usRGB)
{
	uint16_t  r, g, b, rgb;

	b = (_usRGB >> 0)  & 0x1F;
	g = (_usRGB >> 5)  & 0x3F;
	r = (_usRGB >> 11) & 0x1F;

	rgb = (b<<11) + (g<<5) + (r<<0);

	return( rgb );
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_QuitWinMode
*	����˵��: �˳�������ʾģʽ����Ϊȫ����ʾģʽ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void SPFD5420_QuitWinMode(void)
{
	SPFD5420_SetDispWin(0, 0, g_LcdHeight, g_LcdWidth);
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_ReadID
*	����˵��: ��ȡLCD����оƬID
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
uint16_t SPFD5420_ReadID(void)
{
	return SPFD5420_ReadReg(0x0000);
}

/*
*********************************************************************************************************
*	�� �� ��: Init_5420_4001
*	����˵��: ��ʼ��5420��4001��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void Init_5420_4001(void)
{
	/* ��ʼ��LCD��дLCD�Ĵ����������� */
	SPFD5420_WriteReg(0x0000, 0x0000);
	SPFD5420_WriteReg(0x0001, 0x0100);
	SPFD5420_WriteReg(0x0002, 0x0100);

	/*
		R003H �Ĵ����ܹؼ��� Entry Mode ��������ɨ�跽��
		�μ���SPFD5420A.pdf ��15ҳ

		240x400��Ļ��������(px,py)����:
		    R003 = 0x1018                  R003 = 0x1008
		  -------------------          -------------------
		 |(0,0)              |        |(0,0)              |
		 |                   |        |					  |
		 |  ^           ^    |        |   ^           ^   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |  ------>  |    |        |   | <------   |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |  |           |    |        |   |           |   |
		 |                   |        |					  |
		 |                   |        |                   |
		 |      (x=239,y=399)|        |      (x=239,y=399)|
		 |-------------------|        |-------------------|
		 |                   |        |                   |
		  -------------------          -------------------

		���հ�����������LCD�ķ����������������������ɨ�跽�����£�(����ͼ��1���Ǻ�)
		 --------------------------------
		|  |(0,0)                        |
		|  |     --------->              |
		|  |         |                   |
		|  |         |                   |
		|  |         |                   |
		|  |         V                   |
		|  |     --------->              |
		|  |                    (399,239)|
		 --------------------------------

		��������(x,y) �����������ת����ϵ
		x = 399 - py;
		y = px;

		py = 399 - x;
		px = y;

	*/
	SPFD5420_WriteReg(0x0003, 0x1018); /* 0x1018 1030 */

	SPFD5420_WriteReg(0x0008, 0x0808);
	SPFD5420_WriteReg(0x0009, 0x0001);
	SPFD5420_WriteReg(0x000B, 0x0010);
	SPFD5420_WriteReg(0x000C, 0x0000);
	SPFD5420_WriteReg(0x000F, 0x0000);
	SPFD5420_WriteReg(0x0007, 0x0001);
	SPFD5420_WriteReg(0x0010, 0x0013);
	SPFD5420_WriteReg(0x0011, 0x0501);
	SPFD5420_WriteReg(0x0012, 0x0300);
	SPFD5420_WriteReg(0x0020, 0x021E);
	SPFD5420_WriteReg(0x0021, 0x0202);
	SPFD5420_WriteReg(0x0090, 0x8000);
	SPFD5420_WriteReg(0x0100, 0x17B0);
	SPFD5420_WriteReg(0x0101, 0x0147);
	SPFD5420_WriteReg(0x0102, 0x0135);
	SPFD5420_WriteReg(0x0103, 0x0700);
	SPFD5420_WriteReg(0x0107, 0x0000);
	SPFD5420_WriteReg(0x0110, 0x0001);
	SPFD5420_WriteReg(0x0210, 0x0000);
	SPFD5420_WriteReg(0x0211, 0x00EF);
	SPFD5420_WriteReg(0x0212, 0x0000);
	SPFD5420_WriteReg(0x0213, 0x018F);
	SPFD5420_WriteReg(0x0280, 0x0000);
	SPFD5420_WriteReg(0x0281, 0x0004);
	SPFD5420_WriteReg(0x0282, 0x0000);
	SPFD5420_WriteReg(0x0300, 0x0101);
	SPFD5420_WriteReg(0x0301, 0x0B2C);
	SPFD5420_WriteReg(0x0302, 0x1030);
	SPFD5420_WriteReg(0x0303, 0x3010);
	SPFD5420_WriteReg(0x0304, 0x2C0B);
	SPFD5420_WriteReg(0x0305, 0x0101);
	SPFD5420_WriteReg(0x0306, 0x0807);
	SPFD5420_WriteReg(0x0307, 0x0708);
	SPFD5420_WriteReg(0x0308, 0x0107);
	SPFD5420_WriteReg(0x0309, 0x0105);
	SPFD5420_WriteReg(0x030A, 0x0F04);
	SPFD5420_WriteReg(0x030B, 0x0F00);
	SPFD5420_WriteReg(0x030C, 0x000F);
	SPFD5420_WriteReg(0x030D, 0x040F);
	SPFD5420_WriteReg(0x030E, 0x0300);
	SPFD5420_WriteReg(0x030F, 0x0701);
	SPFD5420_WriteReg(0x0400, 0x3500);
	SPFD5420_WriteReg(0x0401, 0x0001);
	SPFD5420_WriteReg(0x0404, 0x0000);
	SPFD5420_WriteReg(0x0500, 0x0000);
	SPFD5420_WriteReg(0x0501, 0x0000);
	SPFD5420_WriteReg(0x0502, 0x0000);
	SPFD5420_WriteReg(0x0503, 0x0000);
	SPFD5420_WriteReg(0x0504, 0x0000);
	SPFD5420_WriteReg(0x0505, 0x0000);
	SPFD5420_WriteReg(0x0600, 0x0000);
	SPFD5420_WriteReg(0x0606, 0x0000);
	SPFD5420_WriteReg(0x06F0, 0x0000);
	SPFD5420_WriteReg(0x07F0, 0x5420);
	SPFD5420_WriteReg(0x07DE, 0x0000);
	SPFD5420_WriteReg(0x07F2, 0x00DF);
	SPFD5420_WriteReg(0x07F3, 0x0810);
	SPFD5420_WriteReg(0x07F4, 0x0077);
	SPFD5420_WriteReg(0x07F5, 0x0021);
	SPFD5420_WriteReg(0x07F0, 0x0000);
	SPFD5420_WriteReg(0x0007, 0x0173);

	/* ������ʾ���� WINDOWS */
	SPFD5420_WriteReg(0x0210, 0);	/* ˮƽ��ʼ��ַ */
	SPFD5420_WriteReg(0x0211, 239);	/* ˮƽ�������� */
	SPFD5420_WriteReg(0x0212, 0);	/* ��ֱ��ʼ��ַ */
	SPFD5420_WriteReg(0x0213, 399);	/* ��ֱ������ַ */
}

/*
*********************************************************************************************************
*	�� �� ��: Init_61509
*	����˵��: ��ʼ��61509��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void Init_61509(void)
{
	SPFD5420_WriteReg(0x000,0x0000);
	SPFD5420_WriteReg(0x000,0x0000);
	SPFD5420_WriteReg(0x000,0x0000);
	SPFD5420_WriteReg(0x000,0x0000);
	SPFD5420_Delaly10ms();

	SPFD5420_WriteReg(0x008,0x0808);
	SPFD5420_WriteReg(0x010,0x0010);
	SPFD5420_WriteReg(0x400,0x6200);

	SPFD5420_WriteReg(0x300,0x0c06);	/* GAMMA */
	SPFD5420_WriteReg(0x301,0x9d0f);
	SPFD5420_WriteReg(0x302,0x0b05);
	SPFD5420_WriteReg(0x303,0x1217);
	SPFD5420_WriteReg(0x304,0x3333);
	SPFD5420_WriteReg(0x305,0x1712);
	SPFD5420_WriteReg(0x306,0x950b);
	SPFD5420_WriteReg(0x307,0x0f0d);
	SPFD5420_WriteReg(0x308,0x060c);
	SPFD5420_WriteReg(0x309,0x0000);

	SPFD5420_WriteReg(0x011,0x0202);
	SPFD5420_WriteReg(0x012,0x0101);
	SPFD5420_WriteReg(0x013,0x0001);

	SPFD5420_WriteReg(0x007,0x0001);
	SPFD5420_WriteReg(0x100,0x0730);	/* BT,AP 0x0330��*/
	SPFD5420_WriteReg(0x101,0x0237);	/* DC0,DC1,VC */
	SPFD5420_WriteReg(0x103,0x2b00);	/* VDV	//0x0f00 */
	SPFD5420_WriteReg(0x280,0x4000);	/* VCM */
	SPFD5420_WriteReg(0x102,0x81b0);	/* VRH,VCMR,PSON,PON */
	SPFD5420_Delaly10ms();

	SPFD5420_WriteReg(0x001,0x0100);
	SPFD5420_WriteReg(0x002,0x0100);
	/* SPFD5420_WriteReg(0x003,0x1030); */
	SPFD5420_WriteReg(0x003,0x1018);
	SPFD5420_WriteReg(0x009,0x0001);

	SPFD5420_WriteReg(0x0C,0x0000);	/* MCU interface  */
	/*
		SPFD5420_WriteReg(0x0C,0x0110);	//RGB interface 18bit
		SPFD5420_WriteReg(0x0C,0x0111);	//RGB interface 16bit
		SPFD5420_WriteReg(0x0C,0x0020);	//VSYNC interface
	*/

	SPFD5420_WriteReg(0x090,0x8000);
	SPFD5420_WriteReg(0x00f,0x0000);

	SPFD5420_WriteReg(0x210,0x0000);
	SPFD5420_WriteReg(0x211,0x00ef);
	SPFD5420_WriteReg(0x212,0x0000);
	SPFD5420_WriteReg(0x213,0x018f);

	SPFD5420_WriteReg(0x500,0x0000);
	SPFD5420_WriteReg(0x501,0x0000);
	SPFD5420_WriteReg(0x502,0x005f);
	SPFD5420_WriteReg(0x401,0x0001);
	SPFD5420_WriteReg(0x404,0x0000);
	SPFD5420_Delaly10ms();
	SPFD5420_WriteReg(0x007,0x0100);
	SPFD5420_Delaly10ms();
	SPFD5420_WriteReg(0x200,0x0000);
	SPFD5420_WriteReg(0x201,0x0000);
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_InitHard
*	����˵��: ��ʼ��LCD
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_InitHard(void)
{
	uint16_t id;

	id = SPFD5420_ReadReg(0x0000);  	/* ��ȡLCD����оƬID */

	if (id == 0x5420)	/* 4001����5420��ͬ��4001�������Դ�RGBʱ����Ҫ����ת����5420���� */
	{
		Init_5420_4001();	/* ��ʼ��5420��4001��Ӳ�� */

		/* ������δ�������ʶ����4001������5420�� */
		{
			uint16_t dummy;

			SPFD5420_WriteReg(0x0200, 0);
			SPFD5420_WriteReg(0x0201, 0);

			SPFD5420_REG = 0x0202;
			SPFD5420_RAM = 0x1234;		/* дһ������ */

			SPFD5420_WriteReg(0x0200, 0);
			SPFD5420_WriteReg(0x0201, 0);
			SPFD5420_REG = 0x0202;
			dummy = SPFD5420_RAM; 		/* ������ɫֵ */
			if (dummy == 0x1234)
			{
				s_RGBChgEn = 0;

				g_ChipID = IC_5420;
			}
			else
			{
				s_RGBChgEn = 1;		/* ������صĺ�д��Ĳ�ͬ������ҪRGBת��, ֻӰ���ȡ���صĺ��� */

				g_ChipID = IC_4001;
			}
			g_LcdHeight = LCD_30_HEIGHT;
			g_LcdWidth = LCD_30_WIDTH;
		}
	}
	else if (id == 0xB509)
	{
		Init_61509();		/* ��ʼ��61509��Ӳ�� */

		s_RGBChgEn = 1;			/* ������صĺ�д��Ĳ�ͬ������ҪRGBת��, ֻӰ���ȡ���صĺ��� */

		g_ChipID = IC_61509;
		g_LcdHeight = LCD_30_HEIGHT;
		g_LcdWidth = LCD_30_WIDTH;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_DispOn
*	����˵��: ����ʾ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_DispOn(void)
{
	if (g_ChipID == IC_61509)
	{
		SPFD5420_WriteReg(0x007,0x0100);
	}
	else	/* IC_4001 */
	{
		SPFD5420_WriteReg(7, 0x0173); /* ����262K��ɫ���Ҵ���ʾ */
	}
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_DispOff
*	����˵��: �ر���ʾ
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_DispOff(void)
{
	SPFD5420_WriteReg(7, 0x0000);
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_ClrScr
*	����˵��: �����������ɫֵ����
*	��    �Σ�_usColor : ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_ClrScr(uint16_t _usColor)
{
	uint32_t i;

	SPFD5420_SetCursor(0, 0);		/* ���ù��λ�� */

	SPFD5420_REG = 0x202; 			/* ׼����д�Դ� */

	for (i = 0; i < g_LcdHeight * g_LcdWidth; i++)
	{
		SPFD5420_RAM = _usColor;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_PutPixel
*	����˵��: ��1������
*	��    �Σ�
*			_usX,_usY : ��������
*			_usColor  ��������ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_PutPixel(uint16_t _usX, uint16_t _usY, uint16_t _usColor)
{
	SPFD5420_SetCursor(_usX, _usY);	/* ���ù��λ�� */

	/* д�Դ� */
	SPFD5420_REG = 0x202;
	/* Write 16-bit GRAM Reg */
	SPFD5420_RAM = _usColor;
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_GetPixel
*	����˵��: ��ȡ1������
*	��    �Σ�
*			_usX,_usY : ��������
*			_usColor  ��������ɫ
*	�� �� ֵ: RGB��ɫֵ
*********************************************************************************************************
*/
uint16_t SPFD5420_GetPixel(uint16_t _usX, uint16_t _usY)
{
	uint16_t usRGB;

	SPFD5420_SetCursor(_usX, _usY);	/* ���ù��λ�� */

	{
		/* ׼��д�Դ� */
		SPFD5420_REG = 0x202;

		usRGB = SPFD5420_RAM;

		/* �� 16-bit GRAM Reg */
		if (s_RGBChgEn == 1)
		{
			usRGB = SPFD5420_BGR2RGB(usRGB);
		}
	}

	return usRGB;
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_DrawLine
*	����˵��: ���� Bresenham �㷨����2��仭һ��ֱ�ߡ�
*	��    �Σ�
*			_usX1, _usY1 ����ʼ������
*			_usX2, _usY2 ����ֹ��Y����
*			_usColor     ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_DrawLine(uint16_t _usX1 , uint16_t _usY1 , uint16_t _usX2 , uint16_t _usY2 , uint16_t _usColor)
{
	int32_t dx , dy ;
	int32_t tx , ty ;
	int32_t inc1 , inc2 ;
	int32_t d , iTag ;
	int32_t x , y ;

	/* ���� Bresenham �㷨����2��仭һ��ֱ�� */

	SPFD5420_PutPixel(_usX1 , _usY1 , _usColor);

	/* ��������غϣ���������Ķ�����*/
	if ( _usX1 == _usX2 && _usY1 == _usY2 )
	{
		return;
	}

	iTag = 0 ;
	/* dx = abs ( _usX2 - _usX1 ); */
	if (_usX2 >= _usX1)
	{
		dx = _usX2 - _usX1;
	}
	else
	{
		dx = _usX1 - _usX2;
	}

	/* dy = abs ( _usY2 - _usY1 ); */
	if (_usY2 >= _usY1)
	{
		dy = _usY2 - _usY1;
	}
	else
	{
		dy = _usY1 - _usY2;
	}

	if ( dx < dy )   /*���dyΪ�Ƴ������򽻻��ݺ����ꡣ*/
	{
		uint16_t temp;

		iTag = 1 ;
		temp = _usX1; _usX1 = _usY1; _usY1 = temp;
		temp = _usX2; _usX2 = _usY2; _usY2 = temp;
		temp = dx; dx = dy; dy = temp;
	}
	tx = _usX2 > _usX1 ? 1 : -1 ;    /* ȷ������1���Ǽ�1 */
	ty = _usY2 > _usY1 ? 1 : -1 ;
	x = _usX1 ;
	y = _usY1 ;
	inc1 = 2 * dy ;
	inc2 = 2 * ( dy - dx );
	d = inc1 - dx ;
	while ( x != _usX2 )     /* ѭ������ */
	{
		if ( d < 0 )
		{
			d += inc1 ;
		}
		else
		{
			y += ty ;
			d += inc2 ;
		}
		if ( iTag )
		{
			SPFD5420_PutPixel ( y , x , _usColor) ;
		}
		else
		{
			SPFD5420_PutPixel ( x , y , _usColor) ;
		}
		x += tx ;
	}
}


/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_DrawRect
*	����˵��: ����ˮƽ���õľ��Ρ�
*	��    �Σ�
*			_usX,_usY���������Ͻǵ�����
*			_usHeight �����εĸ߶�
*			_usWidth  �����εĿ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_DrawRect(uint16_t _usX, uint16_t _usY, uint8_t _usHeight, uint16_t _usWidth, uint16_t _usColor)
{
	/*
	 ---------------->---
	|(_usX��_usY)        |
	V                    V  _usHeight
	|                    |
	 ---------------->---
		  _usWidth
	*/

	SPFD5420_DrawLine(_usX, _usY, _usX + _usWidth - 1, _usY, _usColor);	/* �� */
	SPFD5420_DrawLine(_usX, _usY + _usHeight - 1, _usX + _usWidth - 1, _usY + _usHeight - 1, _usColor);	/* �� */

	SPFD5420_DrawLine(_usX, _usY, _usX, _usY + _usHeight - 1, _usColor);	/* �� */
	SPFD5420_DrawLine(_usX + _usWidth - 1, _usY, _usX + _usWidth - 1, _usY + _usHeight, _usColor);	/* �� */
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_DrawCircle
*	����˵��: ����һ��Բ���ʿ�Ϊ1������
*	��    �Σ�
*			_usX,_usY  ��Բ�ĵ�����
*			_usRadius  ��Բ�İ뾶
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_DrawCircle(uint16_t _usX, uint16_t _usY, uint16_t _usRadius, uint16_t _usColor)
{
	int32_t  D;			/* Decision Variable */
	uint32_t  CurX;		/* ��ǰ X ֵ */
	uint32_t  CurY;		/* ��ǰ Y ֵ */

	D = 3 - (_usRadius << 1);
	CurX = 0;
	CurY = _usRadius;

	while (CurX <= CurY)
	{
		SPFD5420_PutPixel(_usX + CurX, _usY + CurY, _usColor);
		SPFD5420_PutPixel(_usX + CurX, _usY - CurY, _usColor);
		SPFD5420_PutPixel(_usX - CurX, _usY + CurY, _usColor);
		SPFD5420_PutPixel(_usX - CurX, _usY - CurY, _usColor);
		SPFD5420_PutPixel(_usX + CurY, _usY + CurX, _usColor);
		SPFD5420_PutPixel(_usX + CurY, _usY - CurX, _usColor);
		SPFD5420_PutPixel(_usX - CurY, _usY + CurX, _usColor);
		SPFD5420_PutPixel(_usX - CurY, _usY - CurX, _usColor);

		if (D < 0)
		{
			D += (CurX << 2) + 6;
		}
		else
		{
			D += ((CurX - CurY) << 2) + 10;
			CurY--;
		}
		CurX++;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: SPFD5420_DrawBMP
*	����˵��: ��LCD����ʾһ��BMPλͼ��λͼ����ɨ����򣺴����ң����ϵ���
*	��    �Σ�
*			_usX, _usY : ͼƬ������
*			_usHeight  ��ͼƬ�߶�
*			_usWidth   ��ͼƬ���
*			_ptr       ��ͼƬ����ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_DrawBMP(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr)
{
	uint32_t index = 0;
	const uint16_t *p;

	/* ����ͼƬ��λ�úʹ�С�� ��������ʾ���� */
	SPFD5420_SetDispWin(_usX, _usY, _usHeight, _usWidth);

	p = _ptr;
	for (index = 0; index < _usHeight * _usWidth; index++)
	{
		SPFD5420_PutPixel(_usX, _usY, *p++);
	}

	/* �˳����ڻ�ͼģʽ */
	SPFD5420_QuitWinMode();
}

/*
*********************************************************************************************************
*	�� �� ��: SetBackLight_byMCU
*	����˵��: ��ʼ������LCD�������GPIO,����ΪPWMģʽ��
*			���رձ���ʱ����CPU IO����Ϊ��������ģʽ���Ƽ�����Ϊ������������������͵�ƽ)����TIM3�ر� ʡ��
*	��    �Σ�_bright ���ȣ�0����255������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SPFD5420_SetBackLight(uint8_t _bright)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	/* ��1������GPIOB RCC_APB2Periph_AFIO ��ʱ��	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

	if (_bright == 0)
	{
		/* ���ñ���GPIOΪ����ģʽ */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);

		/* �ر�TIM3 */
		TIM_Cmd(TIM3, DISABLE);
		return;
	}
	else if (_bright == BRIGHT_MAX)	/* ������� */
	{
		/* ���ñ���GPIOΪ�������ģʽ */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);

		GPIO_SetBits(GPIOB, GPIO_Pin_1);

		/* �ر�TIM3 */
		TIM_Cmd(TIM3, DISABLE);
		return;
	}

	/* ���ñ���GPIOΪ�����������ģʽ */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* ʹ��TIM3��ʱ�� */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	/*
		TIM3 ����: ����1·PWM�ź�;
		TIM3CLK = 72 MHz, Prescaler = 0(����Ƶ), TIM3 counter clock = 72 MHz
		���㹫ʽ��
		PWM���Ƶ�� = TIM3 counter clock /(ARR + 1)

		������������Ϊ100Hz

		�������TIM3CLKԤ��Ƶ����ô�����ܵõ�100Hz��Ƶ��
		�������÷�Ƶ�� = 1000�� ��ô  TIM3 counter clock = 72KHz
		TIM_Period = 720 - 1;
		Ƶ���²�����
	 */
	TIM_TimeBaseStructure.TIM_Period = 720 - 1;	/* TIM_Period = TIM3 ARR Register */
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	/*
		_bright = 1 ʱ, TIM_Pulse = 1
		_bright = 255 ʱ, TIM_Pulse = TIM_Period
	*/
	TIM_OCInitStructure.TIM_Pulse = (TIM_TimeBaseStructure.TIM_Period * _bright) / BRIGHT_MAX;	/* �ı�ռ�ձ� */

	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM3, ENABLE);

	/* ʹ�� TIM3 ��ʱ�� */
	TIM_Cmd(TIM3, ENABLE);
}
/********************************************************************************************************************************************************************************************
                                                                                                main.c�е��ļ�

*********************************************************************************************************************************************************************************************/
/*
*********************************************************************************************************
*	�� �� ��: MainMenu
*	����˵��: ���˵�״̬
*	��    �Σ���
*	�� �� ֵ: ״̬��
*********************************************************************************************************
*/
static uint8_t MainMenu(void)
{
//	uint8_t ucKeyCode;		/* �������� */
	uint8_t ucTouch;		/* �����¼� */
	uint8_t fRefresh;		/* ˢ�������־,1��ʾ��Ҫˢ�� */
	FONT_T tFont;			/* ����һ������ṹ���������������������� */
	char buf[64];
	uint16_t usAdcX, usAdcY;
	int16_t tpX, tpY;

	LCD_ClrScr(CL_BLUE);  	/* ������������ɫ */

	/* ����������� */
	{
		tFont.usFontCode = FC_ST_16;	/* ������� 16���� */
		tFont.usTextColor = CL_WHITE;	/* ������ɫ */
		tFont.usBackColor = CL_BLUE;	/* ���ֱ�����ɫ */
		tFont.usSpace = 0;				/* ���ּ�࣬��λ = ���� */
	}

	fRefresh = 1;	/* 1��ʾ��Ҫˢ��LCD */
	while (1)
	{
		CPU_IDLE();

		if (fRefresh)
		{
			fRefresh = 0;

			/* ʵʱˢ�´���ADC����ֵ��ת��������� */
			{
				LCD_DispStr(5, 3, "����������������", &tFont);			/* ��(8,3)���괦��ʾһ������ */

				/* ��ʾTFT�������ͺź���Ļ�ֱ��� */
				LCD_GetChipDescribe(buf);
				sprintf(&buf[strlen(buf)], "   %d x %d", LCD_GetWidth(), LCD_GetHeight());
				LCD_DispStr(5, 23, buf, &tFont);			/* ��(8,3)���괦��ʾһ������ */

				/* ��ȡ����ʾ��ǰX���Y���ADC����ֵ */
				usAdcX = TOUCH_ReadAdcX();
				usAdcY = TOUCH_ReadAdcY();
				sprintf(buf, "����ADCֵ X = %4d, Y = %4d   ", usAdcX, usAdcY);
				LCD_DispStr(5, 60, buf, &tFont);

				/* ��ȡ����ʾ��ǰ�������� */
				tpX = TOUCH_GetX();
				tpY = TOUCH_GetY();
				sprintf(buf, "��������  X = %4d, Y = %4d   ", tpX, tpY);
				LCD_DispStr(5, 80, buf, &tFont);

				/* �ڴ�������λ����ʾһ��СȦ */
				if ((tpX > 0) && (tpY > 0))
				{
					LCD_DrawCircle(tpX, tpY, 2, CL_YELLOW);
				}
			}

			/* ��ָ��λ����ʾ3��ͼ�� */
			LCD_DrawIcon(ICON1_X, ICON1_Y, ICON1_H, ICON1_W, (uint16_t *)gImage_QQ);
			LCD_DispStr(ICON1_X + 1, ICON1_Y + ICON1_H + 2, " У׼", &tFont);

			LCD_DrawIcon(ICON2_X, ICON2_Y, ICON2_H, ICON2_W, (uint16_t *)gImage_Bat);
			LCD_DispStr(ICON2_X + 1, ICON2_Y + ICON2_H + 2, " ����", &tFont);

			LCD_DrawIcon(ICON3_X, ICON3_Y, ICON3_H, ICON3_W, (uint16_t *)gImage_Spk);
			LCD_DispStr(ICON3_X + 1, ICON3_Y + ICON3_H + 2, " ����", &tFont);
		}

		ucTouch = TOUCH_GetKey(&tpX, &tpY);	/* ��ȡ�����¼� */
		if (ucTouch != TOUCH_NONE)
		{
			switch (ucTouch)
			{
				case TOUCH_DOWN:		/* ���ʰ����¼� */
					if (TOUCH_InRect(tpX, tpY, ICON1_X, ICON1_Y, ICON1_H, ICON1_W))
					{
						LCD_DrawIconActive(ICON1_X, ICON1_Y, ICON1_H, ICON1_W, (uint16_t *)gImage_QQ);
					}
					else if (TOUCH_InRect(tpX, tpY, ICON2_X, ICON2_Y, ICON2_H, ICON2_W))
					{
						LCD_DrawIconActive(ICON2_X, ICON2_Y, ICON2_H, ICON2_W, (uint16_t *)gImage_Bat);
					}
					else if (TOUCH_InRect(tpX, tpY, ICON3_X, ICON3_Y, ICON3_H, ICON3_W))
					{
						LCD_DrawIconActive(ICON3_X, ICON3_Y, ICON3_H, ICON3_W, (uint16_t *)gImage_Spk);
					}
					break;

				case TOUCH_MOVE:		/* �����ƶ��¼� */
					/* ʵʱˢ�´���ADC����ֵ��ת��������� */
					{
						/* ��ȡ����ʾ��ǰX���Y���ADC����ֵ */
						usAdcX = TOUCH_ReadAdcX();
						usAdcY = TOUCH_ReadAdcY();
						sprintf(buf, "����ADCֵ X = %4d, Y = %4d   ", usAdcX, usAdcY);
						LCD_DispStr(5, 60, buf, &tFont);

						/* ��ȡ����ʾ��ǰ�������� */
						tpX = TOUCH_GetX();
						tpY = TOUCH_GetY();
						sprintf(buf, "��������  X = %4d, Y = %4d   ", tpX, tpY);
						LCD_DispStr(5, 80, buf, &tFont);

						/* �ڴ�������λ����ʾһ��СȦ */
						if ((tpX > 0) && (tpY > 0))
						{
							LCD_DrawCircle(tpX, tpY, 2, CL_YELLOW);
						}
					}
					break;

				case TOUCH_RELEASE:		/* �����ͷ��¼� */
					if (TOUCH_InRect(tpX, tpY, ICON1_X, ICON1_Y, ICON1_H, ICON1_W))
					{
						return MS_CALIBRATION;		/* ���봥��У׼���� */
					}
					else if (TOUCH_InRect(tpX, tpY, ICON2_X, ICON2_Y, ICON2_H, ICON2_W))
					{
						return MS_ADJUST_BRIGHT;	/* ���뱳����ڽ��� */
					}
					else if (TOUCH_InRect(tpX, tpY, ICON3_X, ICON3_Y, ICON3_H, ICON3_W))
					{
						LCD_ClrScr(CL_BLUE);  		/* ������������ɫ */
						fRefresh = 1;
					}
					break;
			}
		}

#if 0
		ucKeyCode = bsp_GetKey();	/* ��ȡ��ֵ, �޼�����ʱ���� KEY_NONE = 0 */
		if (ucKeyCode != KEY_NONE)
		{
			/* �м����� */
			switch (ucKeyCode)
			{
				case  KEY_DOWN_JOY_OK:		/* ҡ��OK�� */
					return MS_CALIBRATION;	/* ���봥������ */
					//break;

				default:
					break;
			}
		}
#endif
	}
}

/*
*********************************************************************************************************
*	�� �� ��: AdjustBright
*	����˵��: ���ڱ�����
*	��    �Σ���
*	�� �� ֵ: ״̬��
*********************************************************************************************************
*/
static uint8_t AdjustBright(void)
{
	uint8_t ucBright;		/* ����Ϊȱʡ���� */
//	uint8_t ucKeyCode;		/* �������� */
	uint8_t fRefresh;		/* ����ˢ�������־ */
	char buf[64];
	FONT_T tFont;		/* ����һ������ṹ���������������������� */

	/* ����������� */
	{
		tFont.usFontCode = FC_ST_16;	/* ������� 16���� */
		tFont.usTextColor = CL_WHITE;	/* ������ɫ */
		tFont.usBackColor = CL_BLUE;	/* ���ֱ�����ɫ */
		tFont.usSpace = 0;				/* ���ּ�࣬��λ = ���� */
	}

	/* ��ȡ��ǰ�ı������Ȳ��� */
	ucBright = LCD_GetBackLight();

	LCD_ClrScr(CL_BLUE);	/* �����Ļ */

	LCD_DispStr(10, 10, "ҡ�����¼�����LCD������", &tFont);
	LCD_DispStr(10, 30, "ҡ���м�ȷ���˳�", &tFont);

	/* ��ʾ1����ɫͼ�꣬���ڹ۲챳��Ч�� */
	LCD_DrawIcon(10, 70, ICON1_H, ICON1_W, (uint16_t *)gImage_UDisk);

	/* ����������ѭ���� */
	fRefresh = 1;
	while (1)
	{
		CPU_IDLE();

		if (fRefresh == 1)
		{
			fRefresh = 0;

			sprintf(buf, "��ǰLCD���������� = %d  ", ucBright);
			LCD_DispStr(10, 50, buf, &tFont);
		}

#if 0
		ucKeyCode = bsp_GetKey();	/* ��ȡ��ֵ, �޼�����ʱ���� KEY_NONE = 0 */
		if (ucKeyCode != KEY_NONE)
		{
			/* �м����� */
			switch (ucKeyCode)
			{
				case KEY_DOWN_JOY_LEFT:		/* ҡ��LEFT������ */
				case KEY_DOWN_JOY_RIGHT:	/* ҡ��RIGHT������ */
					break;

				case KEY_DOWN_JOY_UP:		/* ҡ��UP������ */
					if (ucBright < 255)
					{
						ucBright++;
					}
					LCD_SetBackLight(ucBright);
					fRefresh = 1;
					break;

				case KEY_DOWN_JOY_DOWN:		/* ҡ��DOWN������ */
					if (ucBright > 0)
					{
						ucBright--;
					}
					LCD_SetBackLight(ucBright);
					fRefresh = 1;
					break;

				case KEY_DOWN_JOY_OK:		/* ҡ��OK�� */
					return MS_MAIN_MENU;	/* ���ص����˵� */
					/* break;*/

				default:
					break;
			}
		}
#endif
	}
}

/*
*********************************************************************************************************
*	�� �� ��: InitBoard
*	����˵��: ��ʼ��Ӳ���豸
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void InitBoard(void)
{
	/* ���ô��ڣ�����printf��� */
	bsp_InitUart();

	/* ����LEDָʾ��GPIO */
//	bsp_InitLed();

	/* ���ð���GPIO, ������bsp_InitTimer֮ǰ���� */
//	bsp_InitButton();

	/* ��ʼ��systick��ʱ������������ʱ�ж� */
	bsp_InitTimer();
}

/*
*********************************************************************************************************
*	�� �� ��: PrintfLogo
*	����˵��: ��ӡ�������ƺ����̷�������, ���ϴ����ߺ󣬴�PC���ĳ����ն�������Թ۲���
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void PrintfLogo(void)
{
	printf("*************************************************************\n\r");
	printf("* ��������   : %s\r\n", EXAMPLE_NAME);	/* ��ӡ�������� */
	printf("* ���̰汾   : %s\r\n", DEMO_VER);		/* ��ӡ���̰汾 */
	printf("* ��������   : %s\r\n", EXAMPLE_DATE);	/* ��ӡ�������� */

	/* ��ӡST�̼���汾����3���������stm32f10x.h�ļ��� */
	printf("* �̼���汾 : %d.%d.%d\r\n", __STM32F10X_STDPERIPH_VERSION_MAIN,
			__STM32F10X_STDPERIPH_VERSION_SUB1,__STM32F10X_STDPERIPH_VERSION_SUB2);
	printf("* \n\r");	/* ��ӡһ�пո� */
	printf("* QQ    : 1295744630 \r\n");
	printf("* Email : armfly@qq.com \r\n");
	printf("* Copyright www.armfly.com ����������\r\n");
	printf("*************************************************************\n\r");


