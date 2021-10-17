#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <string>

#include "http.hpp"
#include "error.hpp"

namespace edjx {

/// APIs used to send HTTP Responses for HTTP-triggered serverless functions.
namespace response {

    /**
     * @brief An HTTP response which may include body, headers, and status code.
     * 
     * Each serverless function can send only one response to the client.
     * 
     * Normally, these methods do not need to be used explicitly. EDJX sample
     * [`C++ Serverless Application`](https://github.com/edjx/edjfunction-example-cpp)
     * code file (`main.cpp`) uses one of these methods to process Responses
     * and relay to the client.
     * 
     * The HTTP response consists of a status, version, a set
     * of header fields, and a body.
     */
    struct HttpResponse {
        /// HTTP status code
        edjx::http::HttpStatusCode status;
        /// HTTP version
        edjx::http::HttpVersion version;
        /// HTTP headers
        edjx::http::HttpHeaders headers;
        /// Body of the response
        std::vector<uint8_t> body;

        /**
         * @brief Creates an HttpResponse for the client.
         * 
         * The response is created with status code `200 OK`,
         * version as HTTP/1.1, no headers, and an empty body.
         */
        HttpResponse();

        /**
         * @brief Creates an HttpResponse for the client.
         * 
         * The response is created with status code `200 OK`,
         * version as HTTP/1.1, no headers, and `text` as body.
         * 
         * @param text A string that will be used as the body
         */
        HttpResponse(const std::string & text);

        /**
         * @brief Creates an HttpResponse for the client.
         * 
         * The response is created with status code `200 OK`,
         * version as HTTP/1.1, no headers, and `bytes` as body.
         * 
         * @param bytes A sequence of bytes that will be used as the body
         */
        HttpResponse(const std::vector<uint8_t> & bytes);

        /**
         * @brief Creates an HttpResponse for the client.
         * 
         * The response is created with status code `200 OK`,
         * version as HTTP/1.1, no headers, and a body created from
         * bytes in a memory buffer.
         * 
         * @param mem Pointer to the body bytes
         * @param size Number of bytes in the body
         */
        HttpResponse(const uint8_t * mem, size_t size);

        /**
         * @brief Sets the HTTP status code of the client response.
         * 
         * @param status HTTP status (e.g., 200)
         * @return Reference to this HttpResponse object 
         */
        HttpResponse & set_status(edjx::http::HttpStatusCode status);

        /**
         * @brief Returns the HTTP status code of the response.
         * 
         * @return HTTP status
         */
        edjx::http::HttpStatusCode get_status() const;

        /**
         * @brief Sets the HTTP version of this response.
         * 
         * @param version HTTP version (use constants from [`edjx::http::HttpVersion`])
         * @return Reference to this HttpResponse object
         */
        HttpResponse & set_version(edjx::http::HttpVersion version);

        /**
         * @brief Returns the HTTP version of this response.
         * 
         * @return HTTP version of the response
         */
        edjx::http::HttpVersion get_version() const;

        /**
         * @brief Sets a response header to the given value.
         * 
         * Discards any previous values for the given header name.
         * 
         * @param header_name Header name
         * @param value Header value
         * @return Reference to this HttpResponse object
         */
        HttpResponse & set_header(
            const std::string & header_name,
            const std::string & value
        );

        /**
         * @brief Sets a response header to the given values.
         * 
         * Discards any previous values for the given header name.
         * 
         * @param header_name Header name
         * @param values Multiple header values
         * @return Reference to this HttpResponse object
         */
        HttpResponse & set_header(
            const std::string & header_name,
            const std::vector<std::string> & values
        );

        /**
         * @brief Sets a response header to the given value.
         * 
         * Keeps any previous values for the given header name and adds
         * the new value
         * 
         * @param header_name Header name
         * @param value Header value
         * @return Reference to this HttpResponse object
         */
        HttpResponse & append_header(
            const std::string & header_name,
            const std::string & value
        );

        /**
         * @brief Set the response headers to the given values.
         * 
         * Discards any previous headers.
         * 
         * @param headers Headers
         * @return Reference to this HttpResponse object
         */
        HttpResponse & set_headers(
            const edjx::http::HttpHeaders & headers
        );

        /**
         * @brief Returns a constant reference to the response header map.
         * 
         * @return HTTP headers
         */
        const edjx::http::HttpHeaders & get_headers() const;

        /**
         * @brief Sets the body to be `text`.
         * 
         * @param text Used as response body
         * @return Reference to this HttpResponse object
         */
        HttpResponse & set_body(const std::string & text);

        /**
         * @brief Sets the body to be `bytes`.
         * 
         * @param bytes Used as response body
         * @return Reference to this HttpResponse object
         */
        HttpResponse & set_body(const std::vector<uint8_t> & bytes);

        /**
         * @brief Sets the body to contain `size` bytes from address `mem`.
         * 
         * @param mem Pointer do bytes to be used as body
         * @param size Number of bytes to be used as body
         * @return Reference to this HttpResponse object
         */
        HttpResponse & set_body(const uint8_t * mem, size_t size);

        /**
         * @brief Returns a constant reference to the body.
         * 
         * @return Body of the response
         */
        const std::vector<uint8_t> & get_body() const;

        /**
         * @brief Send the response to the client.
         * 
         * @return Returns edjx::error::HttpError::Success on success,
         * some other value on failure.
         */
        edjx::error::HttpError send();
    };

}}