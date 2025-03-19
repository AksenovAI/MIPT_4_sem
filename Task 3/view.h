#pragma once
#include <stdio.h>

class View;
class TView;
class GView;

enum class Type {
    TEXT;
    GRAPICS;
};

enum Color {
    BLACK   = 30,
    RED     = 31,
    GREEN   = 32,
    YELLOW  = 33,
    BLUE    = 34,
    MAGENTA = 35,
    CYAN    = 36,
    WHITE   = 37,
    DEFAULT = 0
};

class View {
    public:
        virtual void draw() = 0;
        static View * getView(char type, int size_x = 20, size_y = 20);
        virtual void run();
        static View* cur_view = NULL;
};

class TView : public View {
    public:
        TView(int size) : screen_size(size) {}
        void draw();
        void run();
    private:
        void clear_screen();
        void go_to_xy(int x, int y);
        void set_bgr_color(int color);
        void set_txt_color(int color);
        void reset_color();
        void draw_frame();
        TView();
        ~TView();
};

class Field{
    public:
    int x_size;
    int y_size;
    int state;
    Field(int x, int y);

}
