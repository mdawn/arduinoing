// define LEDs segments lit to create each number
byte seven_seg_digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // = 0
    {0, 1, 1, 0, 0, 0, 0}, // = 1
    {1, 1, 0, 1, 1, 0, 1}, // = 2
    {1, 1, 1, 1, 0, 0, 1}, // = 3
    {0, 1, 1, 0, 0, 1, 1}, // = 4
    {1, 0, 1, 1, 0, 1, 1}, // = 5
    {1, 0, 1, 1, 1, 1, 1}, // = 6
    {1, 1, 1, 0, 0, 0, 0}, // = 7
    {1, 1, 1, 1, 1, 1, 1}, // = 8
    {1, 1, 1, 0, 0, 1, 1}, // = 9
};

void setup()
{
  // set the seven-segment LED pins as output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

// sevenSegWrite converts bytes to digits and loops through
// to match proper segments for each digit counted
void sevenSegWrite(byte digit)
{
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount)
  {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void loop()
{
  for (byte count = 10; count > 0; --count)
  {                           // start countdown
    delay(1000);              // 1 second between each digit
    sevenSegWrite(count - 1); // count down by one
  }
  // delay 7 seconds before restarting countdown
  delay(7000);
}
