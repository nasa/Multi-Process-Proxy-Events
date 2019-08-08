cmake_minimum_required(VERSION 2.6.4)
project(CFE_PROXY_EVS C)

include_directories(fsw/platform_inc)

aux_source_directory(fsw/src APP_SRC_FILES)

# Create the app module
add_cfe_app(proxy_evs ${APP_SRC_FILES})
