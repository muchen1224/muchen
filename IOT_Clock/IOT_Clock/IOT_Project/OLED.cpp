#include "stdint.h"
#include <Arduino.h>
#include "OLED.h"

#define OLED_W_SCL(x)		digitalWrite(D1, (x))
#define OLED_W_SDA(x)		digitalWrite(D2, (x))
#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0

void OLED_I2C_Init(void)
{
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);

	OLED_W_SCL(GPIO_PIN_SET);
	OLED_W_SDA(GPIO_PIN_SET);
}
/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void OLED_I2C_Start(void)
{
	OLED_W_SDA(GPIO_PIN_SET);
	OLED_W_SCL(GPIO_PIN_SET);
	OLED_W_SDA(GPIO_PIN_RESET);
	OLED_W_SCL(GPIO_PIN_RESET);
}

/**
  * @brief  I2C停止
  * @param  无
  * @retval 无
  */
void OLED_I2C_Stop(void)
{
	OLED_W_SDA(GPIO_PIN_RESET);
	OLED_W_SCL(GPIO_PIN_SET);
	OLED_W_SDA(GPIO_PIN_SET);
}

/**
  * @brief  I2C发送一个字节
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void OLED_I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i++)
	{
		OLED_W_SDA(Byte & (0x80 >> i));
		OLED_W_SCL(GPIO_PIN_SET);
		OLED_W_SCL(GPIO_PIN_RESET);
	}
	OLED_W_SCL(GPIO_PIN_SET);	//额外的一个时钟，不处理应答信号
	OLED_W_SCL(GPIO_PIN_RESET);
}

/**
  * @brief  OLED写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void OLED_WriteCommand(uint8_t Command)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x00);		//写命令
	OLED_I2C_SendByte(Command); 
	OLED_I2C_Stop();
}

/**
  * @brief  OLED写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void OLED_WriteData(uint8_t Data)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x40);		//写数据
	OLED_I2C_SendByte(Data);
	OLED_I2C_Stop();
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);					//设置Y位置
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_WriteCommand(0x00 | (X & 0x0F));			//设置X位置低4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  */
void OLED_Clear(void)
{  
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(0x00);
		}
	}
}

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{      	
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

/**
  * @brief  OLED显示字符串
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowString(uint8_t Line, uint8_t Column, const char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}

/**
  * @brief  OLED次方函数
  * @retval 返回值等于X的Y次方
  */
uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

/**
  * @brief  OLED显示数字（十进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~4294967295
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十进制，带符号数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-2147483648~2147483647
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length)
{
	uint8_t i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十六进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
  * @param  Length 要显示数字的长度，范围：1~8
  * @retval 无
  */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
}

/**
  * @brief  OLED显示数字（二进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
}

//改写

void OLED_ShowPointNum(uint8_t Line, uint8_t Column, float Number, uint8_t Int_Length, uint8_t Float_Length)
{
	uint8_t i, j;
  uint32_t Temp = Number;  
	for (i = 0; i < Int_Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Temp / OLED_Pow(10, Int_Length - i - 1) % 10 + '0');
	}
  OLED_ShowChar(Line, Column + i, '.');
	for (j = 0; j < Float_Length; j++)							
	{
    Temp = Number * OLED_Pow(10, Float_Length);
    Temp %= OLED_Pow(10, Float_Length);

    OLED_ShowChar(Line, Column + i + j + 1, Temp / OLED_Pow(10, Float_Length - j - 1) % 10 + '0');
  }
}

void OLED_ShowSignedPointNum(uint8_t Line, uint8_t Column, float Number, uint8_t Int_Length, uint8_t Float_Length)
{
	float Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
  OLED_ShowPointNum(Line, Column + 1, Number1, Int_Length, Float_Length);
	// for (i = 0; i < Length; i++)							
	// {
	// 	OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	// }
}

/**
  * @brief  OLED初始化
  * @param  无
  * @retval 无
  */
void OLED_Init(void)
{
	uint32_t i, j;
	
	for (i = 0; i < 1000; i++)			//上电延时
	{
		for (j = 0; j < 1000; j++);
	}
	
	OLED_I2C_Init();			//端口初始化
	
	OLED_WriteCommand(0xAE);	//关闭显示
	
	OLED_WriteCommand(0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCommand(0x80);
	
	OLED_WriteCommand(0xA8);	//设置多路复用率
	OLED_WriteCommand(0x3F);
	
	OLED_WriteCommand(0xD3);	//设置显示偏移
	OLED_WriteCommand(0x00);
	
	OLED_WriteCommand(0x40);	//设置显示开始行
	
	OLED_WriteCommand(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCommand(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCommand(0xDA);	//设置COM引脚硬件配置
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	//设置对比度控制
	OLED_WriteCommand(0xCF);

	OLED_WriteCommand(0xD9);	//设置预充电周期
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);	//设置整个显示打开/关闭

	OLED_WriteCommand(0xA6);	//设置正常/倒转显示

	OLED_WriteCommand(0x8D);	//设置充电泵
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);	//开启显示
		
	OLED_Clear();				//OLED清屏
}

void OLED_ShowAPicTure(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t Weather_Code)
{
	uint16_t i = 0;
	uint8_t  j = 0;
	
	for(i = 0; i < (y2 - y1 + 1); i++)
	{
		OLED_SetCursor((y1 + i), x1);
		for(j = 0; j < (x2 - x1 + 1); j++)
			OLED_WriteData(OLED_Picture3[Weather_Code][i][j]);
	}
}

void OLED_ShowAHanzi(uint8_t Line_Temp, uint8_t Column_Temp, uint8_t Number)
{
	uint8_t i, Column, Line;
	
	Line = (Line_Temp * 2) - 1;
	Column = 1 + (Column_Temp - 1) * 16;
	
	OLED_SetCursor((Line - 1), (Column - 1));		//设置光标位置在上半部分
	for (i = 0; i < 16; i++)
	{
		OLED_WriteData(OLED_Hanzi16x16[Number * 2][i]);			//显示上半部分内容
	}
	OLED_SetCursor(Line, Column - 1);	//设置光标位置在下半部分
	for (i = 0; i < 16; i++)
	{
		OLED_WriteData(OLED_Hanzi16x16[Number * 2][i + 16]);		//显示下半部分内容
	}
}

void OLED_ShowCarton(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t Number)
{
	uint16_t i = 0;
	uint8_t  j = 0;
	
	for(i = 0; i < (y2 - y1 + 1); i++)
	{
		OLED_SetCursor((y1 + i), x1);
		for(j = 0; j < (x2 - x1 + 1); j++)
			OLED_WriteData(OLED_Picture2[Number][i][j]);
	}
}

void OLED_ShowTime(uint8_t Line, uint8_t Column, const char *String)
{
	uint8_t i; uint8_t j; uint8_t k; uint8_t Index = 0;
	for (i = 0; String[i] != '\0'; i++)
	{
    for(k = 0; k < 4; k++)
    {
      OLED_SetCursor((Line - 1) + k, (Column + i - 1) * 16);
      for (j = 0; j < 16; j++)
      {
        if(String[i] == ':')
          Index = 10;
        else
         Index = String[i] - '0';
        OLED_WriteData(OLED_ShowTimeFont[Index][j + k * 16]);
      }
    }
	}
}

// void OLED_ShowString(uint8_t Line, uint8_t Column, const char *String)
// {
// 	uint8_t i;
// 	for (i = 0; String[i] != '\0'; i++)
// 	{
// 		OLED_ShowChar(Line, Column + i, String[i]);
// 	}
// }
