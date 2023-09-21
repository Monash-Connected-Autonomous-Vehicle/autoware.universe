cmake_minimum_required(VERSION 3.5)
project(autoware_msgs)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(jsk_recognition_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files
    "msg/AccelCmd.msg"
    "msg/AdjustXY.msg"
    "msg/BrakeCmd.msg"
    "msg/Centroids.msg"
    "msg/CloudCluster.msg"
    "msg/CloudClusterArray.msg"
    "msg/ColorSet.msg"
    "msg/ControlCommand.msg"
    "msg/ControlCommandStamped.msg"
    "msg/DTLane.msg"
    "msg/DetectedObject.msg"
    "msg/DetectedObjectArray.msg"
    "msg/ExtractedPosition.msg"
    "msg/Gear.msg"
    "msg/GeometricRectangle.msg"
    "msg/ICPStat.msg"
    "msg/ImageLaneObjects.msg"
    "msg/ImageObj.msg"
    "msg/ImageObjRanged.msg"
    "msg/ImageObjTracked.msg"
    "msg/ImageObjects.msg"
    "msg/ImageRect.msg"
    "msg/ImageRectRanged.msg"
    "msg/IndicatorCmd.msg"
    "msg/LampCmd.msg"
    "msg/Lane.msg"
    "msg/LaneArray.msg"
    "msg/NDTStat.msg"
    "msg/ObjLabel.msg"
    "msg/ObjPose.msg"
    "msg/PointsImage.msg"
    "msg/ProjectionMatrix.msg"
    "msg/RemoteCmd.msg"
    "msg/ScanImage.msg"
    "msg/Signals.msg"
    "msg/State.msg"
    "msg/StateCmd.msg"
    "msg/SteerCmd.msg"
    "msg/SyncTimeDiff.msg"
    "msg/SyncTimeMonitor.msg"
    "msg/TrafficLight.msg"
    "msg/TrafficLightResult.msg"
    "msg/TrafficLightResultArray.msg"
    "msg/TunedResult.msg"
    "msg/ValueSet.msg"
    "msg/VehicleCmd.msg"
    "msg/VehicleLocation.msg"
    "msg/VehicleStatus.msg"
    "msg/VscanTracked.msg"
    "msg/VscanTrackedArray.msg"
    "msg/Waypoint.msg"
    "msg/WaypointState.msg"
)

set(srv_files
    "srv/RecognizeLightState.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  DEPENDENCIES geometry_msgs jsk_recognition_msgs sensor_msgs std_msgs
)

ament_package()
