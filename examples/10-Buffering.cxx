///
/// \file 10-Buffering.cxx
/// \author Adam Wegrzynek <adam.wegrzynek@cern.ch>
///

#include "Monitoring/MonitoringFactory.h"

using Monitoring = o2::monitoring::MonitoringFactory;

int main()
{
  // Configure monitoring
  // Pass string with list of URLs as parameter
  auto monitoring = Monitoring::Get("stdout://");
  monitoring->enableBuffering(10);

  // now send an application specific metric
  // 10 is the value
  // myMetric is the name of the metric by creating and moving Metric object
  for (int i = 0; i < 25; i++) {
    monitoring->send({10, "myMetricInt"});
  }
  monitoring->send({10.10, "myMetricFloat"});
  monitoring->flushBuffer();
}
