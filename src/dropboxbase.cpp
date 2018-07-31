#include <QDebug>
#include <QVariant>
#include <QByteArray>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "dropboxhttp.h"


DropboxBase::DropboxBase(QString key, QObject *parent)
    : QObject(parent), m_apiKey(key),
      m_request(new QNetworkRequest()), m_manager(new QNetworkAccessManager())
{
    QString authKey = "Bearer " + m_apiKey;
    m_request->setRawHeader(QByteArray("Authorization"), authKey.toUtf8());
    m_request->setHeader(QNetworkRequest::ContentTypeHeader,
                         "application/json");

    QObject::connect(m_manager, &QNetworkAccessManager::finished,
                     this, &DropboxBase::synced);
}

DropboxBase::~DropboxBase()
{
    delete m_request;
    delete m_manager;
}

QString DropboxBase::getApiKey() const
{
    return m_apiKey;
}

QString DropboxBase::getAuthToken(QString oauth1Token)
{
    return "TODO";
}

void DropboxBase::setApiKey(QString key)
{
    m_apiKey = key;
}

void DropboxBase::synced(QNetworkReply *reply)
{
    QVariant header = reply->header(QNetworkRequest::ContentTypeHeader);
    QByteArray data = reply->readAll();

    qDebug() << "Header   : " << header.toString();
    qDebug() << "Error    : " << reply->error();
    qDebug() << "Response : " << QString::fromStdString(data.toStdString());
}
