# 把.指定路径下的所有源文件名字放入变量名SRC_LIST里面
aux_source_directory(. SRC_LIST)
add_library(rpc ${SRC_LIST})

target_link_libraries(rpc muduo_net muduo_base pthread)