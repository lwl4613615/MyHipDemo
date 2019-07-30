#pragma once
#include <qpushbutton.h>
class CustomPushButton :
    public QPushButton
{
public:
    explicit CustomPushButton(QWidget *parent = NULL);
    //枚举按钮的状态 普通，被点击，
    enum class BtnStatus { NORMAL, PRESSED, HOVER };
    //设置按钮的状态
    void setBtnBackground(const QString& path);
    virtual ~CustomPushButton();

private:
    //拷贝构造函数
    CustomPushButton(const CustomPushButton&obj);

protected:
    //画板函数重载
    void paintEvent(QPaintEvent *event);
    //鼠标按下事件函数
    void mousePressEvent(QMouseEvent *event); 
    //鼠标释放事件函数
    void mouseReleaseEvent(QMouseEvent *event);
    //进入事件
    void enterEvent(QEvent *event);
    //离开事件
    void leaveEvent(QEvent *event);

private:
    //按钮的当前状态
    BtnStatus m_status;
    //是否被点击
    bool isPressed;
    //图片的路径
    QString m_imagePath;

};

