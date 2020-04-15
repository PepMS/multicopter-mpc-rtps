#include "multicopter_mpc_rtps/vehicle_odometry/vehicle_odometrySubscriber.h"
#include "multicopter_mpc/mpc-main.hpp"

#include <fastrtps/Domain.h>

using namespace eprosima;
using namespace eprosima::fastrtps;

int main(int argc, char **argv) {
  int odom_type = 2;
  std::cout << "Starting Multicopter MPC - Publisher Subscriber" << std::endl;

  multicopter_mpc::MpcMain mpc_problem(multicopter_mpc::MultiCopterTypes::Iris, multicopter_mpc::MissionTypes::Hover,
                                       multicopter_mpc::SolverTypes::BoxFDDP);
  vehicle_odometrySubscriber odom_sub;
  if (odom_sub.init()) {
    odom_sub.run();
  }

  return 0;
}
