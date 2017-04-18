cmake_minimum_required(VERSION 3.5)



project(big_package_test)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -g")
endif()



find_package(ament_cmake REQUIRED)

find_package(builtin_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rmw REQUIRED)
find_package(rmw_implementation_cmake REQUIRED)
find_package(std_msgs REQUIRED)



include_directories(
    	${rclcpp_INCLUDE_DIRS}
    	${rmw_INCLUDE_DIRS}
    	${rmw_implementation_INCLUDE_DIRS}
    	${std_msgs_INCLUDE_DIRS}
		${CMAKE_CURRENT_SOURCE_DIR}/src/
)

add_executable(big_packet_test_listener
		"${CMAKE_CURRENT_SOURCE_DIR}/src/listener.cpp")
add_executable(big_packet_test_talker
		"${CMAKE_CURRENT_SOURCE_DIR}/src/talker.cpp")

target_link_libraries(big_packet_test_listener
    	${rclcpp_LIBRARIES}
    	${rmw_LIBRARIES}
    	${rmw_implementation_LIBRARIES}
    	${std_msgs_LIBRARIES}
)
target_link_libraries(big_packet_test_talker
    	${rclcpp_LIBRARIES}
    	${rmw_LIBRARIES}
    	${rmw_implementation_LIBRARIES}
    	${std_msgs_LIBRARIES}
)




install(TARGETS big_packet_test_listener DESTINATION bin)
install(TARGETS big_packet_test_talker DESTINATION bin)

ament_package()

