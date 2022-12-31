const int cosine_lookup[]   PROGMEM ={1000, 980, 923, 831, 707, 555, 382, 195, 0, -195, -382, -555,   -707, -831, -923, -980, -1000, -980, -923, -831, -707, -555, -382, -195, 0, 195,   382, 555, 707, 831, 923, 980, 1000, 923, 707, 382, 0, -382, -707, -923, -1000, -923,   -707, -382, 0, 382, 707, 923, 1000, 923, 707, 382, 0, -382, -707, -923, -1000, -923,   -707, -382, 0, 382, 707, 923, 1000, 831, 382, -195, -707, -980, -923, -555, 0, 555,   923, 980, 707, 195, -382, -831, -1000, -831, -382, 195, 707, 980, 923, 555, 0, -555,   -923, -980, -707, -195, 382, 831, 1000, 707, 0, -707, -1000, -707, 0, 707, 1000,   707, 0, -707, -1000, -707, 0, 707, 999, 707, 0, -707, -1000, -707, 0, 707, 1000,   707, 0, -707, -1000, -707, 0, 707, 1000, 555, -382, -980, -707, 195, 923, 831, 0,   -831, -923, -195, 707, 980, 382, -555, -1000, -555, 382, 980, 707, -195, -923, -831,   0, 831, 923, 195, -707, -980, -382, 555, 1000, 382, -707, -923, 0, 923, 707, -382,   -1000, -382, 707, 923, 0, -923, -707, 382, 1000, 382, -707, -923, 0, 923, 707, -382,   -1000, -382, 707, 923, 0, -923, -707, 382, 1000, 195, -923, -555, 707, 831, -382,   -980, 0, 980, 382, -831, -707, 555, 923, -195, -1000, -195, 923, 555, -707, -831,   382, 980, 0, -980, -382, 831, 707, -555, -923, 195, 1000, 0, -1000, 0, 1000, 0,   -1000, 0, 999, 0, -1000, 0, 1000, 0, -1000, 0, 1000, 0, -1000, 0, 1000, 0, -1000,   0, 1000, 0, -1000, 0, 1000, 0, -1000, 0, 1000, -195, -923, 555, 707, -831, -382,   980, 0, -980, 382, 831, -707, -555, 923, 195, -1000, 195, 923, -555, -707, 831,   382, -980, 0, 980, -382, -831, 707, 555, -923, -195, 1000, -382, -707, 923, 0, -923,   707, 382, -1000, 382, 707, -923, 0, 923, -707, -382, 1000, -382, -707, 923, 0, -923,   707, 382, -1000, 382, 707, -923, 0, 923, -707, -382, 1000, -555, -382, 980, -707,   -195, 923, -831, 0, 831, -923, 195, 707, -980, 382, 555, -1000, 555, 382, -980,   707, 195, -923, 831, 0, -831, 923, -195, -707, 980, -382, -555, 1000, -707, 0, 707,   -1000, 707, 0, -707, 1000, -707, 0, 707, -1000, 707, 0, -707, 1000, -707, 0, 707,   -1000, 707, 0, -707, 1000, -707, 0, 707, -1000, 707, 0, -707, 1000, -831, 382, 195,   -707, 980, -923, 555, 0, -555, 923, -980, 707, -195, -382, 831, -1000, 831, -382,   -195, 707, -980, 923, -555, 0, 555, -923, 980, -707, 195, 382, -831, 1000, -923,   707, -382, 0, 382, -707, 923, -1000, 923, -707, 382, 0, -382, 707, -923, 1000, -923,   707, -382, 0, 382, -707, 923, -1000, 923, -707, 382, 0, -382, 707, -923, 1000, -980,   923, -831, 707, -555, 382, -195, 0, 195, -382, 555, -707, 831, -923, 980, -1000,   980, -923, 831, -707, 555, -382, 195, 0, -195, 382, -555, 707, -831, 923, -980,   1000, -1000, 1000, -1000, 999, -1000, 1000, -1000, 1000, -1000, 1000, -1000, 1000,   -1000, 1000, -1000, 1000, -1000, 1000, -1000, 1000, -1000, 1000, -999, 1000, -1000,   1000, -1000, 1000, -999, 1000, -1000};

