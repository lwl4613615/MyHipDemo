#include "stdafx.h"
#include "CustomPushButton.h"


CustomPushButton::CustomPushButton(QWidget *parent /*= NULL*/):QPushButton(parent)
{

}

void CustomPushButton::paintEvent(QPaintEvent *event)
{
    //初始化画布
    QPainter painter(this);
    //图片路径
    QString pixmapPath;
    switch (m_status)//根据不同的状态绘制不同的背景图片
    {
    case CustomPushButton::BtnStatus::NORMAL:
        pixmapPath = m_imagePath;
        break;
    case CustomPushButton::BtnStatus::PRESSED:
        pixmapPath = m_imagePath + "_hover";
        break;
    case CustomPushButton::BtnStatus::HOVER:
        pixmapPath = m_imagePath + "_pressed";
        break;
    default:
        pixmapPath = m_imagePath;
        break;
    }
    //绘制按钮的背景
    painter.drawPixmap(rect(), QPixmap(pixmapPath));
}

void CustomPushButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    {
        isPressed = true;
        m_status = CustomPushButton::BtnStatus::PRESSED;
        update();
    }
}

void CustomPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton&&isPressed)
    {
        isPressed = false;
        m_status = CustomPushButton::BtnStatus::NORMAL;
        emit clicked();
    }
}

void CustomPushButton::enterEvent(QEvent *event)
{
    isPressed = false;
    m_status = CustomPushButton::BtnStatus::HOVER;
}


void CustomPushButton::leaveEvent(QEvent *event)
{
    isPressed = false;
    m_status = CustomPushButton::BtnStatus::NORMAL;
}

void CustomPushButton::setBtnBackground(const QString& path)
{
	m_imagePath = path;
	// resize the button to fit the background picture.
	setFixedSize(QPixmap(m_imagePath).size());
}

CustomPushButton::~CustomPushButton()
{
}
