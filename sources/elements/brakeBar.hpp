#ifndef DEF_BRAKEBAR
#define DEF_BRAKEBAR

#include <QWidget>
#include <QProgressBar>

class brakeBar : public QProgressBar {
private:


public:
  brakeBar (QWidget* parent) : QProgressBar(parent) {
    this->setStyleSheet("QProgressBar::chunk { background-color: red } QProgressBar { text-align: center; border: 2px solid grey }");
    this->setOrientation(Qt::Vertical);
    this->setMinimum(0);
    this->setMaximum(100);
    this->setValue(30);
    this->setFixedSize(50, 300);
  };
};
#endif
