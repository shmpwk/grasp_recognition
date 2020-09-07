void point_cloud_callback(const sensor_msgs::PointCloud2::ConstPtr &input)
{

  pcl::PointCloud<pcl::PointXYZ> cloud_file;
  pcl::fromROSMsg(*input, cloud_file);

  std::vector<int> mapping;
  pcl::removeNaNFromPointCloud(cloud_file, cloud_file, mapping);
  pcl::io::savePCDFileASCII("/home/test.pcd",cloud_file);

}
