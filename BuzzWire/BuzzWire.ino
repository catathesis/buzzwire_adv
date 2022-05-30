// BuzzWire game with score.  Score = remaining timer value, which is reduced further by each wire touch.
// Adjust timer countdown variables (starting score, speed of decrement) and wire touch penalty for your wire.
// Players should lose if they don't try and hit the wire all the way.
// Circuit/board was designed so player can press start button with loop and begin right away- single hand friendly and more accurate scoring

#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int startPin = 4;
const int endPin = 5;
const int GLED = 6; // Green LED
const int RLED = 7; // Red LED
const int buzzer = 3;
const int buttonPin = 2;

int start, end_; // wire measures
int wireTouchCount;
int score;

String wireTouchLabel = "# Hits = ";
String wireTouchOutput = wireTouchLabel + wireTouchCount;  // combining label + variable

char msg[16]; // used for sprintf printing of score so no numerical artifacts when reducing length of score

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(buzzer, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(startPin, INPUT_PULLUP);
  pinMode(endPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Game Loop before start, screen setup
  score = 9999; // initial score                                             <-- ADJUST to change difficulty
  wireTouchCount = 0; // set initial hits
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press button");
  lcd.setCursor(0, 1);
  lcd.print("with loop!");  // board was designed so start button is by starting wire, can start with loop, see top comments

  while (digitalRead(buttonPin) == LOW); // button not pressed = do nothing

  // Game Loop after start
  lcd.clear();
  digitalWrite(GLED, HIGH);
  while (score > 0) { // during timer countdown, and before no score left

    String wireTouchOutput = wireTouchLabel + wireTouchCount;  // combining label + variable
    start = digitalRead(startPin);
    end_ = digitalRead(endPin);

    lcd.setCursor(0, 0);
    sprintf(msg, "Score = %4d", score);
    lcd.print(msg);
    lcd.setCursor(0, 1);
    lcd.print(wireTouchOutput);
    score = score - 1; // timer decrement                                   <-- ADJUST to change difficulty
    delay(50); // how fast score decreases                                  <-- ADJUST to change difficulty

    // Wire is touched
    if (start == LOW && end_ == LOW ) {
      score = score - 500; //                                               <-- ADJUST to change wire touch penalty
      wireTouchCount++; // increment hit count
      digitalWrite(GLED, LOW);
      digitalWrite(RLED, HIGH);
      tone(buzzer, 675);
      delay(250); // This serves as a grace period                          <-- ADJUST this as desired
      noTone(buzzer);
      delay(20);
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, HIGH);
    }
    // End diode is touched
    else if (start == HIGH && end_ == LOW) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You Win!");
      lcd.setCursor(0, 1);
      sprintf(msg, "Score = %4d", score);
      lcd.print(msg);
      delay(6000);  // delay before returning to start screen
      lcd.clear();
      digitalWrite(GLED, LOW);

      loop(); // <-- go back to the beginning loop, without this, score >0 countdown starts immediately
    }
  }

  // Timer gets to zero
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("You lose!");
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, HIGH);
  tone(buzzer, 375);
  delay(1000);
  noTone(buzzer);
  delay(2500); // delay before returning to start screen
  digitalWrite(RLED, LOW); //Red LED off
}
