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

#ifndef __MESOS_DOCKER_PATHS_HPP__
#define __MESOS_DOCKER_PATHS_HPP__

#include <list>
#include <string>

#include <mesos/mesos.hpp>

namespace mesos {
namespace internal {
namespace slave {
namespace docker {
namespace paths {

/**
 * The Docker store file system layout is as follows:
 * Image store dir ('--docker_store_dir' slave flag)
 *    |--staging (contains temp directories for downloads and extract)
 *    |--layers
 *       |--<layer_id>
 *           |--rootfs
 *    |--rootfses
 *    |--storedImages (file holding on cached images)
 */

std::string getStagingDir(const std::string& storeDir);

std::string getTempStaging(const std::string& storeDir);

std::string getLocalImageTarPath(
    const std::string& discoveryDir,
    const std::string& name);

std::string getLocalImageRepositoriesPath(const std::string& staging);

std::string getLocalImageLayerPath(
    const std::string& staging,
    const std::string& layerId);

std::string getLocalImageLayerManifestPath(
    const std::string& staging,
    const std::string& layerId);

std::string getLocalImageLayerTarPath(
  const std::string& staging,
  const std::string& layerId);

std::string getLocalImageLayerRootfsPath(
  const std::string& staging,
  const std::string& layerId);

std::string getImageLayerPath(
    const std::string& storeDir,
    const std::string& layerId);

std::string getImageLayerRootfsPath(
    const std::string& storeDir,
    const std::string& layerId);

std::string getStoredImagesPath(const std::string& storeDir);

} // namespace paths {
} // namespace docker {
} // namespace slave {
} // namespace internal {
} // namespace mesos {

#endif // __MESOS_DOCKER_PATHS_HPP__
