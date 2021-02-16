////////////////////////////////////////////////////
//  Gebze Technical University                    //
//  Computer Engineering                          //
//  CSE101 Project                                //
//                                                //  
//  Soner Türkoğlu 161044013                      //
//                                                //  
//                                                //
////////////////////////////////////////////////////



const int BUTTON_PIN = 2;      // PIN for counter  and LED
const int LED_PIN = 13;        

int current_button = 0 , previous_button = 0; // state of counter

int menu , len;
char get_buffer[256];
long get_square ;
long result_square;
int counter = 0 ;int index = 0;

void setup() {                  
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT); 
  pinMode(BUTTON_PIN,INPUT);
  
}

void loop() {
  if(Serial.available() ){
    memset(get_buffer,'\0',sizeof(get_buffer));
    menu = Serial.read();
    switch(menu){
      case '1':
        digitalWrite(LED_PIN,HIGH);
        break;
      case '2':
        digitalWrite(LED_PIN,LOW);
        break;
      case '3':
        digitalWrite(LED_PIN,LOW);
        delay(500);
        digitalWrite(LED_PIN,HIGH);
        delay(1000);
        digitalWrite(LED_PIN,LOW);
        delay(1000);
        digitalWrite(LED_PIN,HIGH);
        delay(1000);
        digitalWrite(LED_PIN,LOW);
        delay(1000);
        digitalWrite(LED_PIN,HIGH);
        delay(1000);
        digitalWrite(LED_PIN,LOW);
        delay(1000);
        break;
      case '4':
        while(!Serial.available());
        len = Serial.readBytesUntil('\0',get_buffer,256);
        Serial.read();
        get_buffer[len] = '\0';
        get_square = atol(get_buffer);
        result_square = get_square * get_square;
        sprintf(get_buffer,"%ld",result_square);
        Serial.write(get_buffer,strlen(get_buffer));
        break;
        
      case '5': 
          counter = 0; 
          while(!Serial.available()){
            current_button = digitalRead(BUTTON_PIN);
            if(current_button != previous_button){
              if( current_button == HIGH ){
                counter++;
                sprintf(get_buffer,"%d",counter);
                Serial.print(get_buffer);
                delay(500);
             }
            }
            current_button = previous_button;  
            
          }
        break;
      default:
        break;
    }
    
  }
    

}
