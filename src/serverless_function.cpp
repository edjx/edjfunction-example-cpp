#include <edjx/logger.hpp>
#include <edjx/request.hpp>
#include <edjx/response.hpp>
#include <edjx/http.hpp>

using edjx::logger::info;
using edjx::request::HttpRequest;
using edjx::response::HttpResponse;
using edjx::http::HttpStatusCode;

static const HttpStatusCode HTTP_STATUS_OK = 200;

HttpResponse serverless(const HttpRequest & req) {

    info("Inside example function");

    return HttpResponse("Welcome to EDJX")
        .set_status(HTTP_STATUS_OK)
        .set_header("Server", "EDJX");
}