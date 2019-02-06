//Gear limits
const int minGear = 1;
const int maxGear = 4;

//Buttons
const int upBtn = 13;
const int downBtn = 12;

//Leds
const int gearOneLed = 5;
const int gearTwoLed = 4;
const int gearThreeLed = 3;
const int gearFourLed = 2;

int currentGear;

void setup() 
{  
  //Inputs
  pinMode(upBtn, INPUT);
  pinMode(downBtn, INPUT);
  
  //Outputs
  pinMode(gearOneLed, OUTPUT);
  pinMode(gearTwoLed, OUTPUT);
  pinMode(gearThreeLed, OUTPUT);
  pinMode(gearFourLed, OUTPUT);

  //Start in first gear
  currentGear = 1;
  digitalWrite(gearOneLed, HIGH);
}

void loop() 
{
  //Loop and check if up button or down button has been pressed
  //Check up button pressed
  if(checkButtonPressed(upBtn))
  { 
    //Check up button released
    if(checkButtonReleased(upBtn))
    {
      ShiftUp();
      UpdateLeds();
      delay(400);
    }
  }
  //Check down button pressed
  else if(checkButtonPressed(downBtn))
  {
     //Check down button released
    if(checkButtonReleased(downBtn))
    {
      ShiftDown();
      UpdateLeds();
      delay(400);
    }
  }
  else
  {
    //No button has been pressed yet, so do nothing!
  }
}

//Methods
//Checks if the up button has been pressed
bool checkButtonPressed(int btn)
{
  if (digitalRead(btn) == HIGH)
    return true;
  else
    return false;
}

bool checkButtonReleased(int btn)
{
  while(digitalRead(btn) == HIGH)
  {
    //Loop until the button is relased
  }

  return true;
}

//Increments the current gear
void ShiftUp() 
{
  if (currentGear != maxGear)
    currentGear++;
}

//Decrements the current gear
void ShiftDown() 
{
  if (currentGear != minGear)
    currentGear--;
}

//Turns off all leds
void TurnOffLeds()
{
  digitalWrite(gearOneLed, LOW);
  digitalWrite(gearTwoLed, LOW);
  digitalWrite(gearThreeLed, LOW);
  digitalWrite(gearFourLed, LOW);
}

//Updates the leds in indicate the current gear
void UpdateLeds() 
{
  TurnOffLeds();
  
  switch (currentGear) 
  {
    case 1:
      digitalWrite(gearOneLed, HIGH);
      break;
    case 2:
      digitalWrite(gearTwoLed, HIGH);
      break;
    case 3:
      digitalWrite(gearThreeLed, HIGH);
      break;
    case 4:
      digitalWrite(gearFourLed, HIGH);
      break;
  }
}
