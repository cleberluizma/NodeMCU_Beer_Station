#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 20 chars and 4 line display

const char* ssid = "Miyakoda";
const char* password = "nicole12";

<<<<<<< HEAD
void handleRoot() 
{
=======
ESP8266WebServer server(80);

const int led = 2;

void handleRoot() {
  digitalWrite(led, 1);

>>>>>>> parent of 52efb1f (just updated)
  String textoHTML;

 textoHTML = "Ola!! Aqui &eacute; o <b>ESP8266</b> falando! ";
 textoHTML += "Porta A0: ";
 textoHTML += analogRead(A0);
   
<<<<<<< HEAD
  server.send(200, "text/html", textoHTML);  //digitalWrite(led, 0);
=======
  server.send(200, "text/html", textoHTML);
  digitalWrite(led, 0);
>>>>>>> parent of 52efb1f (just updated)
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
<<<<<<< HEAD
=======
  digitalWrite(led, 0);
>>>>>>> parent of 52efb1f (just updated)
}

void setup()
{
  int dotconectando = 0;
  
  lcd.init();                      // initialize the lcd   
  lcd.backlight();
  ///
 pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output

 ///
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
    lcd.setCursor(0,0);
    lcd.print("CONECTANDO WIFI");  
    lcd.setCursor(dotconectando,1);
    lcd.print(".");
    ledconectando();
    dotconettando++
  }
  lcd.clear();
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    lcd.setCursor(0,0);
    lcd.print(ssid);  
    lcd.setCursor(0,1);//cursor 0 linha 1
    lcd.print(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
  //
 
}

//////////funções/////////////////////////////////////////////////////////////////////////////////////
void ledconectando (void)
{
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(200);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(200);  
}
///
void ledstdby (void)
{
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(3000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);  
}
///
////

////////////////////////////////////////////////////////////////////////////////////////////////

//////main///////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  //lcd.setCursor(0,1);
  //lcd.print(" MIYAKODA TECH  ");
  ///
ledstdby();
  
server.handleClient();

  ///
  
}
