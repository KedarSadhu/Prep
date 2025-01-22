#include "HelloServer.h"

void on_initialize(const string_t address);
void on_shutdown();

std::unique_ptr <OpenApi> g_http;

int main(int argc,wchar_t * argv[])
{
	utility::string_t addr;
	utility::string_t port;

	if (argc == 3)
	{
		addr = argv[2];
		port = argv[3];
	}
	else
	{
		addr = U("http://localhost:");
		port = U("9000");
	}
	addr.append(port);
	on_initialize(addr);

	std::string line;
	std::getline(std::cin, line);
	on_shutdown();
	return 0;
}

void on_initialize(const string_t address)
{
	try
	{
		uri_builder uri(address);
		uri.append_path(U("/PwdServer"));

		auto addr = uri.to_uri().to_string();

		g_http = std::unique_ptr<OpenApi>(new OpenApi(addr));

		g_http->Open().wait();

		ucout << utility::string_t(U("Listening request at :: ")) << addr << std::endl;
	}
	catch (std::exception const &e)
	{ 
		ucout << utility::string_t(U("Exception :: on_initialize ->")) << e.what();
	}

}

void on_shutdown()
{
	g_http->Close().wait();
	ucout << utility::string_t(U("Listener stopped")) <<std::endl;
}