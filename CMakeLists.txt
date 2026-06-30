cmake_minimum_required(VERSION 3.16)

project(GreenBasket VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup(REQUIRES 6.10)

# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appGreenBasket
    src/main.cpp
)

qt_add_qml_module(appGreenBasket
    URI GreenBasket

    QML_FILES
        src/ui/Main.qml

        src/ui/screens/qml/Sale.qml
        src/ui/screens/qml_ui/SaleView.ui.qml

        src/ui/controls/ActionButton2.qml
        src/ui/controls/IconButton.qml
        src/ui/controls/ActionButton.qml
        src/ui/controls/TicketPanel.qml
        src/ui/controls/TabButton1.qml

        src/ui/shapes/Tab.qml

    RESOURCES
        class-diagram/diagram.qmodel

    SOURCES
        src/domain/product.h             src/domain/product.cpp
        src/domain/productlist.h         src/domain/productlist.cpp
        #src/domain/stockproduct.h        src/domain/stockproduct.cpp
        #src/domain/user.h                src/domain/user.cpp
        #src/domain/account.h             src/domain/account.cpp
        src/domain/billitem.h            src/domain/billitem.cpp
        src/domain/sectioninfo.h     src/domain/sectioninfo.cpp
        src/domain/productgroup.h             src/domain/productgroup.cpp
        #src/domain/inventoryitem.h       src/domain/inventoryitem.cpp

        src/domain/qmltypes/bill.h       src/domain/qmltypes/bill.cpp
        src/domain/qmltypes/sale.h       src/domain/qmltypes/sale.cpp
        #src/domain/qmltypes/stock.h      src/domain/qmltypes/stock.cpp
        #src/domain/qmltypes/inventory.h  src/domain/qmltypes/inventory.cpp
        src/domain/qmltypes/menu.h       src/domain/qmltypes/menu.cpp
        SOURCES src/domain/qmltypes/submenu.h src/domain/qmltypes/submenu.cpp


)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appGreenBasket PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appGreenBasket
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGreenBasket
    PRIVATE Qt6::Quick
)
target_link_libraries(appGreenBasket PRIVATE Qt6::Widgets)

# ============================================================
# Firma local de desarrollo para Windows
# ============================================================

if(WIN32 AND NOT ANDROID)

    set(GREENBASKET_SIGNTOOL
        "C:/Program Files (x86)/Windows Kits/10/bin/10.0.28000.0/x64/signtool.exe"
    )

    set(GREENBASKET_CERT_THUMBPRINT
        "A7DCF02CDA7304F2C1082CB2F6EBAA1F4C472054"
    )

    if(EXISTS "${GREENBASKET_SIGNTOOL}")

        add_custom_command(TARGET appGreenBasket POST_BUILD
            COMMAND "${GREENBASKET_SIGNTOOL}"
                    sign
                    /fd SHA256
                    /s My
                    /sha1 ${GREENBASKET_CERT_THUMBPRINT}
                    "$<TARGET_FILE:appGreenBasket>"
            COMMENT "Firmando appGreenBasket.exe con certificado local de desarrollo"
            VERBATIM
        )

    else()
        message(WARNING "No se encontro signtool.exe en: ${GREENBASKET_SIGNTOOL}")
    endif()

endif()

install(TARGETS appGreenBasket
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
