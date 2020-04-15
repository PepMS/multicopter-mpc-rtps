set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)

set(MC_MPC_RTPS_SOURCES
    vehicle_odometry/vehicle_odometry.cxx
    vehicle_odometry/vehicle_odometryPubSubTypes.cxx
    vehicle_odometry/vehicle_odometrySubscriber.cxx
    mpc_controller_main.cpp
)

set(MC_MPC_RTPS_HEADERS
../include/vehicle_odometry/vehicle_odometry.h
../include/vehicle_odometry/vehicle_odometryPubSubTypes.h
../include/vehicle_odometry/vehicle_odometrySubscriber.h
)

set(MC_MPC_RTPS_INCLUDE_DIRS
    ../include
    ${EIGEN3_INCLUDE_DIRS}
    ${MC_MPC_INCLUDE_DIRS}
    # ${CROCODDYL_INCLUDE_DIRS}
)

set(MC_MPC_RTPS_LIBS
${SYS_LIBS}
${FASTRTPS_LIBS}
-lboost_system
${MC_MPC_LIB}
${YAMLCPP_LIBRARY}
${URDFDOM_LIB}
# ${YAML_PARSER_LIB}
# ${CROCODDYL_LIB}
)

add_executable(mc-mpc-rtps-main ${MC_MPC_RTPS_SOURCES})
target_include_directories(mc-mpc-rtps-main PUBLIC ${MC_MPC_RTPS_INCLUDE_DIRS})
target_link_libraries(mc-mpc-rtps-main PUBLIC ${MC_MPC_RTPS_LIBS})