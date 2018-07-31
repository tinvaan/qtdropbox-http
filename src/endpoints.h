#ifndef _DROPBOX_API_ENDPOINTS_H_
#define _DROPBOX_API_ENDPOINTS_H_

#include <QUrl>
#include <QString>


namespace Dropbox {
struct Endpoint
{
    const QString DROPBOX_V2_ENDPOINT = "https://api.dropboxapi.com/2/";

    QUrl getHttpUrl(const QString ) const;
    QString getHttpUrlString(const QString ) const;
};

struct Auth : public Dropbox::Endpoint
{
    const QString TOKEN_FROM_OAUTH1 = "auth/token/from_oauth1";
    const QString TOKEN_REVOKE = "auth/token/revoke";
};

namespace Folders {
struct Folder : public Dropbox::Endpoint
{
    const QString FOLDER_CREATE = "files/create_folder_v2";
    const QString FOLDER_CREATE_BATCH = "files/create_folder_batch";
    const QString FOLDER_CREATE_BATCH_CHECK = "files/create_folder_batch/check";
    const QString LIST_FOLDER = "files/list_folder";
    const QString LIST_FOLDER_CONTINUE = "files/list_folder/continue";
    const QString LIST_FOLDER_LATEST_CURSOR = "files/list_folder/get_latest_cursor";
    const QString LIST_FOLDER_LONGPOLL = "files/list_folder/longpoll";
    const QString SEARCH_FOLDER = "files/search";
};
}

namespace Files {
struct Properties : public Dropbox::Endpoint
{
    const QString PROPERTY_ADD = "file_properties/properties/add";
    const QString PROPERTY_OVERWRITE = "file_properties/properties/overwrite";
    const QString PROPERTY_REMOVE = "file_properties/properties/remove";
    const QString PROPERTY_SEARCH = "file_properties/properties/search";
    const QString PROPERTY_SEARCH_CONTINUE = "file_properties/properties/search/continue";
    const QString PROPERTY_UPDATE = "file_properties/properties/update";
};

struct Templates : public Properties
{
    const QString ADD_FOR_USER = "file_properties/templates/add_for_user";
    const QString GET_FOR_USER = "file_properties/templates/get_for_user";
    const QString LIST_FOR_USER = "file_properties/templates/list_for_user";
    const QString REMOVE_FOR_USER = "file_properties/templates/remove_for_user";
    const QString UPDATE_FOR_USER = "file_properties/templates/update_for_user";
};

struct Requests : public Dropbox::Endpoint
{
    const QString CREATE = "file_requests/create";
    const QString GET = "file_requests/get";
    const QString LIST = "file_requests/list";
    const QString UPDATE = "file_requests/update";
};

struct File : public Dropbox::Endpoint
{
    const QString COPY = "files/copy_v2";
    const QString COPY_BATCH = "files/copy_batch";
    const QString COPY_BATCH_CHECK = "files/copy_batch/check";
    const QString COPY_REFERENCE_GET = "files/copy_reference/get";
    const QString COPY_REFERENCE_SAVE = "files/copy_reference/save";

    const QString DELETE = "files/delete_v2";
    const QString DELETE_BATCH = "files/delete_batch";
    const QString DELETE_BATCH_CHECK = "files/delete_batch/check";
    const QString PERMANENTLY_DELETE = "files/permanently_delete";

    const QString RESTORE_TO_REVISION = "files/restore";
    const QString LIST_REVISIONS = "files/list_revisions";

    const QString MOVE = "files/move_v2";
    const QString MOVE_BATCH = "files/move_batch";
    const QString MOVE_BATCH_CHECK = "files/move_batch/check";

    const QString SAVE_URL = "files/save_url";
    const QString SAVE_URL_CHECK_STATUS = "files/save_url/check_job_status";

    const QString SEARCH_FILE = "files/search";
};

struct Upload : public File
{
    const QString UPLOAD = "files/upload";
    const QString UPLOAD_START = "files/upload_session/start";
    const QString UPLOAD_SESSION_APPEND = "files/upload_session/append_v2";
    const QString UPLOAD_SESSION_FINISH = "files/upload_session/finish";
    const QString UPLOAD_SESSION_FINISH_BATCH = "files/upload_session/finish_batch";
    const QString UPLOAD_SESSION_FINISH_BATCH_CHECK = "files/upload_session/finish_batch/check";
};

struct Download : public File
{
    const QString DOWNLOAD = "files/download";
    const QString DOWNLOAD_ZIP = "files/download_zip";
};

struct MetaInfo : public File
{
    const QString GET_METADATA = "files/get_metadata";
    const QString GET_PREVIEW = "files/get_preview";
    const QString GET_TEMPORARY_LINK = "files/get_temporary_link";
    const QString GET_TEMPORARY_UPLOAD_LINK = "files/get_temporary_upload_link";
    const QString GET_THUMBNAIL = "files/get_thumbnail";
    const QString GET_THUMBNAIL_BATCH = "files/get_thumbnail_batch";
};
}

QUrl Endpoint::getHttpUrl(const QString url) const
{
    return QUrl(DROPBOX_V2_ENDPOINT + url);
}

QString Endpoint::getHttpUrlString(const QString url) const
{
    return QString(DROPBOX_V2_ENDPOINT + url);
}
}

#endif // _DROPBOX_API_ENDPOINTS_H_
