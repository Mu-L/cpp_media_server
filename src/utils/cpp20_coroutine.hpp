#ifndef CPP20_COROUTINE_HPP
#define CPP20_COROUTINE_HPP
#include <stdint.h>
#include <stddef.h>
#include <string>
#ifdef __APPLE__
#include <experimental/coroutine>
#else
#include <coroutine>
#endif

typedef struct cpp20_co_task_s
{
    struct promise_type
    {
        struct cpp20_co_task_s get_return_object() { return {}; }
        #ifdef __APPLE__
        std::experimental::suspend_never initial_suspend() { return {}; }
        std::experimental::suspend_never final_suspend() noexcept { return {}; }
        #else
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        #endif
        void return_void() {}
        void unhandled_exception() {}
    };
} cpp20_co_task;


#endif