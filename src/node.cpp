#include <ros/ros.h>
#include "plan_env/grid_map.h"


GridMap::Ptr   grid_map_test_ ; 

int main(int argc, char** argv)
{
    ros::init(argc, argv, "gridmap_test_node");
    ros::NodeHandle nh_("~");

    grid_map_test_.reset(new GridMap) ;
    grid_map_test_->initMap(nh_) ;

    //grid_map_test_->publishMap(); 

    ros::spin();
  
    return 0;
}

