int const NUM_LEDS = 3; // Cantidad de colores
int const NUM_POTS = 3; // Cantidad de potenciometros
int led_pin[NUM_LEDS][NUM_LEDS] = {{4,7,10}, {5,8,11}, {6,9,12}}; // Pines de leds {{R1, R2, R3}, {G1, G2, G3}, {B1, B2, b3}}
int pot_pin[NUM_POTS] = {0,1,2}; // Pines de potenciometros {R, G, B}
int max_level[NUM_LEDS]; // Vector con la intensidad de cada color, por ejemplo {255, 255, 255}
int switch_pin = 22; // Pin de switch
int time = 10;

void setup(){
    pinMode(switch_pin, INPUT);
    
    for(int i = 0; i < NUM_LEDS; i++){
        for(int j = 0; j < NUM_LEDS; j++){
            pinMode(led_pin[i][j], OUTPUT);
        }
    }
}

void loop(){
    for(int i = 0; i < NUM_LEDS; i ++){
        max_level[i] = analogRead(pot_pin[i]) / 4;
    }

    if(digitalRead(switch_pin) == HIGH){ // Prender y apagar leds progresivamente
        for(int lvl = 0; lvl < 256; lvl ++){
            for(int i = 0; i < NUM_LEDS; i ++){
                analogWrite(led_pin[i][0], lvl);
            }
            delay(time);
        }

        for(int lvl = 255; 0 <= lvl; lvl --){
            for(int i = 0; i < NUM_LEDS; i ++){
                analogWrite(led_pin[i][0], lvl);
            }
            delay(time);
        }
    } else{ // Mantener prendido en los valores leidos por los potenciometros
        for(int i = 0; i < NUM_LEDS; i ++){
                analogWrite(led_pin[i][0], max_level[i]);
            }
    }
}
