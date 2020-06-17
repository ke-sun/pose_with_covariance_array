#include <ros/ros.h>
#include <pose_with_covariance_array/PoseWithCovarianceArray.h>

using namespace std;
using namespace ros;
using namespace pose_with_covariance_array;

int main(int argc, char** argv) {

  ros::init(argc, argv, "pose_with_covariance_array_test_node");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<PoseWithCovarianceArray>("pose_array", 1, true);

  PoseWithCovarianceArray msg;
  msg.header.stamp = ros::Time::now();
  msg.header.frame_id = "map";
  msg.poses.resize(3);

  msg.poses[0].pose.position.x = 0.0;
  msg.poses[0].pose.position.y = 0.0;
  msg.poses[0].pose.position.z = 0.0;
  msg.poses[0].pose.orientation.x = 0.0;
  msg.poses[0].pose.orientation.y = 0.0;
  msg.poses[0].pose.orientation.z = 0.0;
  msg.poses[0].pose.orientation.w = 1.0;
  for (size_t i=0; i<36; ++i) msg.poses[0].covariance[i] = 0.0;
  msg.poses[0].covariance[0] = 1.0;
  msg.poses[0].covariance[7] = 1.0;
  msg.poses[0].covariance[14] = 0.0;

  msg.poses[1].pose.position.x = 1.5;
  msg.poses[1].pose.position.y = 1.5;
  msg.poses[1].pose.position.z = 0.0;
  msg.poses[1].pose.orientation.x = 0.0;
  msg.poses[1].pose.orientation.y = 0.0;
  msg.poses[1].pose.orientation.z = 0.0;
  msg.poses[1].pose.orientation.w = 1.0;
  for (size_t i=0; i<36; ++i) msg.poses[1].covariance[i] = 0.0;
  msg.poses[1].covariance[0] = 1.5;
  msg.poses[1].covariance[7] = 1.5;
  msg.poses[1].covariance[14] = 0.0;

  msg.poses[2].pose.position.x = 3.0;
  msg.poses[2].pose.position.y = 3.0;
  msg.poses[2].pose.position.z = 0.0;
  msg.poses[2].pose.orientation.x = 0.0;
  msg.poses[2].pose.orientation.y = 0.0;
  msg.poses[2].pose.orientation.z = 0.0;
  msg.poses[2].pose.orientation.w = 1.0;
  for (size_t i=0; i<36; ++i) msg.poses[2].covariance[i] = 0.0;
  msg.poses[2].covariance[0] = 2.0;
  msg.poses[2].covariance[7] = 2.0;
  msg.poses[2].covariance[14] = 0.0;

  pub.publish(msg);

  ros::spin();
  return 0;
}
