

#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32_multi_array.hpp"
int count = 0;
void chatterCallback(const std_msgs::msg::UInt32MultiArray::SharedPtr msg)
{
  count++;
  std::cout << "I heard: [" << msg->data.size() << "]" << "My count: "<< count << " Pkg count: " << msg->data[0]<< std::endl;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("listener");

  auto sub = node->create_subscription<std_msgs::msg::UInt32MultiArray>(
    "chatter", chatterCallback, rmw_qos_profile_default);

  rclcpp::spin(node);

  return 0;
}

