#pragma once

namespace edjx {

/// Error-handling enums and utilities.
namespace error {

    /**
     * @brief Enum describing return values of functions that
     * correspond to HTTP modules.
     */
    enum class HttpError {
        /// Operation was successful.
        Success = 0,
        /// An error occured in the SDK library.
        SystemError,
        /// An unknown error occured while performing the request.
        UnknownError,
        /// Invalid header name.
        HeaderInvalidName,
        /// Invalid header value.
        HeaderInvalidValue,
        /// Header name is too long.
        HeaderTooLargeName,
        /// Header value is too long.
        HeaderTooLargeValue,
        /// HTTP body exceeds prescribed limits.
        HTTPBodyTooLarge,
        /// Invalid URI.
        UriInvalid,
        /// URI is too long.
        UriTooLarge,
        /// An invalid HTTP method was provided.
        HTTPInvalidMethod,
        /// An invalid HTTP status code was provided.
        HTTPInvalidStatusCode,
        /// An invalid HTTP version was provided.
        HTTPInvalidVersion
    };

    /**
     * @brief Returns a string representation of HttpError
     * 
     * @param e Error value
     * @return String representation of the error value
     */
    inline std::string to_string(HttpError e) {
        switch (e) {
            case HttpError::Success:
                return "HTTP: success";
            case HttpError::UnknownError:
                return "HTTP: unknown error";
            case HttpError::SystemError:
                return "HTTP: error in SDK function";
            case HttpError::HeaderInvalidName:
                return "HTTP: invalid header name";
            case HttpError::HeaderInvalidValue:
                return "HTTP: invalid header value";
            case HttpError::HeaderTooLargeName:
                return "HTTP: header name length exceeds limit";
            case HttpError::HeaderTooLargeValue:
                return "HTTP: header value length exceeds limit";
            case HttpError::HTTPBodyTooLarge:
                return "HTTP: http body too large error";
            case HttpError::UriInvalid:
                return "HTTP: URI value invalid";
            case HttpError::UriTooLarge:
                return "HTTP: URI value exceeds limit";
            case HttpError::HTTPInvalidMethod:
                return "HTTP: invalid fetch HTTP method";
            case HttpError::HTTPInvalidStatusCode:
                return "HTTP: invalid response status code";
            case HttpError::HTTPInvalidVersion:
                return "HTTP: invalid HTTP version";
        }
    }

    /**
     * @brief Enum describing return values of functions that
     * correspond to kv modules.
     */
    enum class KVError {
        /// KV operation was successful
        Success = 0,
        /// An unknown error has ocurred while trying to perform a KV store operation.
        Unknown,
        /// The value associated with the key could not be found.
        NotFound,
        /// This application is not authorized to access this key.
        UnAuthorized
    };

    /**
     * @brief Returns a string representation of KVError
     * 
     * @param e Error value
     * @return String representation of the error value
     */
    inline std::string to_string(KVError e) {
        switch (e) {
            case KVError::Success:
                return "KV: success";
            case KVError::Unknown:
                return "KV: unknown";
            case KVError::NotFound:
                return "KV: key not found";
            case KVError::UnAuthorized:
                return "KV: unauthorized";
        }
    }

    /**
     * @brief Enum describing return values of functions that
     * correspond to storage modules.
     */
    enum class StorageError {
        /// Storage operation was successful.
        Success = 0,
        /// An error occured in the SDK library.
        SystemError,
        /// Content is required.
        EmptyContent,
        /// File name is required.
        MissingFileName,
        /// The bucket id is deleted.
        DeletedBucketID,
        /// Bucket ID is required.
        MissingBucketID,
        /// An internal error occured while performing the request.
        InternalError,
        /// The content or bucket wasn't found on the store.
        ContentNotFound,
        /// The credentials or policies entered are incorrect. Request could not be performed.
        UnAuthorized,
        /// Attributes are required.
        MissingAttributes,
        /// The required content does not exist or has been deleted.
        ContentDeleted,
        /// The attributes are invalid.
        InvalidAttributes
    };

    /**
     * @brief Returns a string representation of StorageError
     * 
     * @param e Error value
     * @return String representation of the error value
     */
    inline std::string to_string(StorageError e) {
        switch (e) {
            case StorageError::Success:
                return "Storage: success";
            case StorageError::SystemError:
                return "Storage: error occured in SDK library";
            case StorageError::EmptyContent:
                return "Storage: empty content";
            case StorageError::MissingFileName:
                return "Storage: missing query param 'file_name'";
            case StorageError::DeletedBucketID:
                return "Storage: bucket_id is deleted";
            case StorageError::MissingBucketID:
                return "Storage: missing query param 'bucket_id'";
            case StorageError::InternalError:
                return "Storage: internal error";
            case StorageError::ContentNotFound:
                return "Storage: bucket/content not found";
            case StorageError::UnAuthorized:
                return "Storage: unauthorized";
            case StorageError::MissingAttributes:
                return "Storage: missing attributes";
            case StorageError::ContentDeleted:
                return "Storage: content does not exist or was deleted";
            case StorageError::InvalidAttributes:
                return "Storage: invalid attributes";
        }
    }

}}