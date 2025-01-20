

#include"STD_type.h"
#include "BIT_math.h"

#include "FunHelp.h"





u8 STR_COMPARE(u8 * ptr1,u8 * ptr2){

	u8 x,i=0;

	while( (ptr1[i]==ptr2[i])){

		i++;

		if(ptr1[i]=='\0' && ptr2[i]=='\0'){x=1;break;}

		else if( (ptr1[i]!='\0' && ptr2[i]=='\0') || (ptr1[i]=='\0' && ptr2[i]!='\0')){x=0;break;}

	}

	if(ptr1[i]!=ptr2[i]){x=0;}

	return x;
}

u8 STR_LEN(const u8 *str) {
    u8 length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}



void STR_COPY(u8 *dest, const u8 *src) {
    u8 i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';  // Add the null terminator to the end of the destination string
}






void itoi(u16 num, u8 *str, u16 base) {
    u16 i = 0;
    u16 isNegative = 0;

    // Handle 0 explicitly
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Handle negative numbers for base 10
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        u16 rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // Add negative sign if the number was negative
    if (isNegative) {
        str[i++] = '-';
    }

    // Append the null terminator to mark the end of the string
    str[i] = '\0';

    // Reverse the string to get the correct result
    u16 start = 0;
    u16 end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}



u32 map(u32 x, u32 in_min, u32 in_max, u32 out_min, u32 out_max) {
    // Calculate the mapped value
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
