#include "greetings_driver.h"
#include <zephyr/types.h>
#include <zephyr/sys/printk.h>

uint8_t init_ = 0;
static int init(const struct device *dev)
{
    init_ = 1;

    return 0;
}

static void morning1(const struct device *dev, const char *name)
{
    __ASSERT(init, "Device was not initialized!");

    printk("Good morning from the kernel: %s\n", name);
}

static void afternoon1(const struct device *dev, const char *name)
{
    __ASSERT(init, "Device was not initialized!");

    printk("Good afternoon from the kernel: %s\n", name);
}

static void evening1(const struct device *dev, const char *name)
{
    __ASSERT(init, "Device was not initialized!");

    printk("Good evening from the kernel: %s\n", name);
}

static const struct greetings_driver_api greetings_driver_api = {
    .morning = &morning1,
    .afternoon = &afternoon1,
    .evening = &evening1,
};

DEVICE_DT_DEFINE(DT_NODELABEL(greetings_device), init, NULL,
                          NULL,
                          NULL, POST_KERNEL,
                          99, &greetings_driver_api);