//Envía mensajes SMS al número ingresado
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); //Configarión de los pines serial por software
void setup() {
  /////////////// ENCENDIDO AUTOMÁTICO POR SOFTWARE
  digitalWrite(9, HIGH);
delay(1000);
  ///////////////
  SIM900.begin(19200);//Arduino se comunica con el SIM900 a una velocidad de 19200bps
  delay(20000);//Tiempo prudencial para el escudo inicie sesión de red con tu operador
  envioMensaje();// llama a la función envioMensaje
}
void loop() {  
}
void envioMensaje() {
  SIM900.print("AT+CMGF=1\r"); // comando AT para configurar el SIM900 en modo texto
  delay(200);
    SIM900.println("AT + CMGS = \"7751799262\"");//reemplzar por el número a enviar el mensaje
  delay(200);
  SIM900.println("Va");// Reemplzar por el texto a enviar
  delay(200);
  //Finalizamos este comando con el caracter de sustitución (→) código Ascii 26 para el envio del SMS
  SIM900.println((char)26); 
  delay(200);
  SIM900.println();
}
//
Recuperado de:
http://rogerbit.com/wprb/2018/05/sim900-primeros-pasos-envio-de-sms-llamada-encendido-de-led/
//
