
#define PROFILE_ENABLED

#include <thread>
#include <cake.h>


void function_test()
{
    PROFILE_FUNCTION;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void function_frequency_test()
{
    PROFILE_FUNCTION_FREQUENCY;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}



void block_test()
{
    PROFILE_BLOCK_START("block1");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    PROFILE_BLOCK_END;

    PROFILE_BLOCK_START("block2");
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    PROFILE_BLOCK_END;
}

void block_test_nested()
{
    PROFILE_BLOCK_START("block3");
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    PROFILE_BLOCK_START("block4");
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    PROFILE_BLOCK_END;

    PROFILE_BLOCK_END;
}

int main(int argc, char* argv[])
{
    PROFILE_FUNCTION;

    for(auto i = 0; i < 10; ++i)
    {
        function_test();
    }

    std::vector<std::thread> tv;
    for (auto i = 0; i < 10; ++i)
    {
        tv.emplace_back(function_test);
    }

    for (auto i = 0; i < 10; ++i)
    {
        tv[i].join();
    }


    for (auto i = 0; i < 10; ++i)
    {
        function_frequency_test();
    }

    block_test();
    block_test_nested();
}
