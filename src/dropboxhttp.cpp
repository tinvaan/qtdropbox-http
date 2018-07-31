#include <QDebug>
#include <QVariant>
#include <QByteArray>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>


#include "dropboxhttp.h"


DropboxHttp::DropboxHttp(QUrl url, QString key, QObject *parent)
    : QObject(parent),
      m_url(url), m_apiKey(key),
      m_request(new QNetworkRequest(m_url)),
      m_manager(new QNetworkAccessManager())
{
    QString authKey = "Bearer " + m_apiKey;
    m_request->setRawHeader(QByteArray("Authorization"), authKey.toUtf8());
    m_request->setHeader(QNetworkRequest::ContentTypeHeader,
                         "application/json");

    QObject::connect(m_manager, &QNetworkAccessManager::finished,
                     this, &DropboxHttp::synced);
}

DropboxHttp::~DropboxHttp()
{
    delete m_request;
    delete m_manager;
}

void DropboxHttp::upload()
{}

void DropboxHttp::getFilePreview(QString filepath)
{}

void DropboxHttp::getFileMetadata(QString filepath)
{
    QString data = "{\"path\": \"" + filepath + "\"}";
    m_manager->post(*m_request, data.toUtf8());

}

QUrl DropboxHttp::getUrl() const
{
    return m_url;
}

QString DropboxHttp::getApiKey() const
{
    return m_apiKey;
}

void DropboxHttp::synced(QNetworkReply *reply)
{
    QVariant header = reply->header(QNetworkRequest::ContentTypeHeader);
    QByteArray data = reply->readAll();

    qDebug() << "Header   : " << header.toString();
    qDebug() << "Error    : " << reply->error();
    qDebug() << "Response : " << QString::fromStdString(data.toStdString());
}
