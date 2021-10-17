#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <string>

#include "http.hpp"
#include "error.hpp"

namespace edjx {

/// APIs for executing HTTP requests.
namespace fetch {

    /**
     * @brief Response for HTTP fetch request, which may include body,
     * headers, and status code.
     */
    struct FetchResponse {
        /// HTTP status code of the response
        edjx::http::HttpStatusCode status;
        /// HTTP headers of the response
        edjx::http::HttpHeaders headers;
        /// Body of the response
        std::vector<uint8_t> body;

        /**
         * @brief Returns the HTTP status code of the fetch response.
         * 
         * @return Response status code
         */
        edjx::http::HttpStatusCode get_status_code() const;

        /**
         * @brief Returns HTTP headers of the fetch response.
         * 
         * @return HTTP headers
         */
        const edjx::http::HttpHeaders & get_headers() const;

        /**
         * @brief Returns the HTTP body of the fetch response.
         * 
         * @return Response body
         */
        const std::vector<uint8_t> & get_body() const;
    };

    /**
     * @brief An HTTP fetch request includes body, headers,
     * version, method, and URI.
     */
    struct HttpFetch {
        /// HTTP version of the request.
        http::HttpVersion version;
        /// Headers for the request.
        edjx::http::HttpHeaders headers;
        /// URI of the request.
        http::Uri uri;
        /// Method for the request.
        http::HttpMethod method;
        /// Request body.
        std::vector<uint8_t> body;

        /**
         * @brief Creates a request with the given method and URI,
         * version as HTTP/1.1, no headers, and no body.
         * 
         * @param uri Request URI
         * @param method Request method
         */
        inline HttpFetch(http::Uri uri, http::HttpMethod method) :
            version(http::HttpVersion::HTTP_11),
            uri(uri),
            method(method) {}

        /**
         * @brief Sets the HTTP version of the request.
         * 
         * @param version Version to be set
         * @return Reference to this HttpFetch object
         */
        HttpFetch & set_version(http::HttpVersion version);

        /**
         * @brief Gets the HTTP version of the request.
         * 
         * @return HTTP version of the request
         */
        http::HttpVersion get_version() const;

        /**
         * @brief Sets a request header to the given value.
         * 
         * Discards any previous values for the given header name.
         * 
         * @param header_name Header name
         * @param value Header value
         * @return Reference to this HttpFetch object
         */
        HttpFetch & set_header(
            const std::string & header_name,
            const std::string & value
        );

        /**
         * @brief Sets a request header to the given values.
         * 
         * Discards any previous values for the given header name.
         * 
         * @param header_name Header name
         * @param value Header values
         * @return Reference to this HttpFetch object
         */
        HttpFetch & set_header(
            const std::string & header_name,
            const std::vector<std::string> & value
        );

        /**
         * @brief Appends a value to the existing request header.
         * 
         * Keeps any previous values for the given header name.
         * 
         * @param header_name Header name
         * @param value Header value
         * @return Reference to this HttpFetch object
         */
        HttpFetch & append_header(
            const std::string & header_name,
            const std::string & value
        );

        /**
         * @brief Set request headers to the given values.
         * 
         * All previously defined headers will be discarded.
         * 
         * @param value HTTP headers
         * @return Reference to this HttpFetch object
         */
        HttpFetch & set_headers(
            const edjx::http::HttpHeaders & value
        );

        /**
         * @brief Returns a const reference to the request header map
         * 
         * @return Request headers
         */
        const edjx::http::HttpHeaders & get_headers() const;

        /**
         * @brief Sets the given [`text`] value as the body of the request.
         * 
         * Any body that was previously set on the request is discarded.
         * 
         * @param text String to be used as the body
         * @return Reference to this HttpFetch object
         */
        HttpFetch & set_body(const std::string & text);

        /**
         * @brief Sets the given [`bytes`] value as the body of the request.
         * 
         * Any body that was previously set on the request is discarded.
         * 
         * @param bytes Bytes to be used as the body
         * @return Reference to this HttpFetch object
         */
        HttpFetch & set_body(const std::vector<std::uint8_t> bytes);

        /**
         * @brief Returns a constant reference to the body.
         * 
         * @return Request body
         */
        const std::vector<uint8_t> & get_body() const;

        /**
         * @brief Sends the request to the server, and returns after the
         * response is received or an error occurs.
         * 
         * @param response 
         * @return Returns edjx::error::HttpError::Success on success,
         * some other value on failure.
         */
        edjx::error::HttpError send(FetchResponse & response);
    };

}}