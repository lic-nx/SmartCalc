#include "creditcalc.h"

#include "ui_creditcalc.h"

creditCAlc::creditCAlc(QWidget *parent)
    : QWidget(parent), ui(new Ui::creditCAlc) {
  ui->setupUi(this);
}

creditCAlc::~creditCAlc() { delete ui; }

void creditCAlc::on_pushButton_clicked() {
  this->close();
  emit firstWindow();
}

void creditCAlc::on_pushButton_2_clicked() {
  double summ = ui->sum_credit->value();
  int period = ui->time->value();
  int proc = ui->procent->value();
  double SumDifinMounth = 0, procentSumm = 0, totalPayout = 0;

  if (ui->credit_type->currentText() == "аннуитетный") {
    annuityLoan(summ, period, proc, &SumDifinMounth, &procentSumm,
                &totalPayout);
    ui->textBrowser->setText(QString::number(SumDifinMounth, 'f', 2));
    //        ui->result_pmt->setText(QString::number(SumDifinMounth, 'f',2));
  }

  if (ui->credit_type->currentText() == "дифференцированный") {
    ui->textBrowser->setText("");
    while (period > 0) {
      differentiatedCredit(&summ, period, proc, &SumDifinMounth, &procentSumm,
                           &totalPayout);
      ui->textBrowser->setText(ui->textBrowser->toPlainText() + ';' +
                               QString::number(SumDifinMounth, 'f', 2) + "\n");
      period--;
    }
  }

  ui->result_overpay->setText(QString::number(procentSumm, 'f', 2));
  ui->result_total_pay->setText(QString::number(totalPayout, 'f', 2));
}
