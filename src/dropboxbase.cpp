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

// TODO/FIXME:
//    if (m_request->hasRawHeader(QByteArray("Authorization"))) {
//        QString authKey = "Bearer " + m_apiKey;
//        m_request->setRawHeader(QByteArray("Authorization"),
//                                authKey.toUtf8());
//    }

//    QObject::connect(m_manager, &QNetworkAccessManager::finished,
//                     this, &DropboxBase::synced);
}

DropboxBase::~DropboxBase()
{
    delete m_request;
    delete m_manager;
}

void DropboxBase::synced(QNetworkReply *reply)
{
    QVariant header = reply->header(QNetworkRequest::ContentTypeHeader);
    QByteArray data = reply->readAll();

    qDebug() << "Header   : " << header.toString();
    qDebug() << "Error    : " << reply->error();
    qDebug() << "Response : " << QString::fromStdString(data.toStdString());
}
