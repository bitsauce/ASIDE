#ifndef PROFILER_H
#define PROFILER_H

#include <QWidget>

namespace Ui {
class Profiler;
}

class Profiler : public QWidget
{
    Q_OBJECT

public:
    explicit Profiler(QWidget *parent = 0);
    ~Profiler();

private:
    Ui::Profiler *ui;
};

#endif // PROFILER_H
