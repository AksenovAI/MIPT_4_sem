#pragma once
#include <stdio.h>
class t_view {
    private:
        void clear_screen();
        void go_to_xy(int x, int y);
        void set_collor(int r, int g, int b);
        int* rabits;
        int* snake_coordinates;
        int x_size;
        int y_size;
        int r;
        int g;
        int b;
    public:
        void draw_start_screen();
        t_view();
        ~t_view();
};





