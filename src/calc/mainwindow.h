#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <creditcalc.h>

#include <QAbstractButton>
#include <QMainWindow>
#include <QVector>
#include <QWidget>
extern "C" {
#include "s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 public slots:
  void ButtonPressedAndPrinted(bool checked);

 private slots:
  void on_pushButton_13_clicked();
  void on_pushButton_14_clicked();

 private:
  void Setup();
  Ui::MainWindow *ui;
  creditCAlc *creditcalc;
  // new window
  //  то что ниже для графика
  double xBegin, xEnd, h, X;
  int N;
  QVector<double> x, y;
};

#endif  // MAINWINDOW_H
