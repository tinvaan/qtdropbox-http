#ifndef _DROPBOX_API_ENDPOINTS_H_
#define _DROPBOX_API_ENDPOINTS_H_

#include <QUrl>
#include <QString>


namespace Dropbox {
struct Endpoint
{
    static const QString DROPBOX_V2_ENDPOINT;

    static QUrl getHttpUrl(const QString );
    static QString getHttpUrlString(const QString );
};

struct AppAuth
{
    static const QString DROPBOX_APP_AUTH_ENDPOINT;
    static const QString APP_AUTHENTICATION;

    static QUrl getAppAuthUrl();
    static QString getAppAuthUrlString();
};

struct Auth : public Dropbox::Endpoint
{
    static const QString USER_AUTHENTICATION;
    static const QString TEAM_AUTHENTICATION;
    static const QString TOKEN_FROM_OAUTH1;
    static const QString TOKEN_REVOKE;
};


namespace Folders {
struct Folder : public Dropbox::Endpoint
{
    static const QString FOLDER_CREATE;
    static const QString FOLDER_CREATE_BATCH;
    static const QString FOLDER_CREATE_BATCH_CHECK;
    static const QString LIST_FOLDER;
    static const QString LIST_FOLDER_CONTINUE;
    static const QString LIST_FOLDER_LATEST_CURSOR;
    static const QString LIST_FOLDER_LONGPOLL;
    static const QString SEARCH_FOLDER;
};
}


namespace Files {
struct Properties : public Dropbox::Endpoint
{
    static const QString PROPERTY_ADD;
    static const QString PROPERTY_OVERWRITE;
    static const QString PROPERTY_REMOVE;
    static const QString PROPERTY_SEARCH;
    static const QString PROPERTY_SEARCH_CONTINUE;
    static const QString PROPERTY_UPDATE;
};

struct Templates : public Properties
{
    static const QString ADD_FOR_USER;
    static const QString GET_FOR_USER;
    static const QString LIST_FOR_USER;
    static const QString REMOVE_FOR_USER;
    static const QString UPDATE_FOR_USER;
};

struct Requests : public Dropbox::Endpoint
{
    static const QString CREATE;
    static const QString GET;
    static const QString LIST;
    static const QString UPDATE;
};

struct File : public Dropbox::Endpoint
{
    static const QString COPY;
    static const QString COPY_BATCH;
    static const QString COPY_BATCH_CHECK;
    static const QString COPY_REFERENCE_GET;
    static const QString COPY_REFERENCE_SAVE;

    static const QString DELETE;
    static const QString DELETE_BATCH;
    static const QString DELETE_BATCH_CHECK;
    static const QString PERMANENTLY_DELETE;

    static const QString RESTORE_TO_REVISION;
    static const QString LIST_REVISIONS;

    static const QString MOVE;
    static const QString MOVE_BATCH;
    static const QString MOVE_BATCH_CHECK;

    static const QString SAVE_URL;
    static const QString SAVE_URL_CHECK_STATUS;

    static const QString SEARCH_FILE;
};

struct Upload : public File
{
    static const QString UPLOAD;
    static const QString UPLOAD_START;
    static const QString UPLOAD_SESSION_APPEND;
    static const QString UPLOAD_SESSION_FINISH;
    static const QString UPLOAD_SESSION_FINISH_BATCH;
    static const QString UPLOAD_SESSION_FINISH_BATCH_CHECK;
};

struct Download : public File
{
    static const QString DOWNLOAD;
    static const QString DOWNLOAD_ZIP;
};

struct MetaInfo : public File
{
    static const QString GET_METADATA;
    static const QString GET_PREVIEW;
    static const QString GET_TEMPORARY_LINK;
    static const QString GET_TEMPORARY_UPLOAD_LINK;
    static const QString GET_THUMBNAIL;
    static const QString GET_THUMBNAIL_BATCH;
};
}


}

#endif // _DROPBOX_API_ENDPOINTS_H_
