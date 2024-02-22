#ifndef DUCK_H
#define DUCK_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QVector>

class QLabel;
class duck : public QWidget {
    Q_OBJECT

public:
    duck(QWidget *parent = nullptr);

protected:

    void mousePressEvent(QMouseEvent *event) override;
   void showExplosion(const QPoint& position);

      void updateLabels();
private slots:
    void moveDuck();

private:
    QVector<QLabel*> ducks;
    QLabel* explosionLabel;
    QTimer *timer;
    QLabel *Label1;

          int sayac=0;
          int sayac1=0;



};



#endif // DUCK_H
