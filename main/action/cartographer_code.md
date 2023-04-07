---
priority: 1st
status: active
url: 
category: 
parent: 
children: 
link_action: 
link_topic: 
link_project: "[Cleaning Robot](../project/Cleaning%20Robot.md)"
link_course: 
link_notes: 
link_knowledge: "[Cartographer_node](../knowledge/Cartographer_node.md)"
---

For convenience, different ways are used to represent different element in C++, the rule is made as below

 [C]: Class Name       [F]: Function Name         [S]: Struct Name

# Node [C]

## Publish
```cpp
// -- example of publisher and suscriber in ROS --
// publisher
ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
chatter_pub.publish(msg);
spinOnce();
// subsriber
ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
spin();
```

Except for scan_matched_point_cloud, the other 5 publishers below regularly advertise message of which the time is control by `ros::walltime`.  Given `submap_list_publisher` as an example:

```cpp
// push PublishSubmapList task into wall_timers_
(vector<ros::WallTimer>)wall_timers_.push_back(node_handle_.createWallTimer(
      ::ros::WallDuration(node_options_.submap_publish_period_sec),
      &Node::PublishSubmapList, this));
......
// add mutex lock in PublishSubmapList()
void Node::PublishSubmapList(const ::ros::WallTimerEvent& unused_timer_event) {
  absl::MutexLock lock(&mutex_);
  submap_list_publisher_.publish(map_builder_bridge_.GetSubmapList());
}
...
// Here is what the submap_list really does its job.
Map_builder_bridge.GetSubmapList(){
  submap_ist.header.stamp = time::now();
  for (each i = map_builder.SubmapPose){
    submap_list.push(i)
  }
  //? what is the purpose std::allocate<void>,  both submap_entry and submap_list use it
}
```

### publisher: `submap_list_publisher`    bound function: `PublishSubmapList`

Shown as above

### publisher: `trajectory_node_list_publisher`  bound function: `PublishTrajecotryNodeList`

```cpp
void Node::PublishTrajectoryNodeList(
    const ::ros::WallTimerEvent& unused_timer_event) {
  if (trajectory_node_list_publisher_.getNumSubscribers() > 0) {
    absl::MutexLock lock(&mutex_);
    trajectory_node_list_publisher_.publish(
        map_builder_bridge_.GetTrajectoryNodeList());
  }
}
...
visualization_msgs::MarkerArray MapBuilderBridge::GetTrajectoryNodeList(){
    const auto node_poses = map_builder_->pose_graph()->GetTrajectoryNodePoses();
    find the last node indices for each trajectory that have either inter-submap or inter-trajectory Constraint;
    visualization_msgs::MarkerArray trajectory_node_list;
    for each element in node_poses.trajectory_ids(){
        visualization_msgs::Marker marker;
        config marker;
        marker <- all nodes in current trajectory;
        trajectory_node_list.push_back(marker);
    }
    return trajectory_node_list;
}
```

### publisher: `landmark_posed_list_publisher`   bound function: `GetLandmarkPosesList`

```cpp
void Node::PublishLandmarkPosesList(
  const ::ros::WallTimerEvent& unused_timer_event) {
  if (landmark_poses_list_publisher_.getNumSubscribers() > 0) {
    absl::MutexLock lock(&mutex_);
    landmark_poses_list_publisher_.publish(
        map_builder_bridge_.GetLandmarkPosesList());
  }
}
...
visualization_msgs::MarkerArray MapBuilderBridge::GetLandmarkPosesList() {
  visualization_msgs::MarkerArray landmark_poses_list;
  const std::map<std::string, Rigid3d> landmark_poses =
      map_builder_->pose_graph()->GetLandmarkPoses();
  for (const auto& id_to_pose : landmark_poses) {
	    landmark_poses_list.markers.push_back(CreateLandmarkMarker(
        GetLandmarkIndex(id_to_pose.first, &landmark_to_index_),
        id_to_pose.second, node_options_.map_frame));
  }
  return landmark_poses_list;
}
```

### publisher: `constraint_list_publisher`   bound function: `GetConstraintList`

