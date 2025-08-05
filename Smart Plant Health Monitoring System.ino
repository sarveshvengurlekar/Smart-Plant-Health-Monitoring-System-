
#define BLYNK_PRINT Serial 
 
#define BLYNK_TEMPLATE_ID "BLYNK_TEMPLATE_ID" 
#define BLYNK_TEMPLATE_NAME "BLYNK_TEMPLATE_NAME" 
#define BLYNK_AUTH_TOKEN "BLYNK_AUTH_TOKEN" 
 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
#include <LiquidCrystal_I2C.h> 
#include "DHT.h" 
 
#define DHTPIN D4        // Pin connected to the DHT sensor 
#define DHTTYPE DHT11    // DHT 11 
#define SENSOR_PIN A0    // Soil moisture sensor output pin 
#define LDR_PIN D0       // LDR pin 
#define LCD_ADDR 0x27    // LCD I2C address 
#define LCD_COLS 20      // LCD columns 
#define LCD_ROWS 4       // LCD rows 
 
char ssid[] = "wifi ssid"; 
char password[] = "wifi password"; 
char auth[] = BLYNK_AUTH_TOKEN; 
 
DHT dht(DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS); 
 
void setup() { 
  Serial.begin(115200); 
 
  // Initialize DHT sensor 
  dht.begin(); 
 
  // Initialize LCD 
  lcd.init(); 
  lcd.clear(); 
  lcd.backlight(); 
  lcd.setCursor(1, 1); 
  lcd.print("Smart Plant Health"); 
  lcd.setCursor(1, 2); 
  lcd.print("Monitoring System"); 
  delay(4000); 

 
  lcd.clear(); 
 
  // Connect to WiFi 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000); 
    Serial.println("Connecting to WiFi..."); 
  } 
 
  // Start Blynk 
  Blynk.begin(auth, ssid, password); 
} 
 
void loop() { 
  Blynk.run(); 
 
  // Read temperature and humidity 
  float humid01 = dht.readHumidity(); 
  float temp01 = dht.readTemperature(); 
  float temp02 = dht.readTemperature(true); 
 
  // Print temperature and humidity to Serial 
  Serial.println("Temperature: "); 
  Serial.println(temp01); 
  Serial.println(" °C, Humidity: "); 
  Serial.println(humid01); 
  Serial.println(" %"); 
 
  // Display temperature and humidity on LCD 
  lcd.setCursor(0, 0); 
  lcd.print("Temp.:"); 
  lcd.print(temp01, 2); 
  lcd.print("C"); 
  lcd.setCursor(12, 0); 
  lcd.print("|"); 
  lcd.setCursor(14, 0); 
  lcd.print(temp02, 2); 
  lcd.print("F"); 
 
  lcd.setCursor(0, 1); 
  lcd.print("Humidity : "); 
  lcd.print(humid01, 2); 
  lcd.print("%"); 
 
16 
 
  // Read soil moisture 
  int sensor_analog = analogRead(SENSOR_PIN); 
  float soil01 = (100 - ((sensor_analog / 1023.00) * 100)); 
  Serial.print("Moisture Percentage = "); 
  Serial.println(soil01); 
 
  // Display soil moisture on LCD 
  lcd.setCursor(0, 2); 
  lcd.print("Soil Moisture:"); 
  lcd.print(soil01); 
  lcd.print("%"); 
 
  // Read light intensity 
  int Light01 = analogRead(LDR_PIN); 
  Serial.println(Light01); 
 
  // Display light intensity on LCD 
  lcd.setCursor(0, 3); 
  if (Light01 == 0) { 
    lcd.print("Light : Bright"); 
  } else { 
    lcd.print("Light : Dim"); 
  } 
 
  // Send data to Blynk 
  Blynk.virtualWrite(V0, humid01); 
  Blynk.virtualWrite(V2, temp01); 
  Blynk.virtualWrite(V1, soil01); 
  Blynk.virtualWrite(V3, Light01); 
 
  delay(3000); // Update every 3 seconds 
} 
 
 
