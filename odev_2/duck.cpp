
#include "duck.h"
#include <QLabel>
#include <QTime>
#include<QDebug>

duck::duck(QWidget *parent) : QWidget(parent) {

    setFixedSize(800, 600);

    qsrand(QTime::currentTime().msec());

     for (int i = 0; i < 30; ++i) {


         QLabel *duck = new QLabel(this);
         QPixmap duckPixmap("C:/Users/bsanl/OneDrive/Belgeler/odev_2/Images/ordek.png");

         duckPixmap = duckPixmap.scaled(30, 30, Qt::KeepAspectRatio);
         duck->setPixmap(duckPixmap);
         duck->setGeometry(qrand() % (width() - duck->width()), qrand() % (height() - duck->height()), duck->width(), duck->height());

         ducks.append(duck);
}

     QPixmap  explosionPixmap = QPixmap("C:/Users/bsanl/OneDrive/Belgeler/odev_2/Images/vurulma.png");
      explosionPixmap = explosionPixmap.scaledToWidth(30);
      explosionPixmap = explosionPixmap.scaledToHeight(30);


      explosionLabel = new QLabel(this);
      explosionLabel->setPixmap(explosionPixmap);
      explosionLabel->hide();


     Label1 = new QLabel(this);
         updateLabels();


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveDuck()));
    timer->start(700);
}



 void duck::mousePressEvent(QMouseEvent *event){
              if (event->button() == Qt::LeftButton) {

    for (QLabel *duck : ducks) {
        if (duck->geometry().contains(event->pos())) {

          showExplosion(duck->geometry().center());
          duck->hide();
              sayac++;
         updateLabels();


        }
    }
}

}
          void duck::moveDuck() {
    int step = 20;
    for (QLabel *duck : ducks) {
        int x = duck->geometry().x();
        int y = duck->geometry().y();
          y += step;


        if (y > height()) {

            y = 0 - duck->height();
            x = qrand() % (width() - duck->width());
           sayac1++;
            updateLabels();
        }

        duck->setGeometry(x, y, duck->width(), duck->height());
    }
          }


     void duck::showExplosion(const QPoint& position) {

        explosionLabel->move(position - QPoint(explosionLabel->width() / 2, explosionLabel->height() / 2));
        explosionLabel->show();

         QTimer::singleShot(500, this, [this]() {
            explosionLabel->hide();
        });
}

     void duck::updateLabels() {

         Label1->setText("VURULAN ÖRDEK SAYISI: " + QString::number(sayac) + "\n" +
                         "YERE DÜŞEN ÖRDEK SAYISI: " + QString::number(sayac1));
     }
