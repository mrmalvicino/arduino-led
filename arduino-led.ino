int const NUM_R_LEDS = 8; // Cantidad de leds rojos en modo digital
int const NUM_G_LEDS = 8; // Cantidad de leds verdes en modo digital
int const NUM_B_LEDS = 8; // Cantidad de leds azules en modo digital

int const NUM_R_PWM = 3; // Cantidad de leds rojos en modo PWM
int const NUM_G_PWM = 3; // Cantidad de leds rojos en modo PWM
int const NUM_B_PWM = 2; // Cantidad de leds rojos en modo PWM

int const NUM_BUTTONS = 6; // Cantidad de botones
int const NUM_POTS = 3; // Cantidad de potenciometros

int red_pwm_pin[NUM_R_PWM] = {3,5,8};
int green_pwm_pin[NUM_G_PWM] = {2, 6, 9};
int blue_pwm_pin[NUM_B_PWM] = {4, 7};

int red_pin[NUM_R_LEDS] = {23, 24, 29, 30, 34, 37, 46, 50};
int green_pin[NUM_G_LEDS] = {25, 26, 31, 32, 35, 38, 44, 52};
int blue_pin[NUM_B_LEDS] = {22, 27, 28, 33, 36, 40, 42, 48};

int button_pin[NUM_BUTTONS] = {43, 45, 47, 49, 51, 53};
int pot_pin[NUM_POTS] = {0,1,2};

int fade_time = 10; // Tiempo de fade para efectos
int menu_program = 1; // Programa del menu a ejecutar

void read_pots(){
    for(int i = 0; i < NUM_R_PWM; i ++){
        analogWrite(red_pwm_pin[i], analogRead(pot_pin[0]) / 4);
    }

    for(int i = 0; i < NUM_G_PWM; i ++){
        analogWrite(green_pwm_pin[i], analogRead(pot_pin[1]) / 4);
    }

    for(int i = 0; i < NUM_B_PWM; i ++){
        analogWrite(blue_pwm_pin[i], analogRead(pot_pin[2]) / 4);
    }
}

void blink_white(){
    for(int lvl = 0; lvl < 256; lvl ++){ // Sube intensidad PWM
        for(int i = 0; i < NUM_R_PWM; i ++){
            analogWrite(red_pwm_pin[i], lvl);
        }
        for(int i = 0; i < NUM_G_PWM; i ++){
            analogWrite(green_pwm_pin[i], lvl);
        }
        for(int i = 0; i < NUM_B_PWM; i ++){
            analogWrite(blue_pwm_pin[i], lvl);
        }
        delay(fade_time);
    }

    for(int lvl = 255; 0 <= lvl; lvl --){ // Baja intensidad PWM
        for(int i = 0; i < NUM_R_PWM; i ++){
            analogWrite(red_pwm_pin[i], lvl);
        }
        for(int i = 0; i < NUM_G_PWM; i ++){
            analogWrite(green_pwm_pin[i], lvl);
        }
        for(int i = 0; i < NUM_B_PWM; i ++){
            analogWrite(blue_pwm_pin[i], lvl);
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

    for(int i = 0; i < NUM_R_PWM; i++){
        pinMode(red_pwm_pin[i], OUTPUT);
    }

    for(int i = 0; i < NUM_G_PWM; i++){
        pinMode(green_pwm_pin[i], OUTPUT);
    }

    for(int i = 0; i < NUM_B_PWM; i++){
        pinMode(blue_pwm_pin[i], OUTPUT);
    }

    for(int i = 0; i < NUM_BUTTONS; i++){
        pinMode(button_pin[i], INPUT);
    }
    pinMode(52, OUTPUT);
    
}

void loop(){
    digitalWrite(52, HIGH);

    switch(menu_program){
        case 1:
            blink_white();
            break;
        case 2:
            //fade_rainbow();
            break;
        case 3:
            //fade_cyan_to_blue();
            break;
        case 4:
            //fade_pink_to_violet();
            break;
        case 5:
            //strobe_white();
            break;
        case 6:
            //strobe_rainbow();
            break;
        case 7:
            //strobe_random();
            break;
        case 8:
            read_pots();
            break;
        case 9:
            //color_red();
            break;
        case 10:
            //color_green();
            break;
        case 11:
            //color_blue();
            break;
        case 12:
            //color_white();
            break;
        case 13:
            //color_ambar();
            break;
        case 14:
            //color_cyan();
            break;
        case 15:
            //color_pink();
            break;
        case 16:
            //color_violet();
            break;
    }
}