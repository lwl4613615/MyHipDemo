#pragma once

#include <QtWidgets/QWidget>
#include "ui_myhips.h"
#include "CustomPushButton.h"
#include <QDateTime>
class MyHips : public QWidget
{
    Q_OBJECT

public:
    MyHips(QWidget *parent = Q_NULLPTR);

protected:
	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);

private:
    Ui::MyHipsClass ui;
	//top layout
	QHBoxLayout* m_topLayout = nullptr;
	//windows title 
	QLabel* m_windowTitle = nullptr;
	CustomPushButton* m_settings;
	CustomPushButton* m_minBtn;
	CustomPushButton* m_closeBtn;
	//窗体主要的垂直对齐
	QVBoxLayout* m_MainLayout = nullptr;
	QSplitter* splitter;
	QWidget* test;
	QPoint last;
	QStatusBar * statusBar;
};
