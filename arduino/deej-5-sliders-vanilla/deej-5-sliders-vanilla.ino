const int NUM_SLIDERS = 5;
const int analogInputs[NUM_SLIDERS] = {A0, A2, A3, A4, A6};

//delays section
const int del = 50;
const int del2 = 390;


int analogSliderValues[NUM_SLIDERS];

void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }

  pinMode(8, INPUT_PULLUP);
  
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.begin(9600);
// Start test animation
// 1st
digitalWrite(13, HIGH);
digitalWrite(2, HIGH);
delay(del);
digitalWrite(13, LOW);
digitalWrite(4, HIGH);
delay(del);
digitalWrite(2, LOW);
digitalWrite(6, HIGH);
delay(del);
digitalWrite(4, LOW);
digitalWrite(8, HIGH);
delay(del);
digitalWrite(6, LOW);  
delay(del);
digitalWrite(8, LOW);
delay(del);
digitalWrite(13, HIGH);
digitalWrite(2, HIGH);
delay(del);
digitalWrite(13, LOW);
digitalWrite(4, HIGH);
delay(del);
digitalWrite(2, LOW);
digitalWrite(6, HIGH);
delay(del);
digitalWrite(4, LOW);
digitalWrite(8, HIGH);
delay(del);
digitalWrite(6, LOW);  
delay(del);
digitalWrite(8, LOW);
delay(500);
///2nd
digitalWrite(13, HIGH);
digitalWrite(2, HIGH);
digitalWrite(4, HIGH);
digitalWrite(6, HIGH);
digitalWrite(8, HIGH);
delay(700);
digitalWrite(13, LOW);
digitalWrite(2, LOW);
digitalWrite(4, LOW);
digitalWrite(6, LOW);
digitalWrite(8, LOW);
delay(700);
digitalWrite(13, HIGH);
digitalWrite(2, HIGH);
digitalWrite(4, HIGH);
digitalWrite(6, HIGH);
digitalWrite(8, HIGH);
delay(700);
digitalWrite(13, LOW);
digitalWrite(2, LOW);
digitalWrite(4, LOW);
digitalWrite(6, LOW);
digitalWrite(8, LOW);
}

void loop() {
  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)
  // printSliderValues(); // For debug
  delay(10);


  if(analogRead(0) > 4 && analogRead(6) > 4){          //// LED ON if...
    digitalWrite(13, HIGH);
  }
  else {
  digitalWrite(13, LOW);
  }

  if(analogRead(2) > 4 && analogRead(6) > 4){          //// LED ON if...
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  if(analogRead(3) > 4 && analogRead(6) > 4){          //// LED ON if...
    digitalWrite(4, HIGH);
  }
  else {
  digitalWrite(4, LOW);
  }

  if(analogRead(4) > 4 && analogRead(6) > 4){          //// LED ON if...
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  if(analogRead(6) > 4 && analogRead(6) > 4){          //// LED ON if...
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }

}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
