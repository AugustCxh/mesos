/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TYPE_UTILS_HPP__
#define __TYPE_UTILS_HPP__

#include <boost/functional/hash.hpp>

#include <stout/uuid.hpp>

#include "common/attributes.hpp"

#include "messages/log.hpp"
#include "messages/messages.hpp"

// This file includes definitions for operators on protobuf classes
// that don't have these operators generated by the protobuf compiler.

namespace mesos {

bool operator == (const CommandInfo& left, const CommandInfo& right);
bool operator == (const CommandInfo::URI& left, const CommandInfo::URI& right);
bool operator == (const Credential& left, const Credential& right);
bool operator == (const Environment& left, const Environment& right);
bool operator == (const ExecutorInfo& left, const ExecutorInfo& right);
bool operator == (const MasterInfo& left, const MasterInfo& right);
bool operator == (const SlaveInfo& left, const SlaveInfo& right);
bool operator == (const Volume& left, const Volume& right);


inline bool operator == (const ContainerID& left, const ContainerID& right)
{
  return left.value() == right.value();
}


inline bool operator == (const ExecutorID& left, const ExecutorID& right)
{
  return left.value() == right.value();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const ContainerInfo& containerInfo)
{
  return stream << containerInfo.DebugString();
}


inline bool operator == (const FrameworkID& left, const FrameworkID& right)
{
  return left.value() == right.value();
}


inline bool operator == (const FrameworkInfo& left, const FrameworkInfo& right)
{
  return (left.name() == right.name()) && (left.user() == right.user());
}


inline bool operator == (const OfferID& left, const OfferID& right)
{
  return left.value() == right.value();
}


inline bool operator == (const SlaveID& left, const SlaveID& right)
{
  return left.value() == right.value();
}


inline bool operator == (const TaskID& left, const TaskID& right)
{
  return left.value() == right.value();
}


inline bool operator == (const ContainerID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator == (const ExecutorID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator == (const FrameworkID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator == (const OfferID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator == (const SlaveID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator == (const TaskID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator != (const ContainerID& left, const ContainerID& right)
{
  return left.value() != right.value();
}


inline bool operator < (const ContainerID& left, const ContainerID& right)
{
  return left.value() < right.value();
}


inline bool operator < (const ExecutorID& left, const ExecutorID& right)
{
  return left.value() < right.value();
}


inline bool operator < (const FrameworkID& left, const FrameworkID& right)
{
  return left.value() < right.value();
}


inline bool operator < (const OfferID& left, const OfferID& right)
{
  return left.value() < right.value();
}


inline bool operator < (const SlaveID& left, const SlaveID& right)
{
  return left.value() < right.value();
}


inline bool operator < (const TaskID& left, const TaskID& right)
{
  return left.value() < right.value();
}


inline std::size_t hash_value(const ContainerID& containerId)
{
  size_t seed = 0;
  boost::hash_combine(seed, containerId.value());
  return seed;
}


inline std::size_t hash_value(const ExecutorID& executorId)
{
  size_t seed = 0;
  boost::hash_combine(seed, executorId.value());
  return seed;
}


inline std::size_t hash_value(const FrameworkID& frameworkId)
{
  size_t seed = 0;
  boost::hash_combine(seed, frameworkId.value());
  return seed;
}


inline std::size_t hash_value(const OfferID& offerId)
{
  size_t seed = 0;
  boost::hash_combine(seed, offerId.value());
  return seed;
}


inline std::size_t hash_value(const SlaveID& slaveId)
{
  size_t seed = 0;
  boost::hash_combine(seed, slaveId.value());
  return seed;
}


inline std::size_t hash_value(const TaskID& taskId)
{
  size_t seed = 0;
  boost::hash_combine(seed, taskId.value());
  return seed;
}


inline std::ostream& operator << (
    std::ostream& stream,
    const ACLs& acls)
{
  return stream << acls.DebugString();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const ContainerID& containerId)
{
  return stream << containerId.value();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const ExecutorID& executorId)
{
  return stream << executorId.value();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const ExecutorInfo& executor)
{
  return stream << executor.DebugString();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const FrameworkID& frameworkId)
{
  return stream << frameworkId.value();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const MasterInfo& master)
{
  return stream << master.DebugString();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const OfferID& offerId)
{
  return stream << offerId.value();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const RateLimits& limits)
{
  return stream << limits.DebugString();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const SlaveID& slaveId)
{
  return stream << slaveId.value();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const SlaveInfo& slave)
{
  return stream << slave.DebugString();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const TaskID& taskId)
{
  return stream << taskId.value();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const TaskInfo& task)
{
  return stream << task.DebugString();
}


inline std::ostream& operator << (
    std::ostream& stream,
    const TaskState& state)
{
  return stream << TaskState_descriptor()->FindValueByNumber(state)->name();
}


namespace internal {

bool operator == (const Task& left, const Task& right);


inline std::ostream& operator << (
    std::ostream& stream,
    const Modules& modules)
{
  return stream << modules.DebugString();
}


std::ostream& operator << (
    std::ostream& stream,
    const StatusUpdate& update);


inline std::ostream& operator << (
    std::ostream& stream,
    const StatusUpdateRecord::Type& type)
{
  return stream
    << StatusUpdateRecord::Type_descriptor()->FindValueByNumber(type)->name();
}


namespace log {

inline std::ostream& operator << (
    std::ostream& stream,
    const Action::Type& type)
{
  return stream << Action::Type_Name(type);
}


inline std::ostream& operator << (
    std::ostream& stream,
    const Metadata::Status& status)
{
  return stream << Metadata::Status_Name(status);
}

} // namespace log {
} // namespace internal {
} // namespace mesos {

#endif // __TYPE_UTILS_HPP__