```cpp
void Node::PublishConstraintList(
	const ::ros::WallTimerEvent& unused_timer_event) {
	if (constraint_list_publisher_.getNumSubscribers() > 0) {
	  absl::MutexLock lock(&mutex_);
	  constraint_list_publisher_.publish(map_builder_bridge_.GetConstraintList());
	}
}
...
// the marker config for constraint is complicated than the others push marker into a MarkerArray then return the array
visualization_msgs::MarkerArray MapBuilderBridge::GetConstraintList() {
	const auto trajectory_node_poses =
  map_builder_->pose_graph()->GetTrajectoryNodePoses();
  const auto submap_poses = map_builder_->pose_graph()->GetAllSubmapPoses();
  const auto constraints = map_builder_->pose_graph()->constraints();
  visualization_msgs::MarkerArray constraint_list;
    for each constraint in constraints {
      landmark_poses_list.markers.push_back(CreateLandmarkMarker(
      GetLandmarkIndex(id_to_pose.first, &landmark_to_index_),
      id_to_pose.second, node_options_.map_frame));
        visualization_msgs::Marker constraint_marker, residual_maker;
        config marker;
        constraint_marker->colors.push_back(color_constraint)
        residual_marker->colors.push_back(color_residual);;
        constraint_list.push_back(marker);
  }
  return constraint_list;
}
```

### publisher:  `tracked_pose_publisher_`  bound function: `PublishLocalTrajectoryData`

```cpp
void Node::PublishLocalTrajectoryData(const ::ros::TimerEvent& timer_event) {
  absl::MutexLock lock(&mutex_);
  for each in LocalTrajectoryData in map_builder_bridge_.GetLocalTrajectoryData() {
    const auto& trajectory_data = entry.second;

    auto& extrapolator = extrapolators_.at(entry.first);

    check if a point cloud is changed;
    // publish a point cloud if it has changed
    //? how the time works in here
    (TimePointCould)point_cloud <- {range_data.returns, (f_time)0.f};
    // during conversion each point is transformed from local to map.
    convert point_cloud into PointCloud2 message;
    extrapolator.AddPose(trajectory_data.local_slam_data->time,
                      trajectory_data.local_slam_data->local_pose);

    //--------------------------------------------------
    To be continue with 

    geometry_msgs::TransformStamped stamped_transform;
    //--------------------------------------------------

}
...
std::unordered_map<int, MapBuilderBridge::LocalTrajectoryData>
MMap_builder_bridge.GetLocalTrajectoryData(){
    std::unordered_map<int, LocalTrajectoryData> local_trajectory_data;
    for each entry in (map)sensor_bridges{
        const int trajectory_id = entry.first;
        const SensorBridge& sensor_bridge = *entry.second;    
        (shared_ptr)local_slam_data = local_slam_data_.at(trajectory_id);
        local_trajectory_data[trajectory_id] <- {local_slam_data, GetLocalToGlobalTransform(trajectory_id), tf_bridge().LookupToTracking()}
    }
    return local_trajectory_date;
}
```

## Service

```cpp
// -- example of Server and Client in ROS --
// server
ros::ServiceServer service = n.advertiseService("add_two_ints", callback);
spin();
// client
ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
client.call(srv)
1. ```

Given `kSubmapQueryService` as an example:

```cpp
std::vector<::ros::ServiceServer> service_servers_;
...
service_servers_.push_back(node_handle_.advertiseService(
      kSubmapQueryServiceName, &Node::HandleSubmapQuery, this));
1. ...
bool Node::HandleSubmapQuery(
    ::cartographer_ros_msgs::SubmapQuery::Request& request,
    ::cartographer_ros_msgs::SubmapQuery::Response& response) {
  absl::MutexLock loSince tf knows how to interpolate,ck(&mutex_);
  map_builder_bridge_.HandleSubmapQuery(request, response);
  return true;
}
...
void MapBuilderBridge::HandleSubmapQuery(
    cartographer_ros_msgs::SubmapQuery::Request& request,
    cartographer_ros_msgs::SubmapQuery::Response& response) {
  cartographer::mapping::proto::SubmapQuery::Response response_proto;
  cartographer::mapping::SubmapId submap_id{request.trajectory_id,
                                            request.submap_index};
  const std::string error =  map_builder_->SubmapToProto(submap_id, &response_proto);
  
  If (error from proto exist)) return;
  for each texture_pro in response_proto.textures(){
    response.texture <- response_protp.texture;
  }
  response.status <- OK;
  response.submap_version = response_proto.submap_version();
}

```

### service: `kSubmapQueryService`, callback: `HandleSubmapQuery`

Shown as above

### service: `kTrajectoryQueryService`, callback:  `HandleTrajectoryQuery`

