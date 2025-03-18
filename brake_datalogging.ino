#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

char written_values[50]; // Adjust size based on your expected string length
unsigned long epochMillis = 0; // Define a fixed epoch (e.g., when the program starts)

const int pressure_pin_front = A0; // analog input for sensor input, gpio0, adc11
const int pressure_pin_rear = A1;
unsigned long gpioTimer = 0;        // Timer for GPIO polling
String status_fr = "";
String status_re = "";
String currentFilename;  // Global variable to store the filename

// Function to generate a unique filename
String generateFileName() {
  int fileNum = 1;
  String fileName;
  while (true) {
    fileName = "psi_" + String(fileNum) + ".csv";
    if (!SD.exists(fileName)) {
      break;
    }
    fileNum++;
  }
  return fileName;
}

void writeFile(String path, String message)
{
  Serial.print("Writing file: ");
  Serial.println(path);

  File file = SD.open(path, FILE_WRITE);
  if (!file)
  {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message))
  {
    Serial.println("File written");
  }
  else
  {
    Serial.println("Write failed");
  }
  file.close();
}

void appendFile(String path, String message)
{
  Serial.print("Appending to file: ");
  Serial.println(path);

  File file = SD.open(path, FILE_WRITE);
  if (!file)
  {
    Serial.println("Failed to open file for appending");
    return;
  }
  if (file.println(message))  // Changed from print to println
  {
    Serial.println("Message appended");
  }
  else
  {
    Serial.println("Append failed");
  }
  file.close();
}

void setup()
{
  Serial.begin(9600); // Adjusted baud rate to a common value for Arduino Uno
  while (!Serial);  // Wait for serial port to connect

  epochMillis = millis();

  pinMode(pressure_pin_front, INPUT);
  pinMode(pressure_pin_rear, INPUT);


  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Card Mount Failed");
    while(1); // Loop forever if SD card fails to initialize
  }

  Serial.println("SD card initialized.");

  // Generate a unique filename only once during setup
  currentFilename = generateFileName();

  // Create and write the header to the new file
  writeFile(currentFilename, "time, pressure");
  Serial.print("Writing to file: ");
  Serial.println(currentFilename);
}

void loop(){
  if (millis() - gpioTimer >= 50){
    gpioTimer = millis();
    unsigned long elapsedMillis = millis() - epochMillis;
    unsigned long currentMinutes = (elapsedMillis / (1000 * 60)) % 60; // Minutes elapsed since epoch
    unsigned long currentSeconds = (elapsedMillis / 1000) % 60;  // seconds in the current minute
    unsigned long currentMilliseconds = elapsedMillis % 1000;

    int adc_fr = analogRead(pressure_pin_front);
    int adc_re = analogRead(pressure_pin_rear);

    // Scale the pressure values. These are rough conversions, adjust as needed
    float pres_fr = map(adc_fr, 0, 1023, 0, 5000);  // Example: 0-5000 PSI
    float pres_re = map(adc_re, 0, 1023, 0, 5000);  // Example: 0-5000 PSI

    // Format the data string
    String dataString = String(currentMinutes) + ":" + String(currentSeconds) + ":" + String(currentMilliseconds) + "," + String(pres_fr);

    // Append data to the file - using global filename
    appendFile(currentFilename, dataString);

    Serial.println(dataString); // Optionally print to serial monitor

    // delay(10); // Add a small delay for SD card stability
  }
}