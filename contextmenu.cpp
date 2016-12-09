#include "contextmenu.h"
#include <QDebug>

ContextMenu::ContextMenu(QWidget *parent) : QWidget(parent)
{


}

ContextMenu::ContextMenu(QVector<QString> *param,QVector<QString> *name)
{
    this->setWindowTitle("Context menu");
    saveLineEditName = new QString;
    labelVectorArgument = name;
    lineEditVectorArgument = param;
    lineEditName = new QLineEdit;
    vlayout = new QVBoxLayout;
    labelName = new QLabel("Name");
    hlayoutName = new QHBoxLayout;
    vlayoutLabel = new QVBoxLayout;
    vlayoutLineEdit = new QVBoxLayout;
    vlayoutLabelName = new QVBoxLayout;
    vlayoutLineName = new QVBoxLayout;
    pushButton = new QPushButton("OK");
    spacerItem = new QSpacerItem(200,1);
    connect(pushButton,SIGNAL(clicked(bool)),this,SLOT(read()));
    connect(pushButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void ContextMenu::create_field()
{
    this->setLayout(vlayout);
    vlayout->addLayout(hlayoutName);
    vlayoutLabelName->addWidget(labelName);
    vlayoutLineName->addWidget(lineEditName);
    hlayoutName->addLayout(vlayoutLabelName);
    hlayoutName->addLayout(vlayoutLineName);
    for(int i = 0; i < labelVectorArgument->size(); i++){
       hlayout = new QHBoxLayout;
       lineEdit = new QLineEdit;
       label = new QLabel(labelVectorArgument->at(i));
       lineEditVector.push_back(lineEdit);               //спросить у дегана
       vlayout->addLayout(hlayout);
       vlayoutLabel->addWidget(label);
       vlayoutLineEdit->addWidget(lineEdit);
       hlayout->addLayout(vlayoutLabel);
       hlayout->addLayout(vlayoutLineEdit);
    }
       hlayout = new QHBoxLayout;
       vlayout->addLayout(hlayout);
       hlayout->addItem(spacerItem);
       hlayout->addWidget(pushButton);

}

void ContextMenu::read()
{
    for(int i = 0; i < lineEditVector.size(); i++){
        lineEditVectorArgument->push_back(lineEditVector.at(i)->text());
    }
    saveLineEditName->push_back(lineEditName->text());
}
