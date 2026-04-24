#include <Arduino.h>
#include <time.h>
#include <WiFi.h>
#include "Adafruit_VEML7700.h"
#include <Adafruit_AHTX0.h>
#include <ESP32Servo.h>
#include <Adafruit_MCP23X17.h>
#include "stdio.h"
#include <ESP_Knob.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <Audio.h>
#include <TFT_eSPI.h>



// <>
//I2C
#define I2C_SDA 25
#define I2C_SCL 24
TwoWire I2C = TwoWire(0);


//GESTION AUDIO
#define SD_CS_PIN 23

#define I2S_BCLK_PIN 4
#define I2S_LRC_PIN  5 
#define I2S_DOUT_PIN 6
Audio audio;

// Ecran / heure 

TFT_eSPI tft = TFT_eSPI(); 

// wifi logs 
const char* ssid     = "PlanetCampus - Prive 004302";
const char* password = "SAWDUASqCFnoT"; //that's my real password I've no enemies :)


const char* ntpServer = "fr.pool.ntp.org";
const long  gmtOffset_sec = 3600;      // GMT +1
const int   daylightOffset_sec = 3600; // heure été

void ShowHour() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Erreur de récupération de l'heure");
    return;
  }
  tft.setTextColor(TFT_GREEN, TFT_BLACK); // Vert sur fond Noir
  
  // 7segements police
  tft.setTextFont(7); 
  tft.setTextSize(1.5); 

  // Position x y
  tft.setCursor(50, 100);

  // show with the format hours : minutes : secondes
  tft.printf("%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  
  // show date
  tft.setTextFont(4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setCursor(100, 160);
  tft.printf("%02d/%02d/%02d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900);
}


//VEML7700
Adafruit_VEML7700 veml = Adafruit_VEML7700();

//AHT20
Adafruit_AHTX0 aht;

// PIN BONUS
#define BUTTON1_PIN 1 //btn16
#define BUTTON2_PIN 2 //btn1
#define BUTTON3_PIN 3 //btn2
#define BUTTON4_PIN 4 //btn3
#define BUTTON5_PIN 5 //btn...
#define BUTTON6_PIN 6
#define BUTTON7_PIN 7
#define BUTTON8_PIN 8
#define BUTTON9_PIN 9
#define BUTTON10_PIN 10
#define BUTTON11_PIN 11
#define BUTTON12_PIN 12
#define BUTTON13_PIN 13
#define BUTTON14_PIN 14
#define BUTTON15_PIN 15
#define BUTTON16_PIN 16
Adafruit_MCP23X17 mcp;

#define PIN_SG90 45
Servo sg90;

//pin PWM LED 
const int LEDA = 12;
const int LEDB = 17;


// pin Enable MT3608 led / fan
const int EN_mt3608 = 32;


// EC11
#define GPIO_KNOB_A 39
#define GPIO_KNOB_B 38
const int swt_ec11 = 7;
ESP_Knob *knob;

void onKnobLeftEventCallback(int count, void *usr_data)
{
    Serial.printf("Detect left event, count is %d\n", count);
}

void onKnobRightEventCallback(int count, void *usr_data)
{
    Serial.printf("Detect right event, count is %d\n", count);
}

void onKnobHighLimitEventCallback(int count, void *usr_data)
{
    Serial.printf("Detect high limit event, count is %d\n", count);
}

void onKnobLowLimitEventCallback(int count, void *usr_data)
{
    Serial.printf("Detect low limit event, count is %d\n", count);
}

void onKnobZeroEventCallback(int count, void *usr_data)
{
    Serial.printf("Detect zero event, count is %d\n", count);
}




void setup() {


  //screen
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  // wait the wifi connection
  tft.setTextFont(4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setCursor(10, 10);
  tft.println("Connexion WiFi...");

  // wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  tft.println("WiFi OK !");
  tft.println("Recuperation heure...");

  // Init hour
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  
  tft.fillScreen(TFT_BLACK);




  //I2C
  I2C.begin(I2C_SDA, I2C_SCL, 100000);


  // AUDIO / CARTE SD 
 Serial.println("\n--- Test Audio : ESP32-audioI2S ---");

  // 1. Initialisation de la carte SD
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("ERREUR : SD introuvable !");
    while(1); 
  }
  Serial.println("SD OK !");
  
  audio.setPinout(I2S_BCLK_PIN, I2S_LRC_PIN, I2S_DOUT_PIN);
  
  // volume de 0 à 21
  audio.setVolume(5); 

  // ici on doit le mouv si on veut pas que la musique se lance au démarrage 

  bool succes = audio.connecttoFS(SD, "/test.mp3"); // change here the name of the song "test"
  
  if(succes) {
    Serial.println("Lecture en cours...");
  } else {
    Serial.println("Impossible de lire le fichier !");
  }



  // VEML7700
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println("Adafruit VEML7700 Auto Lux Test");

  if (!veml.begin()) {
    Serial.println("Sensor not found");
    while (1);
  }
  Serial.println("Sensor found");

  // AHT20
  Serial.println("Adafruit AHT10/AHT20 demo!");

  if (!aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1)
      delay(10);
  }
  Serial.println("AHT10 or AHT20 found");


  //servo moteur 
  sg90.setPeriodHertz(50); // Fréquence PWM pour le SG90
  sg90.attach(PIN_SG90, 500, 2400); // Largeur minimale et maximale de l'impulsion (en µs) pour aller de 0° à 180°


  // MCP
  Serial.println("MCP23xxx Button Test!");

  // uncomment appropriate mcp.begin
  if (!mcp.begin_I2C()) {
    Serial.println("Error.");
    while (1);
  }

  // configure pin for input with pull up
  mcp.pinMode(BUTTON1_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON2_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON3_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON4_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON5_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON6_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON7_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON8_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON9_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON10_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON11_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON12_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON13_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON14_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON15_PIN, INPUT_PULLUP);
  mcp.pinMode(BUTTON16_PIN, INPUT_PULLUP);
  Serial.println("Looping...");

  // pin Enable MT3608 led / fan
  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);

  //LED PWM
  pinMode(12, OUTPUT);
  pinMode(17, OUTPUT);

  // EC11
  pinMode(7, INPUT); // switch du EC11
  knob = new ESP_Knob(GPIO_KNOB_A, GPIO_KNOB_B);

    // knob->invertDirection();
    knob->begin();
    knob->attachLeftEventCallback(onKnobLeftEventCallback);
    knob->attachRightEventCallback(onKnobRightEventCallback);
    knob->attachHighLimitEventCallback(onKnobHighLimitEventCallback);
    knob->attachLowLimitEventCallback(onKnobLowLimitEventCallback);
    knob->attachZeroEventCallback(onKnobZeroEventCallback);

}

