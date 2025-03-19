#include "view.h"

static View* View::getView(char type, int size_x, int size_y){
    if (View::cur_view != NULL){
        return View::cur_view;
    } else {
        if(type == Type::TEXT){
            return TView::TView(int size_x, int size_y);
        }else if(type == Type::GRAPICS){
            return GView::GView(int size_x, int size_y);
        }else{
            return NULL;
        }
    }
}


void TView::draw(){

}
void TView::run();
void TView::clear_screen();
void TView::go_to_xy(int x, int y){
    std::out << "\033[" << x <<";" << y <<"H";
}
void TView::set_bgr_color(int color);
void TView::set_txt_color(int color);
void TView::reset_color();
void TView::draw_frame();
TView();
~TView();

Field::Field(int x_size_, int y_size_){
    x_size = x_size_;
    y_size = y_size_;
    state[0] = calloc(1, x_size*y_size);
}