int const NUM_R_LEDS = 2; // Cantidad de leds rojos
int const NUM_G_LEDS = 2; // Cantidad de leds verdes
int const NUM_B_LEDS = 2; // Cantidad de leds azules
int const NUM_POTS = 3; // Cantidad de potenciometros
int const NUM_MENU_PROGRAMS = 2; // Cantidad de programas seleccionables por encoder rotativo
int red_pin[NUM_R_LEDS] = {4,7};
int green_pin[NUM_G_LEDS] = {5,8};
int blue_pin[NUM_B_LEDS] = {6,9};
int pot_pin[NUM_POTS] = {0,1,2}; // Pines de potenciometros R G B
int fade_time = 10;
int encoder_menu;

void read_pots(){
    for(int i = 0; i < NUM_R_LEDS; i ++){
        analogWrite(red_pin[i], analogRead(pot_pin[i]) / 4);
    }
}

void blink_white(){
    for(int lvl = 0; lvl < 256; lvl ++){ // Sube intensidad
        for(int i = 0; i < NUM_R_LEDS; i ++){
            analogWrite(red_pin[i], lvl);
        }
        for(int i = 0; i < NUM_G_LEDS; i ++){
            analogWrite(green_pin[i], lvl);
        }
        for(int i = 0; i < NUM_B_LEDS; i ++){
            analogWrite(blue_pin[i], lvl);
        }
        delay(fade_time);
    }

    for(int lvl = 255; 0 <= lvl; lvl --){ // Baja intensidad
        for(int i = 0; i < NUM_R_LEDS; i ++){
            analogWrite(red_pin[i], lvl);
        }
        for(int i = 0; i < NUM_G_LEDS; i ++){
            analogWrite(green_pin[i], lvl);
        }
        for(int i = 0; i < NUM_B_LEDS; i ++){
            analogWrite(blue_pin[i], lvl);
        }
        delay(fade_time);
    }
}

void setup(){
    for(int i = 0; i < NUM_R_LEDS; i++){
        pinMode(red_pin[i], OUTPUT);
    }

    for(int i = 0; i < NUM_G_LEDS; i++){
        pinMode(green_pin[i], OUTPUT);
    }

    for(int i = 0; i < NUM_B_LEDS; i++){
        pinMode(blue_pin[i], OUTPUT);
    }
}

void loop(){
    encoder_menu = 1;

    switch(encoder_menu){
        case 1:
            blink_white();
            break;
        case 2:
            read_pots();
            break;
    }
}