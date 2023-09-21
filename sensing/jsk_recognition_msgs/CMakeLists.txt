cmake_minimum_required(VERSION 3.5)
project(jsk_recognition_msgs)

# Find ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(pcl_msgs REQUIRED)
find_package(jsk_footstep_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files
  "msg/Accuracy.msg"
  "msg/BoundingBoxArray.msg"
  "msg/BoundingBoxMovement.msg"
  "msg/BoundingBox.msg"
  "msg/BoundingBoxArrayWithCameraInfo.msg"
  "msg/Circle2DArray.msg"
  "msg/Circle2D.msg"
  "msg/ClassificationResult.msg"
  "msg/ClipResult.msg"
  "msg/ClusterPointIndices.msg"
  "msg/ColorHistogramArray.msg"
  "msg/ColorHistogram.msg"
  "msg/DepthCalibrationParameter.msg"
  "msg/DepthErrorResult.msg"
  "msg/ExifTags.msg"
  "msg/ExifGPSInfo.msg"
  "msg/HeightmapConfig.msg"
  "msg/Histogram.msg"
  "msg/HistogramWithRangeBin.msg"
  "msg/HistogramWithRange.msg"
  "msg/HistogramWithRangeArray.msg"
  "msg/HumanSkeleton.msg"
  "msg/HumanSkeletonArray.msg"
  "msg/ICPResult.msg"
  "msg/ImageDifferenceValue.msg"
  "msg/Int32Stamped.msg"
  "msg/Label.msg"
  "msg/LabelArray.msg"
  "msg/LineArray.msg"
  "msg/Line.msg"
  "msg/ModelCoefficientsArray.msg"
  "msg/Object.msg"
  "msg/ObjectArray.msg"
  "msg/PanoramaInfo.msg"
  "msg/ParallelEdgeArray.msg"
  "msg/ParallelEdge.msg"
  "msg/PlotData.msg"
  "msg/PointsArray.msg"
  "msg/PolygonArray.msg"
  "msg/PosedCameraInfo.msg"
  "msg/QueryAndProbability.msg"
  "msg/QuestionAndAnswerText.msg"
  "msg/RectArray.msg"
  "msg/Rect.msg"
  "msg/RotatedRect.msg"
  "msg/RotatedRectStamped.msg"
  "msg/SimpleHandle.msg"
  "msg/SimpleOccupancyGridArray.msg"
  "msg/SimpleOccupancyGrid.msg"
  "msg/SlicedPointCloud.msg"
  "msg/SnapItRequest.msg"
  "msg/SparseImage.msg"
  "msg/SparseOccupancyGridArray.msg"
  "msg/SparseOccupancyGridCell.msg"
  "msg/SparseOccupancyGridColumn.msg"
  "msg/SparseOccupancyGrid.msg"
  "msg/Spectrum.msg"
  "msg/TimeRange.msg"
  "msg/TorusArray.msg"
  "msg/Torus.msg"
  "msg/TrackerStatus.msg"
  "msg/TrackingStatus.msg"
  "msg/BoolStamped.msg"
  "msg/VectorArray.msg"
  "msg/VQAResult.msg"
  "msg/WeightedPoseArray.msg"
  "msg/ContactSensor.msg"
  "msg/ContactSensorArray.msg"
  "msg/PlotDataArray.msg"
  "msg/Segment.msg"
  "msg/SegmentStamped.msg"
  "msg/SegmentArray.msg"
  "msg/PeoplePose.msg"
  "msg/PeoplePoseArray.msg"
  "msg/HandPose.msg"
  "msg/HandPoseArray.msg"
)

set(srv_files
  "srv/CallPolygon.srv"
  "srv/CallSnapIt.srv"
  "srv/CheckCircle.srv"
  "srv/CheckCollision.srv"
  "srv/EnvironmentLock.srv"
  "srv/EuclideanSegment.srv"
  "srv/ICPAlign.srv"
  "srv/ICPAlignWithBox.srv"
  "srv/NonMaximumSuppression.srv"
  "srv/PolygonOnEnvironment.srv"
  "srv/RobotPickupReleasePoint.srv"
  "srv/SaveMesh.srv"
  "srv/SetDepthCalibrationParameter.srv"
  "srv/SetLabels.srv"
  "srv/SetPointCloud2.srv"
  "srv/SetTemplate.srv"
  "srv/SnapFootstep.srv"
  "srv/SwitchTopic.srv"
  "srv/TowerPickUp.srv"
  "srv/TowerRobotMoveCommand.srv"
  "srv/TransformScreenpoint.srv"
  "srv/UpdateOffset.srv"
  "srv/WhiteBalancePoints.srv"
  "srv/WhiteBalance.srv"
)

set(action_files
  "action/VQATask.action"
  "action/ClassificationTask.action"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  ${action_files}
  DEPENDENCIES std_msgs sensor_msgs geometry_msgs pcl_msgs jsk_footstep_msgs builtin_interfaces
)

ament_package()
