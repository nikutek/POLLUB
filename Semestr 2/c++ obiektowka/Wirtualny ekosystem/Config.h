#pragma once
#ifndef CONFIG_H
#define CONFIG_H

struct OrganismConfig {
  int eatLimit;
  int maxAgeLowerLimit;
  int maxAgeUpperLimit;
  int costOfReproduction;

  OrganismConfig(int eatLimit, int maxAgeLowerLimit, int maxAgeUpperLimit, int costOfReproduction)
      : eatLimit(eatLimit), maxAgeLowerLimit(maxAgeLowerLimit), maxAgeUpperLimit(maxAgeUpperLimit), costOfReproduction(costOfReproduction) {}
};

class Config {
public:
  OrganismConfig bacteria;
  OrganismConfig algae;
  OrganismConfig fungi;

  Config()
      : bacteria(3, 5, 10, 3),
        algae(3, 5, 10, 3),
        fungi(3, 5, 10, 3)
  {}

};

#endif // CONFIG_H
