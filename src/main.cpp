#include <iostream>
#include <chrono>

#include <curl/curl.h>

#include "EasyHandle.hpp"
#include "EasyHandleBuilder.hpp"
#include "MultiHandle.hpp"

void log_event(const MultiCode mc)
{
    std::cout << mc << "\n";
}

int main(int /*argc*/, char** /*argv[]*/)
{
    using namespace CurlWrapper;

    int is_running = 1; /* keep number of running handles */

    std::chrono::milliseconds poll_timeout {10};
    
    CURLMsg *msg; /* for picking up messages with the transfer status */
    int msgs_left; /* how many messages are left */

    EasyHandleBuilder easy_builder;

    easy_builder.addOptionString(EasyOption::URL, std::string("https://example.com"));
    std::shared_ptr<EasyHandle> easy_handle = easy_builder.build();

    std::unique_ptr<MultiHandle> multi_handle = std::make_unique<MultiHandle>();
    
    multi_handle->addEasyHandle(easy_handle);

    int i = 0;

    int num_of_running_handles = 1;

    while (num_of_running_handles) 
    {
        CURLMcode mc = curl_multi_perform(multi_handle->getHandle(), &is_running);

        MultiCode res;
        std::tie(res, num_of_running_handles) = multi_handle->perform();

        if (res)
        {
            log_event(res);
            break;
        }
        
        if (is_running)
        {
            res = curl_multi_poll(
                    multi_handle->getHandle(),
                    nullptr,
                    0,
                    static_cast<unsigned int>(poll_timeout.count()),
                    nullptr);
        }
        
        if (res)
        {
            log_event(res);
            break;
        }

        ++i;
        std::cout << "Iteration #" << i << '\n';
    }

    /* See how the transfers went */
    /* !checksrc! disable EQUALSnullptr 1 */
    while((msg = curl_multi_info_read(multi_handle->getHandle(), &msgs_left)) != nullptr) 
    {
        if (msg->msg == CURLMSG_DONE) 
        {
            //int found = (msg->easy_handle == handle);

            //if (found)
            //{
            //    break;
            //}

            std::cout << "HTTP transfer completed with status " << msg->data.result << '\n';
        }
    }
    
    return 0;
}
