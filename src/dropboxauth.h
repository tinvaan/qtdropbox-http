#ifndef _DROPBOX_AUTH_H_
#define _DROPBOX_AUTH_H_

#include "dropboxbase.h"


namespace Dropbox {

class DropboxAuth : public DropboxBase
{
    Q_OBJECT

public:
    explicit DropboxAuth(QString, QObject *parent=Q_NULLPTR);
    explicit DropboxAuth(QString, QString, QObject *parent=Q_NULLPTR);

    void setAppKey(QString );
    void setApiToken(QString );
    void setAppSecret(QString );

    QString getAppKey() const;
    QString getApiToken() const;
    QString getAppSecret() const;

    QString appAuthentication();
    QString userAuthentication();
    QString teamAuthentication();

private:
    QString m_apiToken;
    QString m_appKey, m_appSecret;
};

}

#endif // _DROPBOX_AUTH_H_
