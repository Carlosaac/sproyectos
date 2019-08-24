//Envía mensajes SMS al número ingresado
#include <SoftwareSerial.h>
int pulsador=0;////////////////////////////////////////////////////////////////////////////////
SoftwareSerial SIM900(7, 8); //Configarión de los pines serial por software
void setup() {
    pinMode(2, OUTPUT);////////////////////////////////////////////////////////////////////////
  pinMode(4,INPUT);////////////////////////////////////////////////////////////////////////////
  /////////////// ENCENDIDO AUTOMÁTICO POR SOFTWARE
  digitalWrite(9, HIGH);
delay(1000);
  ///////////////
  SIM900.begin(19200);//Arduino se comunica con el SIM900 a una velocidad de 19200bps
  delay(20000);//Tiempo prudencial para el escudo inicie sesión de red con tu operador


}
void loop() {  
  pulsador=digitalRead(4);
    if(pulsador==HIGH){
      digitalWrite(2,HIGH);
    }
    else{
      digitalWrite(2,LOW);
      }
            if(pulsador==HIGH){
  envioMensaje();// llama a la función envioMensaje
      }
}
void envioMensaje() {
  SIM900.print("AT+CMGF=1\r"); // comando AT para configurar el SIM900 en modo texto
  delay(200);
    SIM900.println("AT + CMGS = \"7751799262\"");//reemplzar por el número a enviar el mensaje
  delay(200);
  SIM900.println("ALERTA!!!");// Reemplzar por el texto a enviar
  delay(200);
  //Finalizamos este comando con el caracter de sustitución (→) código Ascii 26 para el envio del SMS
  SIM900.println((char)26); 
  delay(200);
  SIM900.println();
}
//
