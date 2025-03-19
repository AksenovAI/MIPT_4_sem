#include "model.h"
#include "view.h"
#include "controller"

int main(int argc, char** argv){
    clear();
    int hight = 100;
    int width = 100;
    int med_h = hight/2;
    int med_w = hight/2;
    printf("\033[%d;%dH", med_h, med_w);
    printf("\033[1m");    
}