```cpp
bool Node::HandleTrajectoryQuery(
    ::cartographer_ros_msgs::TrajectoryQuery::Request& request,
    ::cartographer_ros_msgs::TrajectoryQuery::Response& response) {
  absl::MutexLock lock(&mutex_);
  check if request.trajectory is available;
  map_builder_bridge_.HandleTrajectoryQuery(request, response);
  return true;
}
...
void MapBuilderBridge::HandleTrajectoryQuery(
    cartographer_ros_msgs::TrajectoryQuery::Request& request,
    cartographer_ros_msgs::TrajectoryQuery::Response& response) {
  // This query is safe if the trajectory doesn't exist (returns 0 poses).
  // However, we can filter unwanted states at the higher level in the node.
  const auto node_poses = map_builder_->pose_graph()->GetTrajectoryNodePoses();
  for (const auto& node_id_data :
       node_poses.trajectory(request.trajectory_id)) {
    if (!node_id_data.data.constant_pose_data.has_value()) {
      continue;
    }
    geometry_msgs::PoseStamped pose_stamped;
    pose_stamped.header.frame_id = node_options_.map_frame;
    pose_stamped.header.stamp =
        ToRos(node_id_data.data.constant_pose_data.value().time);
    pose_stamped.pose = ToGeometryMsgPose(node_id_data.data.global_pose);
    response.trajectory.push_back(pose_stamped);
  }
  response.status.code = cartographer_ros_msgs::StatusCode::OK;
  response.status.message = absl::StrCat(
      "Retrieved ", response.trajectory.size(),
      " trajectory nodes from trajectory ", request.trajectory_id, ".");
}
...
// Map_Builder is inherited from Map_BUilder_interface
map_builder_->pose_graph(){
  // Returns a pointer <unique_ptr> to the managed object of PoseGraph
  // The pointer type is depend on PoseGraph_2d or PosGraph_3d
  (overide)pose_graph_.get(); 

  (plus)FromProto();

  //return a map<int (tra_num), enum (tra_sta)> imported from PoseGraphData 
  //? where is PoseGraphData
  GetTrajectoryStates();
}
```

### service: `kStartTrajectoryService`, callback: `HandleStartTrajectory`

```cpp
bool Node::HandleStartTrajectory(
    ::cartographer_ros_msgs::StartTrajectory::Request& request,
    ::cartographer_ros_msgs::StartTrajectory::Response& response) {
  TrajectoryOptions trajectory_options;
  std::tie(std::ignore, trajectory_options) = LoadOptions(
      request.configuration_directory, request.configuration_basename);

  if (request.use_initial_pose) {
    check validation of request.initial_pose and request.TrajectoryStateToStatus;
    ::cartographer::mapping::proto::InitialTrajectoryPose
        initial_trajectory_pose;
    initial_trajectory_pose.set_to_trajectory_id(
        request.relative_to_trajectory_id);
    *initiael_trajectory_pose.mutable_relative_pose() =
        cartographer::transform::ToProto(pose);
    initial_trajectory_pose.set_timestamp(cartographer::common::ToUniversal(
        ::cartographer_ros::FromRos(ros::Time(0))));
    *trajectory_options.trajectory_builder_options
         .mutable_initial_trajectory_pose() = initial_trajectory_pose;
  }
  if (!ValidateTrajectoryOptions(trajctory_options)) {
    response.status.message = "Invalid trajectory options.";
    LOG(ERROR) << response.status.message;
    response.status.code = cartographer_ros_msgs::StatusCode::INVALID_ARGUMENT;
  } else if (!ValidateTopicNames(trajectory_options)) {
    response.status.message = "Topics are already used by another trajectory.";
    LOG(ERROR) << response.status.message;
    response.status.code = cartographer_ros_msgs::StatusCode::INVALID_ARGUMENT;
  } else {
    response.status.message = "Success.";
    response.trajectory_id = AddTrajectory(trajectory_options);
    response.status.code = cartographer_ros_msgs::StatusCode::OK;
  }
  return true;
}
```

### service: `kFinishTrajectoryService`, callback: `HandleFinishTrajectory`

