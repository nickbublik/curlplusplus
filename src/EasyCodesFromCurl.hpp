#pragma once

#include <array>

#include <curl/curl.h>

#include "EasyCodes.hpp"

namespace CurlWrapper
{
namespace EasyCodesFromCurl
{

static constexpr std::array s_conv_table
{
    std::pair(CURLE_OK, EasyCode::OK ),
    std::pair(CURLE_UNSUPPORTED_PROTOCOL, EasyCode::UNSUPPORTED_PROTOCOL ),
    std::pair(CURLE_FAILED_INIT, EasyCode::FAILED_INIT ),
    std::pair(CURLE_URL_MALFORMAT, EasyCode::URL_MALFORMAT ),
    std::pair(CURLE_NOT_BUILT_IN, EasyCode::NOT_BUILT_IN ),
    std::pair(CURLE_COULDNT_RESOLVE_PROXY, EasyCode::COULDNT_RESOLVE_PROXY ),
    std::pair(CURLE_COULDNT_RESOLVE_HOST, EasyCode::COULDNT_RESOLVE_HOST ),
    std::pair(CURLE_COULDNT_CONNECT, EasyCode::COULDNT_CONNECT ),
    std::pair(CURLE_WEIRD_SERVER_REPLY, EasyCode::WEIRD_SERVER_REPLY ),
    std::pair(CURLE_REMOTE_ACCESS_DENIED, EasyCode::REMOTE_ACCESS_DENIED ),
    std::pair(CURLE_FTP_ACCEPT_FAILED, EasyCode::FTP_ACCEPT_FAILED ),
    std::pair(CURLE_FTP_WEIRD_PASS_REPLY, EasyCode::FTP_WEIRD_PASS_REPLY ),
    std::pair(CURLE_FTP_ACCEPT_TIMEOUT, EasyCode::FTP_ACCEPT_TIMEOUT ),
    std::pair(CURLE_FTP_WEIRD_PASV_REPLY, EasyCode::FTP_WEIRD_PASV_REPLY ),
    std::pair(CURLE_FTP_WEIRD_227_FORMAT, EasyCode::FTP_WEIRD_227_FORMAT ),
    std::pair(CURLE_FTP_CANT_GET_HOST, EasyCode::FTP_CANT_GET_HOST ),
    std::pair(CURLE_HTTP2, EasyCode::HTTP2 ),
    std::pair(CURLE_FTP_COULDNT_SET_TYPE, EasyCode::FTP_COULDNT_SET_TYPE ),
    std::pair(CURLE_PARTIAL_FILE, EasyCode::PARTIAL_FILE ),
    std::pair(CURLE_FTP_COULDNT_RETR_FILE, EasyCode::FTP_COULDNT_RETR_FILE ),
    std::pair(CURLE_OBSOLETE20, EasyCode::OBSOLETE20 ),
    std::pair(CURLE_QUOTE_ERROR, EasyCode::QUOTE_ERROR ),
    std::pair(CURLE_HTTP_RETURNED_ERROR, EasyCode::HTTP_RETURNED_ERROR ),
    std::pair(CURLE_WRITE_ERROR, EasyCode::WRITE_ERROR ),
    std::pair(CURLE_OBSOLETE24, EasyCode::OBSOLETE24 ),
    std::pair(CURLE_UPLOAD_FAILED, EasyCode::UPLOAD_FAILED ),
    std::pair(CURLE_READ_ERROR, EasyCode::READ_ERROR ),
    std::pair(CURLE_OUT_OF_MEMORY, EasyCode::OUT_OF_MEMORY ),
    std::pair(CURLE_OPERATION_TIMEDOUT, EasyCode::OPERATION_TIMEDOUT ),
    std::pair(CURLE_OBSOLETE29, EasyCode::OBSOLETE29 ),
    std::pair(CURLE_FTP_PORT_FAILED, EasyCode::FTP_PORT_FAILED ),
    std::pair(CURLE_FTP_COULDNT_USE_REST, EasyCode::FTP_COULDNT_USE_REST ),
    std::pair(CURLE_OBSOLETE32, EasyCode::OBSOLETE32 ),
    std::pair(CURLE_RANGE_ERROR, EasyCode::RANGE_ERROR ),
    std::pair(CURLE_HTTP_POST_ERROR, EasyCode::HTTP_POST_ERROR ),
    std::pair(CURLE_SSL_CONNECT_ERROR, EasyCode::SSL_CONNECT_ERROR ),
    std::pair(CURLE_BAD_DOWNLOAD_RESUME, EasyCode::BAD_DOWNLOAD_RESUME ),
    std::pair(CURLE_FILE_COULDNT_READ_FILE, EasyCode::FILE_COULDNT_READ_FILE ),
    std::pair(CURLE_LDAP_CANNOT_BIND, EasyCode::LDAP_CANNOT_BIND ),
    std::pair(CURLE_LDAP_SEARCH_FAILED, EasyCode::LDAP_SEARCH_FAILED ),
    std::pair(CURLE_OBSOLETE40, EasyCode::OBSOLETE40 ),
    std::pair(CURLE_FUNCTION_NOT_FOUND, EasyCode::FUNCTION_NOT_FOUND ),
    std::pair(CURLE_ABORTED_BY_CALLBACK, EasyCode::ABORTED_BY_CALLBACK ),
    std::pair(CURLE_BAD_FUNCTION_ARGUMENT, EasyCode::BAD_FUNCTION_ARGUMENT ),
    std::pair(CURLE_OBSOLETE44, EasyCode::OBSOLETE44 ),
    std::pair(CURLE_INTERFACE_FAILED, EasyCode::INTERFACE_FAILED ),
    std::pair(CURLE_OBSOLETE46, EasyCode::OBSOLETE46 ),
    std::pair(CURLE_TOO_MANY_REDIRECTS, EasyCode::TOO_MANY_REDIRECTS ),
    std::pair(CURLE_UNKNOWN_OPTION, EasyCode::UNKNOWN_OPTION ),
    std::pair(CURLE_SETOPT_OPTION_SYNTAX, EasyCode::SETOPT_OPTION_SYNTAX ),
    std::pair(CURLE_OBSOLETE50, EasyCode::OBSOLETE50 ),
    std::pair(CURLE_OBSOLETE51, EasyCode::OBSOLETE51 ),
    std::pair(CURLE_GOT_NOTHING, EasyCode::GOT_NOTHING ),
    std::pair(CURLE_SSL_ENGINE_NOTFOUND, EasyCode::SSL_ENGINE_NOTFOUND ),
    std::pair(CURLE_SSL_ENGINE_SETFAILED, EasyCode::SSL_ENGINE_SETFAILED ),
    std::pair(CURLE_SEND_ERROR, EasyCode::SEND_ERROR ),
    std::pair(CURLE_RECV_ERROR, EasyCode::RECV_ERROR ),
    std::pair(CURLE_OBSOLETE57, EasyCode::OBSOLETE57 ),
    std::pair(CURLE_SSL_CERTPROBLEM, EasyCode::SSL_CERTPROBLEM ),
    std::pair(CURLE_SSL_CIPHER, EasyCode::SSL_CIPHER ),
    std::pair(CURLE_PEER_FAILED_VERIFICATION, EasyCode::PEER_FAILED_VERIFICATION ),
    std::pair(CURLE_BAD_CONTENT_ENCODING, EasyCode::BAD_CONTENT_ENCODING ),
    std::pair(CURLE_OBSOLETE62, EasyCode::OBSOLETE62 ),
    std::pair(CURLE_FILESIZE_EXCEEDED, EasyCode::FILESIZE_EXCEEDED ),
    std::pair(CURLE_USE_SSL_FAILED, EasyCode::USE_SSL_FAILED ),
    std::pair(CURLE_SEND_FAIL_REWIND, EasyCode::SEND_FAIL_REWIND ),
    std::pair(CURLE_SSL_ENGINE_INITFAILED, EasyCode::SSL_ENGINE_INITFAILED ),
    std::pair(CURLE_LOGIN_DENIED, EasyCode::LOGIN_DENIED ),
    std::pair(CURLE_TFTP_NOTFOUND, EasyCode::TFTP_NOTFOUND ),
    std::pair(CURLE_TFTP_PERM, EasyCode::TFTP_PERM ),
    std::pair(CURLE_REMOTE_DISK_FULL, EasyCode::REMOTE_DISK_FULL ),
    std::pair(CURLE_TFTP_ILLEGAL, EasyCode::TFTP_ILLEGAL ),
    std::pair(CURLE_TFTP_UNKNOWNID, EasyCode::TFTP_UNKNOWNID ),
    std::pair(CURLE_REMOTE_FILE_EXISTS, EasyCode::REMOTE_FILE_EXISTS ),
    std::pair(CURLE_TFTP_NOSUCHUSER, EasyCode::TFTP_NOSUCHUSER ),
    std::pair(CURLE_OBSOLETE75, EasyCode::OBSOLETE75 ),
    std::pair(CURLE_OBSOLETE76, EasyCode::OBSOLETE76 ),
    std::pair(CURLE_SSL_CACERT_BADFILE, EasyCode::SSL_CACERT_BADFILE ),
    std::pair(CURLE_REMOTE_FILE_NOT_FOUND, EasyCode::REMOTE_FILE_NOT_FOUND ),
    std::pair(CURLE_SSH, EasyCode::SSH ),
    std::pair(CURLE_SSL_SHUTDOWN_FAILED, EasyCode::SSL_SHUTDOWN_FAILED ),
    std::pair(CURLE_AGAIN, EasyCode::AGAIN ),
    std::pair(CURLE_SSL_CRL_BADFILE, EasyCode::SSL_CRL_BADFILE ),
    std::pair(CURLE_SSL_ISSUER_ERROR, EasyCode::SSL_ISSUER_ERROR ),
    std::pair(CURLE_FTP_PRET_FAILED, EasyCode::FTP_PRET_FAILED ),
    std::pair(CURLE_RTSP_CSEQ_ERROR, EasyCode::RTSP_CSEQ_ERROR ),
    std::pair(CURLE_RTSP_SESSION_ERROR, EasyCode::RTSP_SESSION_ERROR ),
    std::pair(CURLE_FTP_BAD_FILE_LIST, EasyCode::FTP_BAD_FILE_LIST ),
    std::pair(CURLE_CHUNK_FAILED, EasyCode::CHUNK_FAILED ),
    std::pair(CURLE_NO_CONNECTION_AVAILABLE, EasyCode::NO_CONNECTION_AVAILABLE ),
    std::pair(CURLE_SSL_PINNEDPUBKEYNOTMATCH, EasyCode::SSL_PINNEDPUBKEYNOTMATCH ),
    std::pair(CURLE_SSL_INVALIDCERTSTATUS, EasyCode::SSL_INVALIDCERTSTATUS ),
    std::pair(CURLE_HTTP2_STREAM, EasyCode::HTTP2_STREAM ),
    std::pair(CURLE_RECURSIVE_API_CALL, EasyCode::RECURSIVE_API_CALL ),
    std::pair(CURLE_AUTH_ERROR, EasyCode::AUTH_ERROR ),
    std::pair(CURLE_HTTP3, EasyCode::HTTP3 ),
    std::pair(CURLE_QUIC_CONNECT_ERROR, EasyCode::QUIC_CONNECT_ERROR ),
    std::pair(CURLE_PROXY, EasyCode::PROXY ),
    std::pair(CURLE_SSL_CLIENTCERT, EasyCode::SSL_CLIENTCERT ),
    std::pair(CURLE_UNRECOVERABLE_POLL, EasyCode::UNRECOVERABLE_POLL ),
    std::pair(CURLE_TOO_LARGE, EasyCode::TOO_LARGE ),
    std::pair(CURLE_ECH_REQUIRED, EasyCode::ECH_REQUIRED ),
    std::pair(CURL_LAST, EasyCode::LAST )
};

} // namespace EasyCodesFromCurl

constexpr EasyCode convertEasyCodeFromCurl(const CURLcode src) 
{
    for (auto pair : EasyCodesFromCurl::s_conv_table)
    {
        if (std::get<0>(pair) == src)
        {
            return std::get<1>(pair);
        }
    }

    return EasyCode::LAST;
}

} // namespace CurlWrapper
