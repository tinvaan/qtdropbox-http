#include <QDebug>
#include <QVariant>
#include <QByteArray>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "dropboxbase.h"


DropboxBase::DropboxBase(QObject *parent)
    : QObject(parent),
      m_request(new QNetworkRequest()), m_manager(new QNetworkAccessManager())
{
    m_request->setHeader(QNetworkRequest::ContentTypeHeader,
                         "application/json");
}

DropboxBase::~DropboxBase()
{
    delete m_request;
    delete m_manager;
}

QNetworkRequest* DropboxBase::request() const
{
    return m_request;
}

QNetworkAccessManager* DropboxBase::manager() const
{
    return m_manager;
}

void DropboxBase::setRequest(QNetworkRequest *request)
{
    m_request = request;
}

void DropboxBase::setManager(QNetworkAccessManager *manager)
{
    m_manager = manager;
}

void DropboxBase::synced(QNetworkReply *reply)
{
    QVariant header = reply->header(QNetworkRequest::ContentTypeHeader);
    QByteArray data = reply->readAll();

    qDebug() << "Header   : " << header.toString();
    qDebug() << "Error    : " << reply->error();
    qDebug() << "Response : " << QString::fromStdString(data.toStdString());
}
