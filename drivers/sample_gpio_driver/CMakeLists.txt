zephyr_library()
zephyr_library_sources_ifdef(CONFIG_FUNNY_DRIVER_NAME      funny_driver_name.c)
zephyr_library_sources_ifdef(CONFIG_NEW_GPIO_DRIVER_V2     new_gpio_driver_v2.c)