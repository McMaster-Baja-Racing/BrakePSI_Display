#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static const uint8_t image_array_BajaLogo[1024] = {
  // 'Baja_Logo_SMALLLCD, 124x64px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0xe3, 0x8f, 0x9c, 0x70, 0xf1, 0xf7, 0xf3, 0xcf, 0xc0, 0x00, 
	0x00, 0x00, 0x00, 0x04, 0x03, 0xfd, 0xe7, 0x9c, 0xbc, 0xf0, 0xf1, 0x81, 0xc7, 0x0c, 0xc0, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x07, 0xfd, 0xe7, 0xb8, 0x3c, 0xf1, 0xb1, 0x81, 0x86, 0x0c, 0xc0, 0x00, 
	0x00, 0x00, 0x00, 0x1f, 0x9f, 0xfd, 0xad, 0xb0, 0x35, 0xb1, 0xb1, 0xe1, 0x87, 0xcf, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x1f, 0xff, 0xe1, 0xab, 0x30, 0x35, 0x63, 0xb0, 0xe1, 0x87, 0x9f, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0xff, 0x01, 0x3b, 0x38, 0x27, 0x67, 0xf0, 0x71, 0x86, 0x19, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0xfc, 0x03, 0x33, 0x3e, 0x66, 0x66, 0x33, 0xe1, 0x8f, 0x99, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xf8, 0x03, 0x33, 0x0e, 0x66, 0x6e, 0x33, 0xc3, 0x0f, 0x99, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xf0, 0x03, 0xc0, 0x60, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xe2, 0x03, 0xf0, 0xe0, 0x61, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xc3, 0xf3, 0x31, 0xe0, 0x61, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0x83, 0xf7, 0x61, 0xb0, 0x63, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0x81, 0xf7, 0xe3, 0x30, 0x62, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0x00, 0x76, 0x63, 0xf0, 0x67, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0x01, 0xf6, 0x77, 0xf0, 0xcf, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0xff, 0x07, 0xc7, 0xe6, 0x37, 0xcc, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xfe, 0x5f, 0x86, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7e, 0x7f, 0x0f, 0x83, 0x83, 0xe6, 0x61, 0x8f, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1e, 0x3e, 0x0d, 0xc3, 0x87, 0xee, 0x71, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1e, 0x1e, 0x2c, 0xc7, 0xce, 0x0c, 0xf3, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1e, 0x06, 0x4d, 0xc4, 0xcc, 0x0c, 0xfb, 0x37, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1e, 0x0c, 0x5f, 0x0c, 0xcc, 0x0c, 0xdf, 0x77, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1e, 0x0c, 0x5b, 0x9f, 0xcc, 0x0c, 0xcf, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0x1c, 0x59, 0x9d, 0xcf, 0xdc, 0x8e, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0x1c, 0x59, 0xb8, 0xc7, 0x99, 0x86, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0x3c, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0x82, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0xc2, 0x30, 0x02, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xe7, 0xc1, 0x18, 0x04, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xe0, 0x8e, 0x38, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xf0, 0x43, 0xe0, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xf8, 0x20, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xfe, 0x06, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xff, 0xe0, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xcf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0xe7, 0xff, 0xff, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xc1, 0xff, 0xff, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const int pressure_pin_front = 25; // analog input for sensor input, gpio0, adc11 
const int pressure_pin_rear = 13;
const int led_fr_pin = 15; // analog output for led front, gpio15, adc12 - works
const int led_re_pin = 2; // analog output for led rear, gpio2, adc13 - works
unsigned long gpioTimer = 0; // Timer for GPIO polling

void setup() {
  Serial.begin(115200);

  pinMode(pressure_pin_front, INPUT);
  pinMode(pressure_pin_rear, INPUT);
  pinMode(led_fr_pin, OUTPUT);
  pinMode(led_re_pin, OUTPUT);

  
  Wire.begin(5, 4);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  analogReadResolution(12);

  delay(2000);
  display.clearDisplay();
  display.drawBitmap(0, 0, image_array_BajaLogo, 128, 64, 1);
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);

  Serial.print("Setup Finished");

  digitalWrite(led_fr_pin, LOW);
  digitalWrite(led_re_pin, LOW);
}
 
 //2.2,5.59
void loop() {
  if (millis() - gpioTimer >= 500) {
    gpioTimer = millis();
    int adc_fr = analogRead(pressure_pin_front);
    int volt_fr = analogReadMilliVolts(pressure_pin_front);
    int adc_re = analogRead(pressure_pin_rear);
    int volt_re = analogReadMilliVolts(pressure_pin_rear);
    String status_fr = "";
    String status_re = "";

    display.setCursor(0, 10);
    //int brake_pres = (((1748) * ((adc_val * 3.3)/4096)) - (629.37)) ;
    // y=(1240.909*x)*1.3736264-625
    int pres_fr = (1.3736264 * 1240.909 * volt_fr/1000) - 625;
    int pres_re = (1.3736264 * 1240.909 * volt_re/1000) - 625;
    //Serial.println("FR:" + String(volt_fr) + " | " + String(pres_fr) + "\t\t\t" + " RE: " + String(volt_re) + " | " + String(pres_re));
    
    //Serial.println(String(adc_val) + " | " + String(((adc_val * 3.3)/4096)));
    if(pres_fr >= 2000){
      digitalWrite(led_fr_pin, HIGH);
    } else {
      digitalWrite(led_fr_pin, LOW);
    }
    
    if(pres_re >= 2000){
      digitalWrite(led_re_pin, HIGH);
    } else {
      digitalWrite(led_re_pin, LOW);
    }

    display.clearDisplay(); 
    display.setCursor(0, 10);
    if (pres_fr < 0){
      status_fr = "0";
    } else {
      status_fr = String(pres_fr);
    }

    if (pres_re < 0){
      status_re = "0";
    } else {
      status_re = String(pres_re);
    }
    display.print(" FR: " + String(status_fr) + "\n\n RE: " + String(status_re));
    
    display.display();
  }
}