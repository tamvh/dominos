#include <QQuickImageProvider>
#include <qqrencode.h>
#include <QDebug>
#include <QUrl>
#include <QApplication>
#include <QScreen>

class ColorImageProvider : public QQuickImageProvider
{
public:
    ColorImageProvider(float ratio=4.0)
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
        _width = qMin(qApp->primaryScreen()->size().width()/ratio, qApp->primaryScreen()->size().height()/ratio);
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        //qDebug() << "newid" << id;
        QUrl copy(id);

        QString convertId = QUrl::fromPercentEncoding(id.toUtf8());

        QQREncode encoder;
        encoder.encode(convertId);

        return QPixmap::fromImage(encoder.toQImage(_width));
    }

private:
    int _width;
};
