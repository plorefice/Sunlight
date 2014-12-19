#ifndef APPICONPROVIDER_H
#define APPICONPROVIDER_H

#include <QPixmap>
#include <QQuickImageProvider>

class AppIconProvider : public QQuickImageProvider
{
private:
    QPixmap m_currIcon;

public:
    AppIconProvider();
    ~AppIconProvider();

    void setIcon(const QPixmap &pm);

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
};

#endif // APPICONPROVIDER_H
