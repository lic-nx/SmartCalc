#include "mainwindow.h"

#include <iostream>
#include <string>

#include "ui_mainwindow.h"

extern "C" {
#include "s21_calc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  Setup();
  creditcalc = new creditCAlc();
  connect(creditcalc, &creditCAlc::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ButtonPressedAndPrinted(bool checked) {
  bool ok;
  float x = 0;
  if (ui->xValue->text() != "") {
    QString str2 = ui->xValue->text();
    x = str2.toFloat(&ok);
    if (!ok) {
      ui->lineEdit->setText("err input x");
    }
  }

  auto but = static_cast<QAbstractButton *>(sender());
  //  ui->lineEdit->setText("(17*1/5*0.125-(2*32/45-1/7/60))*(11/40/4*7/12+2.64)");
  if (!but) return;
  if (but->text() == "del") {
    QString str = ui->lineEdit->text();
    str.chop(1);
    ui->lineEdit->setText(str);
  } else if (but->text() == "clean") {
    ui->lineEdit->setText("");
  } else if (but->text() == "=") {
    if (ui->lineEdit->text() == "") {
      ui->lineEdit->setText("err input x");
    }
    QString str1 = ui->lineEdit->text();
    QByteArray ba = str1.toLocal8Bit();
    char *text = ba.data();
    char cleanText[255];
    int errprint = validator(text, cleanText);
    std::cout << errprint;
    if (errprint == 0) {
      //        *text = ui->lineEdit->text().toLocal8Bit().data();
      //        ui->lineEdit->setText();
      std::cout << cleanText;
      double result = pol_notation(cleanText, x);
      ui->lineEdit->setText("");
      ui->lineEdit->setText(QString::number(result, 'f', 7));
    } else {
      ui->lineEdit->setText("err input");
    }

  }

  else {
    ui->lineEdit->setText(ui->lineEdit->text() + but->text());
  }
}

void MainWindow::Setup() {
  for (auto &but : ui->all_btns->buttons())
    connect(but, &QAbstractButton::clicked, this,
            &MainWindow::ButtonPressedAndPrinted);
}

void MainWindow::on_pushButton_13_clicked() {
  if (ui->lineEdit->text() == "") {
    ui->lineEdit->setText("err input x");
  }
  QString str1 = ui->lineEdit->text();
  QByteArray ba = str1.toLocal8Bit();
  char *text = ba.data();
  char cleanText[255] = {0};
  int errprint = validator(text, cleanText);

  if (errprint == 0) {
    xBegin = -100;
    xEnd = 100;
    bool okBegin, okEnd;

    if (ui->start->text() != "") {
      QString str2 = ui->start->text();
      xBegin = str2.toFloat(&okBegin);
      if (!okBegin) {
        ui->lineEdit->setText("err input x");
      }
    }
    if (ui->end->text() != "") {
      QString str2 = ui->end->text();
      xEnd = str2.toFloat(&okEnd);
      if (!okEnd) {
        ui->lineEdit->setText("err input x");
      }
    }
    // очищаем график
    ui->widget->clearGraphs();

    // обнуляем координаты
    float yMin, yMax, tmp;
    h = 0.1;
    ui->widget->xAxis->setRange(xBegin, xEnd);

    X = xBegin;
    N = (xEnd - xBegin) / h + 2;
    yMin = pol_notation(cleanText, xBegin);
    yMax = pol_notation(cleanText, xBegin);
    for (X = xBegin + h; X < xEnd; X += h) {
      x.push_back(X);
      tmp = pol_notation(cleanText, X);  // поиск по польской нотации;
      y.push_back(tmp);
      if (tmp < yMin) {
        yMin = tmp;
      } else if (tmp > yMax) {
        yMax = tmp;
      }
    }
    ui->widget->yAxis->setRange(yMin - 1, yMax + 1);
    ui->widget->addGraph();  // создаем новый график
    ui->widget->graph(0)->addData(x,
                                  y);  // устанавливаем значения для отрисовки
    ui->widget->replot();  // рисуем
    x.clear();
    y.clear();
  } else {
    ui->lineEdit->setText("err input");
  }
}

void MainWindow::on_pushButton_14_clicked() {
  this->hide();
  creditcalc->show();
}
