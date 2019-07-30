#pragma once
#include <qpushbutton.h>
class CustomPushButton :
    public QPushButton
{
public:
    explicit CustomPushButton(QWidget *parent = NULL);
    //ö�ٰ�ť��״̬ ��ͨ���������
    enum class BtnStatus { NORMAL, PRESSED, HOVER };
    //���ð�ť��״̬
    void setBtnBackground(const QString& path);
    virtual ~CustomPushButton();

private:
    //�������캯��
    CustomPushButton(const CustomPushButton&obj);

protected:
    //���庯������
    void paintEvent(QPaintEvent *event);
    //��갴���¼�����
    void mousePressEvent(QMouseEvent *event); 
    //����ͷ��¼�����
    void mouseReleaseEvent(QMouseEvent *event);
    //�����¼�
    void enterEvent(QEvent *event);
    //�뿪�¼�
    void leaveEvent(QEvent *event);

private:
    //��ť�ĵ�ǰ״̬
    BtnStatus m_status;
    //�Ƿ񱻵��
    bool isPressed;
    //ͼƬ��·��
    QString m_imagePath;

};

