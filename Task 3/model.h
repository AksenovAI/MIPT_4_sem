#include <list>
#include <cstdlib>
enum Direction {
    UP      = 1,
    RIGHT   = 2,
    DOWN    = 3,
    LEFT    = 4
};



class Model {
    std::list <Rabbit> rabbits;
    std::list <Snake>  snakes;
    public:
        void update(); 
};

class Segment {
    int x;
    int y;
    Segment(int in_x = 0; int in_y = 0){
        x = in_x;
        y = in_y;
    }
};

class Snake {
    std::list <Segment> segments;
    int direction;
    public:
        int move();
        Snake(): ;
        ~Sanke();
};

class Rabbit {
    int x;
    int y;

};