```cpp
bool Node::HandleFinishTrajectory(
    ::cartographer_ros_msgs::FinishTrajectory::Request& request,
    ::cartographer_ros_msgs::FinishTrajectory::Response& response) {
  absl::MutexLock lock(&mutex_);
  response.status = FinishTrajectoryUnderLock(request.trajectory_id);
  return true;
}
...
cartographer_ros_msgs::StatusResponse Node::FinishTrajectoryUnderLock(
    const int trajectory_id) {
  check if we can actually finish the trajectory.
  
  // Shutdown the subscribers of this trajectory.
  // A valid case with no subscribers is e.g. if we just visualize states.
  if (subscribers_.count(trajectory_id)) {
    for (auto& entry : subscribers_[trajectory_id]) {
      entry.subscriber.shutdown();
      subscribed_topics_.erase(entry.topic);
      LOG(INFO) << "Shutdown the subscriber of [" << entry.topic << "]";
    }
    CHECK_EQ(subscribers_.erase(trajectory_id), 1);
  }
  map_builder_bridge_.FinishTrajectory(trajectory_id);
  trajectories_scheduled_for_finish_.emplace(trajectory_id);
  status_response.message =
      absl::StrCat("Finished trajectory ", trajectory_id, ".");
  status_response.code = cartographer_ros_msgs::StatusCode::OK;
  return status_response;
}
...
void MapBuilderBridge::FinishTrajectory(const int trajectory_id) {
  LOG(INFO) << "Finishing trajectory with ID '" << trajectory_id << "'...";

  // Make sure there is a trajectory with 'trajectory_id'.
  CHECK(GetTrajectoryStates().count(trajectory_id));
  map_builder_->FinishTrajectory(trajectory_id);
  sensor_bridges_.erase(trajectory_id);
}
...
void MapBuilder::FinishTrajectory(const int trajectory_id) {
  sensor_collator_->FinishTrajectory(trajectory_id);
  pose_graph_->FinishTrajectory(trajectory_id);
}
...
// pose_graph_ type is bound automatically
void PoseGraph2D::FinishTrajectory(const int trajectory_id) {
	  AddWorkItem([this, trajectory_id]() LOCKS_EXCLUDED(mutex_) {
    absl::MutexLock locker(&mutex_);
    CHECK(!IsTrajectoryFinished(trajectory_id));
    data_.trajectories_state[trajectory_id].state = TrajectoryState::FINISHED;

    for (const auto& submap : data_.submap_data.trajectory(trajectory_id)) {
      data_.submap_data.at(submap.id).state = SubmapState::kFinished;
    }
    return WorkItem::Result::kRunOptimization;
  });
}
```

### service: `kWriteStateService`, callback: `HandleWriteState`

```cpp
bool Node::HandleWriteState(
    ::cartographer_ros_msgs::WriteState::Request& request,
    ::cartographer_ros_msgs::WriteState::Response& response) {
  absl::MutexLock lock(&mutex_);
  if (map_builder_bridge_.SerializeState(request.filename,
                                         request.include_unfinished_submaps)) {
    response.status.code = cartographer_ros_msgs::StatusCode::OK;
    response.status.message =
        absl::StrCat("State written to '", request.filename, "'.");
  } else {
    response.status.code = cartographer_ros_msgs::StatusCode::INVALID_ARGUMENT;
    response.status.message =
        absl::StrCat("Failed to write '", request.filename, "'.");
  }
  return true;
}
...
void MapBuilder::SerializeState(bool include_unfinished_submaps,
                                io::ProtoStreamWriterInterface* const writer) {
  io::WritePbStream(*pose_graph_, all_trajectory_builder_options_, writer,
                    include_unfinished_submaps);
}
```

### service: `kGetTrajectoryStatesService`, callback: `HandleGetTrajectoryStates`

```cpp
bool Node::HandleGetTrajectoryStates(
    ::cartographer_ros_msgs::GetTrajectoryStates::Request& request,
    ::cartographer_ros_msgs::GetTrajectoryStates::Response& response) {
  using TrajectoryState =
      ::cartographer::mapping::PoseGraphInterface::TrajectoryState;
  absl::MutexLock lock(&mutex_);
  response.status.code = ::cartographer_ros_msgs::StatusCode::OK;
  response.trajectory_states.header.stamp = ros::Time::now();
  for (const auto& entry : map_builder_bridge_.GetTrajectoryStates()) {
    response.trajectory_states.trajectory_id.push_back(entry.first);
    switch (entry.second) {
      case TrajectoryState::ACTIVE:
        response.trajectory_states.trajectory_state.push_back(
            ::cartographer_ros_msgs::TrajectoryStates::ACTIVE);
        break;
      case TrajectoryState::FINISHED:
        response.trajectory_states.trajectory_state.push_back(
            ::cartographer_ros_msgs::TrajectoryStates::FINISHED);
        break;
      case TrajectoryState::FROZEN:
        response.trajectory_states.trajectory_state.push_back(
            ::cartographer_ros_msgs::TrajectoryStates::FROZEN);
        break;
      case TrajectoryState::DELETED:
        response.trajectory_states.trajectory_state.push_back(
            ::cartographer_ros_msgs::TrajectoryStates::DELETED);
        break;
    }
  }
  return true;
}
```

### service: `kReadMetricsService`, callback: `HandleReadMetrics`

