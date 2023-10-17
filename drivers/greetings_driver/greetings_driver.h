#ifndef __GREETINGS_DRIVER_H__
#define __GREETINGS_DRIVER_H__

#include <zephyr/device.h>

struct greetings_driver_api {
    void (*morning)(const struct device *dev, const char *name);
    void (*afternoon)(const struct device *dev, const char *name);
    void (*evening)(const struct device *dev, const char *name);
};

__syscall     void        greetings_driver_morning(const struct device *dev, const char *name);
static inline void z_impl_greetings_driver_morning(const struct device *dev, const char *name)
{
    const struct greetings_driver_api *api = dev->api;

    __ASSERT(api->morning, "Callback pointer should not be NULL");

    api->morning1(dev, name);
}

#include <syscalls/greetings_driver.h>


#endif // __GREETINGS_DRIVER_H__