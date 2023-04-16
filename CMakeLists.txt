cmake_minimum_required(VERSION 3.14)

project(GloK LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets SerialPort Bluetooth)

# Установить путь к папке с данными
set(DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example_data)

# Копирование файла JSON в каталог сборки
configure_file(${DATA_DIR}/example_input_config.json ${CMAKE_CURRENT_BINARY_DIR}/example_data/example_input_config.json COPYONLY)



add_executable(GloK
  main.cpp

  item/item.h
  item/src_item/constructor.cpp
  item/src_item/draw.cpp
  item/src_item/geometry.cpp
  item/src_item/rotate.cpp
  item/src_item/parent.cpp
  item/src_item/coord.cpp
  item/src_item/check_input.cpp
  item/src_item/name.cpp
  item/src_item/calculate_end_pos.cpp

  item/adapter_item.h
  item/src_adapter_item/get_item.cpp
  item/src_adapter_item/constructor.cpp
  item/src_adapter_item/delete_item.cpp


  windows/3dgraphics/widget3d.h
  windows/3dgraphics/src/constructor.cpp
  windows/3dgraphics/src/initializegl.cpp
  windows/3dgraphics/src/resizegl.cpp
  windows/3dgraphics/src/paintgl.cpp
  windows/3dgraphics/src/mouseevents.cpp
  windows/3dgraphics/src/cube.cpp

  windows/side/side.h
  windows/side/src/constructor.cpp

  windows/side/item_widget_settings/item_widget.h
  windows/side/item_widget_settings/src/constructor.cpp
  windows/side/item_widget_settings/src/update_all.cpp
  windows/side/item_widget_settings/src/manual_updated.cpp

  windows/side/item_widget_settings/widget_serial_port_connection/widget_serial_port_connection.h
  windows/side/item_widget_settings/widget_serial_port_connection/src/constructor.cpp
  windows/side/item_widget_settings/widget_serial_port_connection/src/slots.cpp

  windows/mainwindow/mainwindow.h
  windows/mainwindow/src/constructor.cpp

  adapters/i_adapter.h
  adapters/iadapter/constructor.cpp
  adapters/iadapter/update_geometry.cpp
  adapters/iadapter/update_rotate.cpp
  adapters/iadapter/get_data.cpp

  adapters/file_reader/file_reader_adapter.h
  adapters/file_reader/src/constructor.cpp
  adapters/file_reader/src/read_config.cpp
  adapters/file_reader/src/read_data.cpp
  adapters/file_reader/src/get_and_change_file_name.cpp
  adapters/file_reader/src/connect_to_point.cpp
  adapters/file_reader/src/get_points.cpp

  adapters/serial_port_redaer/serial_port_reader.h
  adapters/serial_port_redaer/src/constructor.cpp
  adapters/serial_port_redaer/src/get_name_points.cpp
  adapters/serial_port_redaer/src/connect_to_point.cpp
  adapters/serial_port_redaer/src/disconnect_to_point.cpp
  adapters/serial_port_redaer/src/hande_new_data.cpp

  adapters/bluetooth/bluetooth_reader.h
  adapters/bluetooth/src/constuctor.cpp
  adapters/bluetooth/src/connect_to_point.cpp
  adapters/bluetooth/src/get_name_points.cpp

  gestrure_handler/mouse/MouseController.h
  gestrure_handler/mouse/constructor/constructor.cpp
  gestrure_handler/mouse/constructor/calibrate.cpp
  gestrure_handler/mouse/constructor/update.cpp

  gestrure_handler/keyboard/KeyboardController.h

  windows/widget_gesture_handler/widget_gesture_handler.h
  windows/widget_gesture_handler/src/constructor.cpp
)

target_link_libraries(GloK PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::OpenGL
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::SerialPort   
    Qt${QT_VERSION_MAJOR}::Bluetooth
)

install(TARGETS GloK
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
