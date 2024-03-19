
把ego-planner的plan_env模块单独拿出来，可以单独作为功能包编译通过。  

参考https://blog.csdn.net/chunchun2021/article/details/134535140 添加node.cpp和launch文件。  


订阅位姿和深度图或者位姿和点云，发出的是融合后的地图PiontCloud2点云类型话题，包括/grid_map/occupancy_inflate话题和/grid_map/occupancy话题。  

启动命令
```
roslaunch plan_env grid_map.launch
```
可以配合densesurfelmapping提供的带有odom和深度图的surfel_color02.bag一起跑。  
surfel_color02.bag官方下载地址：[surfel_color02.bag](https://hkustconnect-my.sharepoint.com/personal/cliuci_connect_ust_hk/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Fcliuci%5Fconnect%5Fust%5Fhk%2FDocuments%2Fdataset%2Fsurfel%5Fcolor02%2Ebag%2Etar%2Egz&parent=%2Fpersonal%2Fcliuci%5Fconnect%5Fust%5Fhk%2FDocuments%2Fdataset&ga=1)  
surfel_color02.bag有备份至csdn，可以这里下载：https://download.csdn.net/download/sinat_16643223/88979285  

注意实际订阅的odom话题以及深度图话题需要在grid_map.cpp里面订阅话题的位置改，目前没有通过launch文件传参的形式，所以grid_map.launch文件里面设定的odom话题和深度图话名称是不生效的。  
比如订阅的是odometry类型的位姿话题和深度图话题时，修改grid_map.cpp里面下面两句话里订阅的话题名称为实际的深度图话题名称和位姿话题名称，修改完重新catkin_make编译生效。  

```
depth_sub_.reset(new message_filters::Subscriber<sensor_msgs::Image>(node_, "/camera/aligned_depth_to_color/image_raw", 50));
```
```
odom_sub_.reset(new message_filters::Subscriber<nav_msgs::Odometry>(node_, "/vins_estimator/imu_propagate", 100));
```

订阅的位姿话题是odometry类型还是posestamped类型，由launch文件中pose_type参数决定，1为posestamped类型，2为odometry类型。  
