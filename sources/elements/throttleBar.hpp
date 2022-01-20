#ifndef DEF_THROTTLEBAR
#define DEF_THROTTLEBAR

#include <QWidget>
#include <QProgressBar>

class throttleBar : public QProgressBar {

private:


public:
  throttleBar (QWidget* parent) : QProgressBar(parent) {
    this->setStyleSheet("QProgressBar::chunk { background-color: green } QProgressBar { text-align: center; border: 2px solid grey }");
    this->setOrientation(Qt::Vertical);
    this->setMinimum(0);
    this->setMaximum(100);
    this->setFixedSize(50, 300);
  };
};
#endif