```cpp
//? what metric has
bool Node::HandleReadMetrics(
    ::cartographer_ros_msgs::ReadMetrics::Request& request,
    ::cartographer_ros_msgs::ReadMetrics::Response& response) {
  absl::MutexLock lock(&mutex_);
  response.timestamp = ros::Time::now();
  if (!metrics_registry_) {
    response.status.code = cartographer_ros_msgs::StatusCode::UNAVAILABLE;
    response.status.message = "Collection of runtime metrics is not activated.";
    return true;
  }
  metrics_registry_->ReadMetrics(&response);
  response.status.code = cartographer_ros_msgs::StatusCode::OK;
  response.status.message = "Successfully read metrics.";
  return true;
}
```

## Key functions

### AddTrajectory

```cpp
int Node::AddTrajectory(const TrajectoryOptions& options) {
	// get what sensors you have
  const std::set<cartographer::mapping::TrajectoryBuilderInterface::SensorId>
      expected_sensor_ids = ComputeExpectedSensorIds(options);
	// create a trajectory, return the new trajecotry id
  const int trajectory_id =
      map_builder_bridge_.AddTrajectory(expected_sensor_ids, options);
	//? how to use it
  AddExtrapolator(trajectory_id, options);
	//? why need a sampler
  AddSensorSamplers(trajectory_id, options);
	// 
  LaunchSubscribers(options, trajectory_id);

  //? why push_back MaybeWarnAboutTopicMismatch in each AddTrajectory
  wall_timers_.push_back(node_handle_.createWallTimer(
      ::ros::WallDuration(kTopicMismatchCheckDelaySec),
      &Node::MaybeWarnAboutTopicMismatch, this, /*oneshot=*/true));
  for (const auto& sensor_id : expected_sensor_ids) {
    subscribed_topics_.insert(sensor_id.id);
  }
  return trajectory_id;
}
...
std::set<cartographer::mapping::TrajectoryBuilderInterface::SensorId>
Node::ComputeExpectedSensorIds(const TrajectoryOptions& options) const {
   std::set<SensorId> expected_topics;
   list all sensors used and combined multiple topics from same-typed sensors, then push it into expected_topics;
   return expected_topics;
}
... 
int MapBuilderBridge::AddTrajectory(
    const std::set<cartographer::mapping::TrajectoryBuilderInterface::SensorId>&
        expected_sensor_ids,
		    const TrajectoryOptions& trajectory_options) {

		const int trajectory_id = map_builder_->AddTrajectoryBuilder(
      expected_sensor_ids, trajectory_options.trajectory_builder_options,
			// 'this' is catch range in lambda function. it is a callback function address
      [this](const int trajectory_id, const ::cartographer::common::Time time,
             const Rigid3d local_pose,
             ::cartographer::sensor::RangeData range_data_in_local,
             const std::unique_ptr<
                 const ::cartographer::mapping::TrajectoryBuilderInterface::
                     InsertionResult>) {
        OnLocalSlamResult(trajectory_id, time, local_pose, range_data_in_local);
      });

			configure sensor_bridges_[trajectory_id];
}
...
// create a sampler with parameters configured according to `TrajectoryOptions`
void Node::AddSensorSamplers(const int trajectory_id,
                             const TrajectoryOptions& options) {
  CHECK(sensor_samplers_.count(trajectory_id) == 0);
  //* std::piecewise_construct is used to auto convert tuple into map element type
  sensor_samplers_.emplace(
      std::piecewise_construct, std::forward_as_tuple(trajectory_id),
      std::forward_as_tuple(
          options.rangefinder_sampling_ratio, options.odometry_sampling_ratio,
          options.fixed_frame_pose_sampling_ratio, options.imu_sampling_ratio,
          options.landmarks_sampling_ratio));
}
...
void Node::AddExtrapolator(const int trajectory_id,
                           const TrajectoryOptions& options) {
  //? what if the ExtrapolationEstimationTimeSec is assigned with other value
  constexpr double kExtrapolationEstimationTimeSec = 0.001;  // 1 ms
  CHECK(extrapolators_.count(trajectory_id) == 0);
  //? what is the value of gravity_time_constant in 3d setting
  //* map_builder_options is a class with data members defined by .proto file
  const double gravity_time_constant =
      node_options_.map_builder_options.use_trajectory_builder_3d()
          ? options.trajectory_builder_options.trajectory_builder_3d_options()
                .imu_gravity_time_constant()
          : options.trajectory_builder_options.trajectory_builder_2d_options()
                .imu_gravity_time_constant();
	// std::map<int, ::cartographer::mapping::PoseExtrapolator> extrapolators_
  extrapolators_.emplace(
      std::piecewise_construct, std::forward_as_tuple(trajectory_id),
      std::forward_as_tuple(
          ::cartographer::common::FromSeconds(kExtrapolationEstimationTimeSec),
          gravity_time_constant));
}
```

