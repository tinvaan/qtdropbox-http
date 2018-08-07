#include <QDebug>
#include <QVariant>
#include <QByteArray>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "dropboxrequest.h"


namespace Dropbox {

DropboxRequest::DropboxRequest(QObject *parent)
    : QObject(parent),
      m_request(new QNetworkRequest()), m_manager(new QNetworkAccessManager())
{
    m_request->setHeader(QNetworkRequest::ContentTypeHeader,
                         "application/json");

    connect(m_manager, &QNetworkAccessManager::finished,
            this, &DropboxRequest::synced);
}

DropboxRequest::~DropboxRequest()
{
    delete m_request;
    delete m_manager;
}

QNetworkRequest* DropboxRequest::request() const
{
    return m_request;
}

QNetworkAccessManager* DropboxRequest::manager() const
{
    return m_manager;
}

void DropboxRequest::setRequest(QNetworkRequest *request)
{
    m_request = request;
}

void DropboxRequest::setManager(QNetworkAccessManager *manager)
{
    m_manager = manager;
}

void DropboxRequest::synced(QNetworkReply *reply)
{
    QVariant header = reply->header(QNetworkRequest::ContentTypeHeader);
    QByteArray data = reply->readAll();

    qDebug() << "Header   : " << header.toString();
    qDebug() << "Error    : " << reply->error();
    qDebug() << "Response : " << QString::fromStdString(data.toStdString());
}

}
