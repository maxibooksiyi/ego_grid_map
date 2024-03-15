
把ego-planner的plan_env模块单独拿出来，可以单独作为功能包编译通过。

参考https://blog.csdn.net/chunchun2021/article/details/134535140 添加node.cpp和launch文件。

启动命令
```
roslaunch plan_env grid_map.launch
```
可以配合densesurfelmapping提供的带有odom和深度图的bag包一起跑  

注意实际订阅的odom话题以及深度图话题需要在grid_map.cpp里面订阅话题的位置改，目前没有通过launch文件传参的形式，所以grid_map.launch文件里面设定的odom话题和深度图话名称是不生效的。  
