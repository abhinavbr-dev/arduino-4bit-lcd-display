#include<avr/io.h>
void fcom(char x)
{
  char temp;
  PORTB=~(1<<0);
  temp=(x&0xf0);
  temp=(temp>>4);
  PORTB&=~(0xf<<2);
  PORTB|=(temp<<2);
  PORTB|=(1<<1);
  _delay_ms(50);
  PORTB&=~(1<<1);
  _delay_ms(50);
  
  temp=(x&0x0f);
  PORTB&=~(0xf<<2);
  PORTB|=(temp<<2);
  PORTB|=(1<<1);
  _delay_ms(50);
  PORTB&=~(1<<1);
  _delay_ms(50);  
}

void fdat(char x)
{
  char temp;
PORTB= (1<<0);           //1. select the data register.
                         //2. Write mode of LCD.-> rw=0= GND
temp=(x&0xf0);
  temp=(temp>>4);
  PORTB&=~(0xf<<2);
  PORTB|=(temp<<2);
  PORTB|=(1<<1);
  _delay_ms(50);
  PORTB&=~(1<<1);
  _delay_ms(50);
  temp=(x&0x0f);
  PORTB&=~(0xf<<2);
  PORTB|=(temp<<2);
  PORTB|=(1<<1);
  _delay_ms(50);
  PORTB&=~(1<<1);
  _delay_ms(50);
          //delay
}

int main()
{
int i;
DDRB= (0x3f);         //set the direction of LCD pins

char b[]= "shameem"; 
char d[]="abhinav";

fcom(0x02);
fcom(0x28);
fcom(0x01);
fcom(0x80);
//fcom(0xc0);
//fcom(0x89);
fcom(0x0e);
//fcom(0x0c);
//fcom(0x0f);

fdat('I');
fdat('S');
fdat('M'); 

_delay_ms(100);
fcom(0x01);
for(i=0; b[i]!='\0'; i++)
{
fdat(b[i]);
_delay_ms(100);
}

fcom(0xc3);
for(i=0;d[i]!='\0';i++)
{
  fdat(d[i]);
  _delay_ms(100);
}
while(1)
 {
  fcom(0x1c);
  _delay_ms(10);
  }
}
