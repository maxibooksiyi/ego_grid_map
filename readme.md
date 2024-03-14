
把ego-planner的plan_env模块单独拿出来，可以单独作为功能包编译通过。

参考https://blog.csdn.net/chunchun2021/article/details/134535140 添加node.cpp和launch文件。

启动命令
```
roslaunch plan_env grid_map.launch
```
可以配合densesurfelmapping提供的带有odom和深度图的bag包一起跑  
