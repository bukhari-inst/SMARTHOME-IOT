#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

#define LAMP1 D0
#define LAMP2 D1
#define LAMP3 D2
#define LAMP4 D3
#define ldrpin A0

//variabel software Serial/RX:D6-TX:D7
SoftwareSerial DataSerial(D6, D7);

//millis pengganti delay
unsigned long previousMillis = 0;
const long interval = 3000;

//variabel array untuk data parsing
String arrData[2];

const char* ssid = "@NOAH_ID";
const char* password = "@NOAH_Site";
const char* host = "192.168.0.105"; //alamatipserver 192.168.0.105 mysmarthome.bukhariinst.ga

bool Parsing = false;
String dataPHP, data[8], dataPHP2, data2[8], dataPHP3, data3[8], dataPHP4, data4[8];
String ldr, suhu;
void setup()
{
  Serial.begin(9600);
  DataSerial.begin(9600);
  //  Serial.begin(115200);
  //  Serial.println();

  //  Serial.print("Connecting to");
  //  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    //    Serial.print(".");
  }
  //  Serial.println(" connected");

  pinMode(D4, OUTPUT);
  pinMode(LAMP1, OUTPUT);
  digitalWrite(LAMP1, HIGH);
  pinMode(LAMP2, OUTPUT);
  digitalWrite(LAMP2, HIGH);
  pinMode(LAMP3, OUTPUT);
  digitalWrite(LAMP3, HIGH);
  pinMode(LAMP4, OUTPUT);
  digitalWrite(LAMP4, HIGH);
  pinMode(ldrpin, INPUT);
}


