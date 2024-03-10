cmake_minimum_required(VERSION 3.12)
project(DesignPatterns)

set(SOURCES
    abstract-factory/abstractFactory.cpp
    adapter/PowerOutlet_Adapter.cpp
    adapter/Adapter.cpp
    composite/Composite.cpp
    decorator/Decorator.cpp
    factory-method/FactoryMethod_DocumentCreator.cpp
    factory-method/FactoryMethod.cpp
    observer/Observer.cpp
    singleton/Singleton.cpp
    strategy/Strategy.cpp
    template-method/TemplateMethod.cpp
)

foreach(_file IN ITEMS ${SOURCES})
    get_filename_component(_file_name ${_file} NAME_WE) 
    set(_project_name "${_file_name}")
    add_executable(${_project_name} ${_file})
endforeach()
