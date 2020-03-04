
#include "content.h"
Content::Content(QWidget *parent) : QFrame(parent)
{
    stack = new QStackedWidget(this);                           //创建一个堆栈窗口对象
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);       //窗口的显示风格
    //插入页面
    guide = new QGuide();
    spy = new QSpy();
    plugin = new QPlugin();
    stack->addWidget(guide);
    stack->addWidget(spy);
    stack->addWidget(plugin);
    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(2);
    mainLayout->addWidget(stack, 0, 0);
}
