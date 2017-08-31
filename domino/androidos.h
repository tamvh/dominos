#ifndef ANDROIDOS_H
#define ANDROIDOS_H

#include <QObject>

#ifdef Q_OS_ANDROID
#include <QtAndroidExtras>
#include <QtAndroidExtras/QAndroidJniEnvironment>
#include <QtAndroidExtras/QtAndroidExtras>
#include <QAndroidJniObject>
#include "jni.h"
#endif

class Androidos
{
public:
    Androidos();
    virtual ~Androidos();

private:
    void    dim();
    void    wakeup();
    void    keepscreen(bool on);
    void    mobiledata(bool enable);

};

#endif // ANDROIDOS_H
