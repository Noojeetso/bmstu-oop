#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ROTATION_ANGLE 5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();
}


MainWindow::~MainWindow()
{
    ret_code_t rc;
    request_t request;

    request.code = EXIT;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);

    delete ui;
}


void MainWindow::on_load_model_clicked()
{
    ret_code_t rc;
    vector3_t rotation = {0, 0, 0};
    request_t request = { .code = LOAD_MODEL,
                          .filename = "cube.txt" };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = SCALE_MODEL;
    request.scale = 100;

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = ROTATE_MODEL;
    request.rotation = rotation;

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}

void MainWindow::on_scale_up_clicked()
{
    ret_code_t rc;
    request_t request = { .code = SCALE_MODEL,
                          .scale = 1.1 };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_scale_down_clicked()
{
    ret_code_t rc;
    request_t request = { .code = SCALE_MODEL,
                          .scale = .9 };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}

void MainWindow::on_move_up_clicked()
{
    ret_code_t rc;
    vector3_t translation = {0, -10, 0};

    request_t request = { .code = TRANSLATE_MODEL,
                          .translation = translation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_move_right_clicked()
{
    ret_code_t rc;
    vector3_t translation = {10, 0, 0};

    request_t request = { .code = TRANSLATE_MODEL,
                          .translation = translation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_move_down_clicked()
{
    ret_code_t rc;
    vector3_t translation = {0, 10, 0};

    request_t request = { .code = TRANSLATE_MODEL,
                          .translation = translation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_move_left_clicked()
{
    ret_code_t rc;
    vector3_t translation = {-10, 0, 0};

    request_t request = { .code = TRANSLATE_MODEL,
                          .translation = translation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}

void MainWindow::on_rotate_up_x_clicked()
{
    ret_code_t rc;
    vector3_t rotation = {ROTATION_ANGLE, 0, 0};

    request_t request = { .code = ROTATE_MODEL,
                          .rotation = rotation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_rotate_down_x_clicked()
{
    ret_code_t rc;
    vector3_t rotation = {-ROTATION_ANGLE, 0, 0};

    request_t request = { .code = ROTATE_MODEL,
                          .rotation = rotation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}

void MainWindow::on_rotate_up_y_clicked()
{
    ret_code_t rc;
    vector3_t rotation = {0, ROTATION_ANGLE, 0};

    request_t request = { .code = ROTATE_MODEL,
                          .rotation = rotation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_rotate_down_y_clicked()
{
    ret_code_t rc;
    vector3_t rotation = {0, -ROTATION_ANGLE, 0};

    request_t request = { .code = ROTATE_MODEL,
                          .rotation = rotation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_rotate_up_z_clicked()
{
    ret_code_t rc;
    vector3_t rotation = {0, 0, ROTATION_ANGLE};

    request_t request = { .code = ROTATE_MODEL,
                          .rotation = rotation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}


void MainWindow::on_rotate_down_z_clicked()
{
    ret_code_t rc;
    vector3_t rotation = {0, 0, -ROTATION_ANGLE};

    request_t request = { .code = ROTATE_MODEL,
                          .rotation = rotation };

    rc = handle_request(request);
    if (rc != EXIT_OK)
    {
        handle_error(rc);
        return;
    }

    request.code = DRAW_MODEL;
    request.canvas = canvas;

    rc = handle_request(request);
    if (rc != EXIT_OK)
        handle_error(rc);
}
