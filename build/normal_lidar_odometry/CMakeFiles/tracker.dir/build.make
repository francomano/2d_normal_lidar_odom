# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mf/Scrivania/2d_normal_lidar_odom/src/normal_lidar_odom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mf/Scrivania/2d_normal_lidar_odom/build/normal_lidar_odometry

# Include any dependencies generated for this target.
include CMakeFiles/tracker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tracker.dir/flags.make

CMakeFiles/tracker.dir/src/tracker.cpp.o: CMakeFiles/tracker.dir/flags.make
CMakeFiles/tracker.dir/src/tracker.cpp.o: /home/mf/Scrivania/2d_normal_lidar_odom/src/normal_lidar_odom/src/tracker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mf/Scrivania/2d_normal_lidar_odom/build/normal_lidar_odometry/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tracker.dir/src/tracker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tracker.dir/src/tracker.cpp.o -c /home/mf/Scrivania/2d_normal_lidar_odom/src/normal_lidar_odom/src/tracker.cpp

CMakeFiles/tracker.dir/src/tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tracker.dir/src/tracker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mf/Scrivania/2d_normal_lidar_odom/src/normal_lidar_odom/src/tracker.cpp > CMakeFiles/tracker.dir/src/tracker.cpp.i

CMakeFiles/tracker.dir/src/tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tracker.dir/src/tracker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mf/Scrivania/2d_normal_lidar_odom/src/normal_lidar_odom/src/tracker.cpp -o CMakeFiles/tracker.dir/src/tracker.cpp.s

# Object files for target tracker
tracker_OBJECTS = \
"CMakeFiles/tracker.dir/src/tracker.cpp.o"

# External object files for target tracker
tracker_EXTERNAL_OBJECTS =

/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: CMakeFiles/tracker.dir/src/tracker.cpp.o
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: CMakeFiles/tracker.dir/build.make
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libtf2_ros.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libactionlib.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libmessage_filters.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libroscpp.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librosconsole.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libtf2.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librostime.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libcpp_common.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libros_bridge.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libicp.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libtf2_ros.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libactionlib.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libmessage_filters.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libroscpp.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librosconsole.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libtf2.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/librostime.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /opt/ros/noetic/lib/libcpp_common.so
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so: CMakeFiles/tracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mf/Scrivania/2d_normal_lidar_odom/build/normal_lidar_odometry/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tracker.dir/build: /home/mf/Scrivania/2d_normal_lidar_odom/devel/.private/normal_lidar_odometry/lib/libtracker.so

.PHONY : CMakeFiles/tracker.dir/build

CMakeFiles/tracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tracker.dir/clean

CMakeFiles/tracker.dir/depend:
	cd /home/mf/Scrivania/2d_normal_lidar_odom/build/normal_lidar_odometry && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mf/Scrivania/2d_normal_lidar_odom/src/normal_lidar_odom /home/mf/Scrivania/2d_normal_lidar_odom/src/normal_lidar_odom /home/mf/Scrivania/2d_normal_lidar_odom/build/normal_lidar_odometry /home/mf/Scrivania/2d_normal_lidar_odom/build/normal_lidar_odometry /home/mf/Scrivania/2d_normal_lidar_odom/build/normal_lidar_odometry/CMakeFiles/tracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tracker.dir/depend

