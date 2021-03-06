// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file MonitoringFactory.h
/// \author Adam Wegrzynek <adam.wegrzynek@cern.ch>
///

#ifndef ALICEO2_MONITORING_FACTORY_H
#define ALICEO2_MONITORING_FACTORY_H

#include "Monitoring/Monitoring.h"

namespace o2
{
/// ALICE O2 Monitoring system
namespace monitoring
{

/// \brief Monitoring and monitoring backends factory
class MonitoringFactory
{
 public:
  /// Disables copy constructor
  MonitoringFactory& operator=(const MonitoringFactory&) = delete;
  MonitoringFactory(const MonitoringFactory&) = delete;

  /// Provides single instance on Monitoring Monitoring (singleton)
  /// \return              renerence to Monitoring instance
  /// \throw MonitoringException when backend initialisation failed
  static std::unique_ptr<Monitoring> Get(std::string urlsString) noexcept(false);

  /// Provides a Monitoring backend based on the URL
  /// \return		monitoring backend
  /// \throw MonitoringException when backend initialisation failed
  static std::unique_ptr<Backend> GetBackend(std::string& url);

 private:
  /// Private constructor disallows to create instance of Factory
  MonitoringFactory() = default;

  /// Sets backend verbosity based on the URL path
  static void SetVerbosity(std::string selected, std::unique_ptr<Backend>& backend);
};

} // namespace monitoring
} // namespace o2

#endif // ALICEO2_MONITORING_FACTORY_H
