

// constants won't change. They're used here to set pin numbers:

const int iOnButtonPinDir_B = 6;
const int iStepButtonPinDir_B = 5;
const int iStopButtonPin = 4;     // the number of the pushbutton pin
const int iStepButtonPinDir_A = 3;
const int iOnButtonPinDir_A = 2;

const int iLedPinDir_A =  7;      // the number of the LED pin
const int iLedPinDir_B =  8;      // the number of the LED pin

const int iFullModeLEDPinDir_B = 11;
const int iFullModeLEDPinDir_A = 10;

const int iFullDir_B = -2;
const int iStepDir_B = -1;
const int iStop = 0;
const int iStepDir_A = 1;
const int iFullDir_A = 2;

int iCurrentRunMode = 0;

int iOnButtonStateDir_B = LOW;
int iStepButtonStateDir_B = LOW;
int iStopButtonState = LOW;
int iStepButtonStateDir_A = LOW;
int iOnButtonStateDir_A = LOW;

int iOnButtonLastStateDir_B = LOW;
int iStepButtonLastStateDir_B = LOW;
int iStopButtonLastState = LOW;
int iStepButtonLastStateDir_A = LOW;
int iOnButtonLastStateDir_A = LOW;

int iLEDStateDir_A = "LOW";
int iLEDStateDir_B = "LOW";

int iReadOnButtonDir_B = LOW;
int iReadStepButtonDir_B = LOW;
int iReadStopButton = LOW;
int iReadStepButtonDir_A = LOW;
int iReadOnButtonDir_A = LOW;

unsigned long ulLastOnButtonTimeDir_B = 0;
unsigned long ulLastStepButtonTimeDir_B = 0;
unsigned long ulLastStopButtonTime = 0;
unsigned long ulLastStepButtonTimeDir_A = 0;
unsigned long ulLastOnButtonTimeDir_A = 0;

unsigned long ulDebounceDelay = 50;



void setup() {
  // put your setup code here, to run once:

  // initialize the LED pin as an output:
  pinMode(iLedPinDir_A, OUTPUT);
  pinMode(iLedPinDir_B, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(iStopButtonPin, INPUT);
  pinMode(iStepButtonPinDir_A, INPUT);
  pinMode(iOnButtonPinDir_A, INPUT);
  pinMode(iStepButtonPinDir_B, INPUT);
  pinMode(iOnButtonPinDir_B, INPUT);

  // initialize LED off
  digitalWrite(iLedPinDir_A, iLEDStateDir_A);
  digitalWrite(iLedPinDir_B, iLEDStateDir_B);

  digitalWrite(iFullModeLEDPinDir_B,LOW);
  digitalWrite(iFullModeLEDPinDir_A,LOW);

  Serial.begin(9600);

  Serial.println("Fuck Off World");
  iCurrentRunMode = 0;
}

void loop() {

Serial.println(iCurrentRunMode);

if  (iCurrentRunMode == 0)
{

  Serial.println("S");
    //turn LED off
    iLEDStateDir_A = LOW;

    //Check both On and Step Buttons to see if they are pushed

    iReadStepButtonDir_A = digitalRead(iStepButtonPinDir_A);
    if (iReadStepButtonDir_A == HIGH and iReadStepButtonDir_B != HIGH)
    {
      iLEDStateDir_A = HIGH;
      iCurrentRunMode  = iStop;
    }
    else
    {
      iReadStepButtonDir_B = digitalRead(iStepButtonPinDir_B);
      if (iReadStepButtonDir_B == HIGH)
      {
        iLEDStateDir_B = HIGH;
        iCurrentRunMode  = iStop;
      }
      else
      {
        
        
        
        iLEDStateDir_A = LOW;
        iLEDStateDir_B = LOW;

      
        int readingOnButtonDir_A = digitalRead(iOnButtonPinDir_A);
        if (readingOnButtonDir_A != iOnButtonLastStateDir_A)
        {
          ulLastOnButtonTimeDir_A = millis();
          Serial.println("SDir_A");
        }
        if ((millis() - ulLastOnButtonTimeDir_A) > ulDebounceDelay)
        {
          if ( readingOnButtonDir_A != iOnButtonStateDir_A)
          {
            iOnButtonStateDir_A = readingOnButtonDir_A;
    
            if (iOnButtonStateDir_A == HIGH)
            {
              iLEDStateDir_A = HIGH;
              iCurrentRunMode  = iFullDir_A;
            }
          }
    
          
        }
        
        iOnButtonLastStateDir_A = readingOnButtonDir_A;
    
    
    
        int readingOnButtonDir_B = digitalRead(iOnButtonPinDir_B);
        if (readingOnButtonDir_B != iOnButtonLastStateDir_B)
        {
          ulLastOnButtonTimeDir_B = millis();
          Serial.println("SDir_B");
        }
        if ((millis() - ulLastOnButtonTimeDir_B) > ulDebounceDelay)
        {
          if ( readingOnButtonDir_B != iOnButtonStateDir_B)
          {
            iOnButtonStateDir_B = readingOnButtonDir_B;
    
            if (iOnButtonStateDir_B == HIGH)
            {
              iLEDStateDir_B = HIGH;
              iCurrentRunMode  = iFullDir_B;
            }
          }
        }
        
        iOnButtonLastStateDir_B = readingOnButtonDir_B;
      }
    }
}


if (iCurrentRunMode == 2)
{

    // read stop button and if it's pressed then set led OFF and set runmode to stop
    // otherwise do nothing
      Serial.println("F_DIR_A");
    int iReadingStopButton = digitalRead(iStopButtonPin);
    
    if (iReadingStopButton != iStopButtonLastState)
    {
      ulLastStopButtonTime = millis();
    }
    if ((millis() - ulLastStopButtonTime) > ulDebounceDelay)
    {
      if ( iReadingStopButton != iStopButtonState)
      {
        iStopButtonState = iReadingStopButton;

        if (iStopButtonState == HIGH)
        {
          iLEDStateDir_A = LOW;
          iCurrentRunMode  = 0;
        }
      }

      
    }
    iStopButtonLastState = iReadingStopButton;



}

if (iCurrentRunMode == -2)
{

    // read stop button and if it's pressed then set led OFF and set runmode to stop
    // otherwise do nothing
      Serial.println("F_DIR_B");
    int iReadingStopButton = digitalRead(iStopButtonPin);
    
    if (iReadingStopButton != iStopButtonLastState)
    {
      ulLastStopButtonTime = millis();
    }
    if ((millis() - ulLastStopButtonTime) > ulDebounceDelay)
    {
      if ( iReadingStopButton != iStopButtonState)
      {
        iStopButtonState = iReadingStopButton;

        if (iStopButtonState == HIGH)
        {
          iLEDStateDir_B = LOW;
          iCurrentRunMode  = 0;
        }
      }

      
    }
    iStopButtonLastState = iReadingStopButton;



}
Serial.print("LED");
Serial.println(iLEDStateDir_A);


  digitalWrite(iLedPinDir_A, iLEDStateDir_A);
  digitalWrite(iLedPinDir_B, iLEDStateDir_B);

  if (iCurrentRunMode == iFullDir_A)
  {
    digitalWrite(iFullModeLEDPinDir_A, HIGH);
  }
  else
  {
    digitalWrite(iFullModeLEDPinDir_A, LOW);
  }

  if (iCurrentRunMode == iFullDir_B)
  {
    digitalWrite(iFullModeLEDPinDir_B, HIGH);
  }
  else
  {
    digitalWrite(iFullModeLEDPinDir_B, LOW);
  }


}
