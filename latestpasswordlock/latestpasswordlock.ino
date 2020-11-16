//Servo myservo;  // create servo object to control a servo

String inputString = "";
//String command = "";
String password = "arduPi"; // this is the password for opening and closing your door
                            // you can set any pasword you like using digit and symbols
boolean stringComplete = false; 

void setup(){
  //initiate LED indicators
  pinMode(12, OUTPUT);
  //start serial connection
  Serial.begin(9600);  // baud rate is 9600 must match with bluetooth 
  //The String reserve() function allows you to allocate a buffer in memory for manipulating strings.
  //inputString.reserve(50);  // reserve 50 bytes in memory to save for string manipulation 
  //command.reserve(50);
  //value.reserve(50);
}

void loop(){
  // if arduino receive a string termination character like \n stringComplete will set to true
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    //Serial.write(inChar);
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline or a carriage return, set a flag
    // so the main loop can do something about it:
    if (inputString.length() == 6) {
      stringComplete = true;
    } 
  }
  Serial.print("inputString is currently: ");
  Serial.println(inputString);
  if (stringComplete) 
  {
    Serial.println("StringComplete activated");
      if(password==inputString)
      {
           digitalWrite(12, HIGH);
           Serial.println(" OPEN"); // sent open feedback to phone
           inputString = "";
           stringComplete = false;
      }
      else if(password!=inputString)
      {
           digitalWrite(12, LOW);
           Serial.println(" WRONG");
           inputString = "";
           stringComplete = false;
       } 
        //} 
       // clear the string for next iteration
       
    }
   delay(1000);
   
}


//void serialEvent() {
//  while (Serial.available()) {
//    // get the new byte:
//    char inChar = (char)Serial.read(); 
//    //Serial.write(inChar);
//    // add it to the inputString:
//    inputString += inChar;
//    // if the incoming character is a newline or a carriage return, set a flag
//    // so the main loop can do something about it:
//    if (inChar == '\n' || inChar == '\r') {
//      stringComplete = true;
//    } 
//  }
//}
