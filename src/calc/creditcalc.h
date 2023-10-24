#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QWidget>

extern "C" {
#include "credit.h"
}

namespace Ui {
class creditCAlc;
}

class creditCAlc : public QWidget {
  Q_OBJECT

 public:
  explicit creditCAlc(QWidget *parent = nullptr);
  ~creditCAlc();

 signals:
  void firstWindow();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

 private:
  Ui::creditCAlc *ui;
};

#endif  // CREDITCALC_H
