# 把.指定路径下的所有源文件名字放入变量名SRC_LIST里面
# aux_source_directory(. SRC_LIST)
set(SRC_LIST userservice.cc ../user.pb.cc)

add_executable(provider ${SRC_LIST})

# 表示provider这个目标程序，需要链接的库
target_link_libraries(provider pthread rpc protobuf)