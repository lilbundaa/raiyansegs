#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> //Library yang digunakan untuk menghubungkan ke Jaringan Wi-Fi
#include <BlynkSimpleEsp8266.h> //Library Menghubungkan Board ke Server Blynk
#include "DHT.h" //Library untuk DHT11
#include <MQUnifiedsensor.h> //Library untuk MQ135
#include <Servo.h> //Library untuk Servo
 
#define DHTTYPE DHT11 //Definisi Jenis DHT yang digunakan
#define DHTPIN D3 //Definisi Pin DHT11 pada NodeMCU
#define Lampu D1
#define Kipas D2
#define placa "ESP8266" //Define jenis board yang digunakan
#define Voltage_Resolution 5 //Tegangan yang digunakan
#define pin A0 //Pin yang digunakan untuk MQ-135
#define type "MQ-135" //Jenis MQ yang digunakan
#define ADC_Bit_Resolution 10 //Resolusi Bit ADC 
#define RatioMQ135CleanAir 3.6
 
DHT dht(DHTPIN, DHTTYPE);
MQUnifiedsensor MQ135(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type); 
Servo servo;
char auth[] = "eJP_FX1ispD9Yr_gu1hE8b5RuJk7Zvnn";
char ssid[] = "alfharizi";
char pass[] = "iribilangboss";
char server[] = "blynk-cloud.com";
int port = 8080;
 
BlynkTimer timer;
WidgetLCD lcd(V1);
 
void SendSensor(){
  lcd.clear();
  MQ135.update(); 
  MQ135.setA(605.18); MQ135.setB(-3.937);
  float CO = MQ135.readSensor();
  MQ135.setA(110.47); MQ135.setB(-2.862); 
  float CO2 = MQ135.readSensor(); 
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal Membaca Sensor");
    return;
  }
  lcd.print(0, 0, "CO : "); 
  lcd.print(6, 0, CO); 
  lcd.print(0, 1, "CO2 : "); 
  lcd.print(7, 1, CO2);
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
}
 
BLYNK_WRITE(V0) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {    
    servo.write(180);
  }
  if (pinValue == 0) {    
    servo.write(0);
  }
}
 
void setup()
{
  Serial.begin(115200);
  pinMode(Lampu, OUTPUT);
  pinMode(Kipas, OUTPUT);
  digitalWrite(Lampu, HIGH);  
  digitalWrite(Kipas, HIGH);
  servo.attach(13);
  dht.begin();
  MQ135.setRegressionMethod(1); //_PPM =  a*ratio^b //Set Method yang digunakan untuk MQ-135
  MQ135.init(); //Memulai fungsi MQ-135
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    MQ135.update();
    calcR0 += MQ135.calibrate(RatioMQ135CleanAir);
    Serial.print(".");
  }
  MQ135.setR0(calcR0/10);
  Blynk.begin(auth, ssid, pass, server, port);
  lcd.clear(); 
  lcd.print(2, 0, "Hello World"); 
  timer.setInterval(1000L, SendSensor);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
