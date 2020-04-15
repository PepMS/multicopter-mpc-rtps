cmake_minimum_required(VERSION 3.1)

PROJECT(multicopter_mpc_rtps VERSION 0.0
                             DESCRIPTION "Library to solve the MPC problem using MC-MPC library"
                             LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPINOCCHIO_URDFDOM_TYPEDEF_SHARED_PTR -DPINOCCHIO_URDFDOM_USE_STD_SHARED_PTR -DBOOST_MPL_LIMIT_LIST_SIZE=30 -DPINOCCHIO_WITH_URDFDOM")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fpic -m64")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/lib/cmake/YamlCpp") 
set(CMAKE_INSTALL_PREFIX /usr/local)
set(CMAKE_BUILD_TYPE RELEASE)

find_package(Eigen3 3.3 REQUIRED)
find_package(YamlCpp REQUIRED)

# SET(YAML_PARSER_LIB /usr/local/lib/libyaml_parser.so)
# SET(YAML_PARSER_INCLUDE_DIRS /usr/local/include/yaml_parser/)
# SET(CROCODDYL_LIB /usr/local/lib/libcrocoddyl.so)
# SET(CROCODDYL_INCLUDE_DIRS /usr/local/include/crocoddyl)
# SET(PINOCCHIO_LIB /usr/local/lib/libpinocchio.so)
# SET(PINOCCHIO_INCLUDE_DIRS /usr/local/include/pinocchio)
SET(URDFDOM_LIB /usr/lib/x86_64-linux-gnu/liburdfdom_model.so)
SET(MC_MPC_LIB /usr/local/lib/libmulticopter_mpc.so)
SET(MC_MPC_INCLUDE_DIRS /usr/local/include/multicopter_mpc)

SET(SYS_LIBS 
-ldl
-lnsl
-lm
-lpthread
-lrt)
SET(FASTRTPS_LIBS
-lfastcdr 
-lfastrtps
-lssl
-lcrypto
)

message(STATUS "Eigen library:" ${EIGEN3_INCLUDE_DIRS})

add_subdirectory(src)
