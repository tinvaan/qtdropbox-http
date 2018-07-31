#ifndef _DROPBOX_HTTP_H_
#define _DROPBOX_HTTP_H_


#include <QUrl>
#include <QString>
#include <QObject>


class QNetworkReply;
class QNetworkRequest;
class QNetworkAccessManager;

class DropboxHttp : public QObject
{
    Q_OBJECT

public:
    explicit DropboxHttp(QUrl, QString, QObject *parent=Q_NULLPTR);
    ~DropboxHttp();

    void upload();
    void getFilePreview(QString );
    void getFileMetadata(QString );

    QUrl getUrl() const;
    QString getApiKey() const;

public slots:
    void synced(QNetworkReply* );

private:
    QUrl m_url;
    QString m_apiKey;
    QNetworkRequest *m_request;
    QNetworkAccessManager *m_manager;
};

#endif // _DROPBOX_HTTP_H_
