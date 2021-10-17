#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "error.hpp"

namespace edjx {

// APIs for interacting with the EDJX Object Store.
namespace storage {

    /**
     * @brief Response to the [`edjx::storage::get`] request.
     */
    struct StorageResponse {
        /// HTTP headers of the response
        std::map<std::string, std::string> headers;
        /// Body of the response
        std::vector<uint8_t> body;

        /**
         * @brief Constructs a response with no headers and an empty body.
         */
        inline StorageResponse() {}

        /**
         * @brief Constructs a response with headers and body set
         * to the provided values.
         * 
         * @param headers HTTP headers for the response
         * @param body Body for the response
         */
        inline StorageResponse(
            const std::map<std::string, std::string> & headers,
            const std::vector<uint8_t> & body
        ) : headers(headers),
            body(body) {}

        /**
         * @brief Returns the metadata associated with the storage object.
         * 
         * @return Response headers
         */
        const std::map<std::string, std::string> & get_headers() const;

        /**
         * @brief Returns the bytes of the storage object.
         * 
         * @return Response body
         */
        const std::vector<uint8_t> & get_body() const;
    };

    /**
     * @brief Represents the attributes associated with a stored file.
     */
    struct FileAttributes {
        /// Whether file properties are defined
        bool properties_present;
        /// File properties
        std::map<std::string, std::string> properties;
        /// Whether default version is present
        bool default_version_present;
        /// Default version
        std::string default_version;

        /**
         * @brief Construct an empty file attributes object.
         */
        inline FileAttributes() :
            properties_present(false),
            default_version_present(false) {}

        /**
         * @brief Construct a new File Attributes object.
         * 
         * @param properties_present Whether file properties are present
         * @param properties File properties
         * @param default_version_present Whether default version is present
         * @param default_version Default version
         */
        inline FileAttributes(
            bool properties_present,
            const std::map<std::string, std::string> & properties,
            bool default_version_present,
            const std::string & default_version
        ) : properties_present(properties_present),
            properties(properties),
            default_version_present(default_version_present),
            default_version(default_version) {}
    };

    /**
     * @brief Returns a file from the EDJX Object Store.
     * 
     * @param result Result File
     * @param bucket_id Bucket ID
     * @param file_name File name
     * @return edjx::storage::StorageError::Success on success,
     * some other value on failure
     */
    edjx::error::StorageError get(
        StorageResponse & result,
        const std::string & bucket_id,
        const std::string & file_name
    );

    /**
     * @brief Uploads a file to the EDJX Object Store.
     * 
     * @param result Result of the operation
     * @param bucket_id Bucket ID
     * @param file_name File name
     * @param properties Properties
     * @param contents File content
     * @return edjx::error::StorageError::Success on success,
     * some other value on failure
     */
    edjx::error::StorageError put(
        StorageResponse & result,
        const std::string & bucket_id,
        const std::string & file_name,
        const std::string & properties,
        const std::vector<uint8_t> contents
    );

    /**
     * @brief Deletes the given file from the EDJX Object Store.
     * 
     * @param result Result of the operation
     * @param bucket_id Bucket ID
     * @param file_name File Name
     * @return edjx::error::StorageError::Success on success,
     * some other value on failure
     */
    edjx::error::StorageError remove(
        StorageResponse result,
        const std::string & bucket_id,
        const std::string & file_name
    );

    /**
     * @brief Returns attributes associated with the given file from
     * the EDJX Object Store.
     * 
     * @param result Result of the operation
     * @param bucket_id Bucket ID
     * @param file_name File name
     * @return edjx::error::StorageError::Success on success,
     * some other value on failure
     */
    edjx::error::StorageError get_attributes(
        FileAttributes & result,
        const std::string & bucket_id,
        const std::string & file_name
    );

    /**
     * @brief Sets the attributes associated with the given file.
     * 
     * This setting replaces the existing attributes.
     * 
     * @param result Result of the operation
     * @param bucket_id Bucket ID
     * @param file_name File name
     * @param attributes File attributes
     * @return edjx::error::StorageError::Success on success,
     * some other value on failure
     */
    edjx::error::StorageError set_attributes(
        StorageResponse & result,
        const std::string & bucket_id,
        const std::string & file_name,
        const FileAttributes & attributes
    );

}}