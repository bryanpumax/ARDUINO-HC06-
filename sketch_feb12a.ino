/*
 Incluimos las libreria SoftwareSerial.h para crear dos puertos virtuales que seran el 7 y 8
 creado el 19 de feb de 2014
 modificado el 09 de oct de 2015 by Cas6678
*/

#include <SoftwareSerial.h>
SoftwareSerial Serial3(10,11);        // Pin 7 y 8 para TX y RX

void setup()
{
Serial3.begin(9600);  // 
Serial.begin(9600);
Serial.println("Empieza delay");
delay(10000);
Serial.println("Termina delay");
Serial3.print("AT");
Serial.print("AT");
//Espera de 1 segundo según datasheet entre envio de comandos AT
delay(1000);
//Cambio de nombre donde se envia AT+NAME y seguido el nombre que deseemos
Serial3.print("AT+NAMEUTC Modulo Ph1"); // para llamarlo MIBTHC06
//Espera de 1 segundo según datasheet entre envio de comandos AT
Serial.println("AT+NAMEUTC Modulo Ph1");
delay(1000);
/*Cambio de la velocidad del modulo en baudios
Se envia AT+BAUD y seguido el numero correspondiente:

1 -- 1200 baudios
2 -- 2400 baudios
3 -- 4800 baudios
4 -- 9600 baudios (por defecto)
5 -- 19200 baudios
6 -- 38400 baudios
7 -- 57600 baudios
8 -- 115200 baudios

*/
Serial3.print("AT+BAUD4"); // para subirle la velocidad a 38400
//Espera de 1 segundo según datasheet entre envio de comandos AT
Serial.println("AT+BAUD4");
delay(1000);
//Configuracion Password, se envia AT+PIN y seguido password que queremos
Serial3.print("AT+PIN1997"); // para ponerle el pin 1111
//Espera de 1 segundo según datasheet entre envio de comandos AT
Serial.println("AT+PIN1997"); 
delay(1000);
//Mostramos tanto por puerto serial y por led la finalizacion de la
//configuracion AT del modulo bluetooth
Serial.println("TERMINADO");

}
void loop()
{ }