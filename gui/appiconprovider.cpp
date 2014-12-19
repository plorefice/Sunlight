#include "appiconprovider.h"

#include <QDebug>

AppIconProvider::AppIconProvider() :
    QQuickImageProvider(QQuickImageProvider::Pixmap)
{
    /* Initialize with transparent icon */
    m_currIcon = QPixmap(32, 32);
    m_currIcon.fill(Qt::transparent);
}

AppIconProvider::~AppIconProvider()
{

}

void AppIconProvider::setIcon(const QPixmap &pm)
{
    m_currIcon = pm;
}

QPixmap AppIconProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id);

    if (size)
        *size = QSize(m_currIcon.width(), m_currIcon.height());

    if (requestedSize.width() > 0 && requestedSize.height() > 0)
        return m_currIcon.scaled(requestedSize, Qt::KeepAspectRatio);
    else
        return m_currIcon;
}
