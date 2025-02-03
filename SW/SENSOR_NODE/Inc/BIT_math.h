/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 29 FEB 2024                */
/* Version          : v01                        */ 
/*************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR, BIT_NO)    (VAR |=  (1 << (BIT_NO)))
#define CLR_BIT(VAR, BIT_NO)    (VAR &= ~(1 << (BIT_NO)))
#define TOGGLE_BIT(VAR, BIT_NO) (VAR ^=  (1 << (BIT_NO)))
#define GET_BIT(VAR, BIT_NO)    ((VAR >> BIT_NO) & 0x01)

/* Read a value from a register */
#define READ_REG(REG)           (REG)

/* Write a value to a register */
#define WRITE_REG(REG, VALUE)   (REG = (VALUE))

#endif /* BIT_MATH_H_ */
