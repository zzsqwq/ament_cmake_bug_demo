#include "caller/caller.h"

CallerTest::CallerTest(std::string name, rclcpp::NodeOptions& options)
    : rclcpp::Node("caller_test", options) {
  CommonTest(name);
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  auto node = std::make_shared<CallerTest>("ROS2 CallerTest", options);
  rclcpp::spin(node->get_node_base_interface());
  rclcpp::shutdown();
  return 0;
}