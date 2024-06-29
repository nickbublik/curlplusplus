#include <iostream>
#include <chrono>
#include <sstream>

#include "EasyHandle.hpp"
#include "EasyHandleBuilder.hpp"
#include "MultiHandle.hpp"

void log_event(const CurlWrapper::MultiCode mc)
{
    std::cout << static_cast<int>(mc) << "\n";
}

std::stringstream ss;

static size_t write_cb(char *data, size_t n, size_t l, void *userp)
{
    std::cout << "write_cb : n = " << n << ", l = " << l << std::endl;
    (void)data;
    (void)userp;

    for (size_t i = 0; i < l; ++i)
    {
        ss << data[i];
    }

    return n*l;
}

int main(int /*argc*/, char** /*argv[]*/)
{
    using namespace CurlWrapper;

    std::chrono::milliseconds poll_timeout {10};
    
    const std::string c_url{"https://example.com"};

    EasyHandleBuilder easy_builder;

    easy_builder.addOption(EasyOption::URL, c_url);
    easy_builder.addOption(EasyOption::WRITEFUNCTION, write_cb);
    std::shared_ptr<EasyHandle> easy_handle = easy_builder.build();

    std::unique_ptr<MultiHandle> multi_handle = std::make_unique<MultiHandle>();

    multi_handle->addEasyHandle(easy_handle);

    int i = 0;

    int num_of_running_handles = 1;

    while (num_of_running_handles) 
    {
        MultiCode res;
        std::tie(res, num_of_running_handles) = multi_handle->perform();

        if (res != MultiCode::OK)
        {
            log_event(res);
            break;
        }
        
        if (num_of_running_handles)
        {
            res = multi_handle->poll(poll_timeout);
        }
        
        if (res != MultiCode::OK)
        {
            log_event(res);
            break;
        }

        ++i;
        std::cout << "Iteration #" << i << '\n';
    }

    /* See how the transfers went */
    /* !checksrc! disable EQUALSnullptr 1 */


    Message message;
    unsigned messages_left = 0;

    std::tie(message, messages_left) = multi_handle->info_read();

    while (messages_left != 0) 
    {
        if (message.completed) 
        {
            std::cout << "HTTP transfer completed with status " << static_cast<int>(message.data.result) << '\n';
        }

        std::cout << "Multi Info Read Iteration #" << i << '\n';

        std::tie(message, messages_left) = multi_handle->info_read();
    }

    std::cout << "Result of operation: \n" << ss.str() << std::endl;

    return 0;
}
