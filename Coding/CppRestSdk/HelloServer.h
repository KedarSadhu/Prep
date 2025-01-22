#pragma once

#include <cpprest/http_client.h>	// HTTP client class, used to maintain a connection to an HTTP service for an extended session.
#include <cpprest/http_listener.h>	// listening and processing HTTP requests at a specific URI

using namespace utility; // used for utility strings
using namespace web::http; //used for common http functionality
using namespace web::http::experimental::listener; // listening and processing HTTP requests at a specific URI.

class OpenApi
{
public:
	http_listener m_httplistener;
	
	OpenApi(utility::string_t url):m_httplistener(url)
	{
		m_httplistener.support(methods::GET, std::bind(&OpenApi::process_get, this, std::placeholders::_1));
	}
	
	pplx::task <void>Open()
	{
		return m_httplistener.open();
	}
	
	pplx::task <void>Close()
	{
		return m_httplistener.close();
	}

	void process_get(http_request reuest);

	void reply_ok(http_request* message, utility::string_t replystr);

};