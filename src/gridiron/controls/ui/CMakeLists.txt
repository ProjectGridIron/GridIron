# src/gridiron/controls/ui/CMakeLists.txt
set(GRIDIRON_UI_CONTROLS_SOURCE_ROOT ${GRIDIRON_CONTROLS_SOURCE_ROOT}/ui)
set(GRIDIRON_UI_CONTROLS_INCLUDE_ROOT ${GRIDIRON_CONTROLS_INCLUDE_ROOT}/ui)
list(APPEND GRIDIRON_CONTROL_SOURCES
    ${GRIDIRON_UI_CONTROLS_SOURCE_ROOT}/AttributeValue.cpp
    ${GRIDIRON_UI_CONTROLS_INCLUDE_ROOT}/AttributeValue.hpp
    ${GRIDIRON_UI_CONTROLS_SOURCE_ROOT}/ContentValue.cpp
    ${GRIDIRON_UI_CONTROLS_INCLUDE_ROOT}/ContentValue.hpp
    ${GRIDIRON_UI_CONTROLS_SOURCE_ROOT}/Label.cpp
    ${GRIDIRON_UI_CONTROLS_INCLUDE_ROOT}/Label.hpp
)