#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <psxgpu.h>
#include <psxpad.h>  
#include <psxetc.h> 
#include <string.h>



void get_input() {
    char pad_buf[2][34];
    PADTYPE* pad = (PADTYPE*)pad_buf[0];

}

struct Key {
    char psx_name[12];
    char name[12];
};

struct Key keys[] = {
    {"PADup", "dpad_up"},
    {"PADdown", "dpad_down"},
    {"PADleft", "dpad_left"},
    {"PADright", "dpad_right"},
    {"PADselect", "select"},
    {"PADstart", "start"},
    {"PADtriangle", "triangle"},
    {"PADcircle", "circle"},
    {"PADcross", "cross"},
    {"PADsquare", "square"},
    {"PADr1", "r1"},
    {"PADr2", "r2"},
    {"PADl1", "l1"},
    {"PADl2", "l2"}
};

struct Delay {
    char name[5];
    int frames;
};

void controller_init() {
    InitPAD(pad_buf[0], 34, pad_buf[1], 34);
    StartPAD();
}


struct Delay delays[] = {
    {"1s", 60},
    {"2s", 120},
    {"3s", 180},
    {"4s", 240},
    {"5s", 300},
    {"10s", 600}
};


void screen_cout(char *text) {
    FntLoad(960, 0);
    FntPrint(text);
    FntFlush(-1);
}

void delay(char *time) {
    for(int i = 0; i < 6; i++) {
        if(strcmp(time, delays[i].name) == 0) {
            int frames = delays[i].frames;
            while(frames > 0) {
                VSync(0);
                frames--;
            }
            return 0;
        }
    }
    screen_cout("this may crash the kernel");
    screen_cout("this is a serious error");
}

void calibrate_all() {

    //controller
    InitPAD(pad_buf[0], 34, pad_buf[1], 34);
    StartPAD();

    //screen
    VSync(0);
    ResetGraph(0);    
}


// it might work idk bro


// ResetGraph(0);
//   FntLoad(960, 0);
//   FntPrint("TESTING");
//   FntFlush(-1);
//    Vsync(0)



int main() {
    screen_cout("testing print..");
    
}
