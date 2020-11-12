#include "GroundRace.h"
#include "AirRace.h"
#include "MixedRace.h"

int main() {

   std::list<Vehicle*> mix;

   mix.push_back(new Stypa());
   mix.push_back(new FlyingCarpet());
   mix.push_back(new Broom());
   mix.push_back(new Centaur());
   mix.push_back(new RoverBoots());

   MixedRace mixedRace(mix);

   mixedRace.HowWin(1000);




   std::list<GroundVehicle*> ground;

   ground.push_back(new Centaur());
   ground.push_back(new BactrianCamel());
   ground.push_back(new SpeedCamel());
   ground.push_back(new RoverBoots());

   GroundRace groundRace(ground);

   groundRace.HowWin(2000);




   std::list<AirVehicle*> air;

   air.push_back(new Broom());
   air.push_back(new FlyingCarpet());
   air.push_back(new Stypa());

   AirRace airRace(air);

   airRace.HowWin(3000);

}
