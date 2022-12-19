cmake_minimum_required(VERSION 3.8)
project(common)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

set(msg_files msg/Result.msg)

rosidl_generate_interfaces(${PROJECT_NAME}
        ${msg_files}
        DEPENDENCIES std_msgs)

add_library(common_lib src/test.cc)

ament_target_dependencies(common_lib rosidl_default_runtime)

install(TARGETS
        common_lib
        # EXPORT CommonTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION lib/${PROJECT_NAME}
        # INCLUDES DESTINATION include
        )

install(DIRECTORY include/ DESTINATION include)

ament_export_include_directories(include)
ament_export_libraries(common_lib)
ament_export_dependencies(rosidl_default_runtime)
# ament_export_targets(CommonTargets HAS_LIBRARY_TARGET)
ament_package()
