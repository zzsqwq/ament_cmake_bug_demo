#include "common/test.h"
#include "rclcpp/rclcpp.hpp"

class CallerTest : public rclcpp::Node {
 public:
  CallerTest(std::string name, rclcpp::NodeOptions& options);
};
