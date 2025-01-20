/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 29 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#include "STD_type.h"
#include "BIT_math.h"
#include "FunHelp.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"


#include "TFT_interface.h"
#include "TFT_config.h"

#include "TFT_private.h"



void HTFT_voidInit (void)
{


	MGPIO_VidSetPinDirection(TFT_A0_PIN,OUT_SPEED_2MHZ_PP);  /* A0   */
	MGPIO_VidSetPinDirection(TFT_RST_PIN,OUT_SPEED_2MHZ_PP);  /* RST  */
	/* Reset pulse */
	MGPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(100) ;
	MGPIO_VidSetPinValue(TFT_RST_PIN, LOW);
	MSTK_voidSetBusyWait(2) ;
	MGPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(100) ;
	MGPIO_VidSetPinValue(TFT_RST_PIN, LOW);
	MSTK_voidSetBusyWait(100) ;
	MGPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(120000) ;

	/* SLPOT  COMMAND */

	voidWriteCommand(0x11) ;
	/* wait 150 msec */
	MSTK_voidSetBusyWait(150000) ;
	/* color mode Command + paramter */
	voidWriteCommand(0x3A) ;
	voidWriteData(0x05);
	/* Display on command */
	voidWriteCommand(0x29) ;


}




void HTFT_voidDisplayImage (const u16* copy_u16Image)
{

	u16 local_u16Counter =0  ;

	/* Set address range for the whole display */
	voidSetAddress(0  , TFT_MAX_X , 0 , TFT_MAX_Y);

	for(local_u16Counter = 0; local_u16Counter< (TFT_MAX_X * TFT_MAX_Y);local_u16Counter++)
		{
		voidSetColour(copy_u16Image[local_u16Counter]);

		}


}




void HTFT_voidFillDisplay (u16 copy_u16Colour)
{
	HTFT_voidDrawRectangle(0 , 0 ,TFT_MAX_X+1 , TFT_MAX_Y+1 , copy_u16Colour);

}


void HTFT_voidDrawRectangle (u16 copy_u16X ,u16 copy_u16Y , u16 copy_u16Width , u16 copy_u16Hight , u16 copy_u16Color )
{

	u16 loacal_u16EndX = copy_u16X + copy_u16Width - 1;
	u16 loacal_u16EndY = copy_u16Y + copy_u16Hight - 1;

	/* Set area of addresses */
	voidSetAddress(copy_u16X ,loacal_u16EndX,copy_u16Y ,loacal_u16EndY );

	/* Draw the Rectangle*/
	for (u16 i = 0 ; i < (copy_u16Width *copy_u16Hight ) ; i++){
		voidSetColour(copy_u16Color);
	}

}



void HTFT_voidPrintChar(s8 copy_s8Char , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color, u16 copy_u16BackColor)
{

	/* Get array index */
	u8 local_u8CharIndex = 0 ;
	if (( copy_s8Char >= ' ' )){
		local_u8CharIndex = copy_s8Char - 32 ;
	}

	/* Background */
	HTFT_voidDrawRectangle( copy_u16X, copy_u16Y ,copy_u8Size*TFT_CHARACTER_WIDTH ,copy_u8Size*TFT_CHARACTER_HIGHT ,copy_u16BackColor);

	for (u8 i = 0; i <TFT_CHARACTER_WIDTH ; i++ ){
		for (u8 j = 0 ; j <TFT_CHARACTER_HIGHT ; j++){
			if (TFT_font[local_u8CharIndex][i] & (1 << j)){
				if (copy_u8Size == 1){
					voidDrawPixel(copy_u16X+i , copy_u16Y+j , copy_u16Color);
				}
				else {
					u16 local_x = copy_u16X+(i*copy_u8Size) ;
					u16 local_y = copy_u16Y+(j*copy_u8Size) ;
					HTFT_voidDrawRectangle( local_x, local_y ,copy_u8Size ,copy_u8Size ,copy_u16Color);
				}
			}
		}
	}
}

void HTFT_voidPrintText(s8 *copy_s8Text , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color, u16 copy_u16BackColor)
{
	while (*copy_s8Text){
			HTFT_voidPrintChar(*copy_s8Text , copy_u16X ,copy_u16Y ,copy_u8Size ,copy_u16Color,copy_u16BackColor );
			copy_u16X += (copy_u8Size *TFT_CHARACTER_WIDTH)  ;
			copy_s8Text++;
		}
}


void HTFT_voidprintNumber(u16 Copy_u16Number , u16 copy_u16X, u16 copy_u16Y, u8 copy_u8Size, u16 copy_u16Color, u16 copy_u16BackColor) {
    u8 Local_u8Buffer[10]; // Buffer to hold the number as a string
    itoi(Copy_u16Number, Local_u8Buffer, 10); // Convert number to string in base 10
    HTFT_voidPrintText((s8*)Local_u8Buffer, copy_u16X, copy_u16Y, copy_u8Size, copy_u16Color, copy_u16BackColor); // Print the text
}




/////////////////////////////////////////////////////////////////////////////////////////////
static void voidWriteCommand (u8 Copy_u8Command )
{
	u8 Local_u8Temp ; 
	/* set pin A0 in TFT_Module Low */
	MGPIO_VidSetPinValue(TFT_A0_PIN, LOW);
	/* send Command  using SPI */
	MSPI1_voidSendReciveSynch(Copy_u8Command , &Local_u8Temp) ; 


}


static void voidWriteData (u8 Copy_u8Data )
{
	u8 Local_u8Temp ;
	/* set pin A0 in TFT_Module Low */
	MGPIO_VidSetPinValue(TFT_A0_PIN, HIGH);
	/* send Command  using SPI */
	MSPI1_voidSendReciveSynch(Copy_u8Data , &Local_u8Temp) ;


}





static void voidDrawPixel (u16 copy_u16X , u16 copy_u16Y , u16 copy_u16Colour)
{
	if ( (copy_u16X < TFT_MAX_X ) && (copy_u16Y < TFT_MAX_Y )){

		/* Set address of the pixel */
		voidSetAddress(copy_u16X  , copy_u16X+1 , copy_u16Y , copy_u16Y+1);

		/* Write pixel colour */
		voidSetColour(copy_u16Colour);
	}
}




static void voidSetAddress (u16 copy_u16StartX ,u16 copy_u16EndX , u16 copy_u16StartY , u16 copy_u16EndY)
{
	if ( (copy_u16StartX < TFT_MAX_X ) && (copy_u16StartY < TFT_MAX_Y )){
		/* Set x Address */
		voidWriteCommand(0x2A);
		/* Start byte */
		voidWriteData((copy_u16StartX >> 8));  // MS byte
		voidWriteData(copy_u16StartX);

		/* Stop byte */
		voidWriteData((copy_u16EndX >> 8));
		voidWriteData(copy_u16EndX);

		/* Set y Address */
		voidWriteCommand(0x2B);
		/* Start byte */
		voidWriteData((copy_u16StartY >> 8));  // MS byte
		voidWriteData(copy_u16StartY);
		/* Stop byte */
		voidWriteData((copy_u16EndY >> 8));
		voidWriteData(copy_u16EndY);

		/* RAM write */
		voidWriteCommand(0x2C);
	}
}


static void voidSetColour(u16 copy_u16Colour)
{

	/* Write pixel */
	u8 high_byte = (copy_u16Colour >> 8);
	u8 low_byte = (copy_u16Colour & 0x00ff);
	voidWriteData(high_byte);
	voidWriteData(low_byte);
}







