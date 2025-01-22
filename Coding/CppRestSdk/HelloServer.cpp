#include "HelloServer.h"

void OpenApi::process_get(http_request request)
{
	ucout << utility::string_t(U("GET Request recived")) << std::endl;
	reply_ok(&request, utility::string_t(U("GET Request Proccessed Successfully ...")));

}
void OpenApi::reply_ok(http_request* message,utility::string_t replystr)
{

	http_response response;

	response.set_status_code(status_codes::OK);
	response.set_body(replystr.c_str());

	message->reply(response);
}