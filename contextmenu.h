#ifndef BDABDU_H
#define BDABDU_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QLabel>
#include <QTextEdit>
#include <QLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QList>
#include <QVector>


class ContextMenu : public QWidget
{
    Q_OBJECT
public:
    explicit ContextMenu(QWidget *parent = 0);
    ContextMenu (QVector<QString> *param,QVector<QString> *name);
    QString *saveLineEditName;

signals:

public slots:
    void create_field();
    void read();
    void setName(QString *);
private:
    QVector<QLineEdit*> lineEditVector;
    QSpacerItem *spacerItem;
    QPushButton *pushButton;
    QHBoxLayout *hlayout;
    QHBoxLayout *hlayoutName;
    QVBoxLayout *vlayout;
    QVBoxLayout *vlayoutLabel;
    QVBoxLayout *vlayoutLineEdit;
    QVBoxLayout *vlayoutLabelName;
    QVBoxLayout *vlayoutLineName;
    QLineEdit *lineEditName;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *labelName;
    QVector<QString> *lineEditVectorArgument;
    QVector<QString> *labelVectorArgument;
};

#endif // CONTEXTMENU_H