void loop()
{
  digitalWrite(D4, LOW);
  delay(100);
  digitalWrite(D4, HIGH);
  delay(200);
  WiFiClient client;

  //  Serial.print("Connecting to ... ");
  //  Serial.println(host);

  // LAMP 1
  if (client.connect(host, 80)) {
    //    Serial.println("connected");
    //    Serial.println("Sending a request");

    String url = "WEB-Smarthome-IOT/baca-data.php?id=1"; // Lokasi File Baca Data IOT_Test/
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    //    Serial.println("Response:");
    while (client.connected())
    {
      if (client.available())
      {
        dataPHP = client.readStringUntil('\n');
        int q = 0;
        //        Serial.print("Data Masuk : ");
        //        Serial.print(dataPHP);
        // Serial.println();

        data[q] = "";
        for (int i = 0; i < dataPHP.length(); i++) {
          if (dataPHP[i] == '#') {
            q++;
            data[q] = "";
          }
          else {
            data[q] = data[q] + dataPHP[i];
          }
        }
        //        Serial.println(data[1].toInt());
        digitalWrite(LAMP1, data[1].toInt());
        Parsing = false;
        dataPHP = "";
      }
    }
    client.stop();
    //    Serial.println("Disconnected");
  }
  else
  {
    //    Serial.println("connection failed!");
    client.stop();
  }

  // LAMP 2
  if (client.connect(host, 80)) {
    //    Serial.println("connected");
    //    Serial.println("Sending a request");

    String url = "WEB-Smarthome-IOT/baca-data.php?id=2"; // Lokasi File Baca Data IOT_Test/
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    //    Serial.println("Response:");
    while (client.connected())
    {
      if (client.available())
      {
        dataPHP2 = client.readStringUntil('\n');
        int q = 0;
        //        Serial.print("Data Masuk : ");
        //        Serial.print(dataPHP2);
        //        Serial.println();

        data2[q] = "";
        for (int i = 0; i < dataPHP2.length(); i++) {
          if (dataPHP2[i] == '#') {
            q++;
            data2[q] = "";
          }
          else {
            data2[q] = data2[q] + dataPHP2[i];
          }
        }
        //        Serial.println(data2[1].toInt());
        digitalWrite(LAMP2, data2[1].toInt());
        Parsing = false;
        dataPHP2 = "";
      }
    }
    client.stop();
    //    Serial.println("Disconnected");
  }
  else
  {
    //    Serial.println("connection failed!");
    client.stop();
  }

  // LAMP 3
  if (client.connect(host, 80)) {
    //    Serial.println("connected");
    //    Serial.println("Sending a request");

    String url = "WEB-Smarthome-IOT/baca-data.php?id=3"; // Lokasi File Baca Data IOT_Test/
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    //    Serial.println("Response:");
    while (client.connected())
    {
      if (client.available())
      {
        dataPHP3 = client.readStringUntil('\n');
        int q = 0;
        //        Serial.print("Data Masuk : ");
        //        Serial.print(dataPHP3);
        //        Serial.println();

        data3[q] = "";
        for (int i = 0; i < dataPHP3.length(); i++) {
          if (dataPHP3[i] == '#') {
            q++;
            data3[q] = "";
          }
          else {
            data3[q] = data3[q] + dataPHP3[i];
          }
        }
        //        Serial.println(data3[1].toInt());
        digitalWrite(LAMP3, data3[1].toInt());
        Parsing = false;
        dataPHP3 = "";
      }
    }
    client.stop();
    //    Serial.println("Disconnected");
  }
  else
  {
    //    Serial.println("connection failed!");
    client.stop();
  }

  // LAMP 4
  if (client.connect(host, 80)) {
    //    Serial.println("connected");
    //    Serial.println("Sending a request");

    String url = "WEB-Smarthome-IOT/baca-data.php?id=4"; // Lokasi File Baca Data IOT_Test/
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    //    Serial.println("Response:");
    while (client.connected())
    {
      if (client.available())
      {
        dataPHP4 = client.readStringUntil('\n');
        int q = 0;
        //        Serial.print("Data Masuk : ");
        //        Serial.print(dataPHP4);
        //        Serial.println();

        data3[q] = "";
        for (int i = 0; i < dataPHP4.length(); i++) {
          if (dataPHP4[i] == '#') {
            q++;
            data4[q] = "";
          }
          else {
            data4[q] = data4[q] + dataPHP4[i];
          }
        }
        //        Serial.println(data4[1].toInt());
        digitalWrite(LAMP4, data4[1].toInt());
        Parsing = false;
        dataPHP4 = "";
      }
    }
    client.stop();
    //    Serial.println("Disconnected");
  }
  else
  {
    //    Serial.println("connection failed!");
    client.stop();
  }
  //  delay(100);

  //baca data dari arduino
  String data = "";
  while (DataSerial.available() > 0) {
    data += char(DataSerial.read());
  }
  //buang spasi datanya
  data.trim();

  //uji data
  if (data != "") {
    //format data "10#29.45" = array
    //pecah data
    int index = 0;
    for (int i = 0; i <= data.length(); i++) {
      char delimiter = '#';
      if (data[i] != delimiter) {
        arrData[index] += data[i];
      } else {
        index++; //variabel inde bertambah 1
      }
    }
    //memastikan data lengkap
    if (index == 1) {
      //tampilkan nilai sensor
      Serial.println(arrData[0]); //ldr
      ldr = arrData[0];
      Serial.println(arrData[1]); //suhu
      suhu = arrData[1];
      //      String Link;
      //      HTTPClient http;
      //      Link = "http://192.168.0.105/SMARTHOME-IOT/kirimdata.php?sensor=" + String(arrData[0]);
      //      //eksekusi link
      //      http.begin(Link);
      //      //mode GET
      //      http.GET();
      //      http.end();
      //
      //      //proses kirim data ke server
      //      String Link2;
      //      HTTPClient http2;
      //      Link2 = "http://192.168.0.105/SMARTHOME-IOT/kirimdata2.php?sensor2=" + String(arrData[1]);
      //      //eksekusi link
      //      http2.begin(Link2);
      //      //mode GET
      //      http2.GET();
      //      http2.end();
    }
    //mengkosongka data stelah dibaca
    arrData[0] = "";
    arrData[1] = "";
  }


  //  int sensor = analogRead(ldrpin);
  //  float suhu = sensor / 2.0479;
  //  Serial.print("data= ");
  //  Serial.println(sensor);
  //  Serial.print("sensor suhu= ");
  //  Serial.println(suhu);
  //
  String Link;
  HTTPClient http;
  Link = "http://192.168.0.105/WEB-Smarthome-IOT/kirimdata.php?sensor=" + String(ldr);
  //eksekusi link
  http.begin(Link);
  //mode GET
  http.GET();
  http.end();
  //
  int sensor2 = analogRead(ldrpin);
  float suhu2 = (sensor2 / 2.0479) - 22;
  //    Serial.print("data= ");
  //    Serial.println(sensor2);
  //    Serial.print("sensor suhu= ");
  //    Serial.println(suhu2);
  //
  //proses kirim data ke serversss
  String Link2;
  HTTPClient http2;
  Link2 = "http://192.168.0.105/WEB-Smarthome-IOT/kirimdata2.php?sensor2=" + String(suhu2);
  //eksekusi link
  http2.begin(Link2);
  //mode GET
  http2.GET();
  http2.end();

  //minta data ke arduino
  DataSerial.println("ya");
}
