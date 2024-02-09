FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/main/*.*)

idf_component_register(SRCS ${app_sources} INCLUDE_DIRS ".")

# Create a SPIFFS image from the contents of the 'data' directory
# that fits the partition named 'spiffs'. FLASH_IN_PROJECT indicates that
# the generated image should be flashed when the entire project is flashed to
# the target with 'idf.py -p PORT flash'.
spiffs_create_partition_image(spiffs ../data FLASH_IN_PROJECT)