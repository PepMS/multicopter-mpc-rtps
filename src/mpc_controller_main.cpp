#include "multicopter_mpc_rtps/vehicle_odometry/vehicle_odometrySubscriber.h"


#include <fastrtps/Domain.h>

using namespace eprosima;
using namespace eprosima::fastrtps;

int main(int argc, char** argv)
{
	int odom_type = 2;
	std::cout << "Starting Multicopter MPC - Publisher Subscriber" << std::endl;

  vehicle_odometrySubscriber odom_sub;
  if (odom_sub.init())
  {
    odom_sub.run();
  }

	return 0;
}
