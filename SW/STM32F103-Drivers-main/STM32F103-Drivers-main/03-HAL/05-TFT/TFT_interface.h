/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 29 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_


#define TFT_BLACK        0x0000
#define TFT_WHITE        0xFFFF
#define TFT_RED          0xF800
#define TFT_BLUE         0x001F
#define TFT_YELLOW       0xFFE0
#define TFT_ORANGE       0xFD20
#define TFT_PURPLE       0x780F
#define TFT_GREEN        0x07E0
#define TFT_MAGENTA      0xF81F




void HTFT_voidInit (void);

void HTFT_voidDisplayImage(const u16* copy_u16Image);

void HTFT_voidDrawRectangle (u16 copy_u16X ,u16 copy_u16Y , u16 copy_u16Width , u16 copy_u16Hight , u16 copy_u16Color );

void HTFT_voidFillDisplay (u16 copy_u16Colour);

void HTFT_voidPrintChar(s8 copy_s8Char , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color, u16 copy_u16BackColor);

void HTFT_voidPrintText(s8 *copy_s8Text , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color, u16 copy_u16BackColor);

void HTFT_voidprintNumber(u16 Copy_u16Number , u16 copy_u16X, u16 copy_u16Y, u8 copy_u8Size, u16 copy_u16Color, u16 copy_u16BackColor);


#endif
