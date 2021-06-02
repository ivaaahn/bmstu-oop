cmake_minimum_required(VERSION 3.19)
project(implementation)

set(COMMANDS
        commands/camera/camera_command.hpp
        commands/camera/add/add_camera.cpp
        commands/camera/add/add_camera.hpp
        commands/camera/count/count_cameras.cpp
        commands/camera/count/count_cameras.hpp
        commands/camera/move/move_camera.cpp
        commands/camera/move/move_camera.hpp
        commands/camera/remove/remove_camera.cpp
        commands/camera/remove/remove_camera.hpp
        commands/camera/set/set_camera.cpp
        commands/camera/set/set_camera.hpp
        commands/camera/load/load_camera.cpp
        commands/camera/load/load_camera.hpp
        commands/model/model_command.hpp
        commands/model/add/add_model.cpp
        commands/model/add/add_model.hpp
        commands/model/count/count_models.cpp
        commands/model/count/count_models.hpp
        commands/model/load/load_model.cpp
        commands/model/load/load_model.hpp
        commands/model/move/move_model.cpp
        commands/model/move/move_model.hpp
        commands/model/remove/remove_model.cpp
        commands/model/remove/remove_model.hpp
        commands/model/rotate/rotate_model.cpp
        commands/model/rotate/rotate_model.hpp
        commands/model/scale/scale_model.cpp
        commands/model/scale/scale_model.hpp
        commands/model/transform/transform_model.cpp
        commands/model/transform/transform_model.hpp
        commands/scene/scene_command.hpp
        commands/scene/render/render_scene.cpp
        commands/scene/render/render_scene.hpp
#        commands/scene/load/load_scene.cpp
#        commands/scene/load/load_scene.hpp
        )


set(CONFIG_MANAGER
        config_manager/creator/config_manager_creator.hpp
        config_manager/creator/config_manager_creator.cpp
        config_manager/registration/registration_maker.hpp
        config_manager/registration/registration_maker.cpp
        config_manager/solution/solution.hpp
        config_manager/solution/solution.cpp
        config_manager/config_manager.hpp
        config_manager/config_manager.cpp
        )

set(DRAWER
        drawer/drawer.hpp)

set(EXCEPTIONS
        exceptions/base_exception.hpp
        exceptions/load_exceptions.hpp
        exceptions/model_exceptions.hpp
        exceptions/camera_exceptions.hpp
        exceptions/ui_exceptions.hpp
        )

set(FACADE
        facade/facade.hpp
        facade/facade.cpp
        )

set(LOAD
        load/builders/camera/camera_builder.cpp
        load/builders/camera/camera_builder.hpp
        load/builders/model/model_builder.cpp
        load/builders/model/model_builder.hpp
#        load/builders/scene/scene_builder.hpp
#        load/builders/scene/scene_builder.cpp
        load/directors/load_director.hpp
        load/directors/camera/camera_director.cpp
        load/directors/camera/camera_director.hpp
        load/directors/model/model_director.cpp
        load/directors/model/model_director.hpp
        load/solutions/camera/camera_load_solution.cpp
        load/solutions/camera/camera_load_solution.hpp
        load/solutions/model/model_load_solution.cpp
        load/solutions/model/model_load_solution.hpp
        load/loaders/object_loader.hpp
        load/loaders/object_loader_creator.hpp
        load/loaders/camera/camera_loader.hpp
        load/loaders/camera/file_camera_loader/file_camera_loader.cpp
        load/loaders/camera/file_camera_loader/file_camera_loader.hpp
        load/loaders/model/model_loader.hpp
        load/loaders/model/file_model_loader/file_model_loader.cpp
        load/loaders/model/file_model_loader/file_model_loader.hpp
        load/loaders/camera/file_camera_loader/file_camera_loader.hpp
        )

set(MANAGERS
        managers/manager.hpp
        managers/draw/draw_manager.cpp
        managers/draw/draw_manager.hpp
        managers/load/load_manager.cpp
        managers/load/load_manager.hpp
        managers/scene/scene_manager.cpp
        managers/scene/scene_manager.hpp
        managers/transform/transform_manager.cpp
        managers/transform/transform_manager.hpp
        )

set(OBJECTS
        objects/object.hpp
        objects/camera/camera.cpp
        objects/camera/camera.hpp
        objects/composite/composite.cpp
        objects/composite/composite.hpp
        objects/model/model.cpp
        objects/model/model.hpp
        objects/model/model_details/model_details.cpp
        objects/model/model_details/model_details.hpp
        objects/model/model_details/point/point.hpp
        objects/model/model_details/point/point.cpp
        objects/model/model_details/edge/edge.hpp
        objects/model/model_details/edge/edge.cpp
        )

set(SCENE
        scene/scene.cpp
        scene/scene.hpp
#        scene/director/scene_director.cpp
#        scene/director/scene_director.hpp
#        scene/loaders/scene_loader.hpp
#        scene/loaders/scene_loader_creator.hpp
#        scene/loaders/file/file_scene_loader.cpp
#        scene/loaders/file/file_scene_loader.hpp
#        scene/loaders/file/file_scene_loader_creator.hpp
#        scene/solution/scene_load_solution.hpp
#        scene/solution/scene_load_solution.cpp
        )

set(VISITOR
        visitor/visitor.hpp
        visitor/draw_visitor/draw_visitor.cpp
        visitor/draw_visitor/draw_visitor.hpp
        exceptions/camera_exceptions.hpp)


add_library(${PROJECT_NAME}
        ${COMMANDS}
        ${CONFIG_MANAGER}
        ${DRAWER}
        ${EXCEPTIONS}
        ${FACADE}
        ${LOAD}
        ${MANAGERS}
        ${OBJECTS}
        ${SCENE}
        ${VISITOR}
)

target_include_directories(${PROJECT_NAME} PUBLIC ../implementation)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)