### LaunchSubscribers

```cpp
void Node::LaunchSubscribers(const TrajectoryOptions& options,
                             const int trajectory_id) { 
    // e.g. if you have two laser scanners, ComputeRepeatedTopicNames() returns {scan_0, scan_1}
  for (const std::string& topic :
       ComputeRepeatedTopicNames(kLaserScanTopic, options.num_laser_scans)) {
    //  std::unordered_map<int, std::vector<Subscriber>> subscribers_;
    // create a subscriber to laserscan and push it to subscribers_[trajectory_id]
    subscribers_[trajectory_id].push_back(
        {SubscribeWithHandler<sensor_msgs::LaserScan>(
             &Node::HandleLaserScanMessage, trajectory_id, topic, &node_handle_,
             this),
         topic});
  }

  same operation for EchoLaserScan as LaserScan, with &Node::HandleMultiEchoLaserScanMessage;
  same operation for PointCloud2 LaserScan, with &Node::HandlePointCloud2Message;

  // For 2D SLAM, subscribe to the IMU if we expect it. For 3D SLAM, the IMU is
  // required.
  if (node_options_.map_builder_options.use_trajectory_builder_3d() ||
      (node_options_.map_builder_options.use_trajectory_builder_2d() &&
       options.trajectory_builder_options.trajectory_builder_2d_options()
           .use_imu_data())) {
        same operation for EchoLaserScan as LaserScan, with &Node::HandleImuMessage;
  }

  if (options.use_odometry) {
    same operation for EchoLaserScan as LaserScan, with &Node::HandleOdometryMessage;
  }
  if (options.use_nav_sat) {
    same operation for EchoLaserScan as LaserScan, with &Node::HandleNavSatFixMessage;
  }
  if (options.use_landmarks) {
    same operation for EchoLaserScan as LaserScan, with &Node::HandleLandmarkMessage;
  }
}
...
template <typename MessageType>
::ros::Subscriber SubscribeWithHandler(
    void (Node::*handler)(int, const std::string&,
                          const typename MessageType::ConstPtr&),
    const int trajectory_id, const std::string& topic,
    ::ros::NodeHandle* const node_handle, Node* const node) {
  return node_handle->subscribe<MessageType>(
      topic, kInfiniteSubscriberQueueSize,
      boost::function<void(const typename MessageType::ConstPtr&)>(
          [node, handler, trajectory_id,
           topic](const typename MessageType::ConstPtr& msg) {
            (node->*handler)(trajectory_id, topic, msg);
          }));
}
...
std::vector<std::string> ComputeRepeatedTopicNames(const std::string& topic,
                                                   const int num_topics) {
  CHECK_GE(num_topics, 0);
  if (num_topics == 1) {
    return {topic};
  }
  std::vector<std::string> topics;
  topics.reserve(num_topics);
  for (int i = 0; i < num_topics; ++i) {
    topics.emplace_back(topic + "_" + std::to_string(i + 1));
  }
  return topics;
}} 
...
void Node::HandleLaserScanMessage(const int trajectory_id,
                                  const std::string& sensor_id,
                                  const sensor_msgs::LaserScan::ConstPtr& msg) {
  absl::MutexLock lock(&mutex_);
  if (!sensor_samplers_.at(trajectory_id).rangefinder_sampler.Pulse()) {
    return;
  }
  map_builder_bridge_.sensor_bridge(trajectory_id)
      ->HandleLaserScanMessage(sensor_id, msg);
}
```

# SensorBridge [C]

[ ] #Ques  It is true?: Converts ROS messages into SensorData in tracking frame for the MapBuilder.

