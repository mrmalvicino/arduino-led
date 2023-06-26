int const TIME = 5;
int const NUM_LEDS = 3;
int led_io[NUM_LEDS][NUM_LEDS] = {{4,7,10}, {5,8,11}, {6,9,12}};

void setup(){
    for(int i = 0; i < NUM_LEDS; i++){
        for(int j = 0; j < NUM_LEDS; j++){
            pinMode(led_io[i][j], OUTPUT); 
        }
    }
}

void loop(){
    for(int level = 0; level < 256; level ++){
        analogWrite(led_io[0][0], level);
        analogWrite(led_io[1][0], level);
        analogWrite(led_io[2][0], level);
        delay(TIME);
    }

    for(int level = 255; 0 <= level; level --){
        analogWrite(led_io[0][0], level);
        analogWrite(led_io[1][0], level);
        analogWrite(led_io[2][0], level);
        delay(TIME);
    }
}
