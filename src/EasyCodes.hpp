#pragma once

namespace CurlWrapper
{

enum class EasyCode
{
    OK = 0,
    UNSUPPORTED_PROTOCOL,
    FAILED_INIT,
    URL_MALFORMAT,
    NOT_BUILT_IN,
    COULDNT_RESOLVE_PROXY,
    COULDNT_RESOLVE_HOST,
    COULDNT_CONNECT,
    WEIRD_SERVER_REPLY,
    REMOTE_ACCESS_DENIED,
    FTP_ACCEPT_FAILED,
    FTP_WEIRD_PASS_REPLY,
    FTP_ACCEPT_TIMEOUT,
    FTP_WEIRD_PASV_REPLY,
    FTP_WEIRD_227_FORMAT,
    FTP_CANT_GET_HOST,
    HTTP2,
    FTP_COULDNT_SET_TYPE,
    PARTIAL_FILE,
    FTP_COULDNT_RETR_FILE,
    OBSOLETE20,
    QUOTE_ERROR,
    HTTP_RETURNED_ERROR,
    WRITE_ERROR,
    OBSOLETE24,
    UPLOAD_FAILED,
    READ_ERROR,
    OUT_OF_MEMORY,
    OPERATION_TIMEDOUT,
    OBSOLETE29,
    FTP_PORT_FAILED,
    FTP_COULDNT_USE_REST,
    OBSOLETE32,
    RANGE_ERROR,
    HTTP_POST_ERROR,
    SSL_CONNECT_ERROR,
    BAD_DOWNLOAD_RESUME,
    FILE_COULDNT_READ_FILE,
    LDAP_CANNOT_BIND,
    LDAP_SEARCH_FAILED,
    OBSOLETE40,
    FUNCTION_NOT_FOUND,
    ABORTED_BY_CALLBACK,
    BAD_FUNCTION_ARGUMENT,
    OBSOLETE44,
    INTERFACE_FAILED,
    OBSOLETE46,
    TOO_MANY_REDIRECTS,
    UNKNOWN_OPTION,
    SETOPT_OPTION_SYNTAX,
    OBSOLETE50,
    OBSOLETE51,
    GOT_NOTHING,
    SSL_ENGINE_NOTFOUND,
    SSL_ENGINE_SETFAILED,
    SEND_ERROR,
    RECV_ERROR,
    OBSOLETE57,
    SSL_CERTPROBLEM,
    SSL_CIPHER,
    PEER_FAILED_VERIFICATION,
    BAD_CONTENT_ENCODING,
    OBSOLETE62,
    FILESIZE_EXCEEDED,
    USE_SSL_FAILED,
    SEND_FAIL_REWIND,
    SSL_ENGINE_INITFAILED,
    LOGIN_DENIED,
    TFTP_NOTFOUND,
    TFTP_PERM,
    REMOTE_DISK_FULL,
    TFTP_ILLEGAL,
    TFTP_UNKNOWNID,
    REMOTE_FILE_EXISTS,
    TFTP_NOSUCHUSER,
    OBSOLETE75,
    OBSOLETE76,
    SSL_CACERT_BADFILE,
    REMOTE_FILE_NOT_FOUND,
    SSH,
    SSL_SHUTDOWN_FAILED,
    AGAIN,
    SSL_CRL_BADFILE,
    SSL_ISSUER_ERROR,
    FTP_PRET_FAILED,
    RTSP_CSEQ_ERROR,
    RTSP_SESSION_ERROR,
    FTP_BAD_FILE_LIST,
    CHUNK_FAILED,
    NO_CONNECTION_AVAILABLE,
    SSL_PINNEDPUBKEYNOTMATCH,
    SSL_INVALIDCERTSTATUS,
    HTTP2_STREAM,
    RECURSIVE_API_CALL,
    AUTH_ERROR,
    HTTP3,
    QUIC_CONNECT_ERROR,
    PROXY,
    SSL_CLIENTCERT,
    UNRECOVERABLE_POLL,
    TOO_LARGE,
    ECH_REQUIRED,
    LAST
};

} // namespace CurlWrapper
