#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>
#include "model.h"
#include "projected_vertices.h"
#include "pivot.h"
#include "errors.h"

struct canvas_t
{
    QGraphicsScene *scene;
    size_t width;
    size_t height;
};

ret_code_t draw_model(model_t &model, const canvas_t &canvas);

#endif // DRAW_H
