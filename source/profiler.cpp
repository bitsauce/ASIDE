#include "profiler.h"
#include "ui_profiler.h"

Profiler::Profiler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Profiler)
{
    ui->setupUi(this);
}

Profiler::~Profiler()
{
    delete ui;
}
