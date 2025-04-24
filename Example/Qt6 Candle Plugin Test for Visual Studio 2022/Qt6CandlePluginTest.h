#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt6CandlePluginTest.h"
#include <QTreeWidget>

class Qt6CandlePluginTest : public QMainWindow
{
    Q_OBJECT

public:
    Qt6CandlePluginTest(QWidget *parent = nullptr);
    ~Qt6CandlePluginTest();

private:
    QTreeWidget* m_tree;
};
