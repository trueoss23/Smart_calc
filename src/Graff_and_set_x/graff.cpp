#include "graff.h"
#include "ui_graff.h"

s21::Graff::Graff(QString str, QWidget *parent) :
    QWidget(parent),
    res_str(str),
    h(0.1),
    xBegin(0),
    xEnd(0),
    yBegin(0),
    yEnd(0),
    ui(new Ui::Graff) {
    ui->setupUi(this);
}

void s21::Graff::init_vectors_for_graff() {
    for (float X = xBegin; X <= xEnd + h; X += h) {
        Controller controller;
        controller.set_x_in_model(X);
        x.push_back(X);
        controller.add_full_string_in_model(res_str.toStdString());
        std::string temp_str = controller.get_result();
        double y_res = std::stod(temp_str);
        y.push_back(y_res);
    }
}

void s21::Graff::set_borders(double xB, double xE, double yB, double yE) {
    xBegin = xB;
    xEnd = xE;
    yBegin = yB;
    yEnd = yE;
}

void s21::Graff::draw_graff() {
    ui->widget->xAxis->setRange(xBegin, xEnd);
    ui->widget->yAxis->setRange(yBegin, yEnd);
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}



void s21::Graff::init_borders_of_graff(double xB, double xE, double yB, double yE) {
    set_borders(xB, xE, yB, yE);
    init_vectors_for_graff();
    draw_graff();
    show();
}

s21::Graff::~Graff() {
    delete ui;
}


