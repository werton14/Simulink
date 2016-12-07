#include "preview.h"
#include <QGraphicsScene>

Preview::Preview(int x, int y, int p) : currentPainter(p)
{
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsFocusable);
    painterList = getPainterList();
}

QRectF Preview::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void Preview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painterList.at(currentPainter)(painter, -30); // Вызываем функцию отрисовки
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

// В силу костыльности Qt или моей некомпетентности, вместо dragEvent() ивентом запускающим драг будет вот это чудо
void Preview::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QMimeData * mimeData = new QMimeData;
    QDrag * drag = new QDrag(event->widget()->parent());
    QPixmap pixmap(61, 61);
    pixmap.fill(Qt::white);
    QPainter *painter = new QPainter(&pixmap);
    painterList.at(currentPainter)(painter, 0); // Вызываем функцию отрисовки объекта при драге
    drag->setPixmap(pixmap);

    mimeData->setText(QString::number(currentPainter));
    drag->setMimeData(mimeData);
    drag->exec();

    //АХТУНГ!!! КОСТЫЛИ!!! На месте текущего объекта создаем такой же потому что он забрал себе всю сценну и не хочет отдавать
    this->scene()->addItem(new Preview(this->x(), this->y(), currentPainter));
    delete this;
}

