/*
 * Copyright (C) 2020 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This project is dual licensed under LGPL v2.1+ or Apache License.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SCENARIO_PLUGINS_GAZEBO_CONTROLLERRUNNER_H
#define SCENARIO_PLUGINS_GAZEBO_CONTROLLERRUNNER_H

#include <gz/sim/Entity.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/EventManager.hh>
#include <gz/sim/System.hh>
#include <sdf/Element.hh>

#include <memory>

namespace scenario::plugins::gazebo {
    class ControllerRunner;
} // namespace scenario::plugins::gazebo

class scenario::plugins::gazebo::ControllerRunner final
    : public gz::sim::System
    , public gz::sim::ISystemConfigure
    , public gz::sim::ISystemPreUpdate
{
public:
    ControllerRunner();
    ~ControllerRunner() override;

    void Configure(const gz::sim::Entity& entity,
                   const std::shared_ptr<const sdf::Element>& sdf,
                   gz::sim::EntityComponentManager& ecm,
                   gz::sim::EventManager& eventMgr) override;

    void PreUpdate(const gz::sim::UpdateInfo& info,
                   gz::sim::EntityComponentManager& ecm) override;

private:
    class Impl;
    std::unique_ptr<Impl> pImpl = nullptr;
};

#endif // SCENARIO_PLUGINS_GAZEBO_CONTROLLERRUNNER_H
