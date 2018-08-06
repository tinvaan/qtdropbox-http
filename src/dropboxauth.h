#ifndef _DROPBOX_AUTH_H_
#define _DROPBOX_AUTH_H_

#include "dropboxrequest.h"


namespace Dropbox {

class DropboxAuth : public DropboxRequest
{
    Q_OBJECT

public:
    explicit DropboxAuth(QString, QObject *parent=Q_NULLPTR);
    explicit DropboxAuth(QString, QString, QObject *parent=Q_NULLPTR);

    void appAuthentication();
    void userAuthentication();
    void teamAuthentication();

    void setAppKey(QString );
    void setApiToken(QString );
    void setAppSecret(QString );

    QString getAppKey() const;
    QString getApiToken() const;
    QString getAppSecret() const;

private:
    QString m_apiToken;
    QString m_appKey, m_appSecret;
};

}

#endif // _DROPBOX_AUTH_H_
