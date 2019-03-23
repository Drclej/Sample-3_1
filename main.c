
#include <msp430f249.h>
#define uchar unsigned char
#define uint unsigned int

/*Èí¼þÑÓ³ÙmsÖ÷³ÌÐò*/
 
void delayus(uint t)
{
    uint i;
    while(t--){
        for(i=1300;i>0;i--);
  }
}

int main( void )
{
    // Stop watchdog timer to prevent time out reset
    uint mask = 0x01;
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR = 0xFF;
    P1SEL = 0x00;
    P1OUT = 0xFF;
    while(1)
    {
      if ((P2IN & 0x07) == 0x06)
      {
        P1OUT ^= (BIT0+BIT4);
        delayus(100);
      }
      else if ((P2IN & 0x07) == 0x05)
      {
        P1OUT ^= (BIT1+BIT5);
        delayus(200);
      }
      else if ((P2IN & 0x07) == 0x03)
      {
        P1OUT =~mask;
        delayus(10);
        mask += mask;
        
        if (mask == 0x100)
          mask = 0x01;
      }      
      if ((P2IN & 0x07) == 0x07)
        P1OUT = 0xFF;
    }
}
