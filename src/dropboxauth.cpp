#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "endpoints.h"
#include "dropboxauth.h"


namespace Dropbox {

DropboxAuth::DropboxAuth(QString token, QObject *parent)
    : DropboxRequest(parent), m_apiToken(token)
{}

DropboxAuth::DropboxAuth(QString token, QString key, QString secret,
                         QObject *parent)
    : DropboxRequest(parent), m_apiToken(token),
      m_appKey(key), m_appSecret(secret)
{}

void DropboxAuth::appAuthentication()
{
    if (m_appKey == QString() || m_appSecret == QString())
        return;
    else {
        // TODO
    }
}

void DropboxAuth::userAuthentication()
{
    request()->setUrl(Auth::getHttpUrl(Auth::USER_AUTHENTICATION));
    request()->setRawHeader(QByteArray("Authorization"),
                            QString("Bearer " + getApiToken()).toUtf8());

    manager()->post(*(request()), QByteArray());
}

void DropboxAuth::teamAuthentication()
{
    request()->setUrl(Auth::getHttpUrl(Auth::TEAM_AUTHENTICATION));
    request()->setRawHeader(QByteArray("Authorization"),
                            QString("Bearer " + getApiToken()).toUtf8());

    manager()->post(*(request()), QByteArray());
}

void DropboxAuth::setAppKey(QString key)
{
    m_appKey = key;
}

void DropboxAuth::setApiToken(QString token)
{
    m_apiToken = token;
}

void DropboxAuth::setAppSecret(QString secret)
{
    m_appSecret = secret;
}

QString DropboxAuth::getAppKey() const
{
    return m_appKey;
}

QString DropboxAuth::getApiToken() const
{
    return m_apiToken;
}

QString DropboxAuth::getAppSecret() const
{
    return m_appSecret;
}

}
