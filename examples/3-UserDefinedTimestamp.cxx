///
/// \file 3-UserDefinedTimestamp.cxx
/// \author Adam Wegrzynek <adam.wegrzynek@cern.ch>
///

#include <iostream>
#include <chrono>
#include "Monitoring/Collector.h"

namespace Monitoring = AliceO2::Monitoring;

int main() {
  // parse configuration file
  ConfigFile configFile;
  configFile.load("file:/home/awegrzyn/hackathon/Monitoring/examples/SampleConfig.ini");

  // create monitoring object and confuguration as parameter to constructor
  std::unique_ptr<Monitoring::Core::Collector> collector(new Monitoring::Core::Collector(configFile));

  // generate current timestamp
  std::chrono::time_point<std::chrono::system_clock> timestamp = std::chrono::system_clock::now();
	
  // now send an application specific metric
  // 10 is the value 
  // myCrazyMetric is the name of the metric
  collector->send(10, "myCrazyMetric", timestamp);
  
  // sleep 1 second, and send different metric with the same timestamp
  std::this_thread::sleep_for(std::chrono::seconds(1));
  collector->send(40, "myCrazyMetric", timestamp);
}