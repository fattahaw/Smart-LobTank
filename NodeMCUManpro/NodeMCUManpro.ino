#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

int len = 0;
int temperature = 0;

char buffRead[8];
char buffInt[3];

bool toInteger = false;
bool adaCangkang = false;

const char* ssid = "Aw";
const char* password = "12345678";
const char* mqtt_server = "m13.cloudmqtt.com";

String userName = "vgjatqtx";
String passWord = "BlU_DzYWYLFi";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), userName.c_str(), passWord.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600); /* begin serial for debug */
  Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
  setup_wifi();
  client.setServer(mqtt_server, 19889);
  client.setCallback(callback);
}

void loop() {
// Wire.beginTransmission(8); /* begin with device address 8 */
// Wire.write("Hello Arduino");  /* sends hello string */
// Wire.endTransmission();    /* stop transmitting */

 if (!client.connected()) {
   reconnect();
 }
 client.loop();
  
 Wire.requestFrom(8, 12); /* request & read data of size 13 from slave */

 len = 0;
 while(Wire.available()){
    
    char c = Wire.read();
    buffRead[len] = c;
  //  Serial.print(c);
    len++;
 }

 len = 0;
 char charArray[10];
 int i = 0;
 while(len <= 8)
 {
  
   
   if(buffRead[len] == 'S')
   {
    toInteger = true;
    len++;
    continue;
   }
   if(buffRead[len] == 'T')
   {
    toInteger = false;
    i = 0;
   }
   if(buffRead[len] == 'Y')
   {
    adaCangkang = true;
   }
   if(buffRead[len] == 'N')
   {
    adaCangkang = false;
   }
  
   if(toInteger == true)
   {
    charArray[i] = buffRead[len];
    i++;
   }
   len++;
 }

 temperature = atoi(charArray);

 long now = millis();
 if (now - lastMsg > 2000) {
   lastMsg = now;
   ++value;
   snprintf (msg, 75, "hello world #%ld", value);
   Serial.print("Publish message: ");
   Serial.println(msg);
   client.publish("outTopic", msg);
   if(adaCangkang)
   {
     Serial.print("Ada");
   }
   Serial.println(temperature);
   Serial.println(buffRead);
  // Serial.println(charArray);

 }

// delay(1000);
}
