#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>

// #define BUTTON0 DT_NODELABEL(button0)
// static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(BUTTON0, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(DT_NODELABEL(sample_gpiodriver), input_gpios);
#define LED0 DT_NODELABEL(green_led_1)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0, gpios);
static int sample_gpio_driver_init(const struct device *dev)
{
    int ret;

    if (!gpio_is_ready_dt(&button)) {
        return -ENODEV;
    }

    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (ret < 0) {
        return 0;
    }

    return 0;
}



int state = 0;
static int sample_gpio_driver_sample_fetch(const struct device *dev,
                                  enum sensor_channel chan)
{
    state = gpio_pin_get_dt(&led);

    return 0;
}

static int sample_gpio_driver_channel_get(const struct device *dev,
                    enum sensor_channel chan,
                    struct sensor_value *val)
{
    if (chan != SENSOR_CHAN_PROX) {
        return -ENOTSUP;
    }

    val->val1 = state;

    return 0;
}

static const struct sensor_driver_api sample_gpio_driver_api = {
    .sample_fetch = &sample_gpio_driver_sample_fetch,
    .channel_get = &sample_gpio_driver_channel_get,
};

// DEVICE_DT_DEFINE(DT_NODELABEL(sample_gpiodriver), sample_gpio_driver_init, NULL,
//                           NULL,
//                           NULL, POST_KERNEL,
//                           99, &sample_gpio_driver_api);


// DEVICE_DT_DEFINE(DT_NODELABEL(sample_gpiodriver1), sample_gpio_driver_init, NULL,
//                           NULL,
//                           NULL, POST_KERNEL,
//                           98, &sample_gpio_driver_api);

#define INIT_FUNNY_DRIVER(i)                                                        \
    struct sample_gpio_driver_config sample_gpio_driver_config_##i {                \
        .button = GPIO_DT_SPEC_INST_GET(i, input_gpios),                            \
    };                                                                              \
                                                                                    \
    DEVICE_DT_INST_DEFINE(0, sample_gpio_driver_init, NULL,                         \
                          NULL,                                                                             \
                          &sample_gpio_driver_config_##i, POST_KERNEL,                              \
                          99, &sample_gpio_driver_api);

DT_INST_FOREACH_STATUS_OKAY(INIT_FUNNY_DRIVER)