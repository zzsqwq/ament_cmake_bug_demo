cmake_minimum_required(VERSION 3.8)
project(caller)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

find_package(ament_cmake REQUIRED)
find_package(common REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include)

set(dependencies rosidl_default_runtime common rclcpp)

set(srv_files srv/ResultMsgTest.srv)

rosidl_generate_interfaces(${PROJECT_NAME}
        ${srv_files}
        DEPENDENCIES common)

add_executable(caller_bin src/caller.cc)
ament_target_dependencies(caller_bin ${dependencies})

install(TARGETS
        caller_bin
        # EXPORT CallerTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION lib/${PROJECT_NAME}
        # INCLUDES DESTINATION include
        )

install(DIRECTORY include/ DESTINATION include)

ament_export_include_directories(include)
ament_export_dependencies(${dependencies})
# ament_export_targets(CallerTargets)
ament_package()
