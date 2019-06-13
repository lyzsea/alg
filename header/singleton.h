//
// Created by yz L on 2019-06-10.
//

#ifndef ALG_SINGLETON_H
#define ALG_SINGLETON_H

#include <pthread.h>
#include <stdlib.h> // atexit

namespace detail {
    // This doesn't detect inherited member functions!
    // http://stackoverflow.com/questions/1966362/sfinae-to-check-for-inherited-member-functions
    template<typename T>
    struct has_no_destroy {
        template<typename C>
        static char test(decltype(&C::no_destroy));

        template<typename C>
        static int32_t test(...);

        const static bool value = sizeof(test<T>(0)) == 1;
    };
}  // namespace detail

template <typename T>
class CSingleton {
public:
    static T &getInstance() {
        pthread_once(&ponce_, &CSingleton::init);
        assert(value_ != nullptr);
        return *value_;
    }

private:
    CSingleton() = delete;
    CSingleton(const CSingleton&) = delete;
    ~CSingleton() = delete;

    static void init() {
        value_ = new T();
        if (!detail::has_no_destroy<T>::value) {
            ::atexit(destroy);
        }
    }

    static void destroy() {
        typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
        T_must_be_complete_type dummy;
        (void) dummy;

        delete value_;
        value_ = NULL;
    }

private:
    static pthread_once_t ponce_;
    static T*             value_;
};

template<typename T>
pthread_once_t CSingleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* CSingleton<T>::value_ = NULL;
#endif //ALG_SINGLETON_H