```cpp
SensorBridge
{
public:
    // In between, 
    // HandleLaserScanMessage, HandleMultiEchoLaserScanMessage
    // ---> HandleLaserScan
    // ---> HandleRangefinder
    // HandlePointCloud2Message
    // ---> HandleRangefinder
    message handlers;
private:
    void HandleLaserScan(
        const std::string& sensor_id, ::cartographer::common::Time start_time,
        const std::string& frame_id,
        const ::cartographer::sensor::PointCloudWithIntensities& points);
    void HandleRangefinder(const std::string& sensor_id,
                            ::cartographer::common::Time time,
                            const std::string& frame_id,
                            const ::cartographer::sensor::TimedPointCloud& ranges);

    const int num_subdivisions_per_laser_scan_;
    std::map<std::string, cartographer::common::Time>
        sensor_to_previous_subdivision_time_;
    const TfBridge tf_bridge_;
    ::cartographer::mapping::TrajectoryBuilderInterface* const
        trajectory_builder_;

    absl::optional<::cartographer::transform::Rigid3d> ecef_to_local_frame_;
}
...
void SensorBridge::HandleLaserScanMessage(
    const std::string& sensor_id, const sensor_msgs::LaserScan::ConstPtr& msg) {
  carto::sensor::PointCloudWithIntensities point_cloud;
  carto::common::Time time;
  std::tie(point_cloud, time) = ToPointCloudWithIntensities(*msg);
  HandleLaserScan(sensor_id, time, msg->header.frame_id, point_cloud);
}
...
// separate a PointCloudWithIntensities into several TimedPointClouds
void SensorBridge::HandleLaserScan(
    const std::string& sensor_id, const carto::common::Time time,
    const std::string& frame_id,
    const carto::sensor::PointCloudWithIntensities& points) {
  if (points.points.empty()) {
    return;
  }
  CHECK_LE(points.points.back().time, 0.f);
  // TODO(gaschler): Use per-point time instead of subdivisions.
  for (int i = 0; i != num_subdivisions_per_laser_scan_; ++i) {
    const size_t start_index =
        points.points.size() * i / num_subdivisions_per_laser_scan_;
    const size_t end_index =
        points.points.size() * (i + 1) / num_subdivisions_per_laser_scan_;
    //? why vector<int> v()
    //? why subdivision gets time
    carto::sensor::TimedPointCloud subdivision(
        points.points.begin() + start_index, points.points.begin() + end_index);
    if (start_index == end_index) {
      continue;
    }
    const double time_to_subdivision_end = subdivision.back().time;
    // `subdivision_time` is the end of the measurement so sensor::Collator will
    // send all other sensor data first.
    const carto::common::Time subdivision_time =
        time + carto::common::FromSeconds(time_to_subdivision_end);
    auto it = sensor_to_previous_subdivision_time_.find(sensor_id);
    if (it != sensor_to_previous_subdivision_time_.end() &&
        it->second >= subdivision_time) {
      LOG(WARNING) << "Ignored subdivision of a LaserScan message from sensor "
                   << sensor_id << " because previous subdivision time "
                   << it->second << " is not before current subdivision time "
                   << subdivision_time;
      continue;
    }
    sensor_to_previous_subdivision_time_[sensor_id] = subdivision_time;
    for (auto& point : subdivision) {
      point.time -= time_to_subdivision_end;
    }
    CHECK_EQ(subdivision.back().time, 0.f);
    HandleRangefinder(sensor_id, subdivision_time, frame_id, subdivision);
  }
}
...
void SensorBridge::HandleRangefinder(
    const std::string& sensor_id, const carto::common::Time time,
    const std::string& frame_id, const carto::sensor::TimedPointCloud& ranges) {
  if (!ranges.empty()) {
    CHECK_LE(ranges.back().time, 0.f);
  }
  // std::unique_ptr<::cartographer::transform::Rigid3d> TfBridge::LookupToTracking
  const auto sensor_to_tracking =
      tf_bridge_.LookupToTracking(time, CheckNoLeadingSlash(frame_id));
  if (sensor_to_tracking != nullptr) {
    trajectory_builder_->AddSensorData(
        sensor_id, carto::sensor::TimedPointCloudData{
                       time, sensor_to_tracking->translation().cast<float>(),
                       carto::sensor::TransformTimedPointCloud(
                           ranges, sensor_to_tracking->cast<float>())});
  }
}
... 
std::unique_ptr<::cartographer::transform::Rigid3d> TfBridge::LookupToTracking(
    const ::cartographer::common::Time time,
    const std::string& frame_id) const {
  ::ros::Duration timeout(lookup_transform_timeout_sec_);
  std::unique_ptr<::cartographer::transform::Rigid3d> frame_id_to_tracking;
  try {
    const ::ros::Time latest_tf_time =
        buffer_
            ->lookupTransform(tracking_frame_, frame_id, ::ros::Time(0.),
                              timeout)
            .header.stamp;
    const ::ros::Time requested_time = ToRos(time);
    if (latest_tf_time >= requested_time) {
      // We already have newer data, so we do not wait. Otherwise, we would wait
      // for the full 'timeout' even if we ask for data that is too old.
      timeout = ::ros::Duration(0.);
    }
    return absl::make_unique<::cartographer::transform::Rigid3d>(
        ToRigid3d(buffer_->lookupTransform(tracking_frame_, frame_id,
                                           requested_time, timeout)));
  } catch (const tf2::TransformException& ex) {
    LOG(WARNING) << ex.what();
  }
  return nullptr;
}
... 
... cartographer::mapping::TrajectoryBUilderInterface
... overload function, e.g. Imu_data
void AddSensorData(const std::string& sensor_id,
                    const sensor::ImuData& imu_data) override {
if (local_trajectory_builder_) {
    local_trajectory_builder_->AddImuData(imu_data);
}
pose_graph_->AddImuData(trajectory_id_, imu_data);
}
void AddSensorData(
      const std::string& sensor_id,
      const sensor::TimedPointCloudData& timed_point_cloud_data) override {
    CHECK(local_trajectory_builder_)
        << "Cannot add TimedPointCloudData without a LocalTrajectoryBuilder.";
    std::unique_ptr<typename LocalTrajectoryBuilder::MatchingResult>
        matching_result = local_trajectory_builder_->AddRangeData(
            sensor_id, timed_point_cloud_data);
    if (matching_result == nullptr) {
      // The range data has not been fully accumulated yet.
      return;
    }
    kLocalSlamMatchingResults->Increment();
    std::unique_ptr<InsertionResult> insertion_result;
    if (matching_result->insertion_result != nullptr) {
      kLocalSlamInsertionResults->Increment();
      auto node_id = pose_graph_->AddNode(
          matching_result->insertion_result->constant_data, trajectory_id_,
          matching_result->insertion_result->insertion_submaps);
      CHECK_EQ(node_id.trajectory_id, trajectory_id_);
      insertion_result = absl::make_unique<InsertionResult>(InsertionResult{
          node_id, matching_result->insertion_result->constant_data,
          std::vector<std::shared_ptr<const Submap>>(
              matching_result->insertion_result->insertion_submaps.begin(),
              matching_result->insertion_result->insertion_submaps.end())});
    }
    if (local_slam_result_callback_) {
      local_slam_result_callback_(
          trajectory_id_, matching_result->time, matching_result->local_pose,
          std::move(matching_result->range_data_in_local),
          std::move(insertion_result));
    }
  }
```

