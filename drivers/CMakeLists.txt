# add_subdirectory(greetings_driver)
add_subdirectory_ifdef(CONFIG_SAMPLE_GPIO_DRIVER      sample_gpio_driver)
add_subdirectory_ifdef(CONFIG_GREETINGS_DRIVER        greetings_driver)

add_subdirectory_ifdef(CONFIG_SENSOR        dht_driver)