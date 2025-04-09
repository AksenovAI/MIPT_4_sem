#ifndef VIEW_H
#define VIEW_H

#include <memory>
#include "model.h"

class GameView {
public:
    virtual ~GameView() = default;
    virtual void render() = 0;
    virtual void handleInput() = 0;
    virtual bool isRunning() const = 0;    
    void setModel(std::shared_ptr<GameModel> model) { m_model = model; }
    static GameView* get_view(int type) {
        if (type == 1) return new ConsoleView();
        if (type == 2) return new SFMLView();
        return nullptr;
    }
protected:
    std::shared_ptr<GameModel> m_model;
};

#endif