const int sine_lookup[] PROGMEM   ={0, 195, 382, 555, 707, 831, 923, 980, 1000, 980, 923, 831, 707, 555,   382, 195, 0, -195, -382, -555, -707, -831, -923, -980, -1000, -980, -923, -831,   -707, -555, -382, -195, 0, 382, 707, 923, 1000, 923, 707, 382, 0, -382, -707, -923,   -1000, -923, -707, -382, 0, 382, 707, 923, 999, 923, 707, 382, 0, -382, -707, -923,   -1000, -923, -707, -382, 0, 555, 923, 980, 707, 195, -382, -831, -1000, -831, -382,   195, 707, 980, 923, 555, 0, -555, -923, -980, -707, -195, 382, 831, 1000, 831, 382,   -195, -707, -980, -923, -555, 0, 707, 1000, 707, 0, -707, -1000, -707, 0, 707, 999,   707, 0, -707, -1000, -707, 0, 707, 1000, 707, 0, -707, -1000, -707, 0, 707, 1000,   707, 0, -707, -1000, -707, 0, 831, 923, 195, -707, -980, -382, 555, 999, 555, -382,   -980, -707, 195, 923, 831, 0, -831, -923, -195, 707, 980, 382, -555, -1000, -555,   382, 980, 707, -195, -923, -831, 0, 923, 707, -382, -1000, -382, 707, 923, 0, -923,   -707, 382, 1000, 382, -707, -923, 0, 923, 707, -382, -1000, -382, 707, 923, 0, -923,   -707, 382, 1000, 382, -707, -923, 0, 980, 382, -831, -707, 555, 923, -195, -1000,   -195, 923, 555, -707, -831, 382, 980, 0, -980, -382, 831, 707, -555, -923, 195,   1000, 195, -923, -555, 707, 831, -382, -980, 0, 1000, 0, -1000, 0, 999, 0, -1000,   0, 1000, 0, -1000, 0, 1000, 0, -1000, 0, 1000, 0, -1000, 0, 1000, 0, -1000, 0, 1000,   0, -1000, 0, 1000, 0, -1000, 0, 980, -382, -831, 707, 555, -923, -195, 1000, -195,   -923, 555, 707, -831, -382, 980, 0, -980, 382, 831, -707, -555, 923, 195, -1000,   195, 923, -555, -707, 831, 382, -980, 0, 923, -707, -382, 999, -382, -707, 923,   0, -923, 707, 382, -1000, 382, 707, -923, 0, 923, -707, -382, 1000, -382, -707,   923, 0, -923, 707, 382, -1000, 382, 707, -923, 0, 831, -923, 195, 707, -980, 382,   555, -1000, 555, 382, -980, 707, 195, -923, 831, 0, -831, 923, -195, -707, 980,   -382, -555, 1000, -555, -382, 980, -707, -195, 923, -831, 0, 707, -1000, 707, 0,   -707, 1000, -707, 0, 707, -1000, 707, 0, -707, 1000, -707, 0, 707, -1000, 707, 0,   -707, 1000, -707, 0, 707, -999, 707, 0, -707, 999, -707, 0, 555, -923, 980, -707,   195, 382, -831, 1000, -831, 382, 195, -707, 980, -923, 555, 0, -555, 923, -980,   707, -195, -382, 831, -1000, 831, -382, -195, 707, -980, 923, -555, 0, 382, -707,   923, -1000, 923, -707, 382, 0, -382, 707, -923, 1000, -923, 707, -382, 0, 382, -707,   923, -1000, 923, -707, 382, 0, -382, 707, -923, 999, -923, 707, -382, 0, 195, -382,   555, -707, 831, -923, 980, -1000, 980, -923, 831, -707, 555, -382, 195, 0, -195,   382, -555, 707, -831, 923, -980, 999, -980, 923, -831, 707, -555, 382, -195, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0};

#define ADC_PIN 34
#define N 32  // Number of sample
uint16_t   f[N], angle;
float Value;
float cs, ss;
uint8_t x, k;
char pin;
char arr[8][8]=
{
  {0,   0, 0, 0, 0, 0, 0, 31},    //L1
  {0, 0, 0, 0, 0, 0, 31, 31},     //L2
  {0,   0, 0, 0, 0, 31, 31, 31},    //L3
  {0, 0, 0, 0, 31, 31, 31, 31},     //L4
  {0,   0, 0, 31, 31, 31, 31, 31},    //L5
  {0, 0, 31, 31, 31, 31, 31, 31},   //L6
  {0,   31, 31, 31, 31, 31, 31, 31},  //L7
  {31, 31, 31, 31, 31, 31, 31, 31}  //L8
};  



void setup() {
  Serial.begin(250000);
  delay(1000);
  Serial.println("DFT Start.");

  pinMode(ADC_PIN,INPUT);
}

void loop() {
   for(k = 0; k < N; k++) //get 32 value
   {
      f[k] = analogRead(ADC_PIN);  
      
   }

for(k = 0; k < N/2; k++){
  cs = ss = 0;
      for(x   = 0; x < N; x++)
      {
        angle = x + (32*k);
        cs += (float)f[x]*(int16_t)pgm_read_word(&cosine_lookup[angle]);    //real   part of dft
        ss += (float)f[x]*(int16_t)pgm_read_word(&sine_lookup[angle]);      //imaginary   part of dft
     
               
        cs /= N*1000;
        ss /= N*1000;
              

        x   = (uint8_t)sqrt((cs*cs)+(ss*ss));    //absolute value of dft
        x /= 2;   //scaling
        x++;
        if(x   > 16) x = 16;
        if(x < 4)
        {
          delay(1);
          Serial.print("X = ");
          Serial.println(x);
          delay(1);
        }
        else
        {
          delay(1);
           Serial.print("X = ");
          Serial.println(x);
          delay(1);
        }

      }
     
}

delay(10000);




}