# TFBridge [C]

```cpp
class TfBridge {
 public:
  TfBridge(const std::string& tracking_frame,
           double lookup_transform_timeout_sec, const tf2_ros::Buffer* buffer);
  ~TfBridge() {}

  TfBridge(const TfBridge&) = delete;
  TfBridge& operator=(const TfBridge&) = delete;

  // Returns the transform for 'frame_id' to 'tracking_frame_' if it exists at
  // 'time'.
  std::unique_ptr<::cartographer::transform::Rigid3d> LookupToTracking(
      ::cartographer::common::Time time, const std::string& frame_id) const;

 private:
  const std::string tracking_frame_;
  const double lookup_transform_timeout_sec_;
  const tf2_ros::Buffer* const buffer_;
};
```

# PointCloud [C]

```cpp
class PointCloud {
 public:
    //struct RangefinderPoint {
    //  Eigen::Vector3f position;
    //};
    using PointType = RangefinderPoint;

    PointCloud();
    explicit PointCloud(std::vector<PointType> points);
    PointCloud(std::vector<PointType> points, std::vector<float> intensities);
  }

 private:
    // For 2D points, the third entry is 0.f.
    std::vector<PointType> points_;
    // Intensities are optional. If non-empty, they must have the same size as
    // points.
    std::vector<float> intensities_;
};
```

# TimePointCloud [V]

```cpp
// Stores 3D positions of points with their relative measurement time in the
// fourth entry. Time is in seconds, increasing and relative to the moment when
// the last point was acquired. So, the fourth entry for the last point is 0.f.
// If timing is not available, all fourth entries are 0.f. For 2D points, the
// third entry is 0.f (and the fourth entry is time).
using TimePointCloud = std::vector<TimedRangefinferPoint>
// TODO(wohe): Retained for cartographer_ros. To be removed once it is no
// longer used there.
struct PointCloudWithIntensities {
  TimedPointCloud points;
  std::vector<float> intensities;
};
... cartographer::sensor::rangedinfer_point ...
```

# PoseGraphInterface [C]

```markdown
[S] Constraint  : 
		//? how to get zbar_ij
    Pose(zbar_ij, t&r weight),
    landmarkNode,
    summap_id, 
    node_id, 
    pose, 
    tag(intra_ or inter_ summap) 
[S] SumMapPose:
    version
    pose
[S] SummapData  : 
    summap(share_ptr)
    pose
[S] TractoryData:
    gravity_constant (default is 9.8)
    imu_calibration (default is {1., 0., 0., 0.})
    fixed_frame_origin_in_map
```
