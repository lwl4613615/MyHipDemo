#include "stdafx.h"
#include "myhips.h"

MyHips::MyHips(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	
	this->setWindowFlags(Qt::FramelessWindowHint);
	//水平布局
	m_topLayout = new  QHBoxLayout(this);
	m_windowTitle = new QLabel("LWL's hips 1.0 demo", this);
	m_windowTitle->setStyleSheet("color:red");
	QFont font = const_cast<QFont&>(m_windowTitle->font());
	font.setBold(true);
	font.setPointSize(10);
	m_windowTitle->setFont(font);
	m_windowTitle->setObjectName("WhiteLabel");

	m_settings = new CustomPushButton(this);     // 设置按钮
	m_minBtn = new CustomPushButton(this);       // 最小化按钮
	m_closeBtn = new CustomPushButton(this);     // 关闭按钮
	m_settings->setBtnBackground(QStringLiteral(":/SysButtons/menu"));   // 设置按钮的背景图片，下同
	m_settings->setToolTip(QStringLiteral("Settings"));                  // 设置文本提示，下同
	m_minBtn->setBtnBackground(QStringLiteral(":/SysButtons/min"));
	m_minBtn->setToolTip(QStringLiteral("Minimize"));
	m_closeBtn->setBtnBackground(QStringLiteral(":/SysButtons/close"));
	m_closeBtn->setToolTip(QStringLiteral("Close"));
	m_closeBtn->setWindowFlag(Qt::WindowCloseButtonHint);

	m_topLayout->addWidget(m_windowTitle, 0, Qt::AlignVCenter|Qt::AlignTop);   // 文本是垂直居中的
	m_topLayout->addStretch();
	m_topLayout->addWidget(m_settings, 0, Qt::AlignTop);
	m_topLayout->addWidget(m_minBtn, 0, Qt::AlignTop);
	m_topLayout->addWidget(m_closeBtn, 0, Qt::AlignTop);
	m_topLayout->setSpacing(0);   // 组件之间没有空隙，这样按钮与按钮之间看起来就没有间隔了
	m_topLayout->setContentsMargins(10, 0, 10, 0);  // 这里设置的是整个layout与其他layout之间的margin，而spacing是layout内部组件之间的间距
	//中下部分
	m_MainLayout = new QVBoxLayout(this);
	setFixedSize(1024, 768);
	
	//头部布局水平
	//m_MainLayout->addLayout(m_topLayout);
	//中部的分割类
	m_MainLayout->addLayout(m_topLayout);
	
	
	m_MainLayout->setSpacing(0);
	m_MainLayout->setContentsMargins(5, 5, 5, 5);
	setLayout(m_MainLayout);
	

}

void MyHips::paintEvent(QPaintEvent* event)
{
	
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(0, 0, width(), height()-25, QPixmap(":/Background/main1"));  // 设置主窗体的背景图片
}

void MyHips::mousePressEvent(QMouseEvent* e)
{

	last = e->globalPos();
}

void MyHips::mouseMoveEvent(QMouseEvent* e)
{
	
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	last = e->globalPos();
	move(x() + dx, y() + dy);

}

void MyHips::mouseReleaseEvent(QMouseEvent* e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	move(x() + dx, y() + dy);
}