void loop() {
 
  //MUSIQUE 
  audio.loop();

 // VEML7700
 float lux = veml.readLux(VEML_LUX_AUTO);

  Serial.println("------------------------------------");
  Serial.print("Lux = "); Serial.println(lux);
  Serial.println("Settings used for reading:");
  Serial.print(F("Gain: "));
  switch (veml.getGain()) {
    case VEML7700_GAIN_1: Serial.println("1"); break;
    case VEML7700_GAIN_2: Serial.println("2"); break;
    case VEML7700_GAIN_1_4: Serial.println("1/4"); break;
    case VEML7700_GAIN_1_8: Serial.println("1/8"); break;
  }
  Serial.print(F("Integration Time (ms): "));
  switch (veml.getIntegrationTime()) {
    case VEML7700_IT_25MS: Serial.println("25"); break;
    case VEML7700_IT_50MS: Serial.println("50"); break;
    case VEML7700_IT_100MS: Serial.println("100"); break;
    case VEML7700_IT_200MS: Serial.println("200"); break;
    case VEML7700_IT_400MS: Serial.println("400"); break;
    case VEML7700_IT_800MS: Serial.println("800"); break;
  }

    //AHT20
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity,
               &temp); // populate temp and humidity objects with fresh data
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degrees C");
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println("% rH");

  //servo 
  for (int pos = 0; pos <= 180; pos += 1) {
    sg90.write(pos);
    delay(10);
  }


  // MCP BUtton
   // LOW = pressed, HIGH = not pressed
   if (digitalRead(7)==HIGH) {
    Serial.println("BTN du EC11 pushed");
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON1_PIN)) {
    Serial.println("Button1 Pressed!");
    delay(50);
  }
   if (!mcp.digitalRead(BUTTON2_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON3_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON4_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON5_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON6_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON7_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON8_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON9_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON10_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON11_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON12_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON13_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON14_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON15_PIN)) {
    delay(50);
  }
  if (!mcp.digitalRead(BUTTON16_PIN)) {
    delay(50);
  }

  // led PWM 
  // exemple ici uniquement avec LEDA, LED B existe aussi 
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    analogWrite(LEDA, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    analogWrite(LEDA, dutyCycle);
    delay(15);
  }

  ShowHour(); // show hour and update every 1s with the delay 1000 bellow

  delay(1000);
}

