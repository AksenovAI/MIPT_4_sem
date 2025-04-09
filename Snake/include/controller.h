#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include "view.h"
#include "model.h"

class GameController {
public:
    GameController(std::unique_ptr<GameView> view, std::shared_ptr<GameModel> model);
    void run();

private:
    std::unique_ptr<GameView> m_view;
    std::shared_ptr<GameModel> m_model;
};

#endif