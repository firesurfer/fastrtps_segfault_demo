
#include <iostream>
#include <memory>
#include <random>
#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32_multi_array.hpp"

int main(int argc, char * argv[])
{
  int data_length = 2000000;

  rclcpp::init(argc, argv);

  auto node = rclcpp::node::Node::make_shared("talker");

  rmw_qos_profile_t custom_qos_profile = rmw_qos_profile_default;
  custom_qos_profile.depth = 7;

  auto chatter_pub = node->create_publisher<std_msgs::msg::UInt32MultiArray>("chatter", custom_qos_profile);

  rclcpp::WallRate loop_rate(2);

  auto msg = std::make_shared<std_msgs::msg::UInt32MultiArray>();
  
  std::vector<uint32_t> data;

  for(int i = 0; i < data_length; i++)
  {
		data.push_back(i);
  }
  int count = 0;
  while (rclcpp::ok()) {
    count ++;
    msg->data = data;
    msg->data[0] = count;
    std::cout << "Publishing: '" << msg->data.size() << "' "  << count << std::endl;
    chatter_pub->publish(msg);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }

  return 0;
}

