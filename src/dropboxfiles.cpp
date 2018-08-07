#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "endpoints.h"
#include "dropboxfiles.h"


namespace Dropbox {

DropboxFiles::DropboxFiles(QString token, QObject *parent)
    : DropboxAuth(token, parent)
{}

DropboxFiles::DropboxFiles(QString token, QString key, QString secret,
                           QObject *parent)
    : DropboxAuth (token, key, secret, parent)
{}


QString DropboxFiles::getPreview(QString filepath)
{
    request()->setUrl(Files::MetaInfo::GET_PREVIEW);
    request()->setRawHeader(QByteArray("Authorization"),
                            QString("Bearer " + getApiToken()).toUtf8());

    QString data = "{\"path\": \"" + filepath + "\"}";
    request()->setRawHeader(QByteArray("Dropbox-API-Arg"), data.toUtf8());

    manager()->post(*(request()), QByteArray());
}

QString DropboxFiles::getMetadata(QString filepath)
{
    request()->setUrl(Files::MetaInfo::GET_METADATA);
    request()->setRawHeader(QByteArray("Authorization"),
                            QString("Bearer " + getApiToken()).toUtf8());

    QString data = "{\"path\": \"" + filepath + "\"}";
    manager()->post(*(request()), data.toUtf8());
}

}
