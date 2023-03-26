#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draw.h"
#include "transform.h"
#include "manager.h"
#include "errors.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_model_clicked();

    void on_scale_up_clicked();

    void on_scale_down_clicked();

    void on_move_up_clicked();

    void on_move_right_clicked();

    void on_move_down_clicked();

    void on_move_left_clicked();

    void on_rotate_up_x_clicked();

    void on_rotate_down_x_clicked();

    void on_rotate_up_y_clicked();

    void on_rotate_down_y_clicked();

    void on_rotate_up_z_clicked();

    void on_rotate_down_z_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    canvas_t canvas;

    void handle_rc(const ret_code_t rc);
};
#endif // MAINWINDOW